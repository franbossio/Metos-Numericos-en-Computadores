#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define E 2.718281828
using namespace std;
double f(double x){
	return ((9.81*x)/14)*(1-pow(E,-((14*7)/x)))-35;
}
	int main(int argc, char *argv[]) {
		double a=0, b=100, tol=10e-10, c=0;
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
				return 2;
			}
			error=(b-a)/2;
		} while(error>tol);
		printf("La raiz es: %lf", c);
		printf("\nEl error es: %lf", error);
		printf("\nInteraciones: %d ", count);
		return 0;
	}
	
	
	
