#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "linalg.h"


void
elementwise_addition(
		     double *res,
		     double *v1,
		     double *v2,
		     unsigned int len
	            )
{
	for(int i = 0; i < len; i++){
		res[i] = v1[i] + v2[i]; 
	}
}


void
elementwise_multiplication(
			   double *res,
			   double *v1,
			   double *v2,
			   unsigned int len
	                  )
{
	for(int i = 0; i < len; i++){
		res[i] = v1[i] * v2[i]; 
	}
}
 

double dot_product(
	    double *v1,
	    double *v2,
	    unsigned int len
	   )
{
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
void matrix_multiplication(
		      double **result,
		      double **mat1,
		      double **mat2,
		      unsigned int m,
		      unsigned int n,
		      unsigned int p ){

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
void elementwise_matrix_multiplication(
			double **result, 
			double **mat1, 
			double **mat2, 
			unsigned int m,
		        unsigned int n){

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


double vector_norm(
	    double *v1,
	    unsigned int len
	   )
{
	double sum = 0;
	for(int i = 0; i < len; i++){
		sum += v1[i] * v1[i];
	}
	
    	return sqrt(sum);
}


void normalize_vector(
		 double *v1,
		 unsigned int len
		){
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

