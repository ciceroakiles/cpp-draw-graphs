/*
 * Atribuição dos pontos às funções
 */

#include <math.h>
#include "../classes/funct.h"

// Retorna uma função de grau n
Funct polinomial_tn(vector<double> t) {
	Funct fn;                          // Função que vai receber os pontos
	int n = t.size()-1;                // Grau da função
	double step = (n >= 2) ? 0.25 : 1; // Intervalo de precisão entre os pontos
	double lim = WIDTH/2;              // Limites superior e inferior
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
	fn.linkAll();
	return fn;
}

// Retorna uma função do tipo círculo
Funct circle_t2(vector<double> t) {
	Funct fn;
	Point p(t[0], t[1]);
	p.set_radius(t[2]);
	fn.addPoint(p);
	fn.setType("circle");
	return fn;
}

// Retorna uma função trigonométrica
double tr_select(double x, int t);
Funct trigonometric(int t) {
	Funct fn;                            // Função que vai receber os pontos
	double step = (t < 3) ? 0.25 : 0.01; // Intervalo de precisão entre os pontos
	double lim = WIDTH/2;                // Limites superior e inferior
   	double x, y;
	for (x = -lim; x < lim; x += step) {
		y = tr_select(x, t);
		Point p(x, y);
		fn.addPoint(p);
	}
	if (t >= 3) fn.setType("trig3+");
	fn.linkAll();
	return fn;
}

// Procedimento auxiliar (escolha de função)
double tr_select(double x, int t) {
	switch (t) {
		case 1: {
			return sin(x);
		} break;
		case 2: {
			return cos(x);
		} break;
		case 3: {
			return tan(x);
		} break;
		case 4: {
			return 1/sin(x);
		} break;
		case 5: {
			return 1/cos(x);
		} break;
		case 6: {
			return 1/tan(x);
		} break;
	}
	return 0;
}

