#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
double g(double x){
	return pow(x,x-cos(x));
}
	int main(int argc, char *argv[]) {
		double x_v=0, error=1, x_n, tol=10e-12;
		int iter=0;
		
		do{
			iter++;
			x_n=g(x_v);
			if(abs(((g(x_v+0.01)-g(x_v))/0.01))>1){
				printf("No se cumple el criteio de convergencia");
				return 1;
			}
			error=abs(x_n-x_v);
			x_v=x_n;
		} while(error>tol && iter<10000);
		
		printf("Raiz: %lf", x_n);
		printf("\nError: %lf", error);
		printf("\nIteraciones: %d", iter);
		return 0;
	}
