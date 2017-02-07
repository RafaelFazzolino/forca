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
	do{/*Criando um loop para menu, antes de entrar efetivamente no jogo*/
		printf("\e[H\e[2J");
		opcao = menu();/*Printa o menu e obtem a opção desejada do aluno*/
		switch(opcao){/*Fiz um switch pois pretendia adicionar algumas outras funcionalidades, 
		como incluir novas palavras no arquivo txt, por exemplo.. acho que incluo isto para a parte 2 */
			case 1: 
				printf("\e[H\e[2J");/*Limpando a tela (linux)*/
				play();/*Chamando o jogo*/
		}
		

	}while(opcao != 2);/*Se for, fim*/

	printf("\n--------------------------------------------------\n");
	printf("The End..\n");
	printf("--------------------------------------------------\n");
	return 0;
}