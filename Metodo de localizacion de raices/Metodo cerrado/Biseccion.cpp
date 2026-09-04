#include <stdio.h>
#include <math.h>

// Tope de iteraciones: es una seguridad para no colgar el programa.
// CAMBIAR si el ejercicio/la profe pide un limite de iteraciones puntual
// (ej: "maximo 10 iteraciones"), sino dejar un numero grande.
#define MAX_ITERACIONES 1000

double funcion(double x);
void biseccion();

int main() {
    biseccion();
    return 0;
}

// ---- Cosas que hay que revisar/tocar para cambiar de problema ----
// 1) El cuerpo de esta funcion.
// 2) MAX_ITERACIONES arriba, si el ejercicio pide un limite especifico.
double funcion(double x) {
    return -2 + 7*x - 5*pow(x,2) + 6*pow(x,3);
}
// ------------------------------------------------------------------

void biseccion() {
    double a, b, tolerancia;
    double fa, fb;

    do {
        printf("Ingrese el limite inferior del intervalo: ");
        scanf("%lf", &a);
        printf("Ingrese el limite superior del intervalo: ");
        scanf("%lf", &b);
        printf("Ingrese la tolerancia: ");
        scanf("%lf", &tolerancia);

        if (a > b) {
            double aux = a;
            a = b;
            b = aux;
        }

        fa = funcion(a);
        fb = funcion(b);

        if (fa == 0) {
            printf("\nLa raiz es exactamente el limite inferior: %.10lf\n", a);
            return;
        }
        if (fb == 0) {
            printf("\nLa raiz es exactamente el limite superior: %.10lf\n", b);
            return;
        }
        if (fa * fb >= 0) {
            printf("\nNo hay raiz o hay un numero par de ellas en ese intervalo. Intente de nuevo.\n\n");
        }

    } while (fa * fb >= 0);

    double c, fc, error;
    int iterator = 0;

    do {
        c = (a + b) / 2;
        fc = funcion(c);
        error = (b - a) / 2;

        if (fc == 0) {
            break;
        } else if (fa * fc > 0) {
            a = c;
            fa = fc;
        } else {
            b = c;
        }

        iterator++;

    } while (error > tolerancia && iterator < MAX_ITERACIONES);

    printf("\nResultado de la raiz: %.10lf", c);
    printf("\nError estimado: %.10lf", error);
    printf("\nCantidad de iteraciones: %d\n", iterator);

    if (iterator >= MAX_ITERACIONES) {
        printf("Aviso: se alcanzo el limite de iteraciones sin llegar a la tolerancia pedida.\n");
    }
}
