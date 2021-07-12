/*
 * Declara��o e defini��o da classe Fun��o
 */

#include "point.h"

// Representa��o de uma fun��o
class Funct {
	private:
		int color;         // Cor
		vector<Point> pts; // Pontos
		string expr;       // F�rmula
		string type;       // Tipo de fun��o
	
	public:
		// Getter e setter da f�rmula
		string toString() { return expr; }
		void setExpr(string s) { expr = s; }
		
		// Altera o tipo da fun��o
		void setType(string s) { type = s; }
		
		// Adiciona ponto
		void addPoint(Point p) { pts.push_back(p); }
		
		// Muda cor
		void setColor(int c) { color = c; }
		
		// Desenha a fun��o
		void draw_fun() {
			setcolor(color);
			if (type.compare("circle") == 0) {
				pts[0].draw(pts[0].getR());
			} else {
				for (int i = 0; i < (int)pts.size()-1; i++) {
					// Chama m�todo externo (line)
					graph.g_line(pts[i].getX(), pts[i].getY(), pts[i+1].getX(), pts[i+1].getY());
				}
			}
			setcolor(graph.getColor());
		}
};

