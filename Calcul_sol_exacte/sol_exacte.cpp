#include <iostream>
#include <complex>
#include <Eigen/Sparse>
#include <Eigen/Dense>
#include "sol_exacte.h"
#include <math.h>

//condition créneau initiale
double u_0(double x)
{
    if (x>=0.6 && x<=0.7)
    {
        return 1;
    }
    else {
    return 0;
    }
}

//solution exacte
double sol_exacte_diff(Eigen::VectorXd points, Eigen::VectorXd poids, double x, double t, int n, double nu)
{
     double u = 0;
     for (int i=0;i<n; i++)
     {
         u+=poids(i)*u_0(x-sqrt(nu*t)*points(i));
     }
    return u;
}


//ça ça sert à rien
// //construction des poids wi
// Eigen::VectorXd racines(int n)
// {
//     Eigen::VectorXd y; //racines yi
//     y.resize(n);
//     switch(n) {
//     case 10: { //en 10 points
//         y.resize(10);
//         y(0)= -3.436159;
//         y(1)=-2.532732;
//         y(2)=-1.756684;
//         y(3)=-1.036611;
//         y(4)=-0.342901;
//         y(5)=0.342901;
//         y(6)=1.036611;
//         y(7)=1.756684;
//         y(8)=2.532732;
//         y(9)=3.436159;
//             }
//             }
//     return y;
// }

// Eigen::VectorXd constr_poids(int n)
// {
// Eigen::VectorXd y = racines(n); //racines yi
// Eigen::VectorXd w; //poids
// w.resize(n);
// for (int j=0;j<n;j++)
// {
//     //dérivée du polynôme de l'hermite en yj : 
//     //H'n(yj)=nHn-1(yj)
//     double hn_prime = n*hermite(y(j),n-1);
//     w(j)=(pow(2,n+1)*factoriel(n)*sqrt(M_PI))/pow(hn_prime,2);
// }
// return w;
// }

// double u_0(double x)
// { //condition initiale créneau
//         if (x>=15 && x<=16)
//     {
//         return 1;
//     }
//     else {
//     return 0;
//     }
// }



// double solution(double x, double t, int n)
// { //calcul de u(x,t) avec n points d'interpolation
// double nu=0.01; //coef de diffusion
// Eigen::VectorXd w = constr_poids(n);
// Eigen::VectorXd y = racines(n);
//     double u=0;
//     for (int i=0;i<n;i++)
//     {
//         u+=(1/sqrt(4*M_PI*t*nu))*w(i)*u_0(x-y(i));
//     }
//     return u;
// }

// void readGaussHermite(const std::string& filename, Eigen::VectorXd points, Eigen::VectorXd weights) {
//     std::ifstream infile(filename);

//     if (!infile.is_open()) {
//         std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << std::endl;
//         return;
//     }
//     std::vector<double> temp_points; // Stockage temporaire
//     std::vector<double> temp_weights;

//     std::string line;
//     while (std::getline(infile, line)) {
//         std::istringstream iss(line);
//         double point, weight;

//         // Lecture des deux valeurs dans chaque ligne
//         if (iss >> point >> weight) {
//             temp_points.push_back(point);
//             temp_weights.push_back(weight);
//         }
//     }

//     infile.close();
//     points = Eigen::VectorXd::Map(temp_points.data(), temp_points.size());
//     weights = Eigen::VectorXd::Map(temp_weights.data(), temp_weights.size());
// }