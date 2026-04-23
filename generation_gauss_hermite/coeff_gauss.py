import numpy as np

def gauss_hermite_to_file(n, filename):
    """
    Génère les points et poids de la quadrature de Gauss-Hermite
    et les écrit dans un fichier avec deux colonnes.

    Parameters:
        n (int): Nombre de points pour la quadrature.
        filename (str): Nom du fichier à créer.
    """
    # Calcul des points et poids
    points, weights = np.polynomial.hermite.hermgauss(n)
    
    # Création et écriture dans le fichier
    with open(filename, 'w') as f:
        f.write("Points\tPoids\n")  # En-tête des colonnes
        for p, w in zip(points, weights):
            f.write(f"{p:.6f}\t{w:.10f}\n")  # Écriture avec formatage

    print(f"Les points et poids ont été écrits dans le fichier {filename}")

# Exemple d'utilisation
n_points = 10  # Nombre de points
output_file = "gauss_hermite.txt"  # Nom du fichier
gauss_hermite_to_file(n_points, output_file)
