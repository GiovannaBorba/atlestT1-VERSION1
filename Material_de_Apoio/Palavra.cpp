#include "Palavra.hpp"

using namespace std;

    Palavra::Palavra(){
        this->palavra = palavra;
    }

    Palavra::Palavra(const string& palavra) {
        this->palavra = palavra; // Inicializa o membro "palavra" com o valor passado
        this->primeiraOcorrencia = 0; // Inicializa o membro "primeiraOcorrencia" com nullptr
    }

    int Palavra::PrimeiraOcorrencia(int total){
        int pag = total / 2500 + 1;
        this->primeiraOcorrencia = pag;
        return primeiraOcorrencia;
    }
    int Palavra::obtemPrimeiraOcorrencia(){
        return primeiraOcorrencia;
    }

    string Palavra::definePalavra(string palavra){
        palavra = palavra;
        return palavra;
    }
    string Palavra::getPalavra(){
        return palavra;
    }
