/*
 * Definições de alcance global
 */

#include <graphics.h>
#include <vector>
#define TITLE "Gráfico da função" // Título da janela
#define WIDTH 800                 // Largura da janela
#define HEIGHT 600                // Altura da janela
#define POINT_R 3                 // Raio do ponto em px
#define GRID_COLOR 7              // Cor da grade
#define AXIS_COLOR 0              // Cor dos eixos
using std::string;
using std::vector;

class Global {
	private:
		int color; // Cor atual (0-15)
		int scale; // Escala
		bool dots; // Mostrar pontos
	
	public:
		// Construtor
		Global(int c, int s, bool d) {
			color = c;
			scale = s;
			dots = d;
		}
		
		// Getters
		int getColor() { return color; }
		int getScale() { return scale; }
		bool getDots() { return dots; }
		
		// Setters
		void setColor(int c) { color = c; }
		void setScale(int s) { scale = s; }
		void setDots() { dots = !dots; }
};

// Instância padrão
Global g(1, 10, false);

