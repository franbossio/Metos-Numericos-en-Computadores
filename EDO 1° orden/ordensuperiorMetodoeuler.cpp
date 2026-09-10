#include <stdio.h>
#include <math.h>

// ==================== CAMBIAR EN CADA EJERCICIO ====================
// Unica parte que hay que tocar a mano: el sistema equivalente a la EDO de
// orden superior (y=y1, v=y'=dy1/dx) y, si se conoce, la solucion exacta
// para comparar el error.
// Ejemplo resuelto: y''+2y'+5y=0  =>  v'=-2v-5y
double f1(double y, double v) {
	return v; // dy/dx = v
}
double f2(double y, double v) {
	return -2 * v - 5 * y; // dv/dx = -2v - 5y
}
double solucion_exacta(double x) {
	return exp(-x) * sin(2 * x);
}
// =====================================================================

int main() {
	double x0, x_final, y0, v0, h;

	printf("Ingresar x inicial (x0): ");
	scanf("%lf", &x0);
	printf("Ingresar x final: ");
	scanf("%lf", &x_final);
	printf("Ingresar y(x0): ");
	scanf("%lf", &y0);
	printf("Ingresar y'(x0): ");
	scanf("%lf", &v0);
	printf("Ingresar h (paso): ");
	scanf("%lf", &h);

	double x = x0, y = y0, v = v0;
	int n = (int)((x_final - x0) / h); // Numero de pasos

	// Encabezado para la tabla
	printf("%10s %15s %15s %15s\n", "x", "y (Euler)", "y (Exacta)", "Error");
	printf("---------------------------------------------------------------\n");

	// Metodo de Euler
	for (int i = 0; i <= n; i++) {
		// Solucion exacta
		double y_exacta = solucion_exacta(x);

		// Imprimir los valores actuales
		printf("%10.2f %15.6f %15.6f %15.6f\n", x, y, y_exacta, fabs(y - y_exacta));

		// Actualizar valores con el metodo de Euler
		double y_new = y + h * f1(y, v); // y(n+1) = y(n) + h * dy/dx
		double v_new = v + h * f2(y, v); // v(n+1) = v(n) + h * dv/dx

		y = y_new;
		v = v_new;
		x += h; // Incremento de x
	}

	return 0;
}
