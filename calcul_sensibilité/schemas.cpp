#include <iostream>
#include <complex>
#include <Eigen/Sparse>
#include <Eigen/Dense>
#include "schemas.h"

using namespace Eigen;
using namespace std;

TimeScheme::TimeScheme() : _sys(0)
{
}

// Destructeur
TimeScheme::~TimeScheme()
{
}

// Initialisation de vos différentes variables
void TimeScheme::Initialize(double t0, double dt, VectorXd & sol0, string results, OdeSystem* sys)
{
   this->_dt = dt;
   this->_t = t0 ;
   this->_sol0 = sol0;
   this->_sol = sol0;
   this->_sys = sys;
   if (results.size() > 0)
   {
      this->_sys->InitializeFileName(results);
   }
}
for (i = 1; i<=imax; i++)
{
        
}
      //  do k=1, imax
      //      !u_i0 : à l'instant 0
       //     xi(k)=k*delta_x
       //     un(k)=uinit(xi(k),ci)
       // end do
       // open(1,file=fichier)
       // write(1,*)0,un(0)
       // tn=delta_t
       // do while (tn<tmax)
        //!calcul à l'instant n
        //    un(0)=ug(tn,cl)
        //    un1(0)=ug(tn,cl)
        //    do i=1,imax-1
        //        un1(i)=un(i)-(a*delta_t/delta_x)*(un(i)-un(i-1))+(D/delta_x**2)*(un(i+1)+un(i-1)-2*un(i))
        ///    end do
         //   un1(imax)=un1(imax-1)
         //   un=un1
         //   tn=tn + delta_t
       // end do
       // tn=tn-delta_t