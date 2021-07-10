/*
 * Gr�ficos de fun��es com C++ e graphics.h
 * (input via console)
 */

#include <iostream>
#include "_submenus.h"

// Loop principal
void input(vector<Funct> &vf, vector<Point> &ps) {
	bool dont_pause = false;
	char op;
	// Menu
	menu_options();
	std::cin >> op;
	// Escolhas
	switch (op) {
		// Fun��es
		case 'f': {
			subm_fun(vf, ps);
			dont_pause = true;
		} break;
		// Pontos
		case 'p': {
			subm_pts(vf, ps);
			dont_pause = true;
		} break;
		// Mudar escala
		case 'e': {
			bool width_ok = false, height_ok = false;
			int scale;
			do {
				std::cout << std::endl << "Nova escala:\n>";
				std::cin >> scale;
				width_ok = ((WIDTH % scale == 0) && ((WIDTH/scale) % 2 == 0));
				height_ok = ((HEIGHT % scale == 0) && ((HEIGHT/scale) % 2 == 0));
				if (!width_ok || !height_ok) {
					std::cout << "[!] Escala com problemas nos eixos.\n";
				}
			} while (!width_ok || !height_ok);
			g.setScale(scale);
			redraw(vf, ps);
		} break;
		default: {
			dont_pause = true;
			// Pausa para resultado do gr�fico
			SetForegroundWindow(FindWindow(NULL, TITLE));
			std::cout << std::endl << "Pressione qualquer tecla no grafico para continuar..." << std::endl;
			getch();
			// Volta ao console
			SetForegroundWindow(GetConsoleWindow());
		} break;
	}
	std::cout << std::endl;
	if (!dont_pause) system("pause");
	dont_pause = false;
	clear_input();
	system("cls");
}

int main() {
	// Fun��es salvas e pontos marcados
	vector<Funct> funcoes;
	vector<Point> pontos;
	// Janelas (console e gr�ficos)
	HWND window1, window2;
	// Inicia segunda janela e muda t�tulos
	initwindow(WIDTH+11, HEIGHT+15, "");
	system("title draw-graphs");
	window2 = FindWindow(NULL, "Windows BGI");
	SetWindowTextA(window2, TITLE);
	// Impede maximiza��o da janela de gr�ficos
	DWORD style = GetWindowLong(window2, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(window2, GWL_STYLE, style);
	SetWindowPos(window2, NULL, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE|SWP_FRAMECHANGED);
	// Altera posi��o e dimens�es do console
	window1 = GetConsoleWindow();
	MoveWindow(window1, WIDTH+4, 0, 500, HEIGHT+42, TRUE);
  	// Desenha grid
	show_grid();
	// Volta ao console
	SetForegroundWindow(GetConsoleWindow());
	do {
		input(funcoes, pontos);
	} while (true);
    return 0;
}

