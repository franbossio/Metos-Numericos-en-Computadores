#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	
	double m[3][2]={{0,1},{1,3},{2,0}},x,suma, prod;
	int n=3-1;//filas - 1
	printf("Introducir el valor a interpolar: ");
	scanf(" %lf", &x);
	
	//armar el polinomio
	suma=0;
	for(int k=0;k<n;k++){
		prod=1;
		for(int i=0;i<n;i++){
			if(i!=k){
				prod=prod*((x-m[i][0])/(m[k][0]-m[i][0]));
			}
		}
		suma=suma+m[k][1]*prod;
	}
	printf("el resultado es: %lf", suma);
	return 0;
}
