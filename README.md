# LBYARCH Machine Project 2

By Ruth Yee and Patricia Zamora (S14)

<h3>Overview</h3>
<hr>
This project implements a kernel that calculates the Euclidean distances between coordinate points across two vectors. The kernel is implemented in two versions: a C version and an x86-64 assembly language version using SIMD floating-point instructions. The goal is to compare the performance and correctness of both implementations across different input sizes and evaluate the execution time for various vector lengths.

<h3>Project Structure</h3>
<hr>

C Program (distance.c): 
- Contains the C implementation for calculating the Euclidean distance between two sets of points.
- Handles dynamic memory allocation for vectors, calculates distances, and measures the execution time.
- Provides the user interface for displaying the results and checking correctness by comparing C and assembly outputs.
- Runs multiple times (30 iterations) to average execution times for benchmarking.

x86-64 Program (distance_asm.asm):
- Contains the x86-64 assembly language implementation of the distance calculation kernel.
- Utilizes scalar SIMD floating-point instructions to compute the distance.
- Optimized for performance and compared against the C implementation.

<h3>Comparative Execution Time</h3>
<hr>

<h3>Analysis <h3>
<hr>
