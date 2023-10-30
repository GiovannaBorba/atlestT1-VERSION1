// Iaçanã Ianiski Weber - 09/2023
#include <iostream>
#include <cstdlib>
#include <string>
#include "LeitorArquivo.hpp"
#include "menu.hpp"
#include "Palavra.hpp"
#include "ListaOrdenadaDePalavras.hpp"
#include "Ocorrencia.hpp"

using namespace std;

int main() {
    LeitorArquivo a = LeitorArquivo("Livros/alice.txt");
    ListaOrdenadaDePalavras teste;
    int k = 0;
    int MaxPalavras = 100;
    
    //string listas[MaxPalavras];
    //ListaDeOcorrencia lista("teste");

    int count = 0;
    ListaDeOcorrencia* listas[100000] = {nullptr};
    int i = 0;
    int total = 0;

    while(i<2500){
        string b = a.proximaPalavra();
        total = teste.pagina(total, b); 
        if(!b.empty()) b = teste.lowercase(b);
        if(teste.StopWords(b)){
            if(!teste.contains(b)){
            teste.add(b, total);
            //ListaDeOcorrencia *novaLista = new ListaDeOcorrencia(b);
            listas[k] = new ListaDeOcorrencia(b);
            //string ListaPalavra = novaLista->defineNome(b);
            //cout << "Teste palavra: " << ListaPalavra << endl; 
            //listas[k] = ListaPalavra;
            //cout << "Listas[" << k << "]: " << listas[k]->getNome() << endl;
            k++;
            }
        }

        for(int j = 0; j < k; j++){
            if(b == listas[j]->getNome()){
                //cout << "Estou aqui[" << j << "]: " << listas[j]->getNome() << endl;
                listas[j]->add(total);
                //listas[j]->ImprimeListaOcorrencia();
                break;
            }
        }
        //cout << b << endl;
        count++;
        //if(k == MaxPalavras) {MaxPalavras++;}
        if(b.empty()){
            break;   
        }
        i++;
    }

    /*for(int k = 0; k < 551; k++){
        //cout << "Palavra[" << k << "]: " << listas[k]->getNome() << endl;
        //listas[k]->ImprimeListaOcorrencia();
        //cout<<endl<<endl;
    }*/
    cout << "Counter: " << count << endl;
    cout << "Caracteres: " << total << endl;

    teste.ImprimeLista(*listas);

    ////[Menu Do Usuario]///

    int menu = 0;
    int flag = 0;

    /*while(flag != 1){
    cout << str();
    cin >> menu; 
    if(menu != 7){cout << "------------------------------" << endl;}


    switch (menu){
    ////////////////////////////////////////////////
    case 1:
        cout << "1. Indice remissimo em ordem alfabética:" << endl; 


        if(saida() == 7){
            flag = 1;
            encerrando();
            cout << "Volte sempre!" << endl;
            } 

        break;

    ////////////////////////////////////////////////
    case 2:
        cout << "2. Indice remissimo em ordem decrescente:" << endl; 


        if(saida() == 7){
            flag = 1;
            encerrando();
            cout << "Até mais!" << endl;
            } 

        break;

    ////////////////////////////////////////////////
    case 3:
        cout << "3. Informações sobre a catalogação:" << endl; 

        int tres;
        tres = FuncaoTres();
        if(tres == 1){}

        if(tres == 2){}

        if(tres == 3){}

        if(tres == 4){}

        
        if(tres == 7){
            flag = 1;
            encerrando();
            cout << "Adios!" << endl;
        } 

        break;

    ////////////////////////////////////////////////
    case 4:
        cout << "4. Indice remissimo em ordem alfabética:" << endl; 

        if(saida() == 7){
            flag = 1;
            encerrando();
            cout << "Tchau-Tchau!" << endl;
            } 

        break;

    ////////////////////////////////////////////////
    case 5:
        cout << "1. Indice remissimo em ordem alfabética:" << endl; 

 

        if(saida() == 7){
            flag = 1;
            encerrando();
            cout << "Até a próxima!" << endl;
            } 

        break;

    ////////////////////////////////////////////////
    case 6:
        cout << "1. Indice remissimo em ordem alfabética:" << endl; 



        if(saida() == 7){
            flag = 1;
            encerrando();
            cout << "Arrivederci!" << endl;
            } 

        break;

    ////////////////////////////////////////////////
    case 7:
        flag = 1;
        encerrando();
        cout << "Até logo!" << endl;
        break;

    ////////////////////////////////////////////////
    default:
        break;
        }
    }*/

for (int j = 0; j < 100; j++) {
    if (listas[j] != nullptr) {
        delete listas[j];
    }
}
}