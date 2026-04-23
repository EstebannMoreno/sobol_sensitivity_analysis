from math import *
from random import *
import matplotlib.pyplot as plt
import numpy as np

#fonction exemple u
def u(a,nu,dx):
    return exp(-a+dx)+nu*(a**3)

# N points (matrices de taille Nx3)
N=1000000

#N_x points pour le pas dx
N_x = 200
v = 1/N_x
valeurs = [v,v/2,v/4,v/8]

#MATRICE A
#simulations de a : loi uniforme sur [1,2], tableau de N valeurs
a_A = np.random.uniform(1, 2, N)
#print(a_A)

#simulations de nu : loi uniforme sur [0,10], tableau de N valeurs
nu_A = np.random.uniform(0, 10, N)
#print(nu_A)

#simulations de dx : loi uniforme sur {1/Nx...,1/8Nx}, tableau de N valeurs
#dx_A = np.random.uniform(v, 1/(8*v), N)
dx_A = np.random.choice(valeurs, size=N)
#print(dx_A)

A = np.array([a_A, nu_A, dx_A]).T
#print(A)

#MATRICE B
#simulations de a : loi uniforme sur [1,2], tableau de N valeurs
a_B = np.random.uniform(1, 2, N)

#simulations de nu : loi uniforme sur [0,10], tableau de N valeurs
nu_B = np.random.uniform(0, 10, N)

#simulations de dx : loi uniforme sur {1/Nx...,1/8Nx}, tableau de N valeurs
#dx_B = np.random.choice(valeurs, size=N)
#dx_B=np.random.uniform(0, 1, N)

dx_B = np.random.choice(valeurs, size=N)
#dx_B = np.random.uniform(v, 1/(8*v), N)


B = np.array([a_B, nu_B, dx_B]).T


#MATRICE Ca
C_a = np.array([a_B, nu_A, dx_A]).T


#MATRICE C_nu
C_nu = np.array([a_A, nu_B, dx_A]).T


#MATRICE C_dx
C_dx = np.array([a_A, nu_A, dx_B]).T


#Construction des indices de Sobol
V_a = 0
V_nu = 0
V_dx = 0

V_tot_a = 0
V_tot_nu = 0
V_tot_dx = 0

uA=[]
uB=[]
uCa=[]
uCnu=[]
uCdx=[]

for i in range(N):
    u_iA=u(A[i][0],A[i][1],A[i][2])
    u_iB=u(B[i][0],B[i][1],B[i][2])
    u_iCa=u(C_a[i][0],C_a[i][1],C_a[i][2])
    u_iCnu=u(C_nu[i][0],C_nu[i][1],C_nu[i][2])
    u_iCdx=u(C_dx[i][0],C_dx[i][1],C_dx[i][2])

    uA.append(u_iA)
    uB.append(u_iB)
    uCa.append(u_iCa)
    uCnu.append(u_iCnu)
    uCdx.append(u_iCdx)

    V_a+=-(1/N)*u_iB*(u_iA-u_iCa)
    V_nu+=-(1/N)*u_iB*(u_iA-u_iCnu)
    V_dx+=-(1/N)*u_iB*(u_iA-u_iCdx)

    V_tot_a += (1/N)*u_iA*(u_iA-u_iCa)
    V_tot_nu += (1/N)*u_iA*(u_iA-u_iCnu)
    V_tot_dx += (1/N)*u_iA*(u_iA-u_iCdx)



Vtot = (1/5)*(np.var(uA)+np.var(uB)+np.var(uCa)+np.var(uCdx)+np.var(uCnu))

S_a = abs(V_a)/Vtot
S_nu = abs(V_nu)/Vtot
S_dx = abs(V_dx)/Vtot

S_tot_a = abs(V_tot_a)/Vtot
S_tot_nu = abs(V_tot_nu)/Vtot
S_tot_dx = abs(V_tot_dx)/Vtot

print("Indice de a = ", S_a*100, "%")
print("Indice de nu = ", S_nu*100, "%")
print("Indice de dx = ", S_dx*100, "%")
print("Indice total de a = ", S_tot_a*100, "%")
print("Indice total de nu = ", S_tot_nu*100, "%")
print("Indice total de dx = ", S_tot_dx*100, "%")
print("Indices couplés de a, Sa_dx + Snu_a + Snu_a_dx = ", (S_tot_a-S_a)*100, "%")
print("Indices couplés de nu, Snu_a + Snu_dx + Snu_dx_a = ", (S_tot_nu-S_nu)*100, "%")
print("Indices couplés de dx, Sdx_a + S_dx_nu + S_dx_nu_a = ", (S_tot_dx-S_dx)*100, "%")

