#include <iostream>
#include <cstring>

void pedirParaInput(char palavra[])
{
    std::cout << "------JOGO DA FORCA---------" << std::endl;
    std::cout << "USER 1: Digite uma palavra para iniciar o jogo: " << std::endl;

    std::cin.getline(palavra, 30);
    std::system("cls");

    if (strlen(palavra) == 0 || strspn(palavra, " \t") == strlen(palavra))
    {
        std::cout << "\nAVISO: Voce precisa digitar uma palavra para iniciar o jogo\n\n";
        return;
    }

    std::cout << "ARMAZENANDO.." << std::endl;
    std::cout << "USER 2: Sua vez!! AQUI ESTAO OS DADOS:" << std::endl;

    int tamanho = strlen(palavra);
    std::cout << "A palavra tem --> " << tamanho << " letras." << std::endl;
    std::cout << "Lembre-se, voce tem apenas 10 tentativas!" << std::endl;
}

void loopParaInserirLetra(char palavra[])
{
    bool exibir = true;
    char palavraEscondida[30];

    for (int i = 0; i < strlen(palavra); i++)
    {
        palavraEscondida[i] = '*';
    }
    palavraEscondida[strlen(palavra)] = '\0';

    while (exibir)
    {
        std::cout << "USER 2: Digite uma letra: " << std::endl;
        char letra;
        std::cin >> letra;
        std::cout << "A letra digitada foi --> " << letra << std::endl;

        bool letraEncontrada = false;
        for (int i = 0; i < strlen(palavra); i++)
        {
            if (palavra[i] == letra)
            {
                palavraEscondida[i] = letra;
                letraEncontrada = true;
            }
        }

        if (!letraEncontrada)
        {
            std::cout << "A letra '" << letra << "' nao foi encontrada" << std::endl;
        }
        else
        {
            std::cout << "A letra '" << letra << "' foi encontrada na palavra." << std::endl;
            std::cout << "Palavra Atual: " << palavraEscondida << std::endl;

            if (std::strchr(palavraEscondida, '*') == nullptr)
            {
                std::cout << "Parabens! Voce acertou a palavra: " << palavra << std::endl;
                exibir = false;
            }
        }
    }
}

int main()
{
    char palavra[30];
    pedirParaInput(palavra);
    loopParaInserirLetra(palavra);
    return 0;
}