#include "__class_point.h"

/*
 * Declara��o e defini��o da classe Fun��o
 */

// Representa��o de uma fun��o
class Funct {
	private:
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
		
		// Desenha a fun��o
		void draw_fun() {
			if (type.compare("circle") == 0) {
				pts[0].draw(pts[0].getR());
			} else {
				for (int i = 0; i < (int)pts.size()-1; i++) {
					// Fun��o line refeita de acordo com o sistema de coordenadas
					line(WIDTH/2+pts[i].getX(), HEIGHT/2-pts[i].getY(), WIDTH/2+pts[i+1].getX(), HEIGHT/2-pts[i+1].getY());
				   	// Marca os pontos ou n�o
				   	if (dots && ((int)pts[i].getX() % scale == 0)) pts[i].draw(POINT_R);
				}
			}
		}
};

