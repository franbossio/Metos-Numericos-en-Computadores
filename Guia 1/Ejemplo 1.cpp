#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
double f(double x){
	return 2*x-4;
}
int main(int argc, char *argv[]) {
	double a=1.5, b=4.3, tol=10e-10, c=0;
	if(f(a)*f(b)>0){
		printf("Cambie los valores de a o b");
		return 1;
	}
	double error = 1;
	do{
		c=(a+b)/2;
		if(f(a)*f(c)>0){
			a=c;
		}else if(f(a)*f(c)<0){
			b=c;
		}else{
			printf("La raiz es %lf", c);
			return 2;
		}
		error=(b-a)/2;
	} while(error>tol);
	printf("La raiz es: %lf", c);
	printf("\nEl error es: %lf", error);
	return 0;
}

