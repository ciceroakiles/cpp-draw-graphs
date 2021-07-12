/*
 * Gráficos de funções com C++ e graphics.h
 * (input via console)
 */

#include <iostream>
#include "_menus.h"

int main() {
	// Funções salvas e pontos marcados
	vector<Funct> funcoes;
	vector<Point> pontos;
	// Janelas (console e gráficos)
	HWND window1, window2;
	// Inicia segunda janela e muda títulos
	initwindow(WIDTH+11, HEIGHT+15, "");
	system("title draw-graphs");
	window2 = FindWindow(NULL, "Windows BGI");
	SetWindowTextA(window2, TITLE);
	// Impede maximização da janela de gráficos
	DWORD style = GetWindowLong(window2, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(window2, GWL_STYLE, style);
	SetWindowPos(window2, NULL, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE|SWP_FRAMECHANGED);
	// Altera posição e dimensões do console
	window1 = GetConsoleWindow();
	MoveWindow(window1, WIDTH+4, 0, 500, HEIGHT+42, TRUE);
  	// Desenha grid
	graph.show_grid();
	// Volta ao console
	SetForegroundWindow(GetConsoleWindow());
	do {
		input(funcoes, pontos);
	} while (true);
    return 0;
}

