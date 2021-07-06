/*
 * Definições de alcance global no projeto
 * TITLE: Título da janela
 * WIDTH: Largura da janela
 * HEIGHT: Altura da janela
 * POINT_R: Raio do ponto em px
 * ?_COLOR: Cor do objeto (0-15)
 */

#include <graphics.h>
#include <vector>
#define TITLE "Gráfico da função"
#define WIDTH 800
#define HEIGHT 600
#define POINT_R 3
#define GRID_COLOR 7
#define AXIS_COLOR 0
using std::string;
using std::vector;

int color = 1; 		// Cor atual (0-15)
int scale = 10;		// Escala
bool dots = false;	// Mostrar pontos

