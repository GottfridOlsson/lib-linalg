/*====================================================*/
//     Project: LIBRARIES IN C
//        File: linalg.c
//      Author: VIKTOR LILJA, GOTTFRID OLSSON
//     Created: 2022-11-15
//     Updated: 2022-11-17
//       About: Contains functions used in linear
//				algebra. Vectors, matrices and such.
/*====================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "linalg.h"


void elementwise_addition(double *res,double *v1,double *v2,unsigned int len){
	for(int i = 0; i < len; i++){
		res[i] = v1[i] + v2[i]; 
	}
}


void elementwise_multiplication(double *res,double *v1,
								double *v2,unsigned int len){
	for(int i = 0; i < len; i++){
		res[i] = v1[i] * v2[i]; 
	}
}
 

double dot_product(double *v1,double *v2,unsigned int len){
	double sum = 0;
	for(int i = 0; i < len; i++){
		sum += v1[i] * v2[i]; 
	}
    	return sum;
}



double* create_vector(unsigned int len){
	double* vector = malloc(sizeof(double) * len);
	
	return vector;
}


void destroy_vector(double* vector){
	free(vector);
}


double** create_matrix(unsigned int rows, unsigned int cols ){

	double** mat = malloc(sizeof(double*) * rows);
	// fill an array with pointers to rows of doubles
	
	for(int i = 0; i < rows; i++){
	// allocate a row of doubles for each pointer
		mat[i] = calloc(cols, sizeof(double) * cols);
	}
	
	return mat;
}


void destroy_matrix(double **matrix,  unsigned int rows){
	for(int i = 0; i < rows; i++){
		free(matrix[i]);
	}
	free(matrix);
}


// mat1 is shape m times n
// mat2 is shape n times p
// result is shape m times p
void matrix_multiplication(double **result,double **mat1,double **mat2,
		      unsigned int m,unsigned int n,unsigned int p){

	for(int i = 0; i < m; i++){
		for(int j = 0; j < p; j++){

			result[i][j] = 0;

			for(int k = 0; k < n; k++){
				result[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}


// all matrices have size m times n
void elementwise_matrix_multiplication(double **result,double **mat1,
		double **mat2,unsigned int m,unsigned int n){

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			result[i][j] = mat1[i][j] * mat2[i][j];
		}
	}
}



void scale_vector_by_factor(double* v, double scale_factor, unsigned int len){
	for(int i = 0; i < len; i++){
		v[i] = v[i] * scale_factor;
	}
}


double vector_norm(double *v1,unsigned int len){
	double sum = 0;
	for(int i = 0; i < len; i++){
		sum += v1[i] * v1[i];
	}
    	return sqrt(sum);
}


void normalize_vector(double *v1,unsigned int len){
	double norm = vector_norm(v1, len);
	scale_vector_by_factor(v1, 1/norm, len);
}

double average(double *v1,unsigned int len ){
	double sum = 0;
	for(int i = 0; i < len; i++){
		sum += v1[i];
	}

   	return sum/len;
}


double standard_deviation(double *v1, unsigned int len){

	double sum = 0;
	double mu = average(v1, len);

	for(int i = 0; i < len; i++){
		sum += pow(v1[i] - mu, 2);
	}

    	return sqrt(sum/len);
	//assuming we have a sample of a distribution, and not
	//the distribution itself it SHOULD be sqrt(sum/(len-1))
}


double distance_between_vectors(double *v1,
			 double *v2,
			 unsigned int len){

	double sum_squared = 0, dist = 0;

	for(int i = 0; i < len; i++){
		sum_squared += pow(v1[i] - v2[i], 2);
	
	}
	dist = sqrt(sum_squared);
	return dist;
}


/* filepath is including the filename
 header is in format: header = "header 1, header 2, [...], header N"
 for N columns of data in array */
void print_matrix_to_file(char* filepath, char* header, double** matrix,
					  	  size_t rows, size_t cols){
	FILE* file = fopen(filepath, "w");
	fprintf(file, "%s\n", header);
	
	for(int row_i = 0; row_i < rows; row_i++){
		for(int col_j = 0; col_j < cols; col_j++){
			if(col_j != cols - 1){
				fprintf(file, "%.8f, ", matrix[row_i][col_j]);
			}else{
				fprintf(file, "%.8f\n", matrix[row_i][col_j]);
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
		fprintf(file, "%.8f\n", vector[index]);
	}

	fclose(file);
	printf("Sucessfully printed vector to file: %s\n", filepath);
}



double get_max_value_of_vector(double* vector, int len){
	double max = vector[0];
	
	for(int i = 1; i < len; i++){
		if(vector[i] > max){
			max = vector[i];
		}
	}
	return max;
}

int get_max_value_of_int_vector(int* vector, int len){
	int max = vector[0];
	
	for(int i = 1; i < len; i++){
		if(vector[i] > max){
			max = vector[i];
		}
	}
	return max;
}

double** create_matrix_with_inserted_column(double** matrix, double* vector, 
								int rows, int cols, int col_insert_index){
	double** result = create_matrix(rows, cols+1);

	for(int j = 0; j < col_insert_index; j++){
		for(int i = 0; i < rows; i++){
			result[i][j] = matrix[i][j];
		}
	}

	// j == col_insert_index
	
	for(int i = 0; i < rows; i++){
		result[i][col_insert_index] = vector[i];
	}	


	for(int j = col_insert_index; j < cols; j++){
		for(int i = 0; i < rows; i++){
			result[i][j+1] = matrix[i][j];
		}
	}

	return result;
}


void print_vectors_as_columns_to_file(char* filepath, char* header,
				double** vector_of_vectors, int num_vectors, int* len_vectors){
	FILE* file = fopen(filepath, "w");
	fprintf(file, "%s\n", header);
	
	int num_cols  = num_vectors;
	int* len_cols = len_vectors;

	int max_rows = get_max_value_of_int_vector(len_cols, num_vectors);
	
	for(int row_i = 0; row_i < max_rows; row_i++){ //rows
		for(int col_i = 0; col_i < num_cols; col_i++){  //cols

			if(col_i != num_cols - 1){

				if(row_i < len_cols[col_i]){ //within vector_i's length; print

					fprintf(file, "%.8f, ", vector_of_vectors[col_i][row_i]);

				}else{// = past vector_i's length and not last column
					fprintf(file, ", ");
				}

			}else{ // = element of last column, break line

				if(row_i < len_cols[col_i]){ //within vector_i's length

					fprintf(file, "%.8f\n", vector_of_vectors[col_i][row_i]);

				}else{// = past vector_i's length and last column, break line
					fprintf(file, "\n");
				}
			}
		}
	}

	fclose(file);
	printf("Sucessfully printed vector of vectors to file: %s\n", filepath);
}





double* create_linspace(double start, double end, int num_points){

	double* linspace = create_vector(num_points);
	
	for(int i = 0; i < num_points; i++){
		linspace[i] = i * (end-start)/(num_points-1) + start;
	}

	return linspace;	
}


double** create_transpose_of_matrix(double** matrix,
									 int initial_rows, int initial_cols){
	double** transpose = create_matrix(initial_cols, initial_rows);
	for(int i = 0; i < initial_rows; i++){
		for(int j = 0; j < initial_cols; j++){
			transpose[j][i] = matrix[i][j];
		}
	}
	return transpose;
}
