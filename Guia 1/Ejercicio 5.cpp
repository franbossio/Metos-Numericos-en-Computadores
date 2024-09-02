#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
double f(double x){
	return ((log(x)-(1-x))/(log(x)+(1-x)/(2/3)))-0.3;
}
	int main(int argc, char *argv[]) {
		double a=40, b=60, tol=0.3, c=0;
		int count=0;
		if(f(a)*f(b)>0){
			printf("Cambie los valores de a o b");
			return 1;
		}
		double error ;
		do{
			count++;
			c=(a+b)/2;
			if(f(a)*f(c)>0){
				a=c;
			}else if(f(a)*f(c)<0){
				b=c;
			}else{
				printf("La raiz es %lf", c);
				printf("\nInterac-iones: %d ", count);
				printf("\nError: %lf ",error );
				return 2;
			}
			error=(((b-a)/2)*1/c)*100;
		} while(error>tol);
		printf("La raiz es: %lf", c);
		printf("\nEl error es: %lf", error);
		printf("\nInteraciones: %d ", count);
		return 0;
	}
	
	
