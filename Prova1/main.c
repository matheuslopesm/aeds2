#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTAM 2
 typedef struct Funcionario {
     int cod;
     int salario;
     char nome[50];
     char cpf[15];
     char data_nascimento[11];
 }TFunc;

 void toString(TFunc *func);

int main(){

    FILE *arq;
    TFunc func;

    arq = fopen("dados.dat", "w+b");

    if(arq != NULL){
        for(int i = 0; i < MAXTAM; i++){
            printf("\nDigite o nome do Funcionario: ");
            gets(func.nome);
            fflush(stdin);
            fwrite(func.nome, sizeof(char), 50, arq);

            printf("Digite o CPF do Funcionario: ");
            gets(func.cpf);
            fflush(stdin);
            fwrite(func.cpf, sizeof(char), 15, arq);

            printf("Digite o Codigo do Funcionario: ");
            scanf("%i", &func.cod);
            fflush(stdin);
            fwrite(func.cod, sizeof(int), 0, arq);

            printf("Digite a data de nascimento: ");
            gets(func.data_nascimento);
            fflush(stdin);
            fwrite(func.data_nascimento, sizeof(char), 11, arq);

            printf("Digite o salário: ");
            scanf("%i", &func.salario);
            fflush(stdin);
            fwrite(func.salario, sizeof(int), 0, arq);
            // toString(&func);
        }   
    }
    
    fclose(arq);
    return 0;
}

// void toString(TFunc *func){
    
//     printf("Nome: %s", func->nome);
//     printf("\nCPF: %s", func->cpf);
//     printf("\nCódigo: %i", func->cod);
//     printf("\nSalário: %.2f", func->salario);
// }

//sequential_search (int vector[VECTOR_SIZE], int item)
// { //  
  //     for (int i = 0; i < VECTOR_SIZE; i++) {
 //  
   //        if (vector[i] == item) {
   //            return i;
    //       }
   //    }

 //   return -1;
// }