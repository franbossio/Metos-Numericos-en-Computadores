#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Tamano maximo de sistema soportado.
// CAMBIAR ESTE VALOR si el sistema tiene mas de 20 ecuaciones/incognitas.
#define FILAS 20

// Tope de iteraciones: es una seguridad para no colgar el programa.
// CAMBIAR si el ejercicio/la profe pide un limite de iteraciones puntual
// (ej: "maximo 10 iteraciones"), sino dejar un numero grande.
#define MAX_ITERACIONES 10000

void leerSistema(double a[FILAS][FILAS], double b[FILAS], int filas);
void jacobi(double a[FILAS][FILAS], double b[FILAS], int filas);
void gaussSeidel(double a[FILAS][FILAS], double b[FILAS], int filas);
void relajacion(double a[FILAS][FILAS], double b[FILAS], int filas);
bool diagonalmenteDominante(double a[FILAS][FILAS], int filas);

int main() {
    double a[FILAS][FILAS];
    double b[FILAS];
    int filas, scanner;

    printf("Ingrese la cantidad de ecuaciones/incognitas del sistema: ");
    scanf("%d", &filas);
    leerSistema(a, b, filas);

    printf("\nSeleccione:\n 1 --> Jacobi \n 2 --> Gauss Seidel \n 3 --> Gauss Seidel con Relajacion\n");
    scanf("%d", &scanner);

    switch (scanner) {
        case 1:
            jacobi(a, b, filas);
            break;
        case 2:
            gaussSeidel(a, b, filas);
            break;
        case 3:
            relajacion(a, b, filas);
            break;
        default:
            printf("\nSe selecciono mal la opcion\n");
    }

    return 0;
}

// Pide la matriz del sistema: cada fila son los coeficientes de la ecuacion
// seguidos del termino independiente (ej: para "3x+y+z=5" se ingresa 3 1 1 5).
void leerSistema(double a[FILAS][FILAS], double b[FILAS], int filas) {
    printf("Ingrese el sistema (por fila: %d coeficientes + el termino independiente):\n", filas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < filas; j++) {
            scanf("%lf", &a[i][j]);
        }
        scanf("%lf", &b[i]);
    }
}

void jacobi(double a[FILAS][FILAS], double b[FILAS], int filas) {
    printf("\n\n***Ha seleccionado metodo de Jacobi***\n\n");

    if (!diagonalmenteDominante(a, filas))
        exit(0);

    double* xNuevo = (double*)malloc(filas * sizeof(double));
    double* xViejo = (double*)malloc(filas * sizeof(double));
    if (xNuevo == NULL || xViejo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < filas; i++) {
        xViejo[i] = 0.0;
        xNuevo[i] = 0.0;
    }

    double tolerancia;
    int iteraciones = 0;
    printf("\nIngrese la tolerancia\n");
    scanf("%lf", &tolerancia);

    double error;
    do {
        iteraciones++;
        for (int i = 0; i < filas; i++) {
            double suma = 0;
            for (int j = 0; j < filas; j++) {
                if (j != i)
                    suma += a[i][j] * xViejo[j];
            }
            xNuevo[i] = (b[i] - suma) / a[i][i];
        }

        double sumaError = 0;
        for (int i = 0; i < filas; i++) {
            sumaError += (xNuevo[i] - xViejo[i]) * (xNuevo[i] - xViejo[i]);
        }
        error = sqrt(sumaError);

        for (int i = 0; i < filas; i++) {
            xViejo[i] = xNuevo[i];
        }
    } while (error > tolerancia && iteraciones < MAX_ITERACIONES);

    printf("\nEl resultado es: \nxnuevo = [\t");
    for (int i = 0; i < filas; i++) {
        printf("%lf\t", xNuevo[i]);
    }
    printf("]\nLa cantidad de iteraciones fueron: %d \nEl error es de %lf\n", iteraciones, error);

    if (iteraciones >= MAX_ITERACIONES) {
        printf("Aviso: se alcanzo el limite de iteraciones sin llegar a la tolerancia pedida.\n");
    }

    free(xNuevo);
    free(xViejo);
}

void gaussSeidel(double a[FILAS][FILAS], double b[FILAS], int filas) {
    printf("\n\n***Ha seleccionado metodo de Gauss Seidel***\n\n");

    if (!diagonalmenteDominante(a, filas))
        exit(0);

    double* xNuevo = (double*)malloc(filas * sizeof(double));
    double* xViejo = (double*)malloc(filas * sizeof(double));
    if (xNuevo == NULL || xViejo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < filas; i++) {
        xViejo[i] = 0.0;
        xNuevo[i] = 0.0;
    }

    double tolerancia;
    int iteraciones = 0;
    printf("\nIngrese la tolerancia\n");
    scanf("%lf", &tolerancia);

    double error;
    do {
        iteraciones++;
        for (int i = 0; i < filas; i++) {
            double suma = 0;
            for (int j = 0; j < i; j++) {
                suma += a[i][j] * xNuevo[j];
            }
            for (int j = i + 1; j < filas; j++) {
                suma += a[i][j] * xViejo[j];
            }
            xNuevo[i] = (b[i] - suma) / a[i][i];
        }

        double sumaError = 0;
        for (int i = 0; i < filas; i++) {
            sumaError += (xNuevo[i] - xViejo[i]) * (xNuevo[i] - xViejo[i]);
        }
        error = sqrt(sumaError);

        for (int i = 0; i < filas; i++) {
            xViejo[i] = xNuevo[i];
        }
    } while (error > tolerancia && iteraciones < MAX_ITERACIONES);

    printf("\nEl resultado es: \nxnuevo = [\t");
    for (int i = 0; i < filas; i++) {
        printf("%lf\t", xNuevo[i]);
    }
    printf("]\nLa cantidad de iteraciones fueron: %d \nEl error es de %lf\n", iteraciones, error);

    if (iteraciones >= MAX_ITERACIONES) {
        printf("Aviso: se alcanzo el limite de iteraciones sin llegar a la tolerancia pedida.\n");
    }

    free(xNuevo);
    free(xViejo);
}

void relajacion(double a[FILAS][FILAS], double b[FILAS], int filas) {
    printf("\n\n***Ha seleccionado metodo de Gauss Seidel con Coeficiente de Relajacion***\n\n");

    if (!diagonalmenteDominante(a, filas))
        exit(0);

    double* xNuevo = (double*)malloc(filas * sizeof(double));
    double* xViejo = (double*)malloc(filas * sizeof(double));
    if (xNuevo == NULL || xViejo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < filas; i++) {
        xViejo[i] = 0.0;
        xNuevo[i] = 0.0;
    }

    double tolerancia;
    double factorRelajacion;
    int iteraciones = 0;
    printf("\nIngrese la tolerancia\n");
    scanf("%lf", &tolerancia);
    printf("\nIngrese el factor de relajacion\n");
    scanf("%lf", &factorRelajacion);

    double error;
    do {
        iteraciones++;
        for (int i = 0; i < filas; i++) {
            double suma = 0;
            for (int j = 0; j < i; j++) {
                suma += a[i][j] * xNuevo[j];
            }
            for (int j = i + 1; j < filas; j++) {
                suma += a[i][j] * xViejo[j];
            }
            double gaussSeidelValor = (b[i] - suma) / a[i][i];
            xNuevo[i] = factorRelajacion * gaussSeidelValor + (1 - factorRelajacion) * xViejo[i];
        }

        double sumaError = 0;
        for (int i = 0; i < filas; i++) {
            sumaError += (xNuevo[i] - xViejo[i]) * (xNuevo[i] - xViejo[i]);
        }
        error = sqrt(sumaError);

        for (int i = 0; i < filas; i++) {
            xViejo[i] = xNuevo[i];
        }
    } while (error > tolerancia && iteraciones < MAX_ITERACIONES);

    printf("\nEl resultado es: \nxnuevo = [\t");
    for (int i = 0; i < filas; i++) {
        printf("%lf\t", xNuevo[i]);
    }
    printf("]\nLa cantidad de iteraciones fueron: %d \nEl error es de %lf\n", iteraciones, error);

    if (iteraciones >= MAX_ITERACIONES) {
        printf("Aviso: se alcanzo el limite de iteraciones sin llegar a la tolerancia pedida.\n");
    }

    free(xNuevo);
    free(xViejo);
}

// Chequea ceros en la diagonal (eso si corta la ejecucion, division por cero
// asegurada) y avisa (sin cortar) si la matriz no es diagonalmente dominante,
// porque ahi no esta garantizada la convergencia de Jacobi/Gauss-Seidel.
bool diagonalmenteDominante(double a[FILAS][FILAS], int filas) {
    for (int i = 0; i < filas; i++) {
        double suma = 0;
        for (int j = 0; j < filas; j++) {
            if (j != i)
                suma += fabs(a[i][j]);
        }

        if (fabs(a[i][i]) < suma)
            printf("\nLa matriz no es diagonalmente dominante. Fila: %d\n", i + 1);

        if (a[i][i] == 0) {
            printf("\nHay un cero en la diagonal (fila %d): no se puede continuar.\n", i + 1);
            return false;
        }
    }
    return true;
}
