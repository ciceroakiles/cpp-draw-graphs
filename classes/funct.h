/*
 * Declaração e definição da classe Função
 */

#include "point.h"

// Representação de uma função
class Funct {
	private:
		int color;         // Cor
		vector<Point> pts; // Pontos
		string expr;       // Fórmula
		string type;       // Tipo de função
	
	public:
		// Getter e setter da fórmula
		string toString() { return expr; }
		void setExpr(string s) { expr = s; }
		
		// Altera o tipo da função
		void setType(string s) { type = s; }
		
		// Adiciona ponto
		void addPoint(Point p) { pts.push_back(p); }
		
		// Muda cor
		void setColor(int c) { color = c; }
		
		// Desenha a função
		void draw_fun() {
			setcolor(color);
			if (type.compare("circle") == 0) {
				pts[0].draw(pts[0].getR());
			} else {
				for (int i = 0; i < (int)pts.size()-1; i++) {
					// Chama método externo (line)
					graph.g_line(pts[i].getX(), pts[i].getY(), pts[i+1].getX(), pts[i+1].getY());
				}
			}
			setcolor(graph.getColor());
		}
};

