/*
 * Gráficos de funções com C++ e graphics.h
 * (input via console)
 */
#include <iostream>
#include "_formula.h"
#include "_methods.h"

using std::cout;
using std::cin;
using std::endl;

// Método de impressão (opções do menu)
void print_options() {
	cout << "Dimensoes: " << WIDTH << "x" << HEIGHT << "px" << endl;
	//cout << "[0] test" << endl;
	cout << "[a] Reta" << endl;
	cout << "[b] Parabola" << endl;
	cout << "[c] Circulo" << endl;
	cout << "[w] Funcoes salvas" << endl;
	cout << "[x] Mostrar pontos " << (dots ? "(S)" : "(N)") << endl;
	cout << "[y] Alterar escala (atual: 1/" << scale << "px)" << endl;
	cout << "[z] Limpar grafico e descartar funcoes" << endl;
	cout << "[outro] Ver grafico" << endl;
	cout << "[CTRL+C] Sair" << endl;
	cout << ">";
}

// Loop principal
void input(vector<Funct> &vf) {
	bool no_graph = false, success = false;
	double abc[] = {0, 0, 0};
	string formula = "";
	Funct fx;
	char op;
	// Menu
	print_options();
	cin >> op;
	setcolor(color % 14);
	// Escolhas
	switch (op) {
		case 'a': {
			abc[0] = 0;
			do {
				cout << endl << "Parametros da reta:\n>a b\n>";
				cin >> abc[1];
				cin >> abc[2];
			} while (abc[1] == 0 && abc[2] == 0);
			fx = polinomial_t2(abc);
			formula = make_formula_v2(abc);
			success = true;
		} break;
		case 'b': {
			do {
				cout << endl << "Parametros da parabola:\n>a b c\n>";
				cin >> abc[0];
				cin >> abc[1];
				cin >> abc[2];
			} while (abc[0] == 0 && abc[1] == 0 && abc[2] == 0);
			fx = polinomial_t2(abc);
			formula = make_formula_v2(abc);
			success = true;
		} break;
		case 'c': {
			cout << endl << "Parametros do circulo:\n>x_cen y_cen r\n>";
			cin >> abc[0];
			cin >> abc[1];
			cin >> abc[2];
			fx = circle_t2(abc);
			formula = make_formula_c(abc);
			success = true;
		} break;
		case 'w': {
			cout << endl << "Funcoes salvas:\n";
			for (int i = 0; i < vf.size(); i++) {
				cout << i+1 << ") " << vf[i].toString() << endl;
			}
			system("pause");
			no_graph = true;
		} break;	
		case 'x': {
			char pts;
			cout << endl << "S/N:\n>";
			cin >> pts;
			if (pts == 's' || pts == 'S') dots = true;
			if (pts == 'n' || pts == 'N') dots = false;
			redraw(vf);			
			system("pause");
			no_graph = true;
		} break;
		case 'y': {
			bool width_ok = false, height_ok = false;
			cout << endl << "Nova escala:\n>";
			do {
				cin >> scale;
				width_ok = ((WIDTH % scale == 0) && ((WIDTH/scale) % 2 == 0));
				height_ok = ((HEIGHT % scale == 0) && ((HEIGHT/scale) % 2 == 0));
				if (!width_ok || !height_ok) {
					cout << "[!] Escala com problemas nos eixos.\n>";
				}
			} while (!width_ok || !height_ok);
			system("pause");
			redraw(vf);
    		no_graph = true;
		} break;
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
		cout << endl << "[!] No grafico: " << formula << endl;
		vf.push_back(fx);
		cout << "[!] Funcao salva.\n";
		color++;
	}
	if (!no_graph) {
		// Pausa para resultado do gráfico
		SetForegroundWindow(FindWindow(NULL, TITLE));
		cout << endl << "Pressione qualquer tecla no grafico para continuar..." << endl;
		getch();
		// Volta ao console
		SetForegroundWindow(GetConsoleWindow());	
	}
	success = false;
	no_graph = false;
	cin.clear();
	cin.ignore(10000,'\n');
	system("cls");
}

int main() {
	// Funções salvas
	vector<Funct> funcoes;
	
	// Inicia segunda janela, muda títulos e desenha grid
	initwindow(WIDTH+11, HEIGHT+15, "");
	system("title draw-graphs");
	HWND hWnd = FindWindow(NULL, "Windows BGI");
  	SetWindowTextA(hWnd, TITLE);
	show_grid();
	
	// Volta ao console
	SetForegroundWindow(GetConsoleWindow());
	do {
		input(funcoes);
	} while (true);
    return 0;
}

