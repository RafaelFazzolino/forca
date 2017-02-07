#include "util.h"

/*Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Algoritmos e Programação de Computadores – 0/2017
Aluno(a): Rafael Fazzolino Pinto Barbosa
Matricula: 11/0136942
Turma: VERAO
Versão do compilador: 4.8.4
Descricao: Neste arquivo se encontra toda a lógica do jogo, assim como o loop de repetição que obtem as palavras
do arquivo. Basicamente, a main só chama a função play, minimizando a quantidade de código dentro da main.
*/
	

/*Função destinada a lógica do jogo, assim como obtenção das palavras no arquivo*/
void play(){
	FILE *fp; /*variável utilizada para armazenar o arquivo.*/
	int i, j, perdeu =0;
	char chute, continua = 'S';
	int achou=0, pontuacao, letra_correta=0;

	

	/*Alocando espaço de memórica para os ponteiros stirng_alvo e string_decifrada*/
	string_alvo = malloc(sizeof(char*));
	string_decifrada = malloc(sizeof(char*));

	fp = fopen("palavras.txt", "r");/*Abrindo o arquivo em modo de leitura*/
	if(fp){/*Caso tenha sido aberto com sucesso*/
		/*Enquanto houver palavras e o jogador desejar continuar o jogo e que ele não tenha perdido, o loop continua*/
		while((fscanf(fp, "%s", string_alvo) != EOF) && (toupper(continua) == 'S') && (perdeu == 0)){
			fscanf(fp,"%d",&pontuacao);/*Leio a pontuação da palavra*/
			limpa_forca();
			parte_corpo = 0;
			decifra_string();/*Manipulo a string_decifrada com a quantidade de '_' necessária*/

			gerencia_alfabeto('.');/*Crio o vetor alfabeto*/
			i=0;
			while(parte_corpo<6){
				printf("\e[H\e[2J");/*Limpando a tela (linux)*/
				printf("*** JOGO DA FORCA ***\n");
				printf("PONTUACAO ACUMULADA = %d\n", pontuacao_total);
				printf("PONTUACAO DESTA PALAVRA = %d\n", pontuacao);
				if(i>0){/*Printando as partes já desenhadas (i>0 pq o usuário tem que ter tentado pelo menos uma vez)*/
					cria_forca(parte_corpo);
					imprime_forca();
				}

				printf("\nA palavra eh: %s\n", string_decifrada);

				/*Printando todas as opções de letras*/
				printf("------------------------------------------------------\n");
				for(j=0 ; j<=25 ; j++){
					printf("%c ", alfabeto[j]);
				}
				printf("\n------------------------------------------------------\n");
				do{/*Enquanto a entrada não for válida ou a entrada já tiver sido utilizada*/
				scanf(" %c", &chute);

				achou = gerencia_alfabeto(toupper(chute));/*Verifico a letra nas opções de letras*/
					
				}while(achou == 0);

				letra_correta = verifica_letra(chute);/*Verifica se a letra existe na palavra*/
				if(letra_correta == 0){/*Se não existir*/
					printf("Letra incorreta, voce ainda tem %d chances!\n", 5-i);
					printf("Tecle enter para continuar..\n");
					parte_corpo++;
					pontuacao = pontuacao - 5;/*diminuo 5 pontos*/
					getchar();
					getchar();
				}
				if(compara_string() == 0){/*Verifica se a string já foi decifrada*/
					printf("\e[H\e[2J");/*limpando a tela(linux)*/
					pontuacao_total += pontuacao;/*Acrescento a pontuação obtida na pontuação total*/
					printf("\n------------------------------------------------------\n");
					printf("PARABENS! Voce decifrou a palavra!\nA palavra e: %s\nVoce ganhou %d pontos!\n", string_decifrada, pontuacao);
					printf("Pontuacao total = %d\n", pontuacao_total);
					printf("\n------------------------------------------------------\n");
					break;
				}else{
					if(parte_corpo == 6){ /*Caso ele tenha perdido todas as chances sem decifrar a palavra*/
						printf("\e[H\e[2J");/*Limpando a tela (linux)*/
						cria_forca(6);
						imprime_forca();
						printf("\n------------------------------------------------------\n");
						printf("Infelizmente voce perdeu, boa sorte na próxima vez!\n");
						printf("\n------------------------------------------------------\n");
						perdeu = 1;/*Registrando que ele perdeu, para verificação do while*/
					}
				}
				i++;
			}
			fflush(stdin);
			printf("\n\nDeseja continuar jogando?(S/N)");
			scanf(" %c", &continua);
			/*Garantindo entrada válida*/
			while(continua != 's' && continua != 'S' && continua != 'N' && continua !=  'n'){
				printf("Entrada invalida, tente novamente:");
				scanf(" %c", &continua);
			}	
		}
	}

}