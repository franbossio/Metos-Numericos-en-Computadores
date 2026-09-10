#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ==================== CAMBIAR EN CADA EJERCICIO ====================
// Unica parte que hay que tocar a mano: el sistema equivalente a la EDO de
// orden superior (y=y1, v=y'=dy1/dx) y, si se conoce, la solucion exacta
// para comparar el error.
// Ejemplo resuelto: y''+2y'+5y=0  =>  v'=-2v-5y
double f1(double x, double y, double v) {
	return v; // dy/dx = v
}
double f2(double x, double y, double v) {
	return -2 * v - 5 * y; // dv/dx = -2v - 5y
}
double solucion_exacta(double x) {
	return exp(-x) * sin(2 * x);
}
// =====================================================================

int main() {
	double x0, x_final, y0, v0, h;

	cout << "Ingresar x inicial (x0): ";
	cin >> x0;
	cout << "Ingresar x final: ";
	cin >> x_final;
	cout << "Ingresar y(x0): ";
	cin >> y0;
	cout << "Ingresar y'(x0): ";
	cin >> v0;
	cout << "Ingresar h (paso): ";
	cin >> h;

	double x = x0, y = y0, v = v0;
	int n = (int)((x_final - x0) / h); // Numero de pasos

	cout << setw(10) << "x" << setw(15) << "y (RK4)" << setw(15) << "y (exacta)" << endl;
	cout << "-------------------------------------------------" << endl;

	for (int i = 0; i <= n; i++) {
		// Solucion exacta
		double y_exacta = solucion_exacta(x);

		// Imprimir los valores
		cout << setw(10) << x << setw(15) << y << setw(15) << y_exacta << endl;

		// Metodo de Runge-Kutta de cuarto orden
		double k1y = h * f1(x, y, v);
		double k1v = h * f2(x, y, v);

		double k2y = h * f1(x + h / 2.0, y + k1y / 2.0, v + k1v / 2.0);
		double k2v = h * f2(x + h / 2.0, y + k1y / 2.0, v + k1v / 2.0);

		double k3y = h * f1(x + h / 2.0, y + k2y / 2.0, v + k2v / 2.0);
		double k3v = h * f2(x + h / 2.0, y + k2y / 2.0, v + k2v / 2.0);

		double k4y = h * f1(x + h, y + k3y, v + k3v);
		double k4v = h * f2(x + h, y + k3y, v + k3v);

		y += (k1y + 2 * k2y + 2 * k3y + k4y) / 6.0;
		v += (k1v + 2 * k2v + 2 * k3v + k4v) / 6.0;

		x += h;
	}

	return 0;
}
