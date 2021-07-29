//
// Principal
//

#include "../include/start.h"
#include "../include/sub.h"

void startup() {
	// Fun��es salvas e pontos marcados
	vector<Funct> funcoes;
	Funct ps;
	ps.setColor(0);
	funcoes.push_back(ps);
	// Janelas (console e gr�ficos)
	HWND window1, window2;
	// Inicia segunda janela e muda t�tulos
	initwindow(WIDTH+11, HEIGHT+15, "");
	system("title draw-graphs");
	window2 = FindWindow(NULL, "Windows BGI");
	SetWindowTextA(window2, TITLE);
	// Impede maximiza��o da janela de gr�ficos
	if (!MX_ABLE) {
		DWORD style = GetWindowLong(window2, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX;
		SetWindowLong(window2, GWL_STYLE, style);
		SetWindowPos(window2, NULL, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE|SWP_FRAMECHANGED);
	}
	// Altera posi��o e dimens�es do console
	window1 = GetConsoleWindow();
	MoveWindow(window1, WIDTH+4, 0, 500, HEIGHT+42, TRUE);
	// Volta ao console
	SetForegroundWindow(GetConsoleWindow());
	do {
		input(funcoes);
	} while (true);
}

