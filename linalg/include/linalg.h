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

