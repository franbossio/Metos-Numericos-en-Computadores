#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

// ==================== CAMBIAR EN CADA EJERCICIO ====================
// Unica parte que hay que tocar a mano: el sistema equivalente a la EDO de
// orden superior. Para y'' = g(x,y,y'), se define y1=y, y2=y'=dy1/dx, y
// y2'=dy2/dx=g(x,y1,y2). Ejemplo resuelto: y''+y=4cos(x)  =>  y2'=-y1+4cos(x)
double f1(double y2){
	return y2;		 // dy1/dx = y2
}
double f2(double x ,double y1){
	return -y1+4*cos(x);	 // dy2/dx = -y1 + 4cos(x)
}
// =====================================================================

int main(int argc, char *argv[]) {
	double a,b,h,k11,k21,k31,k41,k12,k22,k32,k42;
	int n;

	printf("\nIngresar intervalo [a,b]\n a:");
	scanf("%lf",&a);
	printf("\nIngresar intervalo [a,b]\n b:");
	scanf("%lf",&b);
	printf("\nIngresar la cantidad de puntos:");
	scanf("%d",&n);
	h = (b-a)/n;

	double *x = (double *)malloc((n+1) * sizeof(double));
	double *y1 = (double *)malloc((n+1) * sizeof(double));
	double *y2 = (double *)malloc((n+1) * sizeof(double));
	if (x == NULL || y1 == NULL || y2 == NULL) {
		printf("Error: No se pudo asignar memoria.\n");
		exit(1);
	}
	x[0] = a;
	printf("\nIngresar y1(x0) [valor de y en x0]: ");
	scanf("%lf", &y1[0]);
	printf("Ingresar y2(x0) [valor de y' en x0]: ");
	scanf("%lf", &y2[0]);


	for(int i = 0 ; i < n ; i++){

		x[i+1] = x[i] + h;


		k11 = f1(y2[i]);
		k12 = f2(x[i],y1[i]);

		k21 = f1( y2[i]+ (h/2)*k12);
		k22 = f2(x[i] + h/2 , y1[i]+ (h/2)*k11);

		k31 = f1( y2[i]+ (h/2)*k22);
		k32 = f2(x[i] + h/2 , y1[i]+ (h/2)*k21);

		k41 = f1(y2[i] + k32 * h);
		k42 = f2(x[i] + h , y1[i] + k31 * h);

		y1[i+1] = y1[i] + (h/6)*(k11+2*k21+2*k31+k41);
		y2[i+1] = y2[i] + (h/6)*(k12+2*k22+2*k32+k42);

		printf("\n(%lf,%lf)", x[i+1], y1[i+1]);
	}
	free(x);
	free(y1);
	free(y2);
	return 0;
}
