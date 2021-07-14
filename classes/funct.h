/*
 * Declara��o e defini��o da classe Fun��o
 */

#include "point.h"

// Representa��o de uma fun��o
class Funct {
	private:
		int color;                // Cor
		vector<Point> pts;        // Todos os pontos
		vector<vector<int> > lnk; // Pontos ligados
		string expr;              // F�rmula
		string type;              // Tipo de fun��o
	
	public:
		// Getter e setter (vetor de pontos)
		vector<Point> getPoints() { return pts; }
		void setPoints(vector<Point> p) { pts = p; }
		
		// Getter e setter (f�rmula)
		string toString() { return expr; }
		void setExpr(string s) { expr = s; }
		
		// Altera o tipo da fun��o
		void setType(string s) { type = s; }
		
		// Adiciona ponto
		void addPoint(Point p) { pts.push_back(p); }
		
		// Muda cor
		void setColor(int c) { color = c; }
		
		// Une dois pontos pelo index
		void singleLink(int a, int b) {
			vector<int> pair;
			pair.push_back(a);
			pair.push_back(b);
			lnk.push_back(pair);
		}
		
		// Cria todos os segmentos observ�veis
		void linkAll() {
			for (int i = 0; i < pts.size()-1; i++) {
				// Liga apenas se um dos dois pontos pode ser mostrado
				if (!pts[i].isDisplayed() && !pts[i+1].isDisplayed()) {	
				} else {
					singleLink(i, i+1);
				}
			}
		}
		
		// Desenho de uma fun��o por segmentos
		void draw_fun() {
			graph.functColor(color);
			if (type.compare("circle") == 0) {
				pts[0].draw(pts[0].getR());
			} else {
				for (int i = 0; i < lnk.size(); i++) {
					// Recupera pontos para desenhar
					Point p1 = pts[lnk[i][0]];
					Point p2 = pts[lnk[i][1]];
					// M�todo externo (line)
					graph.g_line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
				}	
			}
			graph.currentColor();
		}
};

