#ifndef PALAVRA_HPP
#define PALAVRA_HPP

using namespace std;

#include <string>

class ListaOrdenadaDePalavras; // Declarando a classe ListaOrdenadaDePalavras para amizade
class ListaDeOcorrencia;

class Palavra {
public:
    Palavra();
    Palavra(const string& palavra);
    int PrimeiraOcorrencia(int total);
    int obtemPrimeiraOcorrencia();
    string getPalavra();
    string definePalavra(string palavra);
//private:
    string palavra;
    Palavra* next;
    int primeiraOcorrencia;
    friend class ListaOrdenadaDePalavras; // Permitindo que a classe ListaOrdenadaDePalavras acesse membros privados
    friend class ListaDeOcorrencia;
};

#endif