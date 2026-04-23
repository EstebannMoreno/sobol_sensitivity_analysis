# Sobol Sensitivity Analysis Framework

## Overview

This project implements a variance-based global sensitivity analysis framework using Sobol indices, applied to a numerical model derived from an advection-diffusion equation.

The objective is to quantify how uncertainties in model parameters impact the variability of the system output, and to identify the most influential factors driving the dynamics.

Variance-based methods such as Sobol indices decompose the output variance into contributions attributable to each input and their interactions.

---

## Context & Motivation

In numerical simulation and scientific computing, the choice of discretization (e.g. mesh size) can significantly influence results.

This project addresses the following question:

How sensitive is a numerical solution to variations in physical parameters and discretization choices?

The framework is applied to:
- an advection-diffusion equation
- with uncertain parameters (velocity, diffusion coefficient, mesh size)

The goal is to:
- evaluate parameter influence
- detect interaction effects
- guide optimal mesh selection

---

## Methodology

1. Model

We consider a numerical solution of a 1D advection-diffusion equation:

∂t u + a ∂x u = ν ∂²x u

Discretization:
- Explicit Euler (time)
- Upwind scheme (advection)
- Centered scheme (diffusion)

---

2. Sensitivity Analysis

We use Sobol indices, a global sensitivity method based on variance decomposition:

- First-order index: contribution of a parameter alone  
- Total index: contribution including interactions  

These indices allow us to measure:
- individual parameter impact  
- coupled effects between variables  
- global influence across the entire input space  

---

3. Monte Carlo Framework

The implementation follows a classical sampling strategy:

- Construction of matrices A, B, and Ci  
- Evaluation of the model on each sample  
- Estimation of variance contributions  

This requires large-scale simulations (up to 10^6 samples) to ensure convergence.

---

## Results

The analysis highlights several key findings:

- Physical parameters (a, ν) strongly influence the system  
- The mesh size Δx contributes significantly to output variability  
- Interaction effects are non-negligible  
- Sensitivity to discretization decreases with mesh refinement  

## Report

A detailed report including:
- mathematical derivations  
- numerical validation  
- sensitivity analysis  
- Sobol indices computation  

is available here:
[Project Report (PDF)](docs/result_report.pdf)

---

## Applications

- uncertainty quantification  
- numerical scheme validation  
- PDE-based simulations  
- Monte Carlo modelling  
- quantitative finance (risk & sensitivity analysis)  

---

## Limitations

- High computational cost (Monte Carlo sampling)
- Limited to scalar output analysis
- No GPU acceleration

---

## Future Work

- GPU acceleration  
- Extension to higher-dimensional PDEs  
- Integration with statistical learning models  
- Calibration to real-world datasets  

---

## Author

Esteban Moreno  

---

## Positioning

This project focuses on global sensitivity analysis for numerical models, bridging:

- scientific computing  
- uncertainty quantification  
- stochastic modelling  

It is designed as a research-oriented numerical framework, not a production system.
