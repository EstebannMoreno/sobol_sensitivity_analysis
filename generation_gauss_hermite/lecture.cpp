#include <iostream>
#include <fstream>
#include <Eigen/Sparse>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;


int main () {

    ifstream monFlux("/net/netud/m/rpras/2A/TER/gauss_hermite.txt");

    if (monFlux){

        string ligne;
        // getline(monFlux, ligne); //On lit une ligne complète

        // monFlux.ignore();        //On change de mode
        double mot;
        monFlux >> ligne; 
        monFlux >> ligne; 
        
        int n(20);
        Eigen::VectorXd poids, points;
        poids.resize(n);
        points.resize(n);

        for (int i = 0; i<2*n; i++){

            monFlux >> mot;          //On lit un mot depuis le fichier
            // cout << mot << endl;
            if (i/2.== i/2){
                points(i/2) = mot;
            }
            else{
                poids(i/2) = mot;
            }


        }
        cout << "Points" << endl << points << endl;
        cout << "Poids" << endl << poids << endl;
    }
    else {
        cout << "ERREUR, impossible d'ouvrir le fichier" << endl;
    }

    return 0;
}
