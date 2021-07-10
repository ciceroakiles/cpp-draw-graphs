/*
 * Submenus
 */

#include "utils/_draw.h"

// Procedimento auxiliar (limpeza de input)
void clear_input() {
	std::cin.clear();
	std::cin.ignore(10000,'\n');
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
		setcolor(g.getColor() % 14);
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
					g.setColor(1);
				}
			} break;
			default: {
			} break;
		}
		if (op != '<' && fx.toString().compare("") != 0) {
			// Sucesso
			fx.draw_fun();
			std::cout << std::endl << "[!] No grafico: " << fx.toString() << std::endl;
			vf.push_back(fx);
			std::cout << "[!] Funcao salva.\n" << std::endl;
			system("pause");
			g.setColor(g.getColor()+1);
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
				if (op2 == 's' || op2 == 'S') g.setDots();
				if (op2 == 'n' || op2 == 'N') g.setDots();
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
				if (g.getDots()) p.draw(POINT_R);
				setcolor(g.getColor());
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

