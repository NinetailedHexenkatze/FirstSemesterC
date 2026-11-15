#include "15th_functions.h"

//y_m(x_n) = sin^2(m * |x_n|) * cos(m * x_n)
double calculate_y(int m, double x) {
    double sin_val = sin((double)m * fabs(x));
    double cos_val = cos((double)m * x);
    return sin_val * sin_val * cos_val;
}

double get_x(int n, int N, double x0, double x_N) {
    if (N <= 1) return x0;
    return x0 + (double)(n - 1) * (x_N - x0) / (double)(N - 1);
}

int write_table_to_file(const char *filename, int N, int M, double x0, double x_N) {
    FILE *f = fopen(filename, "w");
    if (!f) return 0;

    for (int n = 1; n <= N; n++) {
        double x_n = get_x(n, N, x0, x_N);
        for (int m = 1; m <= M; m++) {
            double y = calculate_y(m, x_n);
            fprintf(f, "%10.5f", y);
        }
        fprintf(f, "\n");
    }

    fclose(f);
    return 1;
}
int process_and_copy_file(const char *src_filename, const char *dest_filename, int N, int M, double max_fractional) {
    FILE *f_in = fopen(src_filename, "r");
    if (!f_in) return 0;

    FILE *f_out = fopen(dest_filename, "w");
    if (!f_out) {
        fclose(f_in);
        return 0;
    }

    double *row_buffer = (double *)malloc(M * sizeof(double));
    if (!row_buffer) {
        fclose(f_in);
        fclose(f_out);
        return 0;
    }

    for (int n = 1; n <= N; n++) {
        int valid_count = 0;

        for (int m = 0; m < M; m++) {
            double val;
            if (fscanf(f_in, "%lf", &val) != 1) break;

            double dummy;
            double fractional_part = fabs(modf(val, &dummy));

            if (fractional_part <= max_fractional) {
                row_buffer[valid_count] = val;
                valid_count++;
            }
        }

        if (n % 2 == 0) {
            for (int i = valid_count - 1; i >= 0; i--) {
                fprintf(f_out, "%9.3f", row_buffer[i]);
            }
        }
        else
        {
            for (int i = 0; i < valid_count; i++) {
                fprintf(f_out, "%9.3f", row_buffer[i]);
            }
        }
        fprintf(f_out, "\n");
    }

    free(row_buffer);
    fclose(f_in);
    fclose(f_out);
    return 1;
}
