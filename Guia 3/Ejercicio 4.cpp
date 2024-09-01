#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	int swap;
	double a[3][3]={{4,-2,1},{-2,1,-1},{-2,3,6}};
	double b[3]={2,-1,0}, factor, sum, x[3]={};
	for(int i=0;i<2;i++){
		for(int j=i+1;j<3;j++){
			int p=i;
			if(abs(a[i][i])<10e-5){
				for(int l=i+1;l<3;l++){
					if(abs(a[l][i])>abs(a[i][i])){
						p=l;
					}
				}
				for(int m=0;m<3;m++){
					swap=a[p][m];
					a[p][m]=a[i][m];
					a[i][m]=swap;
				}
				swap=b[p];
				b[p]=b[i];
				b[i]=swap;
			}
			factor=-(a[j][i]/a[i][i]);
			for(int k=i;k<3;k++){
				a[j][k]=factor*a[i][k]+a[j][k];
			}
			b[j]=factor*b[i]+b[j];
		}
	}
	int prod=1;
	for(int i=0;i<3;i++){
		prod=prod*a[i][i];
	}
	if(prod==0){
		printf("No tiene solucion unica");
		return 1;
	}
	x[2]=b[2]/a[2][2];
	for(int i=1;i>-1;i--){
		sum=b[i];
		for(int j=i+1;j<3;j++){
			sum=sum-a[i][j]*x[j];
		}
		sum=sum/a[i][i];
		x[i]=sum;
	}
	/*for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	printf("%lf\t", a[i][j]);
	}
	printf("\n");
	}*/
	for(int i=0;i<3;i++){
		printf("%lf\t", x[i]);
	}
	return 0;
}

