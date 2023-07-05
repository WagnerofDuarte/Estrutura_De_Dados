#ifndef LISTA
#define LISTA

#include <CelulaLista.h>

/* Esta classe é uma TAD Lista Encadeada que é usada amplamente por outros trechos do código deste projeto, 
   visando armazenar informacoes relevantes em comum em uma única instanciação de objeto */

class Lista {

    private:
        int tam;
        CelulaLista* primeiro;
        CelulaLista* ultimo;

    public:
        Lista();

        void insereFinal(char _caractere, bool _caractereValido);
        void removeInicio();
        void removePosicao(int posicao);
        
        int getTam();
        CelulaLista* getPrimeiro();
        CelulaLista* getUltimo();
        CelulaLista* getPosicao(int posicao);
        int reposiciona(int posicao);

        void copiaLista(Lista* lista);

        void ordena();
};

#endif