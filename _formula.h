/*
 * M�todos para elabora��o das f�rmulas
 */
#include <sstream>
using std::ostringstream;
using std::string;

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
	// Previne in�cio com "1x" ou "+"
	if (formula.substr(1, 2).compare("1x") == 0) formula = formula.replace(1, 1, "");
	if (formula.substr(0, 1).compare("+") == 0) formula = formula.substr(1, formula.size());
	// Se termina com "x^1", retira expoente
	if (formula.substr(formula.size()-3, 3).compare("x^1") == 0) formula = formula.substr(0, formula.size()-2);
	return formula;
}

// Cria a f�rmula (reta e par�bola)
string make_formula_v2(double params[]) {
	string formula = "";
	int j = (int)sizeof(params);
	for (int i = 0; i < j-1; i++) {
		// N�o cria termos do tipo 0x^n
		if (params[i] != 0) {
			formula += "+";
			ostringstream ss1, ss2;
			ss1 << params[i];
			ss2 << j-2-i;
			formula += ss1.str() + "x^" + ss2.str();
		}
		//cout << ">>>> sizeof(params)-2-i: " << sizeof(params)-2-i << " params[i]: " << params[i] << endl;
	}
	formula = ajustes(formula);
	return formula;
}

// Cria a f�rmula (c�rculo)
string make_formula_c(double params[]) {
	string formula = "";
	ostringstream ss;
	for (int i = 0; i < 2; i++) {
		ss << params[i];
		// ASCII x = 120, y = 121
		formula += "+(" + std::string(1, (char)(120+i)) + "-" + ss.str() + ")^2";
		ss.str(std::string());
	}
	ss << params[2]*params[2];
	formula += "=" + ss.str();
	// Ajustes finais
	formula = replace_occurences(formula, "--", "+");
	formula = formula.substr(1, formula.size());
	return formula;
}

