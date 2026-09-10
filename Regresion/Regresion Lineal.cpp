#include <iostream>
#include <math.h>
#include <stdlib.h>
#define ROWS 100
#define FILAS 2 // cantidad de coeficientes del ajuste (a y b), siempre 2
using namespace std;

// ==================== CAMBIAR EN CADA EJERCICIO ====================
// Este programa ajusta un modelo de la forma y = a*z(x) + b (regresion
// lineal en la variable transformada z). Dejar z(x)=x para una regresion
// lineal comun (y=a*x+b). Para un modelo linealizable, poner aca la
// transformacion correspondiente, por ejemplo:
//   y = a*exp(x^2) + b   -->   z(x) = exp(pow(x,2))
//   y = a*ln(x) + b      -->   z(x) = log(x)
//   y = a/x + b          -->   z(x) = 1.0/x
double z(double x){
	return x;
}
// =====================================================================

void triangulacion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas);
void retrosustitucion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas);
void pivot(double a[FILAS][FILAS], double b[FILAS], int filas, int i);
double determinante(double a[FILAS][FILAS], int filas);


void regresionLineal(double m[ROWS][2] , int filas);

int main(int argc, char *argv[]) {
	double m[ROWS][2];
	int filas;

	printf("Ingresar la cantidad de puntos (x,y) de la tabla: ");
	scanf("%d", &filas);
	if (filas < 2 || filas > ROWS) {
		printf("\nCantidad de puntos invalida (debe ser entre 2 y %d).\n", ROWS);
		return 1;
	}
	printf("Ingresar los %d puntos (formato por punto: x y):\n", filas);
	for (int i = 0; i < filas; i++) {
		scanf("%lf %lf", &m[i][0], &m[i][1]);
	}

	printf("\n--> Regresion Lineal\n");

	regresionLineal(m , filas);

	return 0;

}
void regresionLineal(double m[ROWS][2], int filas){
	double a[2][2] = {{0}};
	double b[2] = {0};
	double yProm = 0, r2 = 0, r = 0, Sr = 0, St = 0, sum = 0;
	a[1][1] = filas;
	for(int i = 0 ; i < filas ; i++){
		double zi = z(m[i][0]);
		a[0][0]+= pow(zi,2);
		a[0][1]+= zi;
		a[1][0]+= zi;
		b[0]+= zi * m[i][1];
		b[1] += m[i][1];
	}

	printf("\nMatriz:\n");
	for(int i = 0 ; i < 2 ; i++){
		for(int j = 0 ; j < 2 ; j++){
			printf("\t%lf",a[i][j]);
		}
		printf("\t%lf",b[i]);
		printf("\n");
	}

	double* x = (double*)malloc(2 * sizeof(double));
	if (x == NULL) {
		printf("Error: No se pudo asignar memoria.\n");
		exit(1);
	}
	triangulacion(a, b, x, 2);

	// x[0] = a, x[1] = b, del modelo y = a*z(x) + b
	printf("\n\n\n\nConjunto solucion: \n");
	printf("a = %lf\n", x[0]);
	printf("b = %lf\n", x[1]);

	for(int i = 0; i < filas ; i++){
		yProm+= m[i][1];

	}
	yProm = yProm/filas;
	for(int i = 0; i < filas ; i++){
		St+= pow((m[i][1] - yProm) , 2);

	}

	for(int i = 0; i<filas ; i++){
		sum+= pow((m[i][1] - (x[0]*z(m[i][0])+x[1])) , 2);
	}

	Sr = sqrt(sum/filas);
	printf("\nError estandar de la estimacion (Sr) = %lf\n", Sr);

	r2 = (St - sum)/St; // coeficiente de determinacion
	r = sqrt(fabs(r2)); // coeficiente de correlacion

	printf("Coeficiente de determinacion (r^2) = %lf\n", r2);
	printf("Coeficiente de correlacion (r) = %lf\n", r);

	free(x);
}
void triangulacion(double a[2][2], double b[2], double x[FILAS], int filas){
	for (int i = 0 ; i < (filas - 1) ; i++){
		pivot(a, b, filas , i);

		if (fabs(a[i][i]) < 1e-10) {
			printf("\nMatriz singular: no se pudo eliminar la columna %d (pivote nulo).\n", i);
			return;
		}

		for (int j = i + 1; j < filas; j++) {
			double factor = -a[j][i] / a[i][i];
			for (int k = 0; k < filas; ++k) {
				a[j][k] = a[i][k] * factor + a[j][k];
			}
			b[j] = b[i] * factor + b[j];
		}
	}

	double norma = determinante(a,filas);
	if(norma == 0.0){
		printf("\n\nmatriz singular");
	}else{
		retrosustitucion(a, b, x, filas);
	}
}

void retrosustitucion(double a[2][2], double b[2], double x[FILAS], int filas){
	double value = 0;
	value = b[filas - 1] / a[filas - 1][filas - 1];
	x[filas - 1] = value;
	for (int i = filas - 2; i >= 0; --i) {
		double sum = 0;
		for (int j = i + 1; j < filas; ++j) {
			sum = sum + a[i][j] * x[j];
		}
		value = (b[i] - sum) / a[i][i];
		x[i] = value;
	}

}

void pivot(double a[2][2], double b[2], int filas, int i){
	if (fabs(a[i][i]) < 0.0001) {
		for (int j = i + 1; j < filas; j++) {
			if (fabs(a[j][i]) > fabs(a[i][i])) {
				for (int k = i; k < filas; ++k) {
					printf("Se realizo pivoteo\n");
					double swap = a[i][k];
					a[i][k] = a[j][k];
					a[j][k] = swap;
				}
				double swap = b[i];
				b[i] = b[j];
				b[j] = swap;
			}
		}
	}
}

double determinante(double a[2][2], int filas){
	double norma = 1;
	for(int i = 0; i < filas ; i++){
		norma = norma * a[i][i];
	}
	return norma;
}
