#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

extern void distance_asm(int n, float* X1, float* X2, float* Y1, float* Y2, float* Z);

void distance_c(float* X1, float* X2, float* Y1, float* Y2, float* Z_c, int n) {
    for (int i = 0; i < n; i++) {
        Z_c[i] = sqrt((X2[i] - X1[i]) * (X2[i] - X1[i]) +
            (Y2[i] - Y1[i]) * (Y2[i] - Y1[i]));
    }
}

void display_points(float* X1, float* X2, float* Y1, float* Y2, int n) {
    int max_points = (n < 10) ? n : 10;
    for (int i = 0; i < max_points; i++) {
        printf("Point %d:\n", i + 1);
        printf("  X1[%d]: %.1f\n", i, X1[i]);
        printf("  X2[%d]: %.1f\n", i, X2[i]);
        printf("  Y1[%d]: %.1f\n", i, Y1[i]);
        printf("  Y2[%d]: %.1f\n", i, Y2[i]);
    }
}

void display_first_ten_elements(float* Z, int n, const char* label) {
    printf("%s (first 10 elements):\n", label);
    for (int i = 0; i < 10 && i < n; i++) {
        printf("  Z[%d] = %.8f\n", i, Z[i]);
    }
}

int main() {
    int n = 1048576;

    float* X1 = (float*)malloc(n * sizeof(float));
    float* X2 = (float*)malloc(n * sizeof(float));
    float* Y1 = (float*)malloc(n * sizeof(float));
    float* Y2 = (float*)malloc(n * sizeof(float));
    float* Z_c = (float*)malloc(n * sizeof(float));  // C result
    float* Z = (float*)malloc(n * sizeof(float));    // ASM result

    if (!X1 || !X2 || !Y1 || !Y2 || !Z_c || !Z) {
        printf("Memory allocation failed. Exiting.\n");
        free(X1);
        free(X2);
        free(Y1);
        free(Y2);
        free(Z_c);
        free(Z);
        return 1;
    }

    X1[0] = 1.5f; X2[0] = 3.0f; Y1[0] = 4.0f; Y2[0] = 2.0f;
    X1[1] = 4.0f; X2[1] = 2.5f; Y1[1] = 3.0f; Y2[1] = 2.5f;
    X1[2] = 3.5f; X2[2] = 2.5f; Y1[2] = 3.5f; Y2[2] = 1.0f;
    X1[3] = 2.0f; X2[3] = 1.0f; Y1[3] = 3.0f; Y2[3] = 1.5f;

    srand(42);
    for (int i = 4; i < n; i++) {
        X1[i] = (float)(rand() % 100) / 10.0f;
        Y1[i] = (float)(rand() % 100) / 10.0f;
        X2[i] = (float)(rand() % 100) / 10.0f;
        Y2[i] = (float)(rand() % 100) / 10.0f;
    }

    printf("Initial points:\n");
    display_points(X1, X2, Y1, Y2, n);

    // Time of C kernel for 30 iterations
    double total_time_c = 0.0;
    for (int i = 0; i < 30; i++) {
        clock_t start_c = clock();
        distance_c(X1, X2, Y1, Y2, Z_c, n);
        clock_t end_c = clock();
        total_time_c += (double)(end_c - start_c) / CLOCKS_PER_SEC;
    }
    double avg_time_c = total_time_c / 30.0;

    // Time of ASM kernel for 30 iterations
    double total_time_asm = 0.0;
    for (int i = 0; i < 30; i++) {
        clock_t start_asm = clock();
        distance_asm(n, X1, X2, Y1, Y2, Z);
        clock_t end_asm = clock();
        total_time_asm += (double)(end_asm - start_asm) / CLOCKS_PER_SEC;
    }
    double avg_time_asm = total_time_asm / 30.0;

    printf("\nResults for n = %d:\n", n);
    printf("  C kernel average time: %.6f seconds\n", avg_time_c);
    printf("  ASM kernel average time: %.6f seconds\n", avg_time_asm);

    display_first_ten_elements(Z_c, n, "C kernel result");
    display_first_ten_elements(Z, n, "ASM kernel result");

    for (int i = 0; i < n; i++) {
        if (fabs(Z_c[i] - Z[i]) > 1e-6) {
            printf("Mismatch at index %d: C = %.6f, ASM = %.6f\n", i, Z_c[i], Z[i]);
            break;
        }
    }

    free(X1);
    free(X2);
    free(Y1);
    free(Y2);
    free(Z_c);
    free(Z);

    return 0;
}
