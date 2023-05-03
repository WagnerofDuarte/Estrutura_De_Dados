#ifndef CELULA_LISTA
#define CELULA_LISTA

class CelulaLista {

    private:
        char caractere;
        double num;
        CelulaLista *prox;
        
    public:
        CelulaLista();
        ~CelulaLista();

        char getCaractere();
        double getNum();
        CelulaLista* getProx();

        void setCaractere(char _caractere);
        void setNum(double _num);
        void setProx(CelulaLista *_prox);
};

#endif