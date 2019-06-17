#include <bits/stdc++.h>
#include "trie.cpp"
#include "dicion.h"


using namespace std;


/*

struct BSTno * criaNo(string ID, string nome, string idade, string genero_favorito, string filme_favorito, string guilty_pleasure) {
        struct BSTno *novono;
        novono = (struct BSTno *)malloc(sizeof(struct BSTno));
        novono->ID = ID;
        novono->nome = nome;
        novono->idade = idade;
        novono->genero_favorito = genero_favorito;
        novono->filme_favorito = filme_favorito;
        novono->guilty_pleasure = guilty_pleasure;
        novono->esq = novono-> dir = NULL;
        return novono;
}


void inserir(string ID,string nome, string idade, string genero_favorito, string filme_favorito, string guilty_pleasure) {
        struct BSTno *pai = NULL, *atual = NULL, *novono = NULL;
        int res = 0;
        if (!raiz) {
                raiz = criaNo(ID, nome, idade, genero_favorito, filme_favorito, guilty_pleasure);
                return;
        }
        for (atual = raiz; atual != NULL; atual = (res > 0) ? atual->dir : atual->esq )  {
                if(ID == atual->ID) res=0;
                else if(ID > atual->ID) res=1;
                else res=-1;
                if (res == 0) {
                        printf("ID ja Existente\n");
                return;
              }
        }
        novono = criaNo(ID, nome, idade, genero_favorito, filme_favorito, guilty_pleasure);
        res > 0 ? (pai->dir = novono) : (pai->esq = novono);
        return;
}

void procuraNome(string ID) {
        struct BSTno *temp = NULL;
        int flag = 0, res = 0;
        if (raiz == NULL) {
                printf("Não existe\n");
                return;
        }
        temp = raiz;
        while (temp) {

                if (temp->ID == ID) {
                  res=1;
                  }else{
                    res=0;
                    }

                //if ((res = strcasecmp(temp->ID, ID)) == 0)


                if (res == 0) {
                        printf("Nome   : %s", temp->nome.c_str());
                        printf("Idade  : %s", temp->idade.c_str());
                        printf("Genero Favorito  : %s", temp->genero_favorito.c_str());
                        printf("Filme Favorito   : %s", temp->filme_favorito.c_str());
                        printf("Guilty Pleasure  : %s", temp->guilty_pleasure.c_str());
                        flag = 1;
                        break;
                }
                temp = (res > 0) ? temp->esq : temp->dir;
        }
        if (!flag){
                printf("Elemento Não Existente\n");
        return ;
      }
}

void inorderTraversal(struct BSTno *myNode) {
        if (myNode) {
                inorderTraversal(myNode->esq);
                printf("Nome   : %s", myNode->nome.c_str());
                printf("Idade  : %s", myNode->idade.c_str());
                printf("Genero Favorito  : %s", myNode->genero_favorito.c_str());
                printf("Filme Favorito   : %s", myNode->filme_favorito.c_str());
                printf("Guilty Pleasure  : %s", myNode->guilty_pleasure.c_str());
                printf("\n");
                inorderTraversal(myNode->dir);
        }
        return;
}


        void deletaNo(string ID) {
        struct BSTno *pai = NULL, *atual = NULL, *temp = NULL;
        int flag = 0, res = 0;
        if (!raiz) {
                printf("BST n�o existe \n");
                return;
        }
        atual = raiz;
        while (1) {
                if (atual->ID == ID) {
                  res=1;
                }else{
                  res=0;
                }
                //res = strcasecmp(atual->ID, ID);
                if (res == 0)
                        break;
                flag = res;
                pai = atual;
                atual = (res > 0) ? atual->esq : atual->dir;
                if (atual == NULL)
                        return;
        }
        if (atual->dir == NULL) {
                if (atual == raiz && atual->esq == NULL) {
                        free(atual);
                        raiz = NULL;
                        return;
                } else if (atual == raiz) {
                        raiz = atual->esq;
                        free (atual);
                        return;
                }

                flag > 0 ? (pai->esq = atual->esq) :
                                (pai->dir = atual->esq);
        } else {
                temp = atual->dir;
                if (!temp->esq) {
                        temp->esq = atual->esq;
                        if (atual == raiz) {
                                raiz = temp;
                                free(atual);
                                return;
                        }
                        flag > 0 ? (pai->esq = temp) :
                                        (pai->dir = temp);
                } else {
                        struct BSTno *successor = NULL;
                        while (1) {
                                successor = temp->esq;
                                if (!successor->esq)
                                        break;
                                temp = successor;
                        }
                        temp->esq = successor->dir;
                        successor->esq = atual->esq;
                        successor->dir = atual->dir;
                        if (atual == raiz) {
                                raiz = successor;
                                free(atual);
                                return;
                        }
                        (flag > 0) ? (pai->esq = successor) :
                                        (pai->dir = successor);
                }
        }
        free (atual);
        return;
  }
*/