/*
 * Atribui��o dos pontos �s fun��es
 */

#include <math.h>
#include "../classes/funct.h"

// Retorna uma fun��o de grau n
Funct polinomial_tn(vector<double> t) {
	Funct fn;                          // Fun��o que vai receber os pontos
	int n = t.size()-1;                // Grau da fun��o
	double step = (n < 2) ? 1 : 0.25;  // Intervalo de precis�o entre os pontos
	double lim = WIDTH/2;              // Limites superior e inferior (metade da largura da janela)
   	double x, y;
	for (x = -lim; x <= lim; x += step) {
   		y = 0;
   		// Soma dos termos t(i)x^(n-i)
		for (int i = 0; i <= n; i++) {
			y += t[i]*pow(x, (n-i));
		}
		Point p(x, y);
		fn.addPoint(p);
	}
	return fn;
}

// Retorna uma fun��o do tipo c�rculo
Funct circle_t2(vector<double> t) {
	Funct fn;
	Point p(t[0], t[1]);
	p.set_radius(t[2]);
	fn.addPoint(p);
	fn.setType("circle");
	return fn;
}

// Retorna uma fun��o trigonom�trica
double tr_select(double x, int t);
Funct trigonometric(int t) {
	Funct fn;             // Fun��o que vai receber os pontos
	double step = 0.25;   // Intervalo de precis�o entre os pontos
	double lim = WIDTH/2; // Limites superior e inferior (metade da largura da janela)
   	double x, y;
	for (x = -lim; x < lim; x += step) {
   		y = tr_select(x, t);
		Point p(x, y);
		fn.addPoint(p);
	}
	return fn;
}

// Procedimento auxiliar (escolha de fun��o)
double tr_select(double x, int t) {
	switch (t) {
		case 1: {
			return sin(x);
		} break;
		case 2: {
			return cos(x);
		} break;
	}
	return 0;
}

