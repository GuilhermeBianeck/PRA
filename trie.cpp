#include <bits/stdc++.h>
#include "arvore.cpp"
#include "arquivo.cpp"

#define ALPHABET_SIZE = 26

struct trie tree;

typedef struct {
        char *nome;
        struct BSTno *filho[ALPHABET_SIZE*2];

}BSTno;

typedef struct {
    struct BSTno *raiz;

}trie;

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

void p_invalida(const char *nome, int index)
{
    printf("  nome: \"%s\"\n", nome);
    printf("         ");
    int i;
    for (i = 0; i < index; i++)
    {
        printf(" ");
    }
    printf("^\n");
}

int trie_insere(struct BSTno *node, const char *nome, char *desc)
{
    int i;
    for (i = 0; i < strlen(nome); i++)
    {
        int letra = letra_int(nome[i]);
        if (letra == -1)
        {
            // Carateres inválidos corrompem a arvore.
            printf("Falha na nome\n");
            p_invalida(nome, i);
            printf("  Descrição: \"%s\"\n", desc);
            return false;
        }

        struct BSTno *pai = node;
        node = node->filho[letra];

        if (!node)
        {
            node = malloc(sizeof(struct BSTno));
            pai->filho[letter] = node;
        }
    }

    /*
    * Alocamento de memória da descrição
    */
    int len = strlen(desc);
    node->value = malloc(len + 1);
    strncpy(node->nome, desc, len);
    return true;
}

//Passa pela Trie desde o nó raiz e procura individualmente pelas letras que compõem o nome
char *trie_get(struct BSTno *node, const char *nome)
{
    int i;
    for (i = 0; i < strlen(nome); i++)
    {
        int letra = letra_int(nome[i]);
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
    return node->nome;
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

    char nome[MAX_WORD_SIZE];
    char desc[MAX_DESC_SIZE];

    int count = 0;

    while (fscanf(file, "%s %[^\n]", nome, desc) > 1)
    {
        if (!trie_insere(&tree.raiz, nome, desc))
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

int dicio_ver(const char *nome, char *signif)
{
    // Verificar Letras invalidas
    int i;
    for (i = 0; i < strlen(nome); i++)
    {
        int letra = letra_int(nome[i]);
        if (letter == -1)
        {
            printf("Letra invalida\n");
            p_invalida(nome, i);
            return false;
        }
    }

    // Pega as descrições da Arvore
    char *desc = trie_get(&tree.raiz, nome);

    if (!desc)
    {
        return false;
    }

    // copia a descrição em um buffer
    strcpy(signif, desc);

    return true;
}

