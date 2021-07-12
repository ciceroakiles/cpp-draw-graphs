/*
 * Menus
 */

#include "utils/assign.h"
#include "utils/formula.h"
#include "utils/print.h"

// Assinaturas de métodos
void subm_fun(vector<Funct> &vf, vector<Point> &ps);
void subm_pts(vector<Funct> &vf, vector<Point> &ps);
void redraw(vector<Funct> &vf, vector<Point> &ps);

// Procedimento auxiliar (limpeza de input)
void clear_input() {
	std::cin.clear();
	std::cin.ignore(10000,'\n');
}

// Loop principal
void input(vector<Funct> &vf, vector<Point> &ps) {
	bool dont_pause = false;
	char op;
	menu_options();
	std::cin >> op;
	// Escolhas
	switch (op) {
		// Funções
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
			graph.setScale(scale);
			redraw(vf, ps);
		} break;
		default: {
			dont_pause = true;
			// Pausa para resultado do gráfico
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

// Principal > Funções > Funções trigonométricas
Funct subm_trg(vector<Funct> &vf, vector<Point> &ps) {
	int op;
	Funct fx;
	subm_fun_tr_opt();
	std::cin >> op;
	// Seleção
	fx = trigonometric(op);
	fx.setExpr(make_formula_t(op));
	return fx;
}

// Principal > Funções
void subm_fun(vector<Funct> &vf, vector<Point> &ps) {
	char op;
	do {
		system("cls");
		double temp;
		vector<double> args;
		Funct fx;
		fx.setExpr("");
		subm_fun_opt();
		std::cin >> op;
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
				fx.setExpr(make_formula_vn(args));
			} break;
			// Círculo
			case 'c': {
				std::cout << std::endl << "Parametros do circulo:\n>x_cen y_cen r\n>";
				for (int i = 0; i <= 2; i++) {
					std::cin >> temp;
					args.push_back(temp);
				}
				fx = circle_t2(args);
				fx.setExpr(make_formula_c(args));
			} break;
			// Funções trigonométricas
			case 't': {
				fx = subm_trg(vf, ps);
				// Correção de possível erro, caso não haja função definida
				if (fx.toString().compare("") == 0) clear_input();
			} break;
			// Funções salvas
			case 'y': {
				std::cout << std::endl << "Funcoes salvas:\n";
				for (int i = 0; i < vf.size(); i++) {
					std::cout << i+1 << ") " << vf[i].toString() << std::endl;
				}
				std::cout << std::endl;
				system("pause");
			} break;
			// Descartar funções
			case 'z': {
				char op2;
				std::cout << "\n[!] As funcoes serao removidas do grafico.";
				std::cout << "\nTem certeza? (S)\n>";
				std::cin >> op2;
				if (op2 == 's' || op2 == 'S') {
					vf.clear();
					redraw(vf, ps);
					graph.setColor(1);
				}
			} break;
			default: {
			} break;
		}
		if (op != '<' && fx.toString().compare("") != 0) {
			// Sucesso
			fx.setColor(graph.getColor());
			fx.draw_fun();
			std::cout << std::endl << "[!] No grafico: " << fx.toString() << std::endl;
			vf.push_back(fx);
			std::cout << "[!] Funcao salva.\n" << std::endl;
			graph.colorRotate();
			system("pause");
		}
	} while (op != '<');
}

// Principal > Pontos
void subm_pts(vector<Funct> &vf, vector<Point> &ps) {
	char op;
	do {
		system("cls");
		subm_pts_opt();
		std::cin >> op;
		switch (op) {
			// Mostrar pontos
			case '1': {
				char op2;
				std::cout << std::endl << "S/N:\n>";
				std::cin >> op2;
				if (op2 == 's' || op2 == 'S') graph.setDots();
				if (op2 == 'n' || op2 == 'N') graph.setDots();
				redraw(vf, ps);
			} break;
			// Marcar um ponto
			case '2': {
				double t1, t2;
				std::cout << std::endl << ">x y\n>";
				std::cin >> t1;
				std::cin >> t2;
				Point p(t1, t2);
				setcolor(0);
				if (graph.getDots()) p.draw(POINT_R);
				setcolor(graph.getColor());
				ps.push_back(p);
			} break;
			// Excluir pontos
			case '3': {
				char op2;
				std::cout << std::endl << "Tem certeza? (S)\n>";
				std::cin >> op2;
				if (op2 == 's' || op2 == 'S') {
					ps.clear();
					redraw(vf, ps);
				}
			} break;
			default: {
			} break;
		}
	} while (op != '<');
}

// Redesenho de tudo
void redraw(vector<Funct> &vf, vector<Point> &ps) {
	cleardevice();
	graph.show_grid();
	setcolor(0);
	// Pontos
	for (int i = 0; i < ps.size(); i++) {
		if (graph.getDots()) ps[i].draw(POINT_R);
	}
	// Funções
	for (int i = 0; i < vf.size(); i++) {
		vf[i].draw_fun();
	}
}

