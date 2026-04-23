#include <math.h>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <fstream>


// int factoriel(int n);
// double hermite(double & x, int n);
// Eigen::VectorXd racines(int n);
// Eigen::VectorXd constr_poids(int n);
double u_0(double x);
double sol_exacte_diff(Eigen::VectorXd points, Eigen::VectorXd poids, double x, double t, int n, double nu);
//void readGaussHermite(const std::string& filename, Eigen::VectorXd points, Eigen::VectorXd weights);
// double solution(double x, double t, int n);
