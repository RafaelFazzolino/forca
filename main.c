#include "forca.h"

/*Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Algoritmos e Programação de Computadores – 0/2017
Aluno(a): Rafael Fazzolino Pinto Barbosa
Matricula: 11/0136942
Turma: VERAO
Versão do compilador: 4.8.4
Descricao: Neste arquivo se encontra a função main, a qual fará a chamada para todo o restante do sistema.
Foram utilizados mais 2 arquivos (forca.h e util.h), para melhor distribuição das funções, visando a organização
do código.
*/
int main(){
	int opcao;
	do{
		printf("\e[H\e[2J");
		opcao = menu();
		switch(opcao){
			case 1: 
				printf("\e[H\e[2J");
				play();
		}
		

	}while(opcao != 5);

	return 0;
}