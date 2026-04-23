from math import *
from random import *
import matplotlib.pyplot as plt
import numpy as np




# Chargement des données 

u_all = np.loadtxt("u_num.txt")  
N=len(u_all)//5


# Découpage en blocs
uA = u_all[0:N]
uB = u_all[N:2*N]
uCa = u_all[2*N:3*N]
uCnu = u_all[3*N:4*N]
uCdx = u_all[4*N:5*N]
print(uB)


V_a = 0
V_nu = 0
V_dx = 0

V_tot_a = 0
V_tot_nu = 0
V_tot_dx = 0

# Boucle sur tous les échantillons
for i in range(N):
    u_iA = uA[i]
    u_iB = uB[i]
    u_iCa = uCa[i]
    u_iCnu = uCnu[i]
    u_iCdx = uCdx[i]

    V_a     += -(1/N)*u_iB*(u_iA - u_iCa)
    V_nu    += -(1/N)*u_iB*(u_iA - u_iCnu)
    V_dx    += -(1/N)*u_iB*(u_iA - u_iCdx)

    V_tot_a   += (1/N)*u_iA*(u_iA - u_iCa)
    V_tot_nu  += (1/N)*u_iA*(u_iA - u_iCnu)
    V_tot_dx  += (1/N)*u_iA*(u_iA - u_iCdx)
# ------------------------

Vtot = (1/5)*(np.var(uA)+np.var(uB)+np.var(uCa)+np.var(uCdx)+np.var(uCnu))

# Indices de Sobol
S_a = abs(V_a)/Vtot
S_nu = abs(V_nu)/Vtot
S_dx = abs(V_dx)/Vtot

S_tot_a = abs(V_tot_a)/Vtot
S_tot_nu = abs(V_tot_nu)/Vtot
S_tot_dx = abs(V_tot_dx)/Vtot

# Affichage des résultats
print("Indice de a = ", S_a*100, "%")
print("Indice de nu = ", S_nu*100, "%")
print("Indice de dx = ", S_dx*100, "%")
print("Indice total de a = ", S_tot_a*100, "%")
print("Indice total de nu = ", S_tot_nu*100, "%")
print("Indice total de dx = ", S_tot_dx*100, "%")
print("Indices couplés de a (Sa_dx + Snu_a + Snu_a_dx) = ", (S_tot_a - S_a)*100, "%")
print("Indices couplés de nu (Snu_a + Snu_dx + Snu_dx_a) = ", (S_tot_nu - S_nu)*100, "%")
print("Indices couplés de dx (Sdx_a + S_dx_nu + S_dx_nu_a) = ", (S_tot_dx - S_dx)*100, "%")

# Sauvegarde dans sobol_indices.txt
with open("sobol_indices.txt", "w") as f:
    f.write(f"Indice de a = {S_a*100:.4f} %\n")
    f.write(f"Indice de nu = {S_nu*100:.4f} %\n")
    f.write(f"Indice de dx = {S_dx*100:.4f} %\n")
    f.write(f"Indice total de a = {S_tot_a*100:.4f} %\n")
    f.write(f"Indice total de nu = {S_tot_nu*100:.4f} %\n")
    f.write(f"Indice total de dx = {S_tot_dx*100:.4f} %\n")
    f.write(f"Indices couplés de a (Sa_dx + Snu_a + Snu_a_dx) = {(S_tot_a - S_a)*100:.4f} %\n")
    f.write(f"Indices couplés de nu (Snu_a + Snu_dx + Snu_dx_a) = {(S_tot_nu - S_nu)*100:.4f} %\n")
    f.write(f"Indices couplés de dx (Sdx_a + S_dx_nu + S_dx_nu_a) = {(S_tot_dx - S_dx)*100:.4f} %\n")
