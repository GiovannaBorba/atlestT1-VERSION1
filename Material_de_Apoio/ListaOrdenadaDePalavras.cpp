#include <iostream>
#include <sstream>
using namespace std;

#include "ListaOrdenadaDePalavras.hpp"
#include "Palavra.hpp"
#include "LeitorArquivo.hpp"
#include "Ocorrencia.hpp"

    ListaOrdenadaDePalavras::ListaOrdenadaDePalavras() : primeiro(nullptr){}
    ListaOrdenadaDePalavras::~ListaOrdenadaDePalavras(){
        // Comece pelo primeiro nó da lista
    Palavra* atual = primeiro;
    while (atual) {
        Palavra* proximo = atual->next; // Guarde o próximo nó antes de excluir o atual
        delete atual; // Libere a memória alocada para o objeto Palavra
        atual = proximo; // Avance para o próximo nó
    }
}

    void ListaOrdenadaDePalavras::ImprimeLista(ListaDeOcorrencia* listas){
    /*Palavra* atual;
    ListaDeOcorrencia* listas[100000] = {};
    atual = primeiro;
    atual->palavra = primeiro->palavra;
    for(int j = 0; j < 100000; j++){
        if(atual->getPalavra() == listas[j]->getNome()){
                listas[j]->ImprimeListaOcorrencia();
                break;
            }
        }

    while (atual) {
        cout << atual->palavra << " || " << atual->primeiraOcorrencia << endl;
    for(int j = 0; j < 500; j++){
        cout << "oi?" << endl;
        if(atual->palavra == listas[j]->getNome()){
                cout << "Palavra[" << j << "]: " << listas[j]->getNome() << endl;
                listas[j]->ImprimeListaOcorrencia();
                break;
            }
        }
        atual = atual->next;
    }
        //atual = atual->next;
    cout << "nullptr" << std::endl;*/
       Palavra* atual = primeiro;

    while (atual) {
        cout << atual->palavra << " || " << atual->primeiraOcorrencia << endl;
        for (int j = 0; j < 100; j++) {
            if (listas[j].getNome() == atual->palavra) {
                cout << "Palavra[" << j << "]: " << listas[j].getNome() << endl;
                listas[j].ImprimeListaOcorrencia();
                break;
            }
        }
        atual = atual->next;
    }

    cout << "nullptr" << std::endl;
}

    //}
    int ListaOrdenadaDePalavras::size(){
        return 1;
    }
    void ListaOrdenadaDePalavras::clear(){

    }

    void ListaOrdenadaDePalavras::add(string palavra, int total){
    for (char &c : palavra) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a'; // Converte caracteres maiúsculos para minúsculos
        }
    }

    //Testes:
    //cout << "Palavra: " << palavra << endl; 

    // Cria um novo objeto Palavra no heap e inicializa com a string palavra
    Palavra* novaPalavra = new Palavra(palavra);

    //cout << "Nova Palavra: " << novaPalavra->palavra << endl; 
    //cout << "Primeiro: " << primeiro << endl; 

    // Verifica se a lista está vazia ou se a nova palavra deve ser a primeira na lista
    if (!primeiro || palavra < primeiro->palavra) {
        novaPalavra->next = primeiro;
        primeiro = novaPalavra;
        novaPalavra->primeiraOcorrencia = novaPalavra->PrimeiraOcorrencia(total); // Torna a nova palavra a primeira na lista
        //cout << "Sou primeira palavra: " << primeiro->palavra << endl; 

    } else {
        Palavra* atual = primeiro;
        while (atual->next && palavra > atual->next->palavra) {
            atual = atual->next; // Percorre a lista para encontrar a posição correta
        }
        //cout << "Atual P.O: " << atual->next << endl;
        //cout << "Atual P.O.P: " << atual->primeiraOcorrencia->palavra << endl;

        novaPalavra->next = atual->next;
        atual->next = novaPalavra; // Insere a nova palavra na posição correta
        novaPalavra->primeiraOcorrencia = novaPalavra->PrimeiraOcorrencia(total);
    }

    //cout << endl;
 
}

    void ListaOrdenadaDePalavras::remove(){

    }

    bool ListaOrdenadaDePalavras::contains(string palavra){
                 for (char &c : palavra) {
            if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a'; // Converte caracteres maiúsculos para minúsculos
        }
    }
        Palavra* atual = primeiro;
    
         while (atual != nullptr) {
        if (atual->palavra == palavra) {
            return true; // Encontrou a palavra na lista
        }
        atual = atual->next;
    }
    
    return false; // A palavra não foi encontrada na lista
 
    }

    string ListaOrdenadaDePalavras::lowercase(string palavra){
         for (char &c : palavra) {
            if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a'; // Converte caracteres maiúsculos para minúsculos
        }
    }
    return palavra;
}


    int ListaOrdenadaDePalavras::get(int index){
        return 1;
    }

    int ListaOrdenadaDePalavras::pagina(int total, string palavra){
    int caracter = 0;

    for (int i = 0; palavra[i] != '\0'; i++) {
        caracter++;
    }
    total+=caracter;
    return total;
    }

    void ListaOrdenadaDePalavras::OrdenaAlfabetica(){

    }

    void ListaOrdenadaDePalavras::OrdenaOcorrencia(){

    }

    bool ListaOrdenadaDePalavras::StopWords(string palavra){
                 for (char &c : palavra) {
            if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a'; // Converte caracteres maiúsculos para minúsculos
        }
    }
        LeitorArquivo stop = LeitorArquivo("StopWords/stopwords-en.txt");
        while(1){
        string a = stop.proximaPalavra(); 
            for (char &c : a) {
            if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a'; // Converte caracteres maiúsculos para minúsculos
        }
    }
        if(palavra == a){
            return false;
        }
        //cout << b << endl;
        count++;
        if(a.empty()){
            return true;  
        }
    }
    }
    void ListaOrdenadaDePalavras::CountStopwords(){

    }

    void ListaOrdenadaDePalavras::Percentual(){

    }

    void ListaOrdenadaDePalavras::PesquisaPalavra(){

    }

    void ListaOrdenadaDePalavras::PesquinaPagina(){

    }

    void ListaOrdenadaDePalavras::exibirLista() const{

    }
