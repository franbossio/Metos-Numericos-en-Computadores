#include <stdio.h>
#include <math.h>

// Tope de iteraciones: es una seguridad para no colgar el programa.
// CAMBIAR si el ejercicio/la profe pide un limite de iteraciones puntual
// (ej: "maximo 10 iteraciones"), sino dejar un numero grande.
#define MAX_ITERACIONES 10000

double f(double);
double fPrima(double);
void NewtonRaphson();

int main() {
    NewtonRaphson();
    return 0;
}

// ---- Cosas que hay que revisar/tocar para cambiar de problema ----
// 1) El cuerpo de f(x) y fPrima(x) (la derivada de f).
// 2) MAX_ITERACIONES arriba, si el ejercicio pide un limite especifico.
double f(double x) {
    return x*x - 4;
}
double fPrima(double x) {
    return 2*x;
}
// ------------------------------------------------------------------

void NewtonRaphson() {
    double xViejo, xNuevo, tolerancia, error = 0;
    int contador = 0;

    printf("Ingrese la tolerancia\n");
    scanf("%lf", &tolerancia);
    printf("Ingrese el punto inicial\n");
    scanf("%lf", &xViejo);

    do {
        contador++;

        double derivada = fPrima(xViejo);

        if (fabs(derivada) < 1e-10) {
            printf("\n********\nDERIVADA CERCANA A CERO: el metodo no puede continuar desde x = %.10lf\n********\n", xViejo);
            xNuevo = xViejo;
            break;
        }

        xNuevo = xViejo - (f(xViejo) / derivada);
        error = fabs(xNuevo - xViejo);
        xViejo = xNuevo;

    } while (error > tolerancia && contador < MAX_ITERACIONES);

    printf("\n\nLa raiz de f es: %.10lf", xNuevo);
    printf("\nEl valor del error en la raiz es de: %.10lf", error);
    printf("\nLa resolucion del problema tomo %d iteraciones\n", contador);

    if (contador >= MAX_ITERACIONES) {
        printf("Aviso: se alcanzo el limite de iteraciones sin llegar a la tolerancia pedida.\n");
    }
}
