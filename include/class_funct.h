/*
 * Declaração e definição da classe Função
 */

// Representação de uma função
class Funct {
	private:
		int color;                // Cor
		vector<Point> pts;        // Todos os pontos
		vector<vector<int> > lnk; // Pontos ligados
		string expr;              // Fórmula
		string type;              // Tipo de função
	
	public:
		// Getter e setter (vetor de pontos)
		vector<Point> getPoints() { return pts; }
		void setPoints(vector<Point> p) { pts = p; }
		
		// Getter e setter (fórmula)
		string toString() { return expr; }
		void setExpr(string s) { expr = s; }
		
		// Altera o tipo da função
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
		
		void linkPoints() {
			vector<Point> newPts;
			vector<int> link_out;
			for (int i = 0; i < pts.size()-1; i++) {
				bool p1 = pts[i].isDisplayed();
				bool p2 = pts[i+1].isDisplayed();
				// Liga todos os pontos presentes
				if (!(!p1 && !p2)) {
					singleLink(i, i+1);
				}
			}
		}
		
		// Desenho de uma função por segmentos
		void draw_fun(Graph gr) {
			gr.functColor(color);
			if (type.compare("circle") == 0) {
				pts[0].draw(pts[0].getR(), gr);
			} else {
				for (int i = 0; i < lnk.size(); i++) {
					// Recupera pontos para desenhar
					Point p1 = pts[lnk[i][0]];
					Point p2 = pts[lnk[i][1]];
					// Método externo (line)
					gr.g_line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
				}	
			}
			gr.currentColor();
		}
};

