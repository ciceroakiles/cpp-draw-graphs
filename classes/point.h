/*
 * Declaração e definição da classe Ponto
 */

#include "_globals.h"

// Representação de um ponto
class Point {
	private:
	    double x, y; // Coordenadas
		double r;	 // Suporte ao círculo
	
	public:
	    // Getters (coordenadas)
		double getX() { return x*g.getScale(); }
		double getY() { return y*g.getScale(); }
	    
	    // Suporte ao círculo
		double getR() { return r*g.getScale(); }
		void set_radius(double r_param) {
			r = r_param;
		}
	    
	    // Construtor
		Point(double x_param, double y_param) {
		    x = x_param;
		    y = y_param;
		    r = POINT_R;
		}
		
		// Verifica se um ponto aparece no gráfico
		bool isDisplayed() {
			bool x_ok, y_ok;
			x_ok = ((getX() >= -WIDTH/2) && (getX() <= WIDTH/2) ? true : false);
			y_ok = ((getY() >= -HEIGHT/2) && (getY() <= HEIGHT/2) ? true : false);
			return (x_ok && y_ok);
		}
		
	    // Função circle refeita de acordo com o sistema de coordenadas
		void draw(double radius) {
			circle(WIDTH/2+getX(), HEIGHT/2-getY(), radius);
		}
};

