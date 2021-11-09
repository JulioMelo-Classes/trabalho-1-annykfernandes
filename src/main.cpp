#include <iostream>
#include <vector>
#include <string>

using String = std::string;
int main(){
  
    std::vector<String> menu = {"0 -> Ver scores anteriores", "1 -> Iniciar jogo"};

    std::cout << menu[0] << std::endl;
    std::cout << menu[1] << std::endl;

    int comando;
    std::cin >> comando;

    if(comando == 0)
    {
      std::cout << "Nenhum score armazenado ainda...";
    }
    else if(comando ==1)
    {
      std::cout << "Vamos começar!";
    }
    else
    {
      std::cout << "Comando inválido.";
    }

    return 0;
}