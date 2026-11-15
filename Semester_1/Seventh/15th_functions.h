#ifndef UNTITLED_15TH_FUNCTIONS_H
#define UNTITLED_15TH_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double calculate_y(int m, double x);
double get_x(int n, int N, double x0, double x_N);
int write_table_to_file(const char *filename, int N, int M, double x0, double x_N);
int process_and_copy_file(const char *src_filename, const char *dest_filename, int N, int M, double max_fractional);

#endif //UNTITLED_15TH_FUNCTIONS_H
