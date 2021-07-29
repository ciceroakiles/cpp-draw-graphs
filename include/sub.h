/*
 * starting_menu.cpp <-> submenus.cpp
 */

#include "class_graph.h"
#include "class_point.h"
#include "class_funct.h"

// submenus.cpp:
void input(vector<Funct> &vf);
void subm_fun(vector<Funct> &vf);
Funct subm_trg();
void subm_pts(vector<Funct> &vf);
void redraw(vector<Funct> &vf);

Funct polinomial_tn(vector<double> t);
Funct circle_t2(vector<double> t);
Funct trigonometric(int t);
double tr_select(double x, int t);

