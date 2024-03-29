/*
 * M�todos para elabora��o das f�rmulas
 */

#include <math.h>
#include <sstream>
#include <vector>
using std::ostringstream;
using std::string;
using std::vector;

// Troca as ocorr�ncias de s1 por s2
string replace_occurences(string str, string s1, string s2) {
	size_t index = 0;
	while (true) {
		index = str.find(s1, index);
		if (index == std::string::npos) break;
		str.replace(index, s1.size(), s2);
	}
	return str;
}

// Ajustes na f�rmula final
string ajustes(string formula) {
	// Corre��o do caso zero
	if (formula.size() == 0) formula = "0";
	if (formula.size() > 3) {
		// Remove expoente nulo (x^0) do final
		if (formula.substr(formula.size()-3, 3).compare("x^0") == 0) formula = formula.substr(0, formula.size()-3);
		// Outras corre��es
		formula = replace_occurences(formula, "+1x^1+", "+x+");
		formula = replace_occurences(formula, "+1x^1-", "+x-");
		formula = replace_occurences(formula, "-1x^1+", "-x+");
		formula = replace_occurences(formula, "-1x^1-", "-x-");
		formula = replace_occurences(formula, "+1x^", "+x^");
		formula = replace_occurences(formula, "-1x^", "-x^");
		formula = replace_occurences(formula, "^1+", "+");
		formula = replace_occurences(formula, "^1-", "-");
		formula = replace_occurences(formula, "+-", "-");
		formula = replace_occurences(formula, "++", "+");
		formula = replace_occurences(formula, "--", "-");	
	}
	// Previne in�cio com "1x" ou "+"
	if (formula.substr(1, 2).compare("1x") == 0) formula = formula.replace(1, 1, "");
	if (formula.substr(0, 1).compare("+") == 0) formula = formula.substr(1, formula.size());
	// Se termina com "x^1", retira expoente
	if (formula.size() > 3 && formula.substr(formula.size()-3, 3).compare("x^1") == 0) {
		formula = formula.substr(0, formula.size()-2);
	}
	return formula;
}

/*
 * M�todos para cria��o das f�rmulas
 */

// Fun��o de grau n
string make_formula_vn(vector<double> params) {
	string formula = "";
	for (int i = 0; i < params.size(); i++) {
		// N�o cria termos do tipo 0x^n
		if (params[i] != 0) {
			formula += "+";
			ostringstream ss1, ss2;
			ss1 << params[i];
			ss2 << params.size()-1-i;
			formula += ss1.str() + "x^" + ss2.str();
		}
		//std::cout << ">>>> params.size()-1-i: " << params.size()-1-i << " params[i]: " << params[i] << std::endl;
	}
	formula = ajustes(formula);
	return formula;
}

// C�rculo
string make_formula_c(vector<double> params) {
	string formula = "";
	ostringstream ss;
	for (int i = 0; i < 2; i++) {
		ss << params[i];
		// ASCII x = 120, y = 121
		formula += "+(" + std::string(1, (char)(120+i)) + "-" + ss.str() + ")^2";
		ss.str(std::string());
	}
	ss << pow(params[2], 2);
	formula += "=" + ss.str();
	// Ajustes finais
	formula = replace_occurences(formula, "--", "+");
	formula = formula.substr(1, formula.size());
	return formula;
}

// Fun��es trigonom�tricas
string make_formula_t(int t) {
	switch (t) {
		case 1: {
			return "sen(x)";
		} break;
		case 2: {
			return "cos(x)";
		} break;
		case 3: {
			return "tan(x)";
		} break;
		case 4: {
			return "csc(x)";
		} break;
		case 5: {
			return "sec(x)";
		} break;
		case 6: {
			return "cot(x)";
		} break;
	}
	return "";
}

