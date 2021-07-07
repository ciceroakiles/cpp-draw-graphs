/*
 * Gráficos de funções com C++ e graphics.h
 * (input via console)
 */

#include <iostream>
#include "_formula.h"
#include "_methods.h"
#include "_print.h"

Funct submenu_1(vector<Funct> &vf, vector<Point> &ps);
void submenu_2(vector<Funct> &vf, vector<Point> &ps);

// Loop principal
void input(vector<Funct> &vf, vector<Point> &ps) {
	bool success = false, on_graph = false;
	char op;
	double temp;
	vector<double> args;
	string formula = "";
	Funct fx;
	// Menu
	menu_options();
	std::cin >> op;
	setcolor(color % 14);
	// Escolhas
	switch (op) {
		// Funções polinomiais de qualquer grau
		case 'a':
		case 'b':
		case 'n': {
			int n = -1;
			if (op == 'a') n = 1;
			if (op == 'b') n = 2;
			while (n < 0) {
				std::cout << std::endl << "Grau da funcao: ";
				std::cin >> n;
			}
			std::cout << std::endl << "Definicao dos coeficientes\n";
			for (int i = 0; i <= n; i++) {
				std::cout << "> x elevado a " << n-i << " vezes: ";
				std::cin >> temp;
				args.push_back(temp);
			}
			fx = polinomial_tn(args);
			formula = make_formula_vn(args);
			success = true;
		} break;
		// Círculo
		case 'c': {
			std::cout << std::endl << "Parametros do circulo:\n>x_cen y_cen r\n>";
			for (int i = 0; i <= 2; i++) {
				std::cin >> temp;
				args.push_back(temp);
			}
			fx = circle_t2(args);
			formula = make_formula_c(args);
			success = true;
		} break;
		// Funções trigonométricas
		case 't': {
			fx = submenu_1(vf, ps);
			formula = fx.toString();
			if (formula.compare("") != 0) success = true;
		} break;
		// Pontos
		case 'p': {
			submenu_2(vf, ps);
		} break;
		// Alterar escala
		case 'w': {
			bool width_ok = false, height_ok = false;
			std::cout << std::endl << "Nova escala:\n>";
			do {
				std::cin >> scale;
				width_ok = ((WIDTH % scale == 0) && ((WIDTH/scale) % 2 == 0));
				height_ok = ((HEIGHT % scale == 0) && ((HEIGHT/scale) % 2 == 0));
				if (!width_ok || !height_ok) {
					std::cout << "[!] Escala com problemas nos eixos.\n>";
				}
			} while (!width_ok || !height_ok);
			redraw(vf, ps);
		} break;
		// Funções salvas
		case 'y': {
			std::cout << std::endl << "Funcoes salvas:\n";
			for (int i = 0; i < vf.size(); i++) {
				std::cout << i+1 << ") " << vf[i].toString() << std::endl;
			}
		} break;
		// Limpar gráfico e descartar funções
		case 'z': {
			char op2;
			std::cout << std::endl << "Tem certeza? (S)\n>";
			std::cin >> op2;
			if (op2 == 's' || op2 == 'S') {
				cleardevice();
				show_grid();
				vf.clear();
				color = 1;
			}
		} break;
		default: {
			on_graph = true;
			// Pausa para resultado do gráfico
			SetForegroundWindow(FindWindow(NULL, TITLE));
			std::cout << std::endl << "Pressione qualquer tecla no grafico para continuar..." << std::endl;
			getch();
			// Volta ao console
			SetForegroundWindow(GetConsoleWindow());
		} break;
	}
	if (success) {
		// Sucesso
		fx.setExpr(formula);
		fx.draw_fun();
		std::cout << std::endl << "[!] No grafico: " << formula << std::endl;
		vf.push_back(fx);
		std::cout << "[!] Funcao salva.\n";
		color++;
	}
	std::cout << std::endl;
	if (!on_graph) system("pause");
	on_graph = false;
	success = false;
	std::cin.clear();
	std::cin.ignore(10000,'\n');
	system("cls");
}

// Submenu - Funções trigonométricas
Funct submenu_1(vector<Funct> &vf, vector<Point> &ps) {
	int op;
	Funct fx;
	submenu1_options();
	std::cin >> op;
	// Seleção
	fx = trigonometric(op);
	fx.setExpr(make_formula_t(op));
	return fx;
}

// Submenu - Pontos
void submenu_2(vector<Funct> &vf, vector<Point> &ps) {
	char op;
	submenu2_options();
	std::cin >> op;
	switch (op) {
		// Mostrar pontos
		case 'm': {
			char op2;
			std::cout << std::endl << "S/N:\n>";
			std::cin >> op2;
			if (op2 == 's' || op2 == 'S') dots = true;
			if (op2 == 'n' || op2 == 'N') dots = false;
			redraw(vf, ps);
		} break;
		// Marcar um ponto
		case 'v': {
			double t1, t2;
			std::cout << std::endl << ">x y\n>";
			std::cin >> t1;
			std::cin >> t2;
			Point p(t1, t2);
			setcolor(0);
			if (dots) p.draw(POINT_R);
			setcolor(color);
			ps.push_back(p);
		} break;
		// Excluir pontos
		case 'x': {
			ps.clear();
			redraw(vf, ps);
		} break;
		default: {
		} break;
	}
}

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
	show_grid();
	// Volta ao console
	SetForegroundWindow(GetConsoleWindow());
	do {
		input(funcoes, pontos);
	} while (true);
    return 0;
}

