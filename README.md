# Pipe Network Calculation Tool

This C++ console application calculates the fluxes and hydraulic heads in a water supply network. It was developed as a mandatory assignment for the course **Computation in Engineering I** at the Technical University of Munich (TUM) at the end of 2023.

## Overview
The program reads input data for nodes and tubes from a text file to compute the resulting hydraulic state of a pipe network.

### Key Components
* **Node Class**: Stores coordinates, IDs, and flow values (Q) for each junction in the network.
* **Tube Class**: Handles pipe properties such as diameter and calculates permeability (B) based on length and diameter.
* **PipeNetwork Class**: Reads the input file, assembles the global permeability matrix, and computes fluxes.
* **Linear Algebra Library**: The linalg library (containing matrix and vector operations & system solver) was provided as part of the assignment material.

> [!IMPORTANT]
> **Note on linalg**: The linear algebra library files (linalg.cpp, linalg.hpp, and linalg_impl.hpp) are not included in this repository as they are the property of the Chair for Computing in civil Engineering at TUM.

## How to Run
1. Ensure a valid input file (like pipedata.txt) is available in the directory.
2. The program assembles the system Bh = Q, imposes boundary conditions, and solves for the system.
3. The output can be viewed on the screen or written to a results file.
