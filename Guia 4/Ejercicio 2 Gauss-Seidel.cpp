#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;


void jacobi (double a[4][4] , double b[4], int filas);
void gaussSeidel (double a[4][4] , double b[4], int filas);
void relajacion (double a[4][4] , double b[4], int filas);
bool diagonalmenteDominante(double a[4][4], int filas);


int main(int argc, char* argv[])
{
	double a[4][4]={{5,7,6,5},{7,10,8,7},{6,8,10,9},{5,7,9,10}};
	double b[4]={23,32,33,31};
	int scanner;
	printf("Seleccione:\n 1 --> Jacobi \n 2 --> Gauss Seidel \n 3 --> Gauss Seidel con Relajacion\n");
	scanf("%d",&scanner);
	switch(scanner){
		case 1:
			jacobi(a,b,3);
			break;
			
		case 2: 
			gaussSeidel(a,b,3);
			break;
		case 3: 
			relajacion(a,b,3);
			break;
			
		default: 
			printf("\n Se seleccionó mal la opcion");
	}
	

}
	
void jacobi(double a[4][4] , double b[4] , int filas){
	printf("\n\n***Ha seleccionado método de jacobi***\n\n");
	
	bool check = diagonalmenteDominante(a,filas);
	if(!check)
		exit(0);
	
	double suma = 0; 
	double* xNuevo = (double*)malloc(filas * sizeof(double));
	double* xViejo = (double*)malloc(filas * sizeof(double));
	
	if(xNuevo == NULL || xViejo == NULL){
		printf("Error: No se pudo asignar memoria.\n");
		exit(1);
	}
	
	for (int i = 0; i < filas; i++) {
		xViejo[i] = 0.0;
		xNuevo[i] = xViejo[i];
	}
	
	double error;
	double tolerancia;
	int iteraciones = 0;
	printf("\nIngrese la tolerancia\n");
	scanf("%lf", &tolerancia);
	
	do {
		iteraciones++;
		for (int i = 0; i < filas; i++) {
			suma = 0;
			for (int j = 0; j < filas; j++) {
				if (j != i)
					suma += a[i][j] * xViejo[j];
			}
			xNuevo[i] = (b[i] - suma) / a[i][i];
		}
		
		// Manejo del error
		suma = 0;
		for (int i = 0; i < filas; i++) {
			suma += (xNuevo[i] - xViejo[i]) * (xNuevo[i] - xViejo[i]);
		}
		error = sqrt(suma);
		
		// Reasignación del vector viejo para la próxima pasada.
		for (int i = 0; i < filas; i++) {
			xViejo[i] = xNuevo[i];
		}
	} while (error > tolerancia && iteraciones < 10000);
	
	printf("\n El resultado es: \nxnuevo = [\t");
	for (int i = 0; i < filas; i++) {
		printf("%lf\t", xNuevo[i]);
	}
	
	printf("]\n La cantidad de iteraciones fueron: %d \n El error es de %lf", iteraciones, error);
}
void gaussSeidel (double a[4][4] , double b[4], int filas){
	printf("\n\n***Ha seleccionado método de Gauss Seidel***\n\n");
	
	bool check = diagonalmenteDominante(a,filas);
	if(!check)
		exit(0);
	
	double suma = 0; 
	double* xNuevo = (double*)malloc(filas * sizeof(double));
	double* xViejo = (double*)malloc(filas * sizeof(double));
	
	if(xNuevo == NULL || xViejo == NULL){
		printf("Error: No se pudo asignar memoria.\n");
		exit(1);
	}
	
	for (int i = 0; i < filas; i++) {
		xViejo[i] = 0.0;
		xNuevo[i] = xViejo[i];
	}
	
	double error;
	double tolerancia;
	int iteraciones = 0;
	printf("\nIngrese la tolerancia\n");
	scanf("%lf", &tolerancia);
	
	do {
		iteraciones++;
		for (int i = 0; i < filas; i++) {
			suma = 0;
			if(i == 0){
				for(int j = 1 ; j < filas ; j++){
					suma+= a[i][j] * xNuevo[j];
				}
				xNuevo[i] = (b[i] - suma)/a[i][i]; 
			}else{
				for(int j = 0 ; j < i  ; j++){
					suma += a[i][j] * xNuevo[j];
				}
				
				for(int j = i+1 ; j < filas ; j++){
					suma+= a[i][j] * xViejo[j]; 
				}
				
				xNuevo[i] = (b[i] - suma)/a[i][i];
			}
		}
		
		// Manejo del error
		suma = 0;
		for (int i = 0; i < filas; i++) {
			suma += (xNuevo[i] - xViejo[i]) * (xNuevo[i] - xViejo[i]);
		}
		error = sqrt(suma);
		
		// Reasignación del vector viejo para la próxima pasada.
		for (int i = 0; i < filas; i++) {
			xViejo[i] = xNuevo[i];
		}
	} while (error > tolerancia && iteraciones < 10000);
	
	printf("\n El resultado es: \nxnuevo = [\t");
	for (int i = 0; i < filas; i++) {
		printf("%lf\t", xNuevo[i]);
	}
	
	printf("]\n La cantidad de iteraciones fueron: %d \n El error es de %lf", iteraciones, error);
}
	
void relajacion (double a[4][4] , double b[4], int filas){
	printf("\n\n***Ha seleccionado método de Gauss Seidel con Coeficiente de Relajacion***\n\n");
	bool check = diagonalmenteDominante(a,filas);
	if(!check)
		exit(0);
	
	double suma = 0; 
	double* xNuevo = (double*)malloc(filas * sizeof(double));
	double* xViejo = (double*)malloc(filas * sizeof(double));
	
	if(xNuevo == NULL || xViejo == NULL){
		printf("Error: No se pudo asignar memoria.\n");
		exit(1);
	}
	
	for (int i = 0; i < filas; i++) {
		xViejo[i] = 0.0;
		xNuevo[i] = xViejo[i];
	}
	
	double error;
	double tolerancia;
	int iteraciones = 0;
	float factor_relajacion;
	printf("\nIngrese la tolerancia\n");
	scanf("%lf", &tolerancia);
	printf("\nIngrese el factor relajacion\n");
	scanf("%f", &factor_relajacion);
	
	do {
		iteraciones++;
		for (int i = 0; i < filas; i++) {
			suma = 0;
			if(i == 0){
				for(int j = 1 ; j < filas ; j++){
					suma+= a[i][j] * xNuevo[j];
				}
				xNuevo[i] = (b[i] - suma)/a[i][i];
				xNuevo[i] = factor_relajacion * xNuevo[i] + (1-factor_relajacion) * xViejo[i]; 
			}else{
				for(int j = 0 ; j < i  ; j++){
					suma += a[i][j] * xNuevo[j];
				}
				
				for(int j = i+1 ; j < filas ; j++){
					suma+= a[i][j] * xViejo[j]; 
				}
				
				xNuevo[i] = (b[i] - suma)/a[i][i];
				xNuevo[i] = factor_relajacion * xNuevo[i] + (1-factor_relajacion) * xViejo[i]; 
			}
		}
		
		// Manejo del error
		suma = 0;
		for (int i = 0; i < filas; i++) {
			suma += (xNuevo[i] - xViejo[i]) * (xNuevo[i] - xViejo[i]);
		}
		error = sqrt(suma);
		
		// Reasignación del vector viejo para la próxima pasada.
		for (int i = 0; i < filas; i++) {
			xViejo[i] = xNuevo[i];
		}
	} while (error > tolerancia && iteraciones < 10000);
	
	printf("\n El resultado es: \nxnuevo = [\t");
	for (int i = 0; i < filas; i++) {
		printf("%lf\t", xNuevo[i]);
	}
	
	printf("]\n La cantidad de iteraciones fueron: %d \n El error es de %lf", iteraciones, error);

}
bool diagonalmenteDominante(double a[4][4], int filas){
	double suma = 0; 
	int counter = 0;
	for(int i = 0; i < filas ; i++){
		suma = 0; 
		counter++;
		for(int j = 0 ; j < filas ; j++){
			if(j!=i){
				suma+= fabs(a[i][j]);
			}
		}
		
		if(fabs(a[i][i]) < suma)
			printf("\nLa matriz no es diagonalmente dominante. Fila: %d",counter);
		
		if(a[i][i] == 0){
			printf("\nCeros en la diagonal");
			return false;
		}
	}
	return true;
}
