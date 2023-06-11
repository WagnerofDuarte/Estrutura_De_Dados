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
        void insereFinal(int _x, int _y, Ponto* A, Ponto* B);
        void insereInicio(int _x, int _y, Ponto* A, Ponto* B);
        void removeInicio();
        void imprime();
        void limpa();
        int getTam();
        void setPrimeiro(CelulaListaPonto* celula);
        void setUltimo(CelulaListaPonto* celula);
        Ponto* menorPontoX();
        Ponto* menorPontoY();
        Ponto* pontoNaPosicao(int p);
        Reta* retaNaPosicao(int p);
        CelulaListaPonto* celulaNaPosicao(int p);
        CelulaListaPonto* getPrimeiro();
        CelulaListaPonto* getUltimo();
        CelulaListaReta* getPrimeiraReta();
};

#endif