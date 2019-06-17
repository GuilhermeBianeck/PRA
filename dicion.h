#ifndef DICION_H
#define DICION_H

#define MAX_WORD_SIZE   40 //Tamanho máximo de palavra no dicionário
#define MAX_DESC_SIZE  500 //Tamanho máximo da Descrição do dicionário

void dicio_inic();

int dicio_arq(const char * filename);

int dicio_ver(const char * nome, char * signif);

#endif
