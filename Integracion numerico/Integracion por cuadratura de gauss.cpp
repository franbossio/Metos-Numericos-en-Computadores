#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;
//declarar funcion
double f(double x);

int main(int argc, char *argv[]) {
	double a,b, c0,c1,c2,c3,c4,c5,x0,x1,x2,x3,x4,x5,I/*,Iexacta,error*/;
	int puntos;
	printf("Ingresar los limites de integracion: ");
	scanf(" %lf", &a);
	scanf(" %lf", &b);
	
	//Ingresar la integral exacta si te la dan
	/*printf("Ingresar la integral exacta: ");
	scanf(" %lf", &Iexacta);*/
	//calcular I
	printf("Ingresar la cantidad de puntos a usar(entre 2 y 6): ");
	scanf(" %d", &puntos);
	
	switch(puntos){
	case 2:
		c0=1;
		c1=1;
		x0=-0.577350269;
		x1=-x0;
		I=((b-a)/2)*(c0*f(((b-a)/2)*x0+((b+a)/2))+c1*f(((b-a)/2)*x1+((b+a)/2)));
		break;
	case 3:
		c0=0.5555556;
		c1=0.8888889;
		c2=c0;
		x0=-0.774596669;
		x1=0;
		x2=-x0;
		I=((b-a)/2)*(c0*f(((b-a)/2)*x0+((b+a)/2))+c1*f(((b-a)/2)*x1+((b+a)/2))+c2*f(((b-a)/2)*x2+((b+a)/2)));
		break;
	case 4:
		c0=0.3478548;
		c1=0.6521452;
		c2=c1;
		c3=c0;
		x0=-0.861136312;
		x1=-0.339981044;
		x2=-x1;
		x3=-x0;
		I=((b-a)/2)*(c0*f(((b-a)/2)*x0+((b+a)/2))+c1*f(((b-a)/2)*x1+((b+a)/2))+c2*f(((b-a)/2)*x2+((b+a)/2))+c3*f(((b-a)/2)*x3+((b+a)/2)));
		break;
	case 5:
		c0=0.2369269;
		c1=0.4786287;
		c2=0.5688889;
		c3=c1;
		c4=c0;
		x0=-0.906179846;
		x1=-0.538469310;
		x2=0;
		x3=-x1;
		x4=-x0;
		I=((b-a)/2)*(c0*f(((b-a)/2)*x0+((b+a)/2))+c1*f(((b-a)/2)*x1+((b+a)/2))+c2*f(((b-a)/2)*x2+((b+a)/2))+c3*f(((b-a)/2)*x3+((b+a)/2))+c4*f(((b-a)/2)*x4+((b+a)/2)));
		break;
	case 6:
		c0=0.1713245;
		c1=0.3607616;
		c2=0.4679139;
		c3=c2;
		c4=c1;
		c5=c0;
		x0=-0.932469514;
		x1=-0.661209386;
		x2=-0.238619186;
		x3=-x2;
		x4=-x1;
		x5=-x0;
		I=((b-a)/2)*(c0*f(((b-a)/2)*x0+((b+a)/2))+c1*f(((b-a)/2)*x1+((b+a)/2))+c2*f(((b-a)/2)*x2+((b+a)/2))+c3*f(((b-a)/2)*x3+((b+a)/2))+c4*f(((b-a)/2)*x4+((b+a)/2))+c5*f(((b-a)/2)*x5+((b+a)/2)));
		break;
	default: 
		printf("Los puntos ingresado no estan entre 2 y 6");
		return 1;
	}
	//error=abs(Iexacta-I);
	
	printf("La integral es: %.2lf\n", I);//suma=Iaprox
	//printf("el error es: %.2lf", error);
	
	return 0;
}
double f(double x){
	//camia en cada problema
	return x;
}
