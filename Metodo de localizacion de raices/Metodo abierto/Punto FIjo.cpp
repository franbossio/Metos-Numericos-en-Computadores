#include <stdio.h>
#include <math.h>

// Tope de iteraciones: es una seguridad para no colgar el programa.
// CAMBIAR si el ejercicio/la profe pide un limite de iteraciones puntual
// (ej: "maximo 10 iteraciones"), sino dejar un numero grande.
#define MAX_ITERACIONES 10000

double g(double);
void PuntoFijo();

int main() {
    PuntoFijo();
    return 0;
}

// ---- Cosas que hay que revisar/tocar para cambiar de problema ----
// 1) El cuerpo de esta funcion g(x) (tiene que ser la forma despejada x=g(x)).
//    El punto inicial no importa mucho, va a converger igual salvo que |g'(x)|>=1.
// 2) MAX_ITERACIONES arriba, si el ejercicio pide un limite especifico.
double g(double x) {
    return exp(-x);
}
// ------------------------------------------------------------------

void PuntoFijo() {
    double xViejo, xNuevo, tolerancia, error = 0;
    int contador = 0;

    printf("Ingrese la tolerancia\n");
    scanf("%lf", &tolerancia);
    printf("Ingrese el punto inicial\n");
    scanf("%lf", &xViejo);

    do {
        contador++;
        xNuevo = g(xViejo);

        double derivadaAprox = (g(xViejo + 0.01) - g(xViejo)) / 0.01;
        if (fabs(derivadaAprox) > 1) {
            printf("\n\nNo cumple con el criterio de convergencia. El metodo diverge (|g'(x)|>1) en x = %.10lf\n", xViejo);
            break;
        }

        error = fabs(xNuevo - xViejo);
        xViejo = xNuevo;

    } while (error > tolerancia && contador < MAX_ITERACIONES);

    printf("\n\nEl punto fijo de g(x), es decir la raiz de f, es: %.10lf", xNuevo);
    printf("\nEl valor del error en la raiz es de: %.10lf", error);
    printf("\nLa resolucion del problema tomo %d iteraciones\n", contador);

    if (contador >= MAX_ITERACIONES) {
        printf("Aviso: se alcanzo el limite de iteraciones sin llegar a la tolerancia pedida.\n");
    }
}
