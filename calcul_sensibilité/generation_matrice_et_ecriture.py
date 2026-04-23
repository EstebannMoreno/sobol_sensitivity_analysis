from math import *
from random import *
import matplotlib.pyplot as plt
import numpy as np

N=10000

#MATRICE A
#simulations de a : loi uniforme sur [1,2], tableau de N valeurs
a_A = np.random.uniform(0, 1, N)
# print(a_A)

#simulations de nu : loi uniforme sur [0,10], tableau de N valeurs
nu_A = np.random.uniform(0, 1, N)
# print(nu_A)

#simulations de dx : loi uniforme sur {1/Nx...,1/8Nx}, tableau de N valeurs
dx_A = np.random.uniform(0, 1, N)
#print(dx_A)

A = np.array([a_A, nu_A, dx_A]).T
# print(A)

#MATRICE B
#simulations de a : loi uniforme sur [1,2], tableau de N valeurs
a_B = np.random.uniform(0, 1, N)

#simulations de nu : loi uniforme sur [0,10], tableau de N valeurs
nu_B = np.random.uniform(0, 1, N)

#simulations de dx : loi uniforme sur {1/Nx...,1/8Nx}, tableau de N valeurs
#dx_B = np.random.choice(valeurs, size=N)
dx_B=np.random.uniform(0, 1, N)

B = np.array([a_B, nu_B, dx_B]).T
# print(B)

#MATRICE Ca
C_a = np.array([a_B, nu_A, dx_A]).T
# print(C_a)

#MATRICE C_nu
C_nu = np.array([a_A, nu_B, dx_A]).T
# print(C_nu)

#MATRICE C_dx
C_dx = np.array([a_A, nu_A, dx_B]).T
# print(C_dx)

output_file = "coeffs_matrices.txt"  # Nom du fichier

    
# Création et écriture dans le fichier
with open(output_file, 'w') as f:
    for p, w, z in zip(a_A, nu_A, dx_A):
        f.write(f"{p:.10f}\t{w:.10f}\t{z:.10f}\n")  # Écriture A
    for p, w, z in zip(a_B, nu_B, dx_B):
        f.write(f"{p:.10f}\t{w:.10f}\t{z:.10f}\n")  # Écriture B
    for p, w, z in zip(a_B, nu_A, dx_A):
        f.write(f"{p:.10f}\t{w:.10f}\t{z:.10f}\n")  # Écriture C_a
    for p, w, z in zip(a_A, nu_B, dx_A):
        f.write(f"{p:.10f}\t{w:.10f}\t{z:.10f}\n")  # Écriture C_nu
    for p, w, z in zip(a_A, nu_A, dx_B):
        f.write(f"{p:.10f}\t{w:.10f}\t{z:.10f}\n")  # Écriture C_dx

