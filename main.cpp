#include <bits/stdc++.h>
#include "arquivo.cpp"
//#include "dicion.h"
//#include "trie.cpp"


//g++ -std=c++0x  "filename.cpp"

using namespace std;

int main(int argc, char ** argv){

    int escolha;
    char c;
    int dez=10;
    int rando=0;

    //Trecho Alterado ....
    char palavra[MAX_WORD_SIZE+1];
    char resposta[MAX_DESC_SIZE+1];
    dicio_inic();

    




    while(true){

        cout << "***********************************************************"<<endl;        
        cout << "*  1 - Gerar arquivo                                       *"<<endl;
        cout << "*  2 - Alimentar Arvore completa                           *"<<endl;
        cout << "*  3 - Alimentar Arvore com id                             *"<<endl;
        cout << "*  4 - Alimentar Arvore com 10 ids aleatórios              *"<<endl;
        cout << "*  5 - Buscar ID                                           *"<<endl;
        cout << "************************************************************  \n\n"<<endl;
        cin >> escolha;
        char *id;
        switch (escolha){

        case 1:
            gerar_arquivo();
            break;

        case 2:
            //Trecho Alterado
            for (int i = 1; i < argc; i++)
                {
                    dicio_arq(argv[i]);
                }
            

            break;

        case 3:
        	//c=id+'0';
          //  cout << "ID:";
          // cin >> id;

            break;

        case 4:

            while(dez--) {
                rando = rand()%MAX;
                c=rando+'0';
            }
            break;
        case 5:
            printf("ID: \n");
            scanf("%s",id);
            for (int i = 0; id[0] != '\0'; i++)
                {
                if (dicio_ver(id,resposta))
                {
                    printf("%s:\t%s\n", id, resposta);
                } else {
                    printf("%s:\t%s\n", id, "Não Exise");
                }
            }

            break;
        }
            
    }

    return 0;
}