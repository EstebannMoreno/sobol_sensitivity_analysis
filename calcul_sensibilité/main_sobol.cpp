#include <iostream>
#include <fstream>
#include <complex>
#include <Eigen/Sparse>
#include <Eigen/Dense>
#include "sol_exacte.h"
//#include "schemas.h"

using namespace Eigen;
using namespace std;



   
//solution créneau initiale pour vérifier partie diffusion 
double uinit_diff(double & x)
{
   if (x>=0.6 && x<=0.7)
    {
        return 1;
    }
    else {
    return 0;
    }
}


//fonction bord gauche
double ug(double & t)
{
return 0;
}


int main()
{

//CODE PRINCIPAL
ofstream fichiersortie, fichiersortie2,fichiersortie3,fichiersortie4;
ofstream solexacte;
FILE *parametres;

parametres = fopen("coeffs_matrices_2.txt", "r");

if (parametres == NULL) {
    perror("Erreur lors de l'ouverture du fichier");
    return 1;   // Fin du programme avec un code d'erreur
}


double L = 1.0 ;
double cfl(0.44);
double tmax(0.1);

//IL FAUT FAIRE UNE BOUCLE POUR RELANCER LA SIMULATION POUR CHAQUE LIGNE DU FICHIER TEXTE

double a, nu, dx;

fichiersortie3.open("u_065.txt");
fichiersortie2.open("u_060.txt");
fichiersortie.open("u_050.txt");
fichiersortie4.open("u_080.txt");

if (!fichiersortie.is_open() || !fichiersortie2.is_open() || !fichiersortie3.is_open() || !fichiersortie4.is_open()  ) {
cerr << "Erreur : impossible d'ouvrir le fichier pour écriture." << endl;
return 1;
}


// Boucle qui lit les 3 paramètres à chaque ligne
while (fscanf(parametres, "%lf %lf %lf", &a, &nu, &dx) == 3) {
//récupération de dx, nu et adepuis la ligne i du fichier texte créé par code python contenant les lignes de chaque matrice

int imax = int(ceil(L/dx));


// On veut interpoler u en x = 0.65 exactement
int m = int(ceil(0.65/dx));
int k = int(ceil(0.6/dx));
int j = int(ceil(0.5/dx));
int p = int(ceil(0.8/dx));

if (j >= imax) 
{
    j = imax - 1;
}

if (k >= imax) 
{
    k = imax - 1;
}

if (m >= imax) 
{
    m = imax - 1;
}

if (p >= imax) 
{
    p = imax - 1;
}




double x_left_j = (j-1) * dx;
double x_right_j = j * dx;
double x_left_k = (k-1) * dx;
double x_right_k = k * dx;
double x_left_m = (m-1) * dx;
double x_right_m = m * dx;
double x_left_p = (p-1) * dx;
double x_right_p = p * dx;

double dt = cfl*pow(dx,2)/nu;
int nb_iterations = int(ceil(tmax/dt));

Eigen::VectorXd u;
Eigen::VectorXd un1;
Eigen::VectorXd X;
X.resize(imax+1);
u.resize(imax+1);
un1.resize(imax+1);

for (int i = 0; i<=imax; i++)
{
    //maillage en espace
    X(i)=i*dx;
    //condition initiale
    u(i)=uinit_diff(X(i));
}


    double t = dt;

    //bord gauche
    un1(0)=ug(t);
    u(0)=ug(t);
    
    //cout<<"n="<< nb_iterations<< endl;
    //cout << "j=" << j << " (approx x=0.65)" << endl;


    for (int n=1; n<=nb_iterations; n++)
    {
        //calcul à l'instant n
        for (int i=1;i<imax;i++)
        {
            un1(i)=u(i)-(a*dt/dx)*(u(i)-u(i-1))+(nu*dt/pow(dx,2))*(u(i+1)+u(i-1)-2*u(i));
        }
        if (n == nb_iterations)
        {
            // Interpolation linéaire de u en x=0.65 entre j et j+1
            double u_interp_1 = un1(j-1) + (0.5 - x_left_j) * (un1(j) - un1(j-1)) / (x_right_j - x_left_j);
            fichiersortie  << u_interp_1 << endl;
            double u_interp_2 = un1(k-1) + (0.6 - x_left_k) * (un1(k) - un1(k-1)) / (x_right_k - x_left_k);
            fichiersortie2  << u_interp_2 << endl;
            double u_interp_3 = un1(m-1) + (0.65 - x_left_m) * (un1(m) - un1(m-1)) / (x_right_m - x_left_m);
            fichiersortie3  << u_interp_3 << endl;
            double u_interp_4 = un1(p-1) + (0.8 - x_left_p) * (un1(p) - un1(p-1)) / (x_right_p - x_left_p);
            fichiersortie4  << u_interp_4 << endl;
            cout << "ecriture " << u_interp_1 << endl;
        }
        un1(imax)=un1(imax-1);
        t+=dt;
        u=un1;
    }
    
}

    fichiersortie.close();
    fclose(parametres);

 
return 0;
}