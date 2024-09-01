#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool diagonalmenteDominante(double a[3][3], int filas);

int main(int argc, char *argv[]) {
	double a[3][3]={{4,-1,1},{4,-8,1},{-2,1,5}}, b[3]={7,-21,15};
	bool check = diagonalmenteDominante(a,3);
	if(!check){
		exit(0);
	}
	int iter=0;
	double suma=0,error=1, tol = 10e-5; 
	double xn[3], xv[3]={0,0,0};
	do{
		iter++;
		for(int i=0;i<3;i++){
			suma=0;
			for(int j=0;j<3;j++){
				if(j!=i){
					suma+=a[i][j]*xv[j];
				}
			}
			xn[i]=(b[i]-suma)/a[i][i];
		}
		suma=0;
		for(int i=0;i<3;i++){
			suma += (xn[i] - xv[i]) * (xn[i] - xv[i]);
		}
		error=sqrt(suma);
		for(int i=0;i<3;i++){
			xv[i]=xn[i];
		}
	} while(error>tol&&iter<=10000);
	printf("\n El resultado es: \nxnuevo = [\t");
	for (int i = 0; i < 3; i++) {
		printf("%lf\t", xn[i]);
	}
	
	printf("]\n La cantidad de iteraciones fueron: %d \n El error es de %lf", iter, error);
	
	return 0;
}
bool diagonalmenteDominante(double a[3][3], int filas){
	double suma = 0; 
	int counter = 0;
	for(int i = 0; i < filas ; i++){
		suma = 0; 
		counter++;
		for(int j = 0 ; j < filas ; j++){
			if(j!=i){
				suma+= fabs(a[i][j]);
			}
		}
		
		if(fabs(a[i][i]) < suma)
			printf("\nLa matriz no es diagonalmente dominante. Fila: %d",counter);
		
		if(a[i][i] == 0){
			printf("\nCeros en la diagonal");
			return false;
		}
	}
	return true;
}
	

