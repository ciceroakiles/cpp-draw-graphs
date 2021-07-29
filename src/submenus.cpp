//
// Gráficos de funções com C++ e graphics.h
// (input via console)
//

#include "../include/_formula.h"
#include "../include/_print.h"
#include "../include/sub.h"

// Instância padrão de um gráfico
Graph graph(1, true);

//
// Submenus
//

// Procedimento auxiliar (limpeza de input)
void clear_input() {
	std::cin.clear();
	std::cin.ignore(10000,'\n');
}

// Loop principal
void input(vector<Funct> &vf) {
	// Desenha grid
	graph.show_grid();
	
	bool dont_pause = false;
	char op;
	std::cout << "Dimensoes: " << WIDTH << "x" << HEIGHT << "px" << std::endl;
	std::cout << "Escala atual: 1/" << scale << "px" << std::endl;
	menu_options();
	std::cin >> op;
	// Escolhas
	switch (op) {
		// Funções
		case 'f': {
			subm_fun(vf);
			dont_pause = true;
		} break;
		// Pontos
		case 'p': {
			subm_pts(vf);
			dont_pause = true;
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
Funct subm_trg() {
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
void subm_fun(vector<Funct> &vf) {
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
				fx = subm_trg();
				// Correção de possível erro, caso não haja função definida
				if (fx.toString().compare("") == 0) clear_input();
			} break;
			// Funções salvas
			case 'y': {
				std::cout << std::endl << "Funcoes salvas:\n";
				for (int i = 1; i < vf.size(); i++) {
					std::cout << i << ") " << vf[i].toString() << std::endl;
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
					Funct temp = vf[0];
					vf.clear();
					vf.push_back(temp);
					redraw(vf);
					graph.setColor(1);
				}
			} break;
			default: {
			} break;
		}
		if (op != '<' && fx.toString().compare("") != 0) {
			// Sucesso
			fx.setColor(graph.getColor());
			fx.draw_fun(graph);
			std::cout << std::endl << "[!] No grafico: " << fx.toString() << std::endl;
			vf.push_back(fx);
			std::cout << "[!] Funcao salva.\n" << std::endl;
			graph.colorRotate();
			system("pause");
		}
	} while (op != '<');
}

// Principal > Pontos
void subm_pts(vector<Funct> &vf) {
	char op;
	do {
		system("cls");
		// Na função zero: todos os pontos do submenu
		vector<Point> points = vf[0].getPoints();
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
				redraw(vf);
			} break;
			// Marcar um ponto
			case '2': {
				double x, y;
				std::cout << std::endl << ">x y\n>";
				std::cin >> x;
				std::cin >> y;
				// Desenha e salva o ponto, se puder
				Point p(x, y);
				if (p.isDisplayed()) {
					graph.blackColor();
					if (graph.getDots()) p.draw(POINT_R, graph);
					graph.currentColor();
					vf[0].addPoint(p);
				} else {
					std::cout << "\n[!] O ponto nao pode ser exibido.";
					std::cout << "\n[!] O ponto nao foi salvo.\n" << std::endl;
					system("pause");
				}
			} break;
			// Ligar dois pontos
			case '3': {
				double pA, pB;
				std::cout << std::endl << ">pA pB\n>";
				std::cin >> pA;
				std::cin >> pB;
				// Desenha segmento
				graph.blackColor();
				vf[0].singleLink(pA-1, pB-1);
				vf[0].draw_fun(graph);
				graph.currentColor();
				system("pause");
			} break;
			// Pontos salvos
			case '4': {
				std::cout << std::endl << "Pontos salvos:\n";
				for (int i = 0; i < points.size(); i++) {
					double x = points[i].getX()/scale;
					double y = points[i].getY()/scale;
					std::cout << i+1 << ") (" << x << ", " << y << ")" << std::endl;
				}
				std::cout << std::endl;
				system("pause");
			} break;
			// Excluir pontos / Excluir segmentos
			case '5':
			case '6': {
				char op2;
				std::cout << std::endl << "Tem certeza? (S)\n>";
				std::cin >> op2;
				if (op2 == 's' || op2 == 'S') {
					Funct ps;
					ps.setColor(0);
					if (op == '6') ps.setPoints(points);
					vf[0] = ps;
					redraw(vf);
				}
			} break;
			default: {
			} break;
		}
	} while (op != '<');
}

// Redesenho de tudo
void redraw(vector<Funct> &vf) {
	cleardevice();
	graph.show_grid();
	graph.blackColor();
	// Pontos (função index zero - f0)
	vector<Point> points = vf[0].getPoints();
	for (int i = 0; i < points.size(); i++) {
		if (graph.getDots()) points[i].draw(POINT_R, graph);
	}
	// Segmentos da f0 e funções
	for (int i = 0; i < vf.size(); i++) {
		vf[i].draw_fun(graph);
	}
}

string dotSwitch() {
	return (graph.getDots() ? "(S)" : "(N)");
}


//
// Atribuição dos pontos às funções
//

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
	fn.linkPoints();
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
	fn.linkPoints();
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

