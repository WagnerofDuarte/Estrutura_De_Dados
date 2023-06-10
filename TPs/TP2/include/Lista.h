#ifndef LISTA
#define LISTA

#include <CelulaListaPonto.h>
#include <CelulaListaReta.h>

class Lista {

    private:
        CelulaListaPonto* primeiro;
        CelulaListaPonto* ultimo;

        CelulaListaReta* primeiraReta;
        CelulaListaReta* ultimaReta;

        int tam;

        bool ponto_ou_reta;

    public:
        Lista(bool _ponto_ou_reta);
        ~Lista();

        void insereFinal(int _x, int _y, Ponto* A, Ponto* B);
        void insereInicio(int _x, int _y, Ponto* A, Ponto* B);
        void removeInicio();

        Ponto* menorPontoX();
        Ponto* menorPontoY();
        Ponto* pontoNaPosicao(int p);
        Reta* retaNaPosicao(int p);

        CelulaListaPonto* celulaNaPosicao(int p);

        void imprime();
        void limpa();

        int getTam();

        CelulaListaPonto* getPrimeiro();
        CelulaListaPonto* getUltimo();

        CelulaListaReta* getPrimeiraReta();

        void setPrimeiro(CelulaListaPonto* celula);
        void setUltimo(CelulaListaPonto* celula);

};

#endif