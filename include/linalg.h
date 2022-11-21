#pragma once

/* **********************************************
 *
 * Add v1 and v2 elementwise
 * results is stored in res
 *
 * **********************************************/
void
elementwise_addition(
		     double *res,
		     double *v1,
		     double *v2,
		     unsigned int len
	            );


/* **********************************************
 *
 * Multiply v1 and v2 elementwise
 * results is stored in res
 *
 * **********************************************/
void
elementwise_multiplication(
			   double *res,
			   double *v1,
			   double *v2,
			   unsigned int len
	                  );


/* **********************************************
 *
 * Calculate the dot product between
 * v1 and v2
 *
 * **********************************************/
double
dot_product(
	    double *v1,
	    double *v2,
	    unsigned int len
	   );



double*
create_vector(unsigned int len);

void
destroy_vector(double* vector);


/* **********************************************
 *
 * Allocate the memory to a 2D array
 *
 * **********************************************/
double**
create_matrix(
		unsigned int rows,
		unsigned int cols
	     );

void
destroy_matrix(
		 double **mat,
		 unsigned int rows
	        );

void
matrix_multiplication(
		      double **result,
		      double **v1,
		      double **v2,
		      unsigned int m,
		      unsigned int n, 
		      unsigned int p
		     );

void elementwise_matrix_multiplication(
			double **result, 
			double **mat1, 
			double **mat2, 
			unsigned int m,
		        unsigned int n);

double
vector_norm(
	    double *v1,
	    unsigned int len
	   );

void
normalize_vector(
		 double *v1,
		 unsigned int len
		);

double
average(
	double *v1,
	unsigned int len
       );

double
standard_deviation(
	    	   double *v1,
	    	   unsigned int len
	          );

double
distance_between_vectors(
			 double *v1,
			 double *v2,
			 unsigned int len
	                );


void scale_vector_by_factor(double* v, double scale_factor, unsigned int len);



void print_matrix_to_file(char* filepath, char* header, double** matrix,
							 size_t rows, size_t cols);


void print_vector_to_file(char* filepath, char* header, double* vector,
					  	  size_t size);

double* create_linspace(double start, double end, int num_points);

double get_max_value_of_vector(double* vector, int len);

void print_vectors_as_columns_to_file(char* filepath, char* header, double** vector_of_vectors, int num_vectors, int* len_vectors);

double** create_transpose_of_matrix(double**, int, int);

double** create_matrix_with_inserted_column(double** matrix, double* vector,
								int rows, int cols, int col_insert_index);
