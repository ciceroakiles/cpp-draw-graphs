/*
 * Métodos de impressão
 */

// Opções - Menu principal
void menu_options() {
	std::cout << "Dimensoes: " << WIDTH << "x" << HEIGHT << "px" << std::endl;
	std::cout << "[f] Funcoes" << std::endl;
	std::cout << "[p] Pontos" << std::endl;
	std::cout << "[e] Mudar escala (atual: 1/" << scale << "px)" << std::endl;
	std::cout << "[outro] Alternar para o grafico" << std::endl;
	std::cout << "[CTRL+C] Sair" << std::endl;
	std::cout << ">";
}

// Opções - Funções
void subm_fun_opt() {
	std::cout << "Principal > Funcoes" << std::endl;
	std::cout << "[n] Funcao de grau n" << std::endl;
	std::cout << "[a] Reta" << std::endl;
	std::cout << "[b] Parabola" << std::endl;
	std::cout << "[c] Circulo" << std::endl;
	std::cout << "[t] Funcoes trigonometricas" << std::endl;
	std::cout << "[y] Funcoes salvas" << std::endl;
	std::cout << "[z] Descartar funcoes" << std::endl;
	std::cout << "[<] Voltar" << std::endl;
	std::cout << ">";
}

// Opções - Funções trigonométricas (ampliar)
void subm_fun_tr_opt() {
	std::cout << std::endl;
	std::cout << "[1] Seno" << std::endl;
	std::cout << "[2] Cosseno" << std::endl;
	std::cout << "[outro] Voltar" << std::endl;
	std::cout << ">";
}

// Opções - Pontos
void subm_pts_opt() {
	std::cout << "Principal > Pontos" << std::endl;
	std::cout << "[1] Mostrar pontos " << (dots ? "(S)" : "(N)") << std::endl;
	std::cout << "[2] Marcar um ponto" << std::endl;
	std::cout << "[3] Excluir pontos" << std::endl;
	std::cout << "[<] Voltar" << std::endl;
	std::cout << ">";
}

