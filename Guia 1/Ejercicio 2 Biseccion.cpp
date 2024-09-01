#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
double f(double x){
	return pow(x,10)-1;
}
	int main(int argc, char *argv[]) {
		double a=0, b=2, tol=10e-5, c=0;
		int count=0;
		if(f(a)*f(b)>0){
			printf("Cambie los valores de a o b");
			return 1;
		}
		double error = 1;
		do{
			count++;
			c=(a+b)/2;
			if(f(a)*f(c)>0){
				a=c;
			}else if(f(a)*f(c)<0){
				b=c;
			}else{
				printf("La raiz es %lf", c);
				printf("\nInteraciones: %d ", count);
				printf("\nEl error es: 0");
				return 2;
			}
			error=(b-a)/2;
		} while(error>tol);
		printf("La raiz es: %lf", c);
		printf("\nEl error es: %lf", error);
		printf("\nInteraciones: %d ", count);
		return 0;
	}
	

