Para utilizar **graphics.h** no Dev C++ 5.11 é preciso seguir os seguintes passos:

* Adicionar os arquivos `graphics.h` e `winbgim.h` às pastas `..\Dev-Cpp\MinGW64\include` e `..\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include` (caminho pode variar dependendo da instalação);

* Adicionar o arquivo `libbgi.a` às pastas `..\Dev-Cpp\MinGW64\lib` e `..\Dev-Cpp\MinGW64\x86_64-w64-mingw32\lib` (caminho pode variar dependendo da instalação);

* Nas opções do projeto, alterar o compilador para a opção "TDM-GCC 4.9.2 32-bit Profiling" e adicionar `-lbgi -lgdi32 -luser32` aos parâmetros do linker.

Segue um código de teste para verificar se tudo foi instalado com sucesso.

```
#include <graphics.h>
int main() {
	initwindow(400, 400, "");
	circle(200, 200, 100);
	getch();
	closegraph();
 }
```
