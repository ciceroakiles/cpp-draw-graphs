#include "__funct.h"
/*
 * Métodos que retornam funções
 */

// Retorna uma função de grau 1 ou 2 (adiciona os pontos sequencialmente)
Funct polinomial_t2(double params[]) {
	// params[0]: a, params[1]: b, params[2]: c
	Funct fn;                                  // Função que vai receber os pontos
	double step = (params[0] == 0) ? 1 : 0.25; // Intervalo de precisão entre os pontos
   	double x2, y1, y2, lim = WIDTH/2;          // Limites superior e inferior (metade da largura da janela)
   	for (double x1 = -lim; x1 < lim; x1 += step) {
   		x2 = x1 + step;
   		y1 = params[0]*x1*x1 + params[1]*x1 + params[2];
   		y2 = params[0]*x2*x2 + params[1]*x2 + params[2];
		Point p1(x1, y1);
	   	Point p2(x2, y2);
	   	fn.addPoint(p1);
	   	fn.addPoint(p2);
	}
	return fn;
}

// Retorna uma função do tipo círculo
Funct circle_t2(double params[]) {
	// params[0]: x_cen, params[1]: y_cen, params[2]: r
	Funct fn;
	Point p(params[0], params[1]);
	p.set_radius(params[2]);
	fn.addPoint(p);
	fn.setType('c');
	return fn;
}

/*
 * Métodos para desenho de grade
 */

// Desenho da grade
void show_grid() {
	setcolor(GRID_COLOR);
    floodfill(0, 0, GRID_COLOR);
	// Linhas
	for (int i = 0; i <= WIDTH; i += scale) {
		line(i, 0, i, HEIGHT);
	}
	for (int i = 0; i <= HEIGHT; i += scale) {
		line(0, i, WIDTH, i);
	}
	// Eixos X e Y
	setcolor(AXIS_COLOR);
	line(0, HEIGHT/2, WIDTH, HEIGHT/2);
	line(WIDTH/2, 0, WIDTH/2, HEIGHT);
}

// Redesenhar tudo
void redraw(vector<Funct> &vf) {
	cleardevice();
	show_grid();
	for (int i = 0; i < vf.size(); i++) {
		setcolor((i+1) % 14);
		vf[i].draw_fun();
	}
}

