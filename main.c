#include <stdio.h>
#include <stdlib.h>
#include "algebra.h"
#include <string.h>
#include <windows.h>
#include <locale.h>

Mat *listaMats[15];

int auxiliar = 0;

int menu();

int main(int argc, char *argv[])
{

char *nome, *nomes;
Mat *M, *M2, *resut, *ops, *temp, *A, *M3, *M4, *M5, *M6, *M7,*M8;
int uso, num, escolha, variavel,x=0,k,p,s,q,r;

	zerarlista();

	int Menu()
	{
	int escolha;
		listaMat();
	printf("**************************************************\n");
	printf("*********************UNASP-SP*********************\n");
	printf("******   DISCIPLINA:                          ****\n");
	printf("******   PROFESSOR: Thiago                    ****\n");
	printf("******   ALUNO: Mouzinho Feliz Raimundo       ****\n");
	printf("******   RA: 102785                           ****\n");
	printf("**************************************************\n");
	printf("**************************************************\n");
	printf("********** 0- SAIR                    ************\n");
	printf("********** 1- CARREGA MATRIZ          ************\n");
	printf("********** 2- EXIBIR MATRIZ           ************\n");
	printf("********** 3- SOMA DE MATRIZ          ************\n");
	printf("********** 4- MULTIPLICAÇÃO DE MATRIZ ************\n");
	printf("********** 5- MATRIZ TRANSPOSTA       ************\n");
	printf("********** 6- DETERMINANTE            ************\n");
	printf("********** 7- SISTEMA DE EQUAÇOES     ************\n");
	printf("********** 8- LER ARQUIVO TXT         ************\n");
	printf("********** 9- ESCREVER NO ARQUIVO TXT ************\n");
	printf("********** 10-EXIBIR LISTA MAT        ************\n");
	printf("********** 11-REMOVER DA LISTA        ************\n");
	printf("********** 12-LISTA DAS MATRIZES      ************\n");
	printf("********** 13-EQN                     ************\n");
	printf("\t\t\t\n\n OPCAO: \n\n");
	printf("**************************************************\n");
	printf("\t\t\t\n\n OPCAO: ");
	scanf("%d", &escolha);
	return escolha;
	}
	
	while(x>=0){
	
	
	switch(escolha)
	{
		
		
			case 0:{
				return 0;
				break;

				}

			case 1:{

				M = criaMat();
				carregaM(M);
				insereMatList(M);

				break;
			}

			case 2:{

				printf("Escolha a matriz:");
				scanf("%d",&q);
				showMat(listaMats[q]);
				/*getch();*/

				break;
			}

			case 3:{
				printf("Escolher primeira Matriz:");
				scanf("%d",&p);
				printf("Escolher segunda Matriz:");
				scanf("%d",&s);
				M=listaMats[p];
				M2=listaMats[s];
				printf("\n\n");
				showMat(M);
				showMat(M2);
				ops = somaMat(M, M2);
				showMat(ops);
				
				
				/*M= criaMat();
				carregaM (M);
				printf("\n");
	
				M2 = criaMat();
				carregaM (M2);
				printf("\n");

				ops = somaMat(M, M2);
				showMat(ops);
				printf("\n");
				break;*/

				/*getch();*/

				liberaMat(M);
				liberaMat(M2);
				liberaMat(ops);
				break;

				}

			case 4:{
				printf("Escolher primeira Matriz:");
				scanf("%d",&p);
				printf("Escolher segunda Matriz");
				scanf("%d",&s);
				M=listaMats[p];
				M2=listaMats[s];
				printf("\n\n");
				showMat(M);
				showMat(M2);
				temp = multMat(M,M2);
				showMat(temp);

				/*getch();*/

				liberaMat(M);
				liberaMat(M2);
				liberaMat(temp);
				break;

				}

			case 5:{
				printf("Escolher Matriz:");
				scanf("%d",&p);
				M3=listaMats[p];
				printf("\n\n");
				showMat(M3);
				A =	TranspMat(M3);
				insereMatList(A);
				showMat(A);

				getch();

				liberaMat(M3);
				liberaMat(A);

				break;
				}

			case 6:{

				printf("Escolher Matriz:");
				scanf("%d",&p);
				//printf("nome %s %d x %d \n",listaMats[p]->nome,listaMats[p]->l,listaMats[p]->c);
				//getch();
				M7=listaMats[p];
				r=detMat(M7);
				printf("\n\n\t >>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Determinante:%d",r);
				getch();
				liberaMat(M7);

				break;
			}
			case 7:{

				printf("Escolher Matriz:");
				scanf("%d",&p);
				M8=listaMats[p];

				break;
			}
            case 8:{

				lerArquivo();

				break;
			}

			case 9:{

				printf("Escolher Matriz:.");
				scanf("%d",&p);
				M=listaMats[p];
				showMat(M);
				escreverArquivo(p);
				break;
			}

			case 10:{
				listaMat();
				showMat(listaMats[x]);

				break;
				}

			case 11:{

				printf("Escolher posicao da matriz:");
				scanf("d%",&k);
				removeMatList(k);

			break;
			}

			case 12:{

				listaMat();
				break;
				}

		}
	}
    return 0;

}
/*
	
		case 1 : 
			
				printf("\nA OPERACAO QUE O USUARIO ESCOLHEU FOI SOMA DE MATRIZ \n\n");

				M= criaMat();
				carregaM (M);
				printf("\n");
	
				M2 = criaMat();
				carregaM (M2);
				printf("\n");

				ops = somaMat(M, M2);
				showMat(ops);
				printf("\n");
				break;
		
		
		case 2 : 
			
				printf("\nA OPERACAO QUE O USUARIO ESCOLHEU FOI MULTIPLICACAO DE MATRIZ \n\n");
				M= criaMat();
				carregaM (M);
				printf("\n");
	
				M2 = criaMat();
				carregaM (M2);
				printf("\n");
				
				temp = multMat (M, M2);
				showMat(temp);
				printf("\n");

				
				break;
				
	
		case 3 : 
			
				printf("\nMATRIZ TRANSPOSTA\n\n");

				M= criaMat();
				carregaM (M);
				printf("\n");

				A= TranspMat(M);
				showMat(A);
				printf("\n");
	

				return(0);
			
	}
	
	
	}while(num>=1 && num<=3);
}*/










	