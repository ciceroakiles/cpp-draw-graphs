/*
 * Declaração e definição da classe Ponto
 */

#include "_global.h"

// Representação de um ponto
class Point {
	private:
	    double x, y; // Coordenadas
		double r;	 // Suporte ao círculo
	
	public:
		// Construtor
		Point(double x_param, double y_param) {
		    x = x_param;
		    y = y_param;
		    r = POINT_R;
		}
		
	    // Getters (coordenadas)
		double getX() { return x*scale; }
		double getY() { return y*scale; }
	    
	    // Suporte ao círculo
		double getR() { return r*scale; }
		void set_radius(double r_param) {
			r = r_param;
		}
	    
		// Verifica se um ponto aparece no gráfico
		bool isDisplayed() {
			bool x_ok, y_ok;
			x_ok = ((getX() >= -WIDTH/2) && (getX() <= WIDTH/2) ? true : false);
			y_ok = ((getY() >= -HEIGHT/2) && (getY() <= HEIGHT/2) ? true : false);
			return (x_ok && y_ok);
		}
		
	    // Método externo (circle)
		void draw(double radius) {
			graph.g_circle(getX(), getY(), radius);
		}
};

