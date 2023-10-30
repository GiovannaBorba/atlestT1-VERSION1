#include "Ocorrencia.hpp"
#include <iostream>

using namespace std;

Ocorrencia::Ocorrencia() {
    this->next = NULL;
}
Ocorrencia::Ocorrencia(int i) {
    this->numOcorrencia = i;
    this->next = NULL;
}
Ocorrencia::Ocorrencia(int i, Ocorrencia *next){
    this->numOcorrencia = i;
    this->next = next;
}

Ocorrencia::~Ocorrencia() {
    // Você deve liberar a memória alocada dinamicamente, se houver alguma, aqui
    // Por exemplo, se você alocou memória para 'next' em algum lugar, deve liberá-la aqui.
}

ListaDeOcorrencia::ListaDeOcorrencia(string nome) : nome(nome){
//cout << "Criando... [" << nome << "]" << endl;
  head = nullptr;
  tail = nullptr;
  count = 0;
}

ListaDeOcorrencia::~ListaDeOcorrencia() {
    // Você deve liberar a memória alocada dinamicamente, se houver alguma, aqui
    // Por exemplo, você pode iterar pela lista e chamar delete em todos os objetos Ocorrencia.
    //cout << "Deletando... [" << nome << "]" << endl;
    Ocorrencia *atual = head;
    while (atual != nullptr) {
        Ocorrencia *temp = atual;
        atual = atual->next;
        delete temp;
    }
}

string ListaDeOcorrencia::defineNome(string nome){
    nome = nome;
    return nome;
}

string ListaDeOcorrencia::getNome(){
    return nome;
}
    void ListaDeOcorrencia::ImprimeListaOcorrencia(){
    Ocorrencia *ptr;
    if (head == NULL){
    printf("--- Lista Vazia\n");
    return;
    }
    // Caso a lista nao esteja vazia
    ptr = head;
    while (true){
    cout << "Pag = " << ptr->pag << endl;
    //cout << "Ocorrencia = " << ptr->numOcorrencia << endl;
    ptr = ptr->next;
    if (ptr==NULL)
        break;
    }
    cout <<"--- Fim da lista ---" << endl;
}
    
    //bool ListaDeOcorrencia::isEmpty(){}
    //int ListaDeOcorrencia::size(){}
    void ListaDeOcorrencia::add(int total){
        int pag = total/2500+1;

        if(!containsPag(total)){
            add(pag, 1);
        } else {
            set(pag, 1);
        }
    }

    //bool contains(int element);

    int ListaDeOcorrencia::getOcorrencia(int pag){
        Ocorrencia *atual = head;

        while (atual != nullptr){
            if (atual->pag == pag) {
                break;
            }
            atual = atual->next;
        }
        return atual->numOcorrencia;
    }

    bool ListaDeOcorrencia::containsPag(int total){
        total = total/2500+1;
        Ocorrencia* atual = head;
        while (atual != nullptr) {
            if (atual->pag == total) {
                return true; // O nó com o índice especificado já existe
            }
            atual = atual->next;
        }
        return false;
}

    void ListaDeOcorrencia::add(int pag, int numOcorrencia){ //Cria um do para uma nova página caso seja a primeira ocorrência 
    Ocorrencia *novo = new Ocorrencia(numOcorrencia);
    novo->pag = pag;
    count++;
        if(head == NULL){ // se a lista estiver vazia
        tail = novo;
        head = novo;
        } else {
        tail->next = novo;
        tail = novo;
        }
}

    int ListaDeOcorrencia::set(int pag, int numOcorrencia){
    int TotalOcorrencias;
    TotalOcorrencias = getOcorrencia(pag) + numOcorrencia;
    //numOcorrencia = TotalOcorrencias; 

    Ocorrencia *atual = head;

    while (atual != nullptr){
            if (atual->pag == pag) {
                atual->numOcorrencia = TotalOcorrencias;
                break;
            }
            atual = atual->next;
        }
    return atual->numOcorrencia;
    }
