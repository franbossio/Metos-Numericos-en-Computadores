#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	int swap;
	double a[4][4]={{1,0,0,0},{1,1,1,1},{1,2,4,8},{1,3,9,27}};
	double b[4]={0,0,3,4}, factor, sum, x[4]={};
	for(int i=0;i<3;i++){
		for(int j=i+1;j<4;j++){
			int p=i;
			if(abs(a[i][i])<10e-5){
				for(int l=i+1;l<4;l++){
					if(abs(a[l][i])>abs(a[i][i])){
						p=l;
					}
				}
				for(int m=0;m<4;m++){
					swap=a[p][m];
					a[p][m]=a[i][m];
					a[i][m]=swap;
				}
				swap=b[p];
				b[p]=b[i];
				b[i]=swap;
			}
			factor=-(a[j][i]/a[i][i]);
			for(int k=i;k<4;k++){
				a[j][k]=factor*a[i][k]+a[j][k];
			}
			b[j]=factor*b[i]+b[j];
		}
	}
	int prod=1;
	for(int i=0;i<4;i++){
		prod=prod*a[i][i];
	}
	if(prod==0){
		printf("No tiene solucion unica");
		return 1;
	}
	x[3]=b[3]/a[3][3];
	for(int i=2;i>-1;i--){
		sum=b[i];
		for(int j=i+1;j<4;j++){
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
	for(int i=0;i<4;i++){
		printf("%lf\t", x[i]);
	}
	return 0;
}
