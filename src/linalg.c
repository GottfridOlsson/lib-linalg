/*====================================================*/
//     Project: LIBRARIES IN C
//        File: linalg.c
//      Author: VIKTOR LILJA, GOTTFRID OLSSON
//     Created: 2022-11-15
//     Updated: 2022-11-28
//       About: Contains functions used in linear
//		algebra. Vectors, matrices and such.
/*====================================================*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_rng.h>
#include "linalg.h"


double* create_vector(size_t len){
	double* vector = malloc(sizeof(double) * len);
	return vector;
}

double* create_linspace(double start, double end, size_t num_points){
	double* linspace = create_vector(num_points);
	for(int i = 0; i < num_points; i++){
		linspace[i] = i * (end-start)/(num_points-1) + start;
	}
	return linspace;	
}

double* create_random_uniform_vector(size_t len, unsigned long int seed){
	double* vector = create_vector(len);	
	gsl_rng * r;
	r = gsl_rng_alloc(gsl_rng_default);
	gsl_rng_set(r, seed);
	for(int i = 0; i < len; i++){
		vector[i] = gsl_rng_uniform(r);
	}
	gsl_rng_free(r);
	return vector;
}


void evaluate_function_on_vector(double* output, double (*function)(double),
								 double* x, int len){
	for(int i = 0; i < len; i++){
		output[i] = (*function)(x[i]); //dereference function
		//since (*function) is the address of the function		
	}
}

void destroy_vector(double *vector){
	free(vector);
}

void copy_vector(double *v_dest, double *v_source, size_t len) {
	for (int i = 0; i < len; i++) {
		v_dest[i] = v_source[i];
	}
}

void scale_vector_by_factor(double *v, double scale_factor, size_t len){
	for(int i = 0; i < len; i++){
		v[i] = v[i] * scale_factor;
	}
}

void elementwise_addition(double *res, double *v1, double *v2, size_t len){
	for(int i = 0; i < len; i++){
		res[i] = v1[i] + v2[i]; 
	}
}

void elementwise_multiplication(double *res, double *v1,
								double *v2, size_t len){
	for(int i = 0; i < len; i++){
		res[i] = v1[i] * v2[i]; 
	}
}
 
double dot_product(double *v1, double *v2, size_t len){
	double sum = 0;
	for (int i = 0; i < len; i++) {
		sum += v1[i] * v2[i]; 
	}
    return sum;
}

double vector_norm(double *v1, size_t len){
	double sum = 0;
	for(int i = 0; i < len; i++){
		sum += v1[i] * v1[i];
	}
    return sqrt(sum);
}


void normalize_vector(double *v1, size_t len){
	double norm = vector_norm(v1, len);
	scale_vector_by_factor(v1, 1/norm, len);
}


double distance_between_vectors(double *v1, double *v2, size_t len) {
	double sum_squared = 0, res = 0;
	for(int i = 0; i < len; i++){
		sum_squared += pow(v1[i] - v2[i], 2);
	}
	res = sqrt(sum_squared);
	return res;
}


double vector_average(double *v1, size_t len){
	double sum = 0;
	for(int i = 0; i < len; i++){
		sum += v1[i];
	}

   	return sum/len;
}

double vector_standard_deviation(double *v1, size_t len){
	double sum = 0;
	double mu = vector_average(v1, len);
	for(int i = 0; i < len; i++){
		sum += (v1[i] - mu) * (v1[i] - mu);
	}
    return sqrt(sum/len);
}


double vector_variance(double *v1, size_t len){
	double sum = 0;
	double mu = vector_average(v1, len);
	for(int i = 0; i < len; i++){
		sum += (v1[i] - mu) * (v1[i] - mu);
	}
    return sum/len;
}


double vector_max(double* vector, size_t len){
	double max = vector[0];
	for(int i = 1; i < len; i++){
		if(vector[i] > max){
			max = vector[i];
		}
	}
	return max;
}

double** create_matrix(size_t rows, size_t cols){
	double** mat = malloc(sizeof(double*) * rows); // array of poiners to rows
	for(int i = 0; i < rows; i++){
		mat[i] = calloc(cols, sizeof(double) * cols); // rows with doubles
	}
	return mat;
}

double** create_transpose_of_matrix(double** matrix,
		size_t initial_rows, size_t initial_cols){
	double** transpose = create_matrix(initial_cols, initial_rows);
	for(int i = 0; i < initial_rows; i++){
		for(int j = 0; j < initial_cols; j++){
			transpose[j][i] = matrix[i][j];
		}
	}
	return transpose;
}

double** create_random_uniform_matrix(size_t rows, size_t cols, 
		unsigned long int seed){
	double** matrix = create_matrix(rows, cols);	
	gsl_rng * r;
	r = gsl_rng_alloc(gsl_rng_default);
	gsl_rng_set(r, seed);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			matrix[i][j] = gsl_rng_uniform(r);
		}
	}
	gsl_rng_free(r);
	return matrix;
}

double** create_matrix_with_inserted_column(double** matrix, double* vector, 
		size_t rows, size_t cols, size_t col_insert_index){
	double** result = create_matrix(rows, cols+1);
	// Before insert
	for(int j = 0; j < col_insert_index; j++){
		for(int i = 0; i < rows; i++){
			result[i][j] = matrix[i][j];
		}
	}
	// Insert, j == col_insert_index
	for(int i = 0; i < rows; i++){
		result[i][col_insert_index] = vector[i];
	}	
	// After insert
	for(int j = col_insert_index; j < cols; j++){
		for(int i = 0; i < rows; i++){
			result[i][j+1] = matrix[i][j];
		}
	}
	return result;
}

void destroy_matrix(double **matrix, size_t rows){
	for(int i = 0; i < rows; i++){
		free(matrix[i]); // Free rows
	}
	free(matrix); // Free array of pointers to rows
}

void scale_matrix_by_factor(double** mat, double factor, 
		size_t rows, size_t cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			mat[i][j] *= factor;
		}
	}
}

void add_scalar_to_matrix(double** mat, double scalar, 
		size_t rows, size_t cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			mat[i][j] += scalar;
		}
	}
}

void elementwise_matrix_addition(double **result, double **mat1,
		double **mat2, size_t rows, size_t cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			result[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}

void elementwise_matrix_multiplication(double **result, double **mat1,
		double **mat2, size_t rows, size_t cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			result[i][j] = mat1[i][j] * mat2[i][j];
		}
	}
}

void add_scaled_matrix_to_matrix(double **result, double **mat,
		double **mat_to_scale, double factor, size_t m, size_t n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			result[i][j] = mat[i][j] + factor*mat_to_scale[i][j];
		}
	}
}

void matrix_multiplication(double **result, double **mat1, double **mat2,
		      size_t m, size_t n, size_t p){

	for(int i = 0; i < m; i++){
		for(int j = 0; j < p; j++){

			result[i][j] = 0;

			for(int k = 0; k < n; k++){
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

void print_vector(double* a, size_t len){
	printf("[");
	for(int ix = 0; ix < len; ix++){
		if(ix != len - 1){
        		printf("%f, ", a[ix]);
		} else {
        		printf("%f", a[ix]);
		}
	}
	printf("]\n");
}


void print_matrix(double** a, size_t rows, size_t cols){
	printf("[\n");
	for(int row_i = 0; row_i < rows; row_i++){
		print_vector(a[row_i], cols);
	}
	printf("]\n");
}

void print_matrix_to_file(char* filepath, char* header, double** matrix,
					  	  size_t rows, size_t cols){
	FILE* file = fopen(filepath, "w");
	fprintf(file, "%s\n", header);
	
	for(int row_i = 0; row_i < rows; row_i++){
		for(int col_j = 0; col_j < cols; col_j++){
			if(col_j != cols - 1){
				fprintf(file, "%.8e, ", matrix[row_i][col_j]);
			}else{
				fprintf(file, "%.8e\n", matrix[row_i][col_j]);
			}
		}
	}
	
	fclose(file);
	printf("Sucessfully printed matrix to file: %s\n", filepath);
}


void print_vector_to_file(char* filepath, char* header, double* vector,
		size_t size){
	FILE* file = fopen(filepath, "w");
	fprintf(file, "%s\n", header);
	for(int index = 0; index < size; index++){
		fprintf(file, "%.8e\n", vector[index]);
	}

	fclose(file);
	printf("Sucessfully printed vector to file: %s\n", filepath);
}

// Helper for print_vectors_as_columns_to_file
int get_max_value_of_int_vector(int* vector, int len){
	int max = vector[0];
	for(int i = 1; i < len; i++){
		if(vector[i] > max){
			max = vector[i];
		}
	}
	return max;
}


void print_vectors_as_columns_to_file(char* filepath, char* header,
		double** vector_of_vectors, int n_vectors, int* len_vectors){
	FILE* file = fopen(filepath, "w");
	fprintf(file, "%s\n", header);
	
	int  n_cols   = n_vectors;
	int* len_cols = len_vectors;
	int max_rows = get_max_value_of_int_vector(len_cols, n_cols);
	
	for(int row_i = 0; row_i < max_rows; row_i++){ //rows
		for(int col_i = 0; col_i < n_cols; col_i++){  //cols
			if(col_i != n_cols - 1){
				if(row_i < len_cols[col_i]){ //within vector_i's length; print
					fprintf(file, "%.8e, ", vector_of_vectors[col_i][row_i]);
				} else {// = past vector_i's length and not last column
					fprintf(file, ", ");
				}
			} else { // = element of last column, break line
				if(row_i < len_cols[col_i]){ //within vector_i's length
					fprintf(file, "%.8e\n", vector_of_vectors[col_i][row_i]);
				} else {// = past vector_i's length and last column, break line
					fprintf(file, "\n");
				}
			}
		}
	}

	fclose(file);
	printf("Sucessfully printed vector of vectors to file: %s\n", filepath);
}


