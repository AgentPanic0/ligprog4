#include <iostream>
#include <string>
#include <vector>
#include "pacientePediatrico.h"
#include "pacienteGeriatrico.h"

using namespace std;

template <class P>
class Arvore
{
    public:
        Arvore() {raiz = NULL;}
        ~Arvore() {CaminharOrdemDelet(raiz);}

        void CaminharOrdemDelet(P *atual)
        {
            if (atual != NULL) 
            {
                CaminharOrdemDelet(atual->esq);
                CaminharOrdemDelet(atual->dir);
                delete atual;
            }
        }

        void CaminharOrdem(P* atual) 
        {
            if (atual != NULL) 
            {
                CaminharOrdem(atual->dir);
                cout << (*atual);
                CaminharOrdem(atual->esq);
            }
        }

        void imprime() { CaminharOrdem(raiz);}

        P* operator[] (string &nome)
        {
            if (raiz == NULL) return NULL; // se arvore vazia

            P *atual = raiz;  // começa a procurar desde raiz

            while (atual->getNome() != nome) 
            { // enquanto nao encontrou
                if(nome < atual->getNome())
                {
                    atual = atual->dir; // caminha para direita

                }
                else 
                {
                    atual = atual->esq; // caminha para esquerda
                }
                if (atual == NULL) return NULL; // encontrou uma folha -> sai
            }

            return atual;
        }

        template <typename T>
        Arvore<P>& operator+ (T &objeto)
        {
            P *novo = new T(objeto.getNome(), objeto.getIdade()); // cria um novo Nó

            if (raiz == NULL) 
            {
                raiz = novo;
            }
            else  
            {// se nao for a raiz
                P *atual = raiz;
                P *anterior;
                while(true) 
                {
                    anterior = atual;
                    if (objeto.getNome() <= atual->getNome()) 
                    {// ir para direita
                        atual = atual->dir;
                        if (atual == NULL) 
                        {
                            anterior->dir = novo;
                            return *this;
                        } 
                    }  // fim da condição ir a direita
                    else 
                    {// ir para esquerda
                        atual = atual->esq;
                        if (atual == NULL) 
                        {
                            anterior->esq = novo;
                            return *this;
                        }
                    }
                }
            }

            return *this;
        }
    private:
        P *raiz;
};
