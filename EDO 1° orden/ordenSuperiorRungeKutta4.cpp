#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Definimos las funciones del sistema
double f1(double x, double y, double v) {
	return v; // dy/dx = v
}

double f2(double x, double y, double v) {
	return -2 * v - 5 * y; // dv/dx = -2v - 5y
}

int main() {
	double x = 0, y = 0, v = 2; // Condiciones iniciales
	double h = 0.01;           // Tamaño del paso
	int n = 100;               // Número de pasos (de 0 a 1 con h = 0.01)
	
	cout << setw(10) << "x" << setw(15) << "y (RK4)" << setw(15) << "y (exacta)" << endl;
	cout << "-------------------------------------------------" << endl;
	
	for (int i = 0; i <= n; i++) {
		// Solución exacta
		double y_exacta = exp(-x) * sin(2 * x);
		
		// Imprimir los valores
		cout << setw(10) << x << setw(15) << y << setw(15) << y_exacta << endl;
		
		// Método de Runge-Kutta de cuarto orden
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
