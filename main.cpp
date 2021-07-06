/*
 * Gráficos de funções com C++ e graphics.h
 * (input via console)
 */

#include <iostream>
#include "_formula.h"
#include "_methods.h"

// Método de impressão (opções do menu)
void print_options() {
	std::cout << "Dimensoes: " << WIDTH << "x" << HEIGHT << "px" << std::endl;
	std::cout << "[n] Funcao de grau n" << std::endl;
	std::cout << "[a] Reta" << std::endl;
	std::cout << "[b] Parabola" << std::endl;
	std::cout << "[c] Circulo" << std::endl;
	std::cout << "[m] Mostrar pontos " << (dots ? "(S)" : "(N)") << std::endl;
	std::cout << "[p] Marcar um ponto" << std::endl;
	std::cout << "[x] Excluir pontos" << std::endl;
	std::cout << "[w] Alterar escala (atual: 1/" << scale << "px)" << std::endl;
	std::cout << "[y] Funcoes salvas" << std::endl;
	std::cout << "[z] Limpar grafico e descartar funcoes" << std::endl;
	std::cout << "[outro] Ver grafico" << std::endl;
	std::cout << "[CTRL+C] Sair" << std::endl;
	std::cout << ">";
}

// Loop principal
void input(vector<Funct> &vf, vector<Point> &ps) {
	bool no_graph = false, success = false;
	char op;
	double temp;
	vector<double> args;
	string formula = "";
	Funct fx;
	// Menu
	print_options();
	std::cin >> op;
	setcolor(color % 14);
	// Escolhas
	switch (op) {
		case 'a':
		case 'b':
		// Função de qualquer grau
		case 'n': {
			int n = -1;
			if (op == 'a') n = 1;
			if (op == 'b') n = 2;
			while (n < 0) {
				std::cout << std::endl << "Grau da funcao:\n";
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
		/*
		// Reta
		case 'a': {
			abc[0] = 0;
			std::cout << std::endl << "Parametros da reta:\n>a b\n>";
			std::cin >> abc[1];
			std::cin >> abc[2];
			fx = polinomial_t2(abc);
			formula = make_formula_v2(abc);
			success = true;
		} break;
		// Parábola
		case 'b': {
			std::cout << std::endl << "Parametros da parabola:\n>a b c\n>";
			std::cin >> abc[0];
			std::cin >> abc[1];
			std::cin >> abc[2];
			fx = polinomial_t2(abc);
			formula = make_formula_v2(abc);
			success = true;
		} break;
		*/
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
		// Mostrar pontos
		case 'm': {
			char op2;
			std::cout << std::endl << "S/N:\n>";
			std::cin >> op2;
			if (op2 == 's' || op2 == 'S') dots = true;
			if (op2 == 'n' || op2 == 'N') dots = false;
			redraw(vf, ps);
			system("pause");
			no_graph = true;
		} break;
		// Marcar um ponto
		case 'p': {
			std::cout << std::endl << ">x y\n>";
			for (int i = 0; i < 2; i++) {
				std::cin >> temp;
				args.push_back(temp);
			}
			Point p(args[0], args[1]);
			setcolor(0);
			if (dots) p.draw(POINT_R);
			setcolor(color);
			ps.push_back(p);
		} break;
		// Excluir pontos
		case 'x': {
			ps.clear();
			redraw(vf, ps);
			no_graph = true;
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
			//system("pause");
			redraw(vf, ps);
    		no_graph = true;
		} break;
		// Funções salvas
		case 'y': {
			std::cout << std::endl << "Funcoes salvas:\n";
			for (int i = 0; i < vf.size(); i++) {
				std::cout << i+1 << ") " << vf[i].toString() << std::endl;
			}
			system("pause");
			no_graph = true;
		} break;
		// Limpar gráfico e descartar funções
		case 'z': {
			cleardevice();
			show_grid();
			vf.clear();
			color = 1;
			no_graph = true;
		} break;
		default: {
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
	if (!no_graph) {
		// Pausa para resultado do gráfico
		SetForegroundWindow(FindWindow(NULL, TITLE));
		std::cout << std::endl << "Pressione qualquer tecla no grafico para continuar..." << std::endl;
		getch();
		// Volta ao console
		SetForegroundWindow(GetConsoleWindow());	
	}
	success = false;
	no_graph = false;
	std::cin.clear();
	std::cin.ignore(10000,'\n');
	system("cls");
}

int main() {
	// Funções salvas e pontos marcados
	vector<Funct> funcoes;
	vector<Point> pontos;
	// Inicia segunda janela, muda títulos e desenha grid
	initwindow(WIDTH+11, HEIGHT+15, "");
	system("title draw-graphs");
	HWND hWnd = FindWindow(NULL, "Windows BGI");
  	SetWindowTextA(hWnd, TITLE);
	show_grid();
	// Volta ao console
	SetForegroundWindow(GetConsoleWindow());
	do {
		input(funcoes, pontos);
	} while (true);
    return 0;
}

