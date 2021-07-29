//
// Principal
//

#include "../include/start.h"
#include "../include/sub.h"

void startup() {
	// Funções salvas e pontos marcados
	vector<Funct> funcoes;
	Funct ps;
	ps.setColor(0);
	funcoes.push_back(ps);
	// Janelas (console e gráficos)
	HWND window1, window2;
	// Inicia segunda janela e muda títulos
	initwindow(WIDTH+11, HEIGHT+15, "");
	system("title draw-graphs");
	window2 = FindWindow(NULL, "Windows BGI");
	SetWindowTextA(window2, TITLE);
	// Impede maximização da janela de gráficos
	if (!MX_ABLE) {
		DWORD style = GetWindowLong(window2, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX;
		SetWindowLong(window2, GWL_STYLE, style);
		SetWindowPos(window2, NULL, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE|SWP_FRAMECHANGED);
	}
	// Altera posição e dimensões do console
	window1 = GetConsoleWindow();
	MoveWindow(window1, WIDTH+4, 0, 500, HEIGHT+42, TRUE);
	// Volta ao console
	SetForegroundWindow(GetConsoleWindow());
	do {
		input(funcoes);
	} while (true);
}

