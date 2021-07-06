#include "___globals.h"

/*
 * Declaração e definição da classe Ponto
 */

// Representação de um ponto
class Point {
	private:
	    double x, y; // Coordenadas
		double r;	 // Suporte ao círculo
	
	public:
	    // Getters (coordenadas)
		double getX() { return x*scale; }
		double getY() { return y*scale; }
	    
	    // Suporte ao círculo
		double getR() { return r*scale; }
		void set_radius(double r_param) {
			r = r_param;
		}
	    
	    // Construtor
		Point(double x_param, double y_param) {
		    x = x_param;
		    y = y_param;
		    r = POINT_R;
		}

	    // Função circle refeita de acordo com o sistema de coordenadas
		void draw(double radius) {
			circle(WIDTH/2+getX(), HEIGHT/2-getY(), radius);
		}
};

