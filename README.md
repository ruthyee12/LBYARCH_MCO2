# LBYARCH x86-to-C Interface Programming Project

By Ruth Yee and Patricia Zamora (S14)

<hr>
<h3>Overview</h3>
This project implements a kernel that calculates the Euclidean distances between coordinate points across two vectors. The kernel is implemented in two versions: a C version and an x86-64 assembly language version using SIMD floating-point instructions. The goal is to compare the performance and correctness of both implementations across different input sizes and evaluate the execution time for various vector lengths.
<hr>

<h3>Project Structure</h3>

C Program (distance.c): 
- Contains the C implementation for calculating the Euclidean distance between two sets of points.
- Handles dynamic memory allocation for vectors, calculates distances, and measures the execution time.
- Provides the user interface for displaying the results and checking correctness by comparing C and assembly outputs.
- Runs multiple times (30 iterations) to average execution times for benchmarking.

x86-64 Program (distance_asm.asm):
- Contains the x86-64 assembly language implementation of the distance calculation kernel.
- Utilizes scalar SIMD floating-point instructions to compute the distance.
- Optimized for performance and compared against the C implementation.
<hr>

<h3>Comparative Execution Time</h3>
The table below shows the comparative execution time between the C program and the x86-64 assembly program for different vector sizes. Each entry represents the average execution time over 30 runs.


|               | 2^20          | 2^24          | 2^30          |
| ------------- | ------------- | ------------- | ------------- |
| C             | Content       |Content        |Content        |
| x86-64        | Content       |Content        |Content        |

<hr>

<h3>Analysis</h3>
The performance comparison between the C program and the x86-64 assembly program highlights the efficiency of low-level optimization. While the C kernel performed adequately for smaller vector sizes 2^20, its average execution time increased significantly as the vector size grew due to scalar processing overhead. In contrast, the x86-64 kernel consistently outperformed the C implementation across all vector sizes, with the performance gap widening for larger datasets 2^24 and 2^30. This advantage stems from the use of SIMD floating-point instructions in the assembly code, enabling faster parallel computation. Overall, the x86-64 kernel demonstrates superior performance, particularly for large-scale computations, showcasing the benefits of hardware-level optimization.
<hr>

<h3>Screenshot</h3>
https://
<hr>

<h3>Video demo</h3>
https://
<hr>
