#include <stdio.h>
#include <math.h>

// Tamano maximo de sistema soportado.
// CAMBIAR ESTOS VALORES si el sistema tiene mas de 20 ecuaciones/incognitas
// (COLUMNAS siempre tiene que ser FILAS + 1, por la columna de terminos independientes).
#define FILAS 20
#define COLUMNAS 21

void leerSistema(double m[FILAS][COLUMNAS], int filas);
void matrizA(double a[FILAS][COLUMNAS], double m[FILAS][COLUMNAS], int filas);
void matrizB(double b[FILAS], double m[FILAS][COLUMNAS], int filas);
void triangulacion(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas);
void retrosustitucion(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas);
void pivot(double a[FILAS][COLUMNAS], double b[FILAS], int filas, int i);
double determinante(double a[FILAS][COLUMNAS], int filas);

int main() {
    double m[FILAS][COLUMNAS];
    double a[FILAS][COLUMNAS];
    double b[FILAS];
    double x[FILAS];
    int filas;

    printf("Ingrese la cantidad de ecuaciones/incognitas del sistema: ");
    scanf("%d", &filas);

    leerSistema(m, filas);
    matrizA(a, m, filas);
    matrizB(b, m, filas);
    triangulacion(a, b, x, filas);

    return 0;
}

// Pide la matriz aumentada: cada fila son los coeficientes de la ecuacion
// seguidos del termino independiente (ej: para "3x+y+z=5" se ingresa 3 1 1 5).
void leerSistema(double m[FILAS][COLUMNAS], int filas) {
    printf("Ingrese la matriz aumentada (por fila: %d coeficientes + el termino independiente):\n", filas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j <= filas; j++) {
            scanf("%lf", &m[i][j]);
        }
    }
}

void matrizA(double a[FILAS][COLUMNAS], double m[FILAS][COLUMNAS], int filas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < filas; j++) {
            a[i][j] = m[i][j];
        }
    }
}

void matrizB(double b[FILAS], double m[FILAS][COLUMNAS], int filas) {
    for (int i = 0; i < filas; i++) {
        b[i] = m[i][filas];
    }
}

void triangulacion(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas) {
    for (int i = 0; i < filas - 1; i++) {
        pivot(a, b, filas, i);

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

    double norma = determinante(a, filas);
    if (norma == 0.0) {
        printf("\nMatriz singular (determinante = 0)\n");
    } else {
        retrosustitucion(a, b, x, filas);
    }
}

void retrosustitucion(double a[FILAS][COLUMNAS], double b[FILAS], double x[FILAS], int filas) {
    x[filas - 1] = b[filas - 1] / a[filas - 1][filas - 1];

    for (int i = filas - 2; i >= 0; --i) {
        double suma = 0;
        for (int j = i + 1; j < filas; ++j) {
            suma += a[i][j] * x[j];
        }
        x[i] = (b[i] - suma) / a[i][i];
    }

    printf("\nConjunto solucion:\n");
    for (int i = 0; i < filas; ++i) {
        printf("x%d = %lf\n", i + 1, x[i]);
    }
}

// Pivoteo parcial: si a[i][i] es (casi) cero, busca en las filas de abajo
// la de mayor valor absoluto en esa columna y la intercambia con la fila i.
void pivot(double a[FILAS][COLUMNAS], double b[FILAS], int filas, int i) {
    if (fabs(a[i][i]) < 1e-4) {
        for (int j = i + 1; j < filas; j++) {
            if (fabs(a[j][i]) > fabs(a[i][i])) {
                for (int k = i; k < filas; ++k) {
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

double determinante(double a[FILAS][COLUMNAS], int filas) {
    double norma = 1;
    for (int i = 0; i < filas; i++) {
        norma = norma * a[i][i];
    }
    printf("\nEl determinante de la matriz triangulada es: %lf\n", norma);
    return norma;
}
