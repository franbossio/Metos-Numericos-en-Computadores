#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
double f(double x){
	return pow(x,10)-1;
}
	int main(int argc, char *argv[]) {
		double a=0, b=2, tol=1e-5, c=0, cv;
		int count=0;
		if(f(a)*f(b)>0){
			printf("Cambie los valores de a o b");
			return 1;
		}
		double error = 1;
		do{
			cv=c;
			count++;
			c=(a*f(b)-b*f(a))/(f(b)-f(a));
			if(f(a)*f(c)>0){
				a=c;
			}else if(f(a)*f(c)<0){
				b=c;
			}else{
				printf("La raiz es %lf", c);
				printf("\nInteraciones: %d ", count);
				return 2;
			}
			error=abs(c-cv);
		} while(error>tol);
		printf("La raiz es: %lf", c);
		printf("\nEl error es: %lf", error);
		printf("\nInteraciones: %d ", count);
		return 0;
	}
	
