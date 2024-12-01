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

![image](https://github.com/user-attachments/assets/10c87bef-7d43-493f-b7cb-a627219334b8)
![image](https://github.com/user-attachments/assets/ed25ea64-6f1d-40ec-9744-7e88fa878e8b)

**AVERAGE EXECUTION TIME**
|               | 2^20          | 2^24          | 2^27          |
| ------------- | ------------- | ------------- | ------------- |
| C             | 0.014813      |0.165494       |1.345304       |
| x86-64        | 0.002461      |0.037354       |0.264277       |

<hr>

<h3>Analysis</h3>
The implementation of the same algorithm in two different programming environments, C and x86-64 assembly, illustrates the performance and optimization trade-offs between high-level and low-level languages. The correctness of the results and execution times were used to assess the outputs of both implementations.


**Performance Comparison:**

Over several runs, the C implementation showed average execution times ranging from 0.010 to 0.012 seconds for vector size 2^20. This pattern of behaviour is also noticeable as the vector size increases. The effective compilation and optimization strategies used by modern C compilers are responsible for this comparatively fast performance. However, with execution times ranging from 0.0022 to 0.0028 seconds, the x86-64 assembly implementation showed noticeably faster performance. The assembly code demonstrated the advantages of low-level programming for tasks requiring high performance, outperforming C by almost five times.
The superior performance of the assembly code can be attributed to its direct access to CPU instructions and registers. Assembly attains a higher level of efficiency by reducing overhead, such as memory access and function call abstractions that are inherent in higher-level languages. Because of this, it is especially well-suited for computationally demanding tasks like calculating distances or doing other repeating mathematical calculations.

**Accuracy of Results:**

During several test runs, the first ten elements of the output array Z yielded the same results for both implementations. This precision consistency shows that the logic of the method was accurately converted into assembly instructions. Examples of these outputs are Z[0] = 2.50000000, Z[1] = 1.58113885, and Z[2] = 2.69258237, proving that the calculations were performed correctly in both settings.


**Results:**

Assembly code performs exceptionally well, but at the expense of greater complexity and less readability. Writing and debugging assembly code can take a lot of effort and requires a thorough understanding of hardware architecture. However, C is a popular option for general-purpose programming because it strikes a balance between performance and usability. Depending on the needs of the assignment, the trade-offs between the two languages should be carefully evaluated.

**Conclusion:**

For certain use situations, especially those requiring maximum efficiency, the performance advantage of low-level programming is evident when comparing C with x86-64 assembly. However, high-level languages like C are more useful for the majority of applications due to their readability and maintainability. As our analysis shows, assembly is still a useful tool for activities that need crucial optimization, such high-speed computations.
<hr>

<h3>Screenshot</h3>
https://github.com/user-attachments/assets/ec4e39e8-282d-482b-a160-103935cb266d
<hr>

<h3>Video demo</h3>
https://drive.google.com/file/d/1DxMOSOsvt4y3StLOr4UdfWVwo4ET5u9j/view?usp=sharing
<hr>
