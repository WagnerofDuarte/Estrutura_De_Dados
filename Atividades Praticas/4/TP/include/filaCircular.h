#ifndef FILA_CIRCULAR
#define FILA_CIRCULAR

class FilaCircular {

    public:
        FilaCircular();
        void enfileira(int item);
        int desenfileira();
        void limpa();
    
    private:
        int frente;
        int tras;
        int tamanho;
        static const int MAXTAM = 10;
        int itens[MAXTAM];

};

#endif