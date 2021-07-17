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
		
		// n >= 2? Cria todos os segmentos observ�veis
		// n < 2? Otimiza a reta com apenas um segmento
		void linkPoints(int n) {
			vector<Point> newPts;
			vector<int> link_out;
			for (int i = 0; i < pts.size()-1; i++) {
				bool p1 = pts[i].isDisplayed();
				bool p2 = pts[i+1].isDisplayed();
				if (n >= 2) {
					// Liga todos os pontos presentes
					if (!(!p1 && !p2)) {
						singleLink(i, i+1);
					}
				} else {
					// Busca pelos segmentos limite
					if ((p1 || p2) && (!(p1 && p2))) {
						link_out.push_back(i);
						link_out.push_back(i+1);
						if (link_out.size() == 4) break;
					}
				}
			}
			if (n < 2) {
				// Garante que a reta ter� apenas dois pontos
				newPts.push_back(pts[link_out[0]]);
				newPts.push_back(pts[link_out[3]]);
				setPoints(newPts);
				singleLink(0, 1);
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

