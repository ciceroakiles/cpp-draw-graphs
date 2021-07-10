/*
 * Métodos de desenho geral e teste
 */

#include "assign.h"
#include "formula.h"
#include "print.h"

void tests();

// Desenho da grade
void show_grid() {
	setcolor(GRID_COLOR);
	floodfill(0, 0, GRID_COLOR);
	// Linhas
	for (int i = 0; i <= WIDTH; i += g.getScale()) {
		line(i, 0, i, HEIGHT);
	}
	for (int i = 0; i <= HEIGHT; i += g.getScale()) {
		line(0, i, WIDTH, i);
	}
	// Eixos X e Y
	setcolor(AXIS_COLOR);
	line(0, HEIGHT/2, WIDTH, HEIGHT/2);
	line(WIDTH/2, 0, WIDTH/2, HEIGHT);
	
	tests();
}

// Redesenho de tudo
void redraw(vector<Funct> &vf, vector<Point> &ps) {
	cleardevice();
	show_grid();
	setcolor(0);
	// Pontos
	for (int i = 0; i < ps.size(); i++) {
		if (g.getDots()) ps[i].draw(POINT_R);
	}
	// Funções
	for (int i = 0; i < vf.size(); i++) {
		setcolor((i+1) % 14);
		vf[i].draw_fun();
	}
}

void tests() {
	
}

