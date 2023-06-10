#include <Arquivos.h>

Arquivos::Arquivos(string _nomeDoArquivo){

    nomeDoArquivo = _nomeDoArquivo;

}


string Arquivos::lerArquivo(){

    fstream arquivoDeLeitura(nomeDoArquivo);

    if(!arquivoDeLeitura){
        cout << "ARQUIVO NAO ECONTRADO" << endl;
        exit(1);
    }

    string linha;
    string arquivoCompleto;

    while(getline(arquivoDeLeitura, linha)){

        arquivoCompleto = arquivoCompleto + "|" + linha;
    }

    return arquivoCompleto + "|";

}