#include <stdio.h>
#include <math.h>

double f(double);
double fPrima(double);
void NewtonRaphson();


int main (){
    NewtonRaphson();
    return 0;
}

double f(double x){
    return x*x -4;////
}
double fPrima(double x){
    return 2*x;////
}
void NewtonRaphson(){
    double xViejo , error , tolerancia , xNuevo;
    int contador = 0;
    printf("Ingrese la tolerancia\n"); 
    scanf("%lf", &tolerancia);
    printf("Ingrese el punto inicial\n"); 
    scanf("%lf", &xViejo);
    do{
        contador ++ ;
		xNuevo = xViejo - (f(xViejo)/fPrima(xViejo));
        if(abs(fPrima(xNuevo)) < 1e-10){
            printf("\n********\nDERIVADA GRANDE********\n");
            break;
        } 
		
		error = abs(xNuevo - xViejo);
		xViejo = xNuevo;
        

    }while(error > tolerancia && contador < 10000 );

    printf("\n\n\nLa raiz de f es: %.10lf", xNuevo);
    printf("\nEl valor del error en la raiz es de: %.10lf", error);
    printf("\nLa resolucion del problema %d iteraciones", contador);
}
