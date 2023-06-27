#include <Huffman.h>

Huffman::Huffman(){
    
    listaDeFrequencias = new Lista();

}

void Huffman::calcularFrequencias(Lista* listaDeCaracteres){
    
    for(int i = 0; i < listaDeCaracteres->getTam()-1; i++){
        char caractere = listaDeCaracteres->getPosicao(i)->getCaractere();
        CelulaLista *aux = listaDeFrequencias->getPrimeiro();
        while(aux != NULL){
            if(aux->getCaractere() == caractere){
                aux->incrementarFrequencia();
                break;
            }
            aux = aux->getProx();
        }
        if(aux == NULL){
            listaDeFrequencias->insereFinal(caractere, true);
        }
    }
}