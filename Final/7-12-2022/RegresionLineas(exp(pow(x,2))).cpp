#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void gauss_pivot(double a[100][100], double b[100], double x[100], int p);

int main() {
	double x[4] = {0.5, 0.8, 1.3, 2.0}, y[4] = {-0.716, -0.103, 3.419, 52.598};
	double a[100][100], b[100], x1[10] = {0};
	int n = 4;
	
	// Construcción de la matriz A y el vector b para f(x) = a * exp(x^2) + b
	double sum_e2x2 = 0, sum_ex2 = 0, sum_yex2 = 0, sum_y = 0;
	for (int i = 0; i < n; i++) {
		double ex2 = exp(x[i] * x[i]);        // e^(x^2)
		sum_e2x2 += ex2 * ex2;               // (e^(x^2))^2
		sum_ex2 += ex2;                      // e^(x^2)
		sum_yex2 += y[i] * ex2;              // y * e^(x^2)
		sum_y += y[i];                       // y
	}
	
	// Matriz A
	a[0][0] = sum_e2x2; // ?(e^(2x^2))
	a[0][1] = sum_ex2;  // ?(e^(x^2))
	a[1][0] = sum_ex2;  // ?(e^(x^2))
	a[1][1] = n;        // Número de puntos
	
	// Vector b
	b[0] = sum_yex2;    // ?(y * e^(x^2))
	b[1] = sum_y;       // ?y
	
	// Imprimir matriz A y vector b
	printf("Matriz A:\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%lf\t", a[i][j]);
		}
		printf("\n");
	}
	printf("Vector b:\n");
	for (int i = 0; i < 2; i++) {
		printf("%lf\t", b[i]);
	}
	
	// Resolver el sistema Ax = b
	gauss_pivot(a, b, x1, 1);
	
	// Imprimir resultados
	printf("\nParámetros ajustados:\n");
	printf("a = %lf\n", x1[0]);
	printf("b = %lf\n", x1[1]);
	
	return 0;
}

void gauss_pivot(double a[100][100], double b[100], double x[100], int p) {
	int swap;
	double factor, sum;
	for (int i = 0; i < p; i++) {
		for (int j = i + 1; j < p + 1; j++) {
			int r = i;
			if (abs(a[i][i]) < 10e-5) {
				for (int l = i + 1; l < p + 1; l++) {
					if (abs(a[l][i]) > abs(a[i][i])) {
						r = l;
					}
				}
				for (int m = 0; m < p + 1; m++) {
					swap = a[r][m];
					a[r][m] = a[i][m];
					a[i][m] = swap;
				}
				swap = b[r];
				b[r] = b[i];
				b[i] = swap;
			}
			factor = -(a[j][i] / a[i][i]);
			for (int k = i; k < p + 1; k++) {
				a[j][k] = factor * a[i][k] + a[j][k];
			}
			b[j] = factor * b[i] + b[j];
		}
	}
	int prod = 1;
	for (int i = 0; i < p + 1; i++) {
		prod = prod * a[i][i];
	}
	if (prod == 0) {
		printf("No tiene solucion unica");
		exit(1);
	}
	x[p] = b[p] / a[p][p];
	for (int i = p - 1; i > -1; i--) {
		sum = b[i];
		for (int j = i + 1; j < p + 1; j++) {
			sum = sum - a[i][j] * x[j];
		}
		sum = sum / a[i][i];
		x[i] = sum;
	}
}
