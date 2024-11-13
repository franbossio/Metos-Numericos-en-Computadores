#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	int swap;
	double a[100][100]={};
	double b[100]={}, factor, sum, x[100]={};
	int filas=100;//poner la cantidad de filas
	//armar matriz b
	b[0]=4.5;
	b[99]=4.5;
	for(int i=1;i<filas-1;i++){
		b[i]=6;
	}
	//armar matriz a
	for(int i=0;i<filas;i++){
		for(int j=0;j<filas;j++){
			if(i==j){
				a[i][j]=2;
				if(i==0){
					a[i][j+1]=1;
				}else if(i==99){
					a[i][j-1]=1;
				}else{
					a[i][j-1]=1;
					a[i][j+1]=1;
				}
			}
		}
	}
	
	for(int i=0;i<(filas-1);i++){
		for(int j=i+1;j<filas;j++){
			int p=i;
			if(abs(a[i][i])<10e-5){
				for(int l=i+1;l<filas;l++){
					if(abs(a[l][i])>abs(a[i][i])){
						p=l;
					}
				}
				for(int m=0;m<filas;m++){
					swap=a[p][m];
					a[p][m]=a[i][m];
					a[i][m]=swap;
				}
				swap=b[p];
				b[p]=b[i];
				b[i]=swap;
			}
			factor=-(a[j][i]/a[i][i]);
			for(int k=i;k<filas;k++){
				a[j][k]=factor*a[i][k]+a[j][k];
			}
			b[j]=factor*b[i]+b[j];
		}
	}
	int prod=1;
	for(int i=0;i<filas;i++){
		prod=prod*a[i][i];
	}
	if(prod==0){
		printf("No tiene solucion unica");
		return 1;
	}
	x[filas-1]=b[filas-1]/a[filas-1][filas-1];
	for(int i=1;i>-1;i--){
		sum=b[i];
		for(int j=i+1;j<filas;j++){
			sum=sum-a[i][j]*x[j];
		}
		sum=sum/a[i][i];
		x[i]=sum;
	}
	
	for(int i=0;i<filas;i++){
		printf("%lf\t", x[i]);
	}
	return 0;
}


