#include <Huffman.h>

Huffman::Huffman(){
    
    listaDeFrequencias = new Lista();
    arvoreDeFrequencias = NULL;
    dicionario = NULL;
    textoCodificado = "";

}

/* Recebe a lista com todos os caracteres do arquivo e cria uma lista que possui cada caractere e 
   quantas vezes cada caractere apareceu  */
void Huffman::calcularFrequencias(Lista* listaDeCaracteres){
    
    for(int i = 0; i < listaDeCaracteres->getTam(); i++){
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

    for(int i = 0; i < listaDeFrequencias->getTam(); i++){
        CelulaLista* aux = listaDeFrequencias->getPosicao(i);
        aux->getArvoreFrequencias()->raiz->setFrequencia(aux->getFrequencia());
    }

}
/* Gera a árvore de codificacao de Huffman baseada na lista de frequencias já construida  */
void Huffman::gerarArvoreDeFrequencias(){

    Lista* listaPreArvoreDeFrequencias = new Lista();
    listaPreArvoreDeFrequencias->copiaLista(listaDeFrequencias);

    while(listaPreArvoreDeFrequencias->getTam() != 1){

        CelulaLista* primeiraCelula = listaPreArvoreDeFrequencias->getPrimeiro();
        CelulaLista* segundaCelula = listaPreArvoreDeFrequencias->getPrimeiro()->getProx();

        int frequenciaSomada = primeiraCelula->getArvoreFrequencias()->raiz->getFrequencia() + segundaCelula->getArvoreFrequencias()->raiz->getFrequencia();

        Arvore* arvoreAux = new Arvore('*', frequenciaSomada);
        arvoreAux->raiz->esq = primeiraCelula->getArvoreFrequencias()->raiz;
        arvoreAux->raiz->dir = segundaCelula->getArvoreFrequencias()->raiz;
    
        primeiraCelula->setCaractere('*');
        primeiraCelula->setFrequencia(frequenciaSomada);
        primeiraCelula->getArvoreFrequencias()->raiz = arvoreAux->raiz;

        listaPreArvoreDeFrequencias->removePosicao(1);
        listaPreArvoreDeFrequencias->reposiciona(0);
    }

    arvoreDeFrequencias = listaPreArvoreDeFrequencias->getPrimeiro()->getArvoreFrequencias();

}

// Gera o dicionário que possui as representacoes binarias compactadas de cada caractere
void Huffman::gerarDicionario(){
    
    dicionario = new Dicionario();
    preencheDicionario(arvoreDeFrequencias->raiz, "");

}
// Preenche o dicionário com as representacoes binarias compactadas de cada caractere
void Huffman::preencheDicionario(NoArvore* p, string bits){

    if(p != NULL){
        preencheDicionario(p->esq, (bits+"0"));
        if(p->esq == NULL && p->dir == NULL){
            dicionario->insereLetra(p->getCaractere(), bits);
        }
        preencheDicionario(p->dir, (bits+"1"));
    }
}

/* Cria a string que armazenará a representacao binaria compactada do texto do arquivo de entrada*/
void Huffman::codificar(Lista* listaCaracteres){

    CelulaLista* aux = listaCaracteres->getPrimeiro();
    while(aux != NULL){
        textoCodificado = textoCodificado + dicionario->buscarLetra(aux->getCaractere())->getBits();
        aux = aux->getProx();
    }
}
/* Irá chamar todos os métodos que são responsáveis por compactar o arquivo, e criar o arquivo compactado */
void Huffman::compactar(char const * nomeDoArquivo){

    Arquivo* arquivo = new Arquivo("");
    arquivo->compactar(textoCodificado, nomeDoArquivo, listaDeFrequencias);
}

/* Irá chamar todos os métodos que são responsáveis por descompactar o arquivo, e criar o arquivo descompactado */
void Huffman::descompactar(char const *nomeDoArquivoComp, char const *nomeDoArquivo){

    Arquivo* arquivo = new Arquivo("");
    listaDeFrequencias = arquivo->extrairListaDeFrequencias(nomeDoArquivoComp);
    gerarArvoreDeFrequencias();
    arquivo->descompactar(nomeDoArquivoComp, nomeDoArquivo, getArvoreDeFrequencias()->raiz);
}

Lista* Huffman::getListaDeFrequecias(){
    return listaDeFrequencias;
}
Arvore* Huffman::getArvoreDeFrequencias(){
    return arvoreDeFrequencias;
}