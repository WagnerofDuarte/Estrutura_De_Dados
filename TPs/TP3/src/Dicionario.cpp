#include <Dicionario.h>

Dicionario::Dicionario(){
    primeiro = new PalavraDicionario('*', "");
    ultimo = primeiro;
    tam = 0;

}

// Insere, ao final do dicionário, um caractere e sua representacao compactada em bits
void Dicionario::insereLetra(char _caractere, string _bits){

    PalavraDicionario *nova = new PalavraDicionario(_caractere, _bits);

    if(tam == 0){
        delete primeiro;
        primeiro = nova;
        ultimo = primeiro;
    } else {
        ultimo->setProx(nova);
        ultimo = nova;
    }

    tam++;
}

// Busca e retorna a celula (PalavraDicionario) que possui a letra buscada
PalavraDicionario* Dicionario::buscarLetra(char letra){
    
    PalavraDicionario *aux = primeiro;

    while(aux->getCaractere() != letra){
        aux = aux->getProx();
    }

    return aux;

}

// Busca e retorna a celula (PalavraDicionario) que possui os bits buscado
PalavraDicionario* Dicionario::buscarBits(string bits){

    PalavraDicionario *aux = primeiro;

    while(aux->getBits() != bits){
        aux = aux->getProx();
    }

    return aux;

}

int Dicionario::getTam(){
    return tam;
}

PalavraDicionario* Dicionario::getPrimeiro(){
    return primeiro;
}

void Dicionario::setPrimeiro(PalavraDicionario* _primeiro){
    primeiro = _primeiro;
}

PalavraDicionario* Dicionario::getUltimo(){
    return ultimo;
}

void Dicionario::setUltimo(PalavraDicionario* _ultimo){
    ultimo = _ultimo;
}