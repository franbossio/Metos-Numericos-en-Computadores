#include <iostream>
#include <math.h>
#include <stdlib.h>

// Tamano maximo de sistema soportado (cantidad de puntos/incognitas).
// CAMBIAR ESTE VALOR si se necesitan mas de 20 puntos.
#define FILAS 20

using namespace std;

void lagrange (double m[FILAS][2], int fila);
void polinomica (double [FILAS][2], int fila);


void triangulacion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas);
void retrosustitucion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas);
void pivot(double a[FILAS][FILAS], double b[FILAS], int filas, int i);
double determinante(double a[FILAS][FILAS], int filas);


// Funcion analitica real (si se conoce) para comparar contra el valor
// interpolado y sacar el error. CAMBIAR ESTA FUNCION en cada ejercicio
// para que coincida con la funcion que genero los puntos de la tabla m.
double func (double x){

	return 1+3*x;
}


int main(int argc, char *argv[]) {
	double m[FILAS][2];
	int filas;
	int seleccion;

	printf("Ingrese la cantidad de puntos (x,y) de la tabla: ");
	scanf("%d", &filas);
	if (filas < 2 || filas > FILAS) {
		printf("\nCantidad de puntos invalida (debe ser entre 2 y %d).\n", FILAS);
		return 1;
	}

	printf("Ingrese los %d puntos (formato por punto: x y):\n", filas);
	for (int i = 0; i < filas; i++) {
		scanf("%lf %lf", &m[i][0], &m[i][1]);
	}

	printf("\nTabla ingresada:\n");
	for(int i = 0; i < filas ; i++){
		printf("(%lf ; %lf)",m[i][0],m[i][1]);
		printf("\n");
	}
	printf("\nIngrese:\n 1 --> Lagrange\n 2 --> Polinomica\n");
	scanf("%d",&seleccion);
	switch (seleccion){
	case 1:
		lagrange(m, filas);
		break;
	case 2:
		polinomica(m, filas);
		break;
	default:
		printf("\nSe selecciono mal la opcion\n");
		break;
	}
	return 0;
}

void lagrange (double m[FILAS][2], int fila){
	double x;//Coeficiente a interpolar
	double e;
	printf("Recuerde haber definido la funcion previamente\n");
	printf("Ingrese el valor a interpolar\n");
	scanf("%lf", &x);

	double sum = 0;
	for (int i = 0; i < fila; i++) {
		double producto = 1;
		for (int j = 0; j < fila; j++) {
			if (j != i) {
				// L_i(x) = producto_{j!=i} (x - x_j) / (x_i - x_j)
				producto *= ((x - m[j][0]) / (m[i][0] - m[j][0]));
			}
		}
		sum += m[i][1] * producto;
	}
	e = fabs(func(x) - sum);
	printf("El valor interpolado para %lf es: %lf, con un error de %lf\n", x, sum, e);
}

void polinomica (double m[FILAS][2], int fila){
	double a[FILAS][FILAS];
	double b[FILAS];

	// Matriz de Vandermonde: fila x fila (una columna por cada potencia
	// de x, de 0 a fila-1), para resolver los "fila" coeficientes del
	// polinomio interpolador de grado fila-1.
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < fila; j++) {
			a[i][j] = pow(m[i][0], j);
		}
		b[i] = m[i][1];
	}
	printf("\nMatriz a\n");
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < fila; j++) {
			printf("%lf",a[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	printf("\nMatriz b\n");
	for (int i = 0; i < fila; i++) {
		printf("%lf",b[i]);
		printf("\t");
	}

	double* x = (double*)malloc(fila * sizeof(double));
	if (x == NULL) {
		printf("Error: No se pudo asignar memoria.\n");
		exit(1);
	}
	triangulacion(a, b, x, fila);
	free(x);
}
void triangulacion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas){
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
void retrosustitucion(double a[FILAS][FILAS], double b[FILAS], double x[FILAS], int filas){
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
	printf("\n\n\n\nConjunto solucion de los coeficientes: \n");
	for (int i = 0; i < filas; ++i) {
		printf("a%d = %lf\n", i , x[i]);
	}

	printf("\n\n");
	printf("Polinomio Interpolador: \n");
	int potencia = 0;
	for (int i = 0; i <= filas - 1; i++) {
		if (potencia == 0)
			printf("%lf", x[i]);
		else {
			if (x[i] >= 0)
				printf(" + %lf.x^%d ", x[i], potencia);
			else
				printf(" %lf.x^%d", x[i], potencia);
		}
		potencia++;
	}
	printf("\n");
}
void pivot(double a[FILAS][FILAS], double b[FILAS], int filas, int i){
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
double determinante(double a[FILAS][FILAS], int filas){
	double norma = 1;
	for(int i = 0; i < filas ; i++){
		norma = norma * a[i][i];
	}
	return norma;
}
