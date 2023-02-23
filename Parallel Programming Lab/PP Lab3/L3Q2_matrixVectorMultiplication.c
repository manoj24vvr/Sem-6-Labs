#include <iostream>
#include <omp.h>
#include <ctime>
#include <cstdlib>
int main() {
    const int num_sizes = 5;
    const int sizes[num_sizes] = {2000, 4000, 6000, 8000, 10000};
    const int num_threads = 8;
    double time_start, time_end;
    double times[num_sizes];
    // loop over matrix sizes
    for (int k = 0; k < num_sizes; k++) {
        int N = sizes[k];
        // allocate matrices and vector
        double **A = new double*[N];
        double *x = new double[N];
        double *y = new double[N];
        for (int i = 0; i < N; i++) {
            A[i] = new double[N];
        }
        // initialize matrix and vector
        for (int i = 0; i < N; i++) {
            x[i] = 1.0;
            for (int j = 0; j < N; j++) {
                A[i][j] = (double)rand() / RAND_MAX;
            }
        }
        // matrix-vector multiplication with one thread
        time_start = omp_get_wtime();
        for (int i = 0; i < N; i++) {
            y[i] = 0.0;
            for (int j = 0; j < N; j++) {
                y[i] += A[i][j] * x[j];
            }
        }
        time_end = omp_get_wtime();
        double time_serial = time_end - time_start;
        // matrix-vector multiplication with multiple threads
        omp_set_num_threads(num_threads);
        time_start = omp_get_wtime();
        #pragma omp parallel for
        for (int i = 0; i < N; i++) {
            y[i] = 0.0;
            for (int j = 0; j < N; j++) {
                y[i] += A[i][j] * x[j];
            }
        }
        time_end = omp_get_wtime();
        double time_parallel = time_end - time_start;
        times[k] = time_parallel;
        // free memory
        for (int i = 0; i < N; i++) {
            delete[] A[i];
        }
        delete[] A;
        delete[] x;
        delete[] y;
        // print execution time for current matrix size
        std::cout << "Matrix size: " << N << ", execution time (serial): " << time_serial << " seconds, execution time (parallel): " << time_parallel << " seconds" << std::endl;
    }
    return 0;
}
