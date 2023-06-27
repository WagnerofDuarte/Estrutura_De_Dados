#include <Arquivo.h>

Arquivo::Arquivo(string _nomeDoArquivo){
    nomeDoArquivo = _nomeDoArquivo;
}

Lista* Arquivo::lerArquivo(){

    fstream arquivoDeLeitura(nomeDoArquivo);

    if(!arquivoDeLeitura){
        cout << "ARQUIVO NAO ECONTRADO" << endl;
        exit(1);
    }

    Lista* listaCaracteres = new Lista();

    string linha;
    string arquivoCompleto;

    while(getline(arquivoDeLeitura, linha)){
        arquivoCompleto = arquivoCompleto + '\n' + linha;
    }

    for(int i = 0; i < arquivoCompleto.size(); i++){
        listaCaracteres->insereFinal(arquivoCompleto[i], true);
    }

    return listaCaracteres;

}