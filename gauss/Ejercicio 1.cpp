#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
	int swap;
	double a[100][100]={0};
	double b[100]={0}, factor, sum, x[100]={0};
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(i==j){
				a[i][j]=2;
			}else{
				a[i][j]=1;
			}
		}
	}
	for(int i=0;i<100;i++){
		if(i==0||i==99){
			b[i]=4.5;
		}else{
			b[i]=6;
		}
	}
	/*for(int i=0;i<100;i++){
		
		printf("%.1lf\t", b[i]);
		
	}*/
	for(int i=0;i<99;i++){
		for(int j=i+1;j<100;j++){
			int p=i;
			if(abs(a[i][i])<10e-5){
				for(int l=i+1;l<100;l++){
					if(abs(a[l][i])>abs(a[i][i])){
						p=l;
					}
				}
				for(int m=0;m<100;m++){
					swap=a[p][m];
					a[p][m]=a[i][m];
					a[i][m]=swap;
				}
				swap=b[p];
				b[p]=b[i];
				b[i]=swap;
			}
			factor=-(a[j][i]/a[i][i]);
			for(int k=i;k<100;k++){
				a[j][k]=factor*a[i][k]+a[j][k];
			}
			b[j]=factor*b[i]+b[j];
		}
	}
	int prod=1;
	for(int i=0;i<100;i++){
		prod=prod*a[i][i];
	}
	if(prod==0){
		printf("No tiene solucion unica");
		return 1;
	}
	x[99]=b[99]/a[99][99];
	for(int i=98;i>-1;i--){//n-1 n=n-1
		sum=b[i];
		for(int j=i+1;j<100;j++){
			sum=sum-a[i][j]*x[j];
		}
		sum=sum/a[i][i];
		x[i]=sum;
	}
	int c=0;
	for(int i=0;i<100;i++){
		c++;
		printf("%.2lf\t", x[i]);
	}
	printf("%d", c);
	return 0;
}

