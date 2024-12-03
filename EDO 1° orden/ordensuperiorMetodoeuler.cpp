#include <stdio.h>
#include <math.h>

// Función para la derivada de y
double f1(double y, double v) {
	return v; // dy/dx = v
}

// Función para la derivada de v
double f2(double y, double v) {
	return -2 * v - 5 * y; // dv/dx = -2v - 5y
}

// Solución exacta
double solucion_exacta(double x) {
	return exp(-x) * sin(2 * x);
}

int main() {
	// Condiciones iniciales
	double x = 0, y = 0, v = 2; // x0 = 0, y0 = 0, v0 = 2
	double h = 0.01;            // Tamaño del paso
	double x_final = 1;         // Valor final de x
	int n = (int)(x_final / h); // Número de pasos
	
	// Encabezado para la tabla
	printf("%10s %15s %15s %15s\n", "x", "y (Euler)", "y (Exacta)", "Error");
	printf("---------------------------------------------------------------\n");
	
	// Método de Euler
	for (int i = 0; i <= n; i++) {
		// Solución exacta
		double y_exacta = solucion_exacta(x);
		
		// Imprimir los valores actuales
		printf("%10.2f %15.6f %15.6f %15.6f\n", x, y, y_exacta, fabs(y - y_exacta));
		
		// Actualizar valores con el método de Euler
		double y_new = y + h * f1(y, v); // y(n+1) = y(n) + h * dy/dx
		double v_new = v + h * f2(y, v); // v(n+1) = v(n) + h * dv/dx
		
		y = y_new;
		v = v_new;
		x += h; // Incremento de x
	}
	
	return 0;
}
