/*
 * Métodos de impressão
 */

// Opções - Menu principal
void menu_options() {
	std::cout << "Dimensoes: " << WIDTH << "x" << HEIGHT << "px" << std::endl;
	std::cout << "[n] Funcao de grau n" << std::endl;
	std::cout << "[a] Reta" << std::endl;
	std::cout << "[b] Parabola" << std::endl;
	std::cout << "[c] Circulo" << std::endl;
	std::cout << "[t] Funcoes trigonometricas" << std::endl;
	std::cout << "[p] Pontos" << std::endl;
	std::cout << "[w] Alterar escala (atual: 1/" << scale << "px)" << std::endl;
	std::cout << "[y] Funcoes salvas" << std::endl;
	std::cout << "[z] Limpar grafico e descartar funcoes" << std::endl;
	std::cout << "[outro] Alternar para o grafico" << std::endl;
	std::cout << "[CTRL+C] Sair" << std::endl;
	std::cout << ">";
}

// Opções - Funções trigonométricas (ampliar)
void submenu1_options() {
	std::cout << std::endl;
	std::cout << "[1] Seno" << std::endl;
	std::cout << "[2] Cosseno" << std::endl;
	std::cout << "[outro] Voltar" << std::endl;
	std::cout << ">";
}

// Opções - Pontos
void submenu2_options() {
	std::cout << std::endl;
	std::cout << "[m] Mostrar pontos " << (dots ? "(S)" : "(N)") << std::endl;
	std::cout << "[v] Marcar um ponto" << std::endl;
	std::cout << "[x] Excluir pontos" << std::endl;
	std::cout << "[outro] Voltar" << std::endl;
	std::cout << ">";
}

