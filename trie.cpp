#include <bits/stdc++.h>
//#include "arquivo.cpp"
#include "dicion.h"

#define ALPHABET_SIZE 26

#define false 0
#define true 1

struct BSTno {
        char *id;
        struct BSTno *filho[ALPHABET_SIZE*2]; 

};

struct trie {
    struct BSTno raiz;

};

struct trie tree;

int letra_int(char letra)
{
    if (letra >= 'A' && letra <= 'Z')
    {
        return letra - 'A' + 26;
    }
    else if (letra >= 'a' && letra <= 'z')
    {
        return letra - 'a';
    }
    return -1;
}

void p_invalida(const char *id, int index)
{
    printf("  id: \"%s\"\n", id);
    printf("         ");
    int i;
    for (i = 0; i < index; i++)
    {
        printf(" ");
    }
    printf("^\n");
}

int trie_insere(struct BSTno *node, const char *id, char *desc)
{
    int i;
    for (i = 0; i < strlen(id); i++)
    {
        int letra = letra_int(id[i]);
        if (letra == -1)
        {
            // Carateres inválidos corrompem a arvore.
            printf("Falha na id\n");
            p_invalida(id, i);
            printf("  Descrição: \"%s\"\n", desc);
            return false;
        }

        struct BSTno *pai = node;
        node = node->filho[letra];

        if (!node)
        {
           struct BSTno* node =(struct BSTno*) malloc(sizeof(struct BSTno));
            pai->filho[letra] = node;
        }
    }

    /*
    * Alocamento de memória da descrição
    */
    int len = strlen(desc);
    //node->id = malloc(len + 1);Não precisa em C++?
    strncpy(node->id, desc, len);
    return true;
}

//Passa pela Trie desde o nó raiz e procura individualmente pelas letras que compõem o id
char *trie_get(struct BSTno *node, const char *id)
{
    int i;
    for (i = 0; i < strlen(id); i++)
    {
        int letra = letra_int(id[i]);
        if (letra == -1)
        {
            return false;
        }

        node = node->filho[letra];
        if (!node)
        {
            return false; // Não tem
        }
    }
    return node->id;
}

void dicio_inic()
{
    tree = (struct trie) {}; // zero
}

int dicio_arq(const char * filename)
{
    // Abre em modo leitura
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        printf("Não foi possivel Abrir o Arq \"%s\"\n", filename);
        return false;
    }

    char id[MAX_WORD_SIZE];
    char desc[MAX_DESC_SIZE];

    int count = 0;

    while (fscanf(file, "%s %[^\n]", id, desc) > 1)
    {
        if (!trie_insere(&tree.raiz, id, desc))
        {
            fclose(file);
            return false;
        }
        else
        {
            count++;
        }
    }

    fclose(file);
    printf("parsed file \"%s\" with %i entries\n", filename, count);
    return true;
}

int dicio_ver(const char *id, char *signif)
{
    // Verificar Letras invalidas
    int i;
    for (i = 0; i < strlen(id); i++)
    {
        int letra = letra_int(id[i]);
        if (letra == -1)
        {
            printf("Letra invalida\n");
            p_invalida(id, i);
            return false;
        }
    }

    // Pega as descrições da Arvore
    char *desc = trie_get(&tree.raiz, id);

    if (!desc)
    {
        return false;
    }

    // copia a descrição em um buffer
    strcpy(signif, desc);

    return true;
}

