/*
 * Defini��es de alcance global no projeto
 * TITLE: T�tulo da janela
 * WIDTH: Largura da janela
 * HEIGHT: Altura da janela
 * ?_COLOR: Cor do objeto (0 ~ 15)
 */
#include <graphics.h>
#include <vector>
#define TITLE "Gr�fico da fun��o"
#define WIDTH 800
#define HEIGHT 600
#define GRID_COLOR 7
#define AXIS_COLOR 0

using std::string;
using std::vector;

int color = 1; 		// Cor atual (0-15)
int scale = 10;		// Escala
bool dots = false;	// Mostrar pontos
double pt_r = 3;	// Raio do ponto

