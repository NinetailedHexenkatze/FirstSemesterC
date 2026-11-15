// #include "6th_Functions.h"
//
// double calculate_y(double x, int m) {
//     if (m * x == 0.0) {
//         return 0.0;
//     }
//
//     double term1 = fabs(x) / 2.0;
//     double term2 = m * x * x;
//     double sin_val = sin(m * x);
//
//     return (sqrt(term1 + term2) * sin_val * sin_val) / (m * x);
// }
//
// int write_initial_table(const char *filename, int N, int M, double x0, double xk) {
//     FILE *f = fopen(filename, "w");
//     if (!f) return 0;
//     double dx = (N > 1) ? (xk - x0) / (N - 1) : 0.0;
//
//     for (int n = 1; n <= N; n++) {
//         double x_n = x0 + (n - 1) * dx;
//         for (int m = 1; m <= M; m++) {
//             double y = calculate_y(x_n, m);
//             fprintf(f, "%9.5f", y);
//         }
//         fprintf(f, "\n");
//     }
//     fflush(f);
//     fclose(f);
//     return 1;
// }
//
// int filter_table(const char *input_filename, const char *output_filename, int N, int M) {
//     FILE *fin = fopen(input_filename, "r");
//     if (!fin) return 0;
//
//     FILE *fout = fopen(output_filename, "w");
//     if (!fout) {
//         fclose(fin);
//         return 0;
//     }
//
//     double *row = (double *)malloc(M * sizeof(double));
//     if (!row) {
//         fclose(fin);
//         fclose(fout);
//         return 0;
//     }
//
//     for (int n = 0; n < N; n++) {
//         double sum = 0.0;
//         int read_success = 1;
//
//         for (int m = 0; m < M; m++) {
//             if (fscanf(fin, "%lf", &row[m]) != 1) {
//                 read_success = 0;
//                 break;
//             }
//             sum += row[m];
//         }
//
//         if (!read_success) break;
//
//         double mean = sum / M;
//
//         for (int m = 0; m < M; m++) {
//             if (row[m] > mean) {
//                 fprintf(fout, "%12.5f", row[m]);
//             }
//         }
//         fprintf(fout, "\n");
//     }
//
//     free(row);
//     fflush(fin);
//     fflush(fout);
//     fclose(fin);
//     fclose(fout);
//     return 1;
// }
