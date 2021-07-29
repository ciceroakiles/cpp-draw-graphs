/*
 * menus.cpp <-> _formula.cpp
 */

#include <math.h>
#include <sstream>
#include <vector>
using std::ostringstream;
using std::string;
using std::vector;

// _formula.cpp:
string replace_occurences(string str, string s1, string s2);
string ajustes(string formula);
string make_formula_vn(vector<double> params);
string make_formula_c(vector<double> params);
string make_formula_t(int t);

