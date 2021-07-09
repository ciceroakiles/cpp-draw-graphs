#include "__class_point.h"

/*
 * Declaração e definição da classe Função
 */

// Representação de uma função
class Funct {
	private:
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
		
		// Desenha a função
		void draw_fun() {
			if (type.compare("circle") == 0) {
				pts[0].draw(pts[0].getR());
			} else {
				for (int i = 0; i < (int)pts.size()-1; i++) {
					// Função line refeita de acordo com o sistema de coordenadas
					line(WIDTH/2+pts[i].getX(), HEIGHT/2-pts[i].getY(), WIDTH/2+pts[i+1].getX(), HEIGHT/2-pts[i+1].getY());
				   	// Marca os pontos ou não
				   	if (dots && ((int)pts[i].getX() % scale == 0)) pts[i].draw(POINT_R);
				}
			}
		}
};

