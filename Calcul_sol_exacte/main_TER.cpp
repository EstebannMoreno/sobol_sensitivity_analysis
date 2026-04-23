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

//VERIFICATION PARTIE DIFFUSIONS
int n_pts=10; //nombre de points d'interpolation

//Lecture du fichier gauss hermite et création des vecteurs avec poids et points d'interpolation 
ifstream monFlux("gauss_hermite.txt");

Eigen::VectorXd poids, points;
poids.resize (n_pts);
points.resize(n_pts);

if (monFlux){

    string ligne;
        // getline(monFlux, ligne); //On lit une ligne complète

        // monFlux.ignore();        //On change de mode
    double mot;
    monFlux >> ligne; 
    monFlux >> ligne; 

    for (int i = 0; i<2*n_pts; i++){

        monFlux >> mot;          //On lit un mot depuis le fichier
            // cout << mot << endl;
        if (i/2.== i/2){
            points(i/2) = mot;
        }
        else{
            poids(i/2) = mot;
        }


        }
       // cout << "Points" << endl << points << endl;
       // cout << "Poids" << endl << poids << endl;
    }
    else {
        cout << "ERREUR, impossible d'ouvrir le fichier" << endl;
    }


    //construction des poids et points à la main
    // Eigen::VectorXd points;
    // Eigen::VectorXd poids;
    // points.resize(n_pts);
    // poids.resize(n_pts);
    // poids << 5.90806787e-79, 1.97286057e-72, 3.08302899e-67, 9.01922230e-63, 8.51888308e-59, 3.45947794e-55, 7.19152946e-52, 8.59756395e-49, 6.42072521e-46, 3.18521788e-43, 1.10047068e-40, 2.74878488e-38, 5.11623260e-36, 7.27457260e-34, 8.06743428e-32, 7.10181223e-30, 5.03779117e-28, 2.91735007e-26, 1.39484153e-24, 5.56102696e-23, 1.86499768e-21, 5.30231618e-20, 1.28683292e-18, 2.68249216e-17, 4.82983532e-16, 7.54889688e-15, 1.02887494e-13, 1.22787851e-12, 1.28790383e-11, 1.19130063e-10, 9.74792125e-10, 7.07585728e-09, 4.56812751e-08, 2.62909748e-07, 1.35179716e-06, 6.22152482e-06, 2.56761594e-05, 9.51716278e-05, 3.17291971e-04, 9.52692189e-04, 2.57927326e-03, 6.30300029e-03, 1.39156652e-02, 2.77791274e-02, 5.01758127e-02, 8.20518274e-02, 1.21537987e-01, 1.63130031e-01, 1.98462850e-01, 2.18892630e-01, 2.18892630e-01, 1.98462850e-01, 1.63130031e-01, 1.21537987e-01, 8.20518274e-02, 5.01758127e-02, 2.77791274e-02, 1.39156652e-02, 6.30300029e-03, 2.57927326e-03, 9.52692189e-04, 3.17291971e-04, 9.51716278e-05, 2.56761594e-05, 6.22152482e-06, 1.35179716e-06, 2.62909748e-07, 4.56812751e-08, 7.07585728e-09, 9.74792125e-10, 1.19130063e-10, 1.28790383e-11, 1.22787851e-12, 1.02887494e-13, 7.54889688e-15, 4.82983532e-16, 2.68249216e-17, 1.28683292e-18, 5.30231618e-20, 1.86499768e-21, 5.56102696e-23, 1.39484153e-24, 2.91735007e-26, 5.03779117e-28, 7.10181223e-30, 8.06743428e-32, 7.27457260e-34, 5.11623260e-36, 2.74878488e-38, 1.10047068e-40, 3.18521788e-43, 6.42072521e-46, 8.59756395e-49, 7.19152946e-52, 3.45947794e-55, 8.51888308e-59, 9.01922230e-63, 3.08302899e-67, 1.97286057e-72, 5.90806787e-79;
    // points << -13.40648734, -12.82379975, -12.34296422, -11.91506194, -11.5214154, -11.15240439, -10.80226075, -10.46718542, -10.14450994, -9.83226981, -9.52896582, -9.23342089, -8.94468922, -8.66199617, -8.38469694, -8.11224731, -7.84418238, -7.58010081, -7.31965282, -7.06253106, -6.80846335, -6.55720703, -6.30854436, -6.06227883, -5.81823214, -5.57624165, -5.33615836, -5.09784511, -4.86117509, -4.62603064, -4.39230208, -4.15988686, -3.92868868, -3.69861686, -3.46958564, -3.24151368, -3.01432358, -2.78794142, -2.5622964, -2.33732046, -2.112948, -1.88911554, -1.66576151, -1.44282597, -1.22025039, -0.99797744, -0.77595076, -0.55411482, -0.33241469, -0.11079587, 0.11079587, 0.33241469, 0.55411482, 0.77595076, 0.99797744, 1.22025039, 1.44282597, 1.66576151, 1.88911554, 2.112948, 2.33732046, 2.5622964, 2.78794142, 3.01432358, 3.24151368, 3.46958564, 3.69861686, 3.92868868, 4.15988686, 4.39230208, 4.62603064, 4.86117509, 5.09784511, 5.33615836, 5.57624165, 5.81823214, 6.06227883, 6.30854436, 6.55720703, 6.80846335, 7.06253106, 7.31965282, 7.58010081, 7.84418238, 8.11224731, 8.38469694, 8.66199617, 8.94468922, 9.23342089, 9.52896582, 9.83226981, 10.14450994, 10.46718542, 10.80226075, 11.15240439, 11.5214154, 11.91506194, 12.34296422, 12.82379975, 13.40648734;



//CODE PRINCIPAL
ofstream fichiersortie;
ofstream solexacte;

//paramètres
double L(1.); 
int imax(200);
double dx = L/imax;
//cout << "dx =" << dx<< endl;
double a(0.0);
double nu(0.001);
double cfl(0.4);
double tmax(1.);
double dt = cfl*pow(dx,2)/nu;
cout << "dt"<<dt<<endl;
int nb_iterations = int(ceil(tmax/dt));

Eigen::VectorXd u;
Eigen::VectorXd un1;
Eigen::VectorXd X;
X.resize(imax);
u.resize(imax);
un1.resize(imax);
u(0)=0;

for (int i = 0; i<imax; i++)
{
    //maillage en espace
    X(i)=i*dx;
    //condition initiale
    u(i)=uinit_diff(X(i));
}

    fichiersortie.open("test_adv_diff.txt");
    solexacte.open("sol_exacte.txt");

    if (!fichiersortie.is_open()  || !solexacte.is_open() ) {
    cerr << "Erreur : impossible d'ouvrir le fichier pour écriture." << endl;
    return 1;
    }

    double t = dt;

    //bord gauche
    un1(0)=ug(t);
    u(0)=ug(t);
    fichiersortie << X(0) << " " << u(0)<< endl; //écriture du terme au bord gauche dans le fichier (le même à tout instant t)
    solexacte << X(0) << " " << sol_exacte_diff(points, poids, X(0),dt*nb_iterations,n_pts, nu)<< endl; //écriture du terme au bord gauche dans le fichier au temps final
    for (int n=1; n<=nb_iterations; n++)
    {
        //calcul à l'instant n
        for (int i=1;i<imax-1;i++)
        {
            un1(i)=u(i)-(a*dt/dx)*(u(i)-u(i-1))+(nu*dt/pow(dx,2))*(u(i+1)+u(i-1)-2*u(i));

            if (n==nb_iterations)
            {
                //écriture dans les fichiers au temps final
                fichiersortie << X(i) << " " << un1(i)<< endl;
                solexacte << X(i) << " " << sol_exacte_diff(points, poids, X(i),t,n_pts, nu)<< endl;
            }
        }
        un1(imax-1)=un1(imax-2);
            if (n==nb_iterations)
            {
        fichiersortie << X(imax-1) << " " << un1(imax-1)<< endl;
        solexacte << X(imax-1) << " " << sol_exacte_diff(points, poids, X(imax-1),t,n_pts, nu)<< endl;
            }
        t+=dt;
        u=un1;
    }
    fichiersortie.close();
    solexacte.close();
 
return 0;
}