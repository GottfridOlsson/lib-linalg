#pragma once

#include <stddef.h> //for size_t

/* **********************************************
 *
 * Create vector of zeros.
 * REMEMBER TO FREE with destroy_vector.
 *
 * **********************************************/
double* create_vector(
	size_t len
);

/* **********************************************
 *
 * Create vector of equally spaced numbers
 * between start and end (endpoints included).
 * REMEMBER TO FREE with destroy_vector.
 *
 * **********************************************/
double* create_linspace(
	double start, 
	double end, 
	size_t n_points
);



/* **********************************************
 *
 * Create vector with random uniform numbers
 * REMEMBER TO FREE with destroy_vector.
 *
 * **********************************************/

double* create_random_uniform_vector(size_t len, unsigned long int seed);



void evaluate_function_on_vector(double* output, double (*function)(double),
								 double* x, int len);


/* **********************************************
 *
 * Free memory of vector created by create_vector
 *
 * **********************************************/
void destroy_vector(
	double *vector
);

/* **********************************************
 *
 * Copy elements of v_source to v_dest.
 *
 * **********************************************/
void copy_vector(
	double *v_dest, 
	double *v_source, 
	size_t len
);

/* **********************************************
 *
 * Multiplies all elements of vector with a 
 * given factor.
 * 
 * **********************************************/
void scale_vector_by_factor(
	double* v, 
	double scale_factor, 
	size_t len
);

void add_scalar_to_vector(double *v, double scalar, size_t len);

/* **********************************************
 *
 * Add v1 and v2 elementwise
 * results is stored in res
 *
 * **********************************************/
void elementwise_addition(
	double *res,
	double *v1,
	double *v2,
	size_t len
);


/* **********************************************
 *
 * Multiply v1 and v2 elementwise
 * results is stored in res
 *
 * **********************************************/
void elementwise_multiplication(
	double *res,
	double *v1,
	double *v2,
	size_t len
);


/* **********************************************
 *
 * Calculate the dot product between
 * v1 and v2
 *
 * **********************************************/
double dot_product(
	double *v1,
	double *v2,
	size_t len
);

/* **********************************************
 *
 * Computes Euclidean norm (2-norm) of vector.
 * 
 * **********************************************/
double vector_norm(
	double *v1,
	size_t len
);

/* **********************************************
 *
 * Normalizes a vector to have 2-norm equal to 1.
 * 
 * **********************************************/
void normalize_vector(
	double *v1,
	size_t len
);

/* **********************************************
 *
 * Returns Euclidean distance between v1 and v2.
 * 
 * **********************************************/
double distance_between_vectors(
	double *v1,
	double *v2,
	size_t len
);

/* **********************************************
 *
 * Compute average of values in vector.
 * 
 * **********************************************/
double vector_average(
	double *v1,
	size_t len
);

/* **********************************************
 *
 * Computes standard deviation of values in
 * vector.
 * 
 * Note: this is NOT sample mean. 
 * 
 * **********************************************/
double vector_standard_deviation(
	double *v1,
	size_t len
);

double vector_variance(double *v1, size_t len);
/* **********************************************
 *
 * Returns value of largest element in vector.
 * 
 * **********************************************/
double vector_max(
	double* vector, 
	size_t len
);

/* **********************************************
 *
 * Create a matrix (fragmented 2D array) with
 * given number of rows and cols on the heap.
 * REMEMBER TO FREE with destroy_matrix.
 *
 * **********************************************/
double** create_matrix(
	size_t rows,
	size_t cols
);

/* **********************************************
 *
 * Creates a new matrix which is the transpose of
 * a given matrix.
 * REMEMBER TO FREE with destroy_matix.
 * 
 * **********************************************/
double** create_transpose_of_matrix(
	double **mat, 
	size_t initial_rows, 
	size_t initial_cols);

/* **********************************************
 *
 * Creates a new matrix which is the same as
 * a given matrix but with an additional column
 * inserted at a given index. Inserted column
 * (vector) must have length equal to number
 * of rows in matrix.
 * REMEMBER TO FREE with destroy_matrix
 * 
 * col_insert_index == 0 	-> insert first
 * col_insert_index == cols -> insert last 
 * 
 * 
 * **********************************************/
double** create_matrix_with_inserted_column(
	double** matrix, 
	double* vector,
	size_t rows, 
	size_t cols, 
	size_t col_insert_index
);

/* **********************************************
 *
 * Creates a new matrix populated with random
 * doubles uniformly distributed on [0, 1].
 * Random seed must be specified.
 * REMEMBER TO FREE with destroy_matrix.
 * 
 * **********************************************/
double** create_random_uniform_matrix(
	size_t rows, 
	size_t cols, 
	unsigned long int seed
);


/* **********************************************
 *
 * Free memory of matrix created with
 * create_matrix
 *
 * **********************************************/
void destroy_matrix(
	double **mat,
	size_t rows
);

/* **********************************************
 *
 * Adds a scalar to alla elements of matrix.
 * 
 * **********************************************/
void scale_matrix_by_factor(
	double **mat, 
	double factor, 
	size_t rows,
	size_t cols
);

/* **********************************************
 *
 * Multiplies all elements of matrix by scalar.
 * 
 * **********************************************/
void add_scalar_to_matrix(
	double **mat, 
	double scalar, 
	size_t rows, 
	size_t cols
);

/* **********************************************
 *
 * Elementwize addition
 * Adds mat1 and mat2 and stores in res.
 * mat1, mat2 and res should be of same size.
 * 
 * **********************************************/
void elementwise_matrix_addition(
	double **res,
	double **mat1,
	double **mat2, 
	size_t rows, 
	size_t cols
);

/* **********************************************
 *
 * Elementwize product
 * Multiplies mat1 and mat2 and stores in res.
 * mat1, mat2 and res should be of same size.
 * 
 * **********************************************/
void elementwise_matrix_multiplication(
	double **res, 
	double **mat1, 
	double **mat2, 
	size_t rows,
	size_t cols
);

/* **********************************************
 *
 * Elementwise addition of matrices where second
 * matrix is scaled by a constant factor.
 * Result is stored in res.
 * Matrices should have the same size.
 * 
 * **********************************************/
void add_scaled_matrix_to_matrix(
	double **res, 
	double **mat,
	double **mat_to_scale, 
	double factor, 
	size_t rows, 
	size_t cols
);

/* **********************************************
 *
 * Matrix product
 * Multiplies mat 1 (m x n) by mat2
 * (n x p) and stores result in res (m x p)
 *
 * **********************************************/
void matrix_multiplication(
	double **res,
	double **mat1,
	double **mat2,
	size_t m,
	size_t n, 
	size_t p
);

/* **********************************************
 *
 * Print a vector to the terminal.
 * 
 * **********************************************/
void print_vector(
	double* a, 
	size_t len
);

/* **********************************************
 *
 * Print a matrix to the terminal.
 * 
 * **********************************************/
void print_matrix(
	double** a,
	size_t rows,
	size_t cols
);

/* **********************************************
 *
 * Writes a matrix to a CSV file. 
 * File will be overwritten.
 * Rows of matrix will be rows of file.
 * 
 * Arguments:
 * filepath: string with path to save file to, include filename
 * header: string in format "header 1, header 2, [...], header N"
 * 		   (end line inserted automatically)
 * matrix: Matrix to write to file.
 * 
 * **********************************************/
void print_matrix_to_file(
	char *filepath, 
	char *header, 
	double **matrix,
	size_t rows, 
	size_t cols
);

/* **********************************************
 *
 * Writes a single vector to a CSV file. 
 * One element will be written to each row.
 * File will be overwritten.
 * 
 * Arguments:
 * filepath: string with path to save file to
 * header: string to put at first line of file
 * 		   (end line inserted automatically)
 * vector: vector to write to file.
 * 
 * **********************************************/
void print_vector_to_file(
	char *filepath, 
	char *header, 
	double *vector,
	size_t size
);

/* **********************************************
 *
 * Write vectors to columns of CSV file. Vectors
 * can differ in length.
 * 
 * vector_of_vectors is an array of pointers to
 * the vectors to write. 
 * len_vectors is an array which contains the
 * lengths of each vector.
 * num_vectors is the number of vectors and
 * the number of columns in the resulting CSV file
 * 
 * **********************************************/
void print_vectors_as_columns_to_file(
	char* filepath,
	char* header,
	double** vector_of_vectors,
	int num_vectors,
	int* len_vectors
);
