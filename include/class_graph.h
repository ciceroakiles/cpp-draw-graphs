/*
 * Declaração e definição da classe Gráfico
 */

#include "__global.h"

class Graph {
	private:
		int color; // Cor atual (0-15)
		bool dots; // Mostrar pontos
	
	public:
		// Construtor
		Graph(int c, bool d) {
			color = c;
			dots = d;
		}
		
		// Getters
		int getColor() { return color; }
		bool getDots() { return dots; }
		
		// Setters
		void setColor(int c) { color = c; }
		void setDots() { dots = !dots; }
		
		// Muda para a cor preta, atual, ou da função
		void blackColor() { setcolor(0); }
		void currentColor() { setcolor(getColor()); }
		void functColor(int c) { setcolor(c); }
		
		// Mudança de cores
		void colorRotate() {
			setColor((getColor()+1) % 14);
			// Cores para ignorar
			if (getColor() == GRID_COLOR || getColor() == AXIS_COLOR || getColor() == 11) {
				setColor((getColor()+1) % 14);
			}
			currentColor();
		}
		
		// Desenho da grade
		void show_grid() {
			setcolor(GRID_COLOR);
			floodfill(0, 0, GRID_COLOR);
			// Linhas
			for (int i = 0; i <= WIDTH; i += scale) {
				line(i, 0, i, HEIGHT);
			}
			for (int i = 0; i <= HEIGHT; i += scale) {
				line(0, i, WIDTH, i);
			}
			// Eixos X e Y
			setcolor(AXIS_COLOR);
			line(0, HEIGHT/2, WIDTH, HEIGHT/2);
			line(WIDTH/2, 0, WIDTH/2, HEIGHT);
			currentColor();
		}
		
		// Método circle refeito de acordo com o sistema de coordenadas
		void g_circle(double x, double y, double r) {
			circle(WIDTH/2 + x, HEIGHT/2 - y, r);
		}
		
		// Método line refeito de acordo com o sistema de coordenadas
		void g_line(double x1, double y1, double x2, double y2) {
			line(WIDTH/2 + x1, HEIGHT/2 - y1, WIDTH/2 + x2, HEIGHT/2 - y2);
		}
};

