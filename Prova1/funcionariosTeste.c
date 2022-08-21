#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionariosTeste.h"

int main(){

    FILE *arq = fopen("funcionarios.dat", "wb+");

    if(arq == NULL){
        printf("\n!!! ERRO AO ABRIR ARQUIVO !!!\n");
        return 1;
    }

    int qtd_Func = 10;
    cria_base_de_dados(arq, qtd_Func);
    Tfunc *func = busca_sequencial(9, arq, qtd_Func);

    if(func == NULL){
        printf("\n!!! Funcionario nao encontrado na base de dados\n");
    }else{
        printf("\n# Funcionario Encontrado!\n\n");
        printf("##### Dados do Funcionario #####\n");
        printf("\n* COD: %i", func->cod);
        printf("\n* Nome: %s", func->nome);
        printf("\n* CPF: %s", func->cpf);
        printf("\n* Data de Nascimento: %s", func->data_de_nascimento);
        printf("\n* Salario: %.2lf", func->salario);

    }

    free(func);
    fclose(arq);

    return 0;
}

void salva_arq(Tfunc *func, FILE *out){

    fwrite(&func->cod, sizeof(int), 1, out);
    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
    fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
    fwrite(func->data_de_nascimento, sizeof(char), sizeof(func->data_de_nascimento), out);
    fwrite(&func->salario, sizeof(double),1, out);

}

Tfunc *le(FILE *in){

    Tfunc *func = (Tfunc*) malloc(sizeof(Tfunc));

    if( 0 >= fread(&func->cod, sizeof(int), 1, in)){
        free(func);
        return NULL;
    }

    fread(func->nome, sizeof(char), sizeof(func->nome), in);
    fread(func->cpf, sizeof(char), sizeof(func->cpf), in);
    fread(func->data_de_nascimento, sizeof(char), sizeof(func->data_de_nascimento), in);
    fread(&func->salario, sizeof(double), 1, in);
    
    return func;

}

void cria_base_de_dados(FILE *arq, int qtd_func){

    for(int i = 1; i <= qtd_func; i++){

        Tfunc func;
        func.cod = i;
        sprintf(func.nome, "Funcionario %i", i);
        sprintf(func.cpf, "000.000.000-00");
        sprintf(func.data_de_nascimento, "00/00/0000");
        func.salario = 1000+i;
        fseek(arq, (i-1)*sizeof(Tfunc), SEEK_SET);
        salva_arq(&func, arq);
    }

}

// Implementação da busca sequencial conforme foi pedido na prova
Tfunc *busca_sequencial(int cod, FILE *arq, int tam_arq){

    for(int i=0; i<tam_arq; i++){
        fseek(arq, i*sizeof(Tfunc), SEEK_SET);
        Tfunc *func = le(arq);
        if(func->cod == cod){
            return func;
        }
    }

    return NULL;
}

Tfunc *insertionSorting(int cod, FILE *arq, int tam_arq){

    int i, j, x;

    for(i = 2; i<=tam_arq; i++){
        x = func.cod;
        j = i-1;
        cod
    }
}

void insercao (int vet, int tam){
int i, j, x;
for (i=2; i<=tam; i++){
	x = vet[i];
	j=i-1;
	vet[0] = x; 
	while (x < vet[j]){
        vet[j+1] = vet[j];
        j--;
    }
    vet[j+1] = x;
}