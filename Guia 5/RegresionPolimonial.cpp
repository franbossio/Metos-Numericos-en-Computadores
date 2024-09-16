#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void gauss_pivot(double a[100][100],double b[100],double x[100],int p);

int main(int argc, char *argv[]) {
	double x[5]={0,1,1.5,3,5},y[5]={1.2,2.7,3.9,7.1,10},a[100][100],b[100],x1[10]={0};
	int p, n=5;
	if(n<p+1){
		printf("no hay suficientes datos");
		return 1;
	}
	printf("Ingresar el grado del polinomio: ");
	scanf(" %d", &p);
	double sumaxy, sumax;
	for(int l=0;l<p+1;l++){
		sumaxy=0;
		for(int i=0; i<n;i++){
			sumaxy+=pow(x[i],l)*y[i];
		}
		b[l]=sumaxy;
		for(int m=0;m<p+1;m++){
			sumax=0;
			for(int i=0;i<n;i++){
				sumax+=pow(x[i],(l+m));
			}
			a[l][m]=sumax;
		}
	}
	/*for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("%lf\t", a[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<p+1;i++){
		printf("%lf\t", b[i]);
	}*/
	gauss_pivot(a,b,x1,p);
	return 0;
}

void gauss_pivot(double a[100][100],double b[100],double x[100],int p){
	int swap;
	//p=1, entonces 2=p+1
	double factor, sum;
	for(int i=0;i<p;i++){
		for(int j=i+1;j<p+1;j++){
			int r=i;
			if(abs(a[i][i])<10e-5){
				for(int l=i+1;l<p+1;l++){
					if(abs(a[l][i])>abs(a[i][i])){
						r=l;
					}
				}
				for(int m=0;m<p+1;m++){
					swap=a[r][m];
					a[r][m]=a[i][m];
					a[i][m]=swap;
				}
				swap=b[r];
				b[r]=b[i];
				b[i]=swap;
			}
			factor=-(a[j][i]/a[i][i]);
			for(int k=i;k<p+1;k++){
				a[j][k]=factor*a[i][k]+a[j][k];
			}
			b[j]=factor*b[i]+b[j];
		}
	}
	int prod=1;
	for(int i=0;i<p+1;i++){
		prod=prod*a[i][i];
	}
	if(prod==0){
		printf("No tiene solucion unica");
		exit(1);
	}
	x[p]=b[p]/a[p][p];
	for(int i=p-1;i>-1;i--){
		sum=b[i];
		for(int j=i+1;j<p+1;j++){
			sum=sum-a[i][j]*x[j];
		}
		sum=sum/a[i][i];
		x[i]=sum;
	}
	//imprimir valores de x
	printf("\nValores:\n");
	for(int i=0;i<p+1;i++){
		printf("%lf\t", x[i]);
	}
	printf("\nEl polinomio es:\n");
	//imprimir polinomio
	for(int i=0;i<p+1;i++){
		printf("%lf*x^%d +",x[i],p);
		p--;
		if(p==0){
			printf(" %lf\t", x[i]);
		}
	}
}
