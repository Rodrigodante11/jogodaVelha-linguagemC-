//nome da varievel=getchar()  varivel pega um carater

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h> //mudar cor de tela
#include<string.h>
#include<stack> //nao estou usando  essa 
#include<time.h>
#include<windows.h> //para usar Sleep

void menuJogo()
{
	printf("-------------------------------MENU-DO-JOGO-------------------------------------\n");
	printf("\t\tPara iniciar o jogo com jogador 1   Digite (1)\n");//Menu do meu programa
	printf("\t\tPara iniciar o jogo com jogador 2   Digite (2)\n");
	printf("\t\tPara preencimento automatico        Digite (3)\n");
	printf("\t\tPara sair \t\t            Digite (4)\n\n\n\n\n\n\n\n");
}
void cabecalho()
{
	printf("--------------------------------------------------------------------------------\n");
	printf("-----------------------------PROGRAMA RODRIGO-----------------------------------\n");
	printf("--------------------------------------------------------------------------------\n");
}

void cabecalho2()
{
	printf("-----------------------------PROGRAMA RODRIGO-----------------------------------\n");
	printf("------------------------------JOGO-DA-VELHA-------------------------------------\n");
	printf("--------------------------------------------------------------------------------\n");
}

void tabela()
{
	printf("\t\t\t    Tabela de cores: \n\n");
	printf("\t\t\t0 - PRETO \t8 - CINZA\n");
	printf("\t\t\t1 - AZUL  \t9 - AZUL CLARO\n");
	printf("\t\t\t2 - VERDE  \tA - VERDE CLARO \n");
	printf("\t\t\t3 - VERDE-ÁGUA  B - VERDE-ÁGUA CLARO \n");   //menu de cores
	printf("\t\t\t4 - VERMELHO  \tC - VERMELHO CLARO \n");
	printf("\t\t\t5 - ROXO  \tD - LILÁS \n");
	printf("\t\t\t6 - AMARELO  \tE - AMARELO-CLARO\n");
	printf("\t\t\t7 - BRANCO  \tF - BRANCO BRILHANTE\n");
}

void divisorTela()
{
	printf("--------------------------------------------------------------------------------\n"); //separando o cabecalho do menu
}

int main()
{

	char opcaoCor[2] , velha[4][4];
	char comando[9] = "color " ;
	int opMenu, mensagem = 0, desejando = 0, l, c; //varivel mensagem pra exibir critica ao usuario
	int fim = 0, opcaoInvalida, cont = 0, volta, jogador, colunaRandom, linhaRandom, voltaRandom = 0;
	int  tudo = 0, jogada = 0;

	setlocale(LC_ALL, "Portuguese");

	cabecalho();
	tabela();
	divisorTela();

	printf("Digite a cor de fundo desejada: ");
	scanf("%s", &opcaoCor[0]);
	getchar(); // igual (cin.ignore()) do c++, mas tambem pode ser usado pra capturar frases com espaco

	printf("\nDigite a cor da letra desejada: ");
	scanf("%s", &opcaoCor[1]);

	strcat(comando, opcaoCor);  //juntando strings
	system(comando);  // mudando a cor exemplo system("color 3e")

	do
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				velha [i][j] = ' ';
			}
		}
		system("cls");
		cabecalho2();
		menuJogo();

		do
		{
			if(mensagem > 0) printf("\n\t\t\tOpção invalida !!\n"); //exibindo mesagem ao usuario apos roda o loop uma vez
			printf("\t\t\tDigite opcao desejada:");
			scanf("%i", &opMenu);
			mensagem ++;
		}
		while(opMenu < 1 || opMenu > 4 );

		mensagem = 0; //zerando a varivel de criticar o usuario para usar mais vezes

		do
		{
			fim = 0;
			jogada=0;
			cont = 0;
			tudo = 0;
			voltaRandom = 0;
			switch(opMenu)
			{

//////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 1:
				do
				{
					system("cls");
					cabecalho();

					if(desejando == 0) printf("\n\t\tJogo começou boa sorte aos Participantes \n\n");
					desejando++;
					for(int i = 0; i < 3; i++)
					{
						printf("\n\t\t\t\t");
						for(int j = 0; j < 3; j++)
						{
							if(j < 2) printf("%c|", velha [i][j]) ;
							else printf("%c", velha [i][j]) ;

						}
						if(i < 2)printf("\n\t\t\t       _______");
					}
					if(mensagem > 0) printf("\n\n\t\t\tOpção invalida na matriz!!\n");
					mensagem = 0;
					do
					{
						if(mensagem > 0) printf("\t\t\tOpção invalida !!\n");
						printf("\n\n\t\tJogador 1 digite a Linha desejada:");
						scanf("%d", &l);
						mensagem++;
					}
					while(l < 0 || l > 2);

					mensagem = 0;

					do
					{
						if(mensagem > 0) printf("\t\t\tOpção invalida !!\n");
						printf("\n\n\t\tJogador 1 digite a coluna desejada:");
						scanf("%d", &c);
						mensagem++;
					}
					while(c < 0 || c > 2);

					mensagem = 0;

					if(velha[l][c] == 'O' || velha[l][c] == 'X')
					{
						opcaoInvalida++;
						mensagem++;
					}
					else
					{
						velha[l][c] = 'O';
						opcaoInvalida = 0;
						if((velha[0][0] == 'O' && velha[0][1] == 'O' && velha[0][2] == 'O') ||
								(velha[1][0] == 'O' && velha[1][1] == 'O' && velha[1][2] == 'O') ||
								(velha[2][0] == 'O' && velha[2][1] == 'O' && velha[2][2] == 'O') ||
								(velha[0][0] == 'O' && velha[1][1] == 'O' && velha[2][2] == 'O') ||
								(velha[0][2] == 'O' && velha[1][1] == 'O' && velha[2][0] == 'O') ||  //condiçao para ver se ganho
								(velha[0][0] == 'O' && velha[1][0] == 'O' && velha[2][0] == 'O') ||
								(velha[0][1] == 'O' && velha[1][1] == 'O' && velha[2][1] == 'O') ||
								(velha[0][2] == 'O' && velha[1][2] == 'O' && velha[2][2] == 'O'))
						{
							system("cls");
							cabecalho();

							for(int i = 0; i < 3; i++)
							{
								printf("\n\t\t\t\t");
								for(int j = 0; j < 3; j++)
								{
									if(j < 2) printf("%c|", velha [i][j]) ;
									else printf("%c", velha [i][j]) ;

								}
								if(i < 2)printf("\n\t\t\t       _______");
							}
							printf("\n\n\t\t\tjogador 1 venceu !!\n");
							printf("\n\n\t\t\tPaaraabeensss !!\n");
							fim++;
							for(int i = 0; i < 3; i++)
							{
								for(int j = 0; j < 3; j++) //zerar a matriz cade vez que alguem ganhar ou der velha
								{
									velha [i][j] = ' ';
								}
							}
						}
						for(int i = 0; i < 3; i++)
						{
							for(int j = 0; j < 3; j++)
							{
								if(velha [i][j] == 'X' || velha [i][j] == 'O') //for para ver se deu velha
								{
									cont++;
								}
							}
						}
						if(cont == 9) //condiçao para ver se deu velha
						{
							system("cls");
							cabecalho();

							for(int i = 0; i < 3; i++)
							{
								printf("\n\t\t\t\t");
								for(int j = 0; j < 3; j++)
								{
									if(j < 2) printf("%c|", velha [i][j]) ;
									else printf("%c", velha [i][j]) ;

								}
								if(i < 2)printf("\n\t\t\t       _______");
							}
							printf("\n\n\t\t\tDeu velha !!\n");
							printf("\n\n\t\t\tNinguem ganhou !!\n");
							fim++;
							for(int i = 0; i < 3; i++)
							{
								for(int j = 0; j < 3; j++) //zerar a matriz cade vez que alguem ganhar ou der velha
								{
									velha [i][j] = ' ';
								}
							}
						}
						cont = 0;  //zerando varivel se nao deu velha
					}
				}
				while(opcaoInvalida > 0);

				desejando++;
				opMenu = 2;
				break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 2:
				do
				{
					system("cls");
					cabecalho();

					if(desejando == 0) printf("\n\t\tJogo começou boa sorte aos Participantes \n\n");
					desejando++;
					for(int i = 0; i < 3; i++)
					{
						printf("\n\t\t\t\t");
						for(int j = 0; j < 3; j++)
						{
							if(j < 2) printf("%c|", velha [i][j]) ;
							else printf("%c", velha [i][j]) ;

						}
						if(i < 2)printf("\n\t\t\t       _______");
					}

					if(mensagem > 0) printf("\n\n\t\t\tOpção invalida na matriz!!\n");

					mensagem = 0;

					do
					{
						if(mensagem > 0) printf("\t\t\tOpção invalida !!\n");
						printf("\n\n\t\tJogador 2 digite a Linha desejada:");
						scanf("%d", &l);
						mensagem++;
					}
					while(l < 0 || l > 2);

					mensagem = 0;

					do
					{
						if(mensagem > 0) printf("\t\t\tOpção invalida !!\n");
						printf("\n\n\t\tJogador 2 digite a coluna desejada:");
						scanf("%d", &c);
						mensagem++;
					}
					while(c < 0 || c > 2);
					mensagem = 0;

					if(velha[l][c] == 'O' || velha[l][c] == 'X')
					{
						opcaoInvalida++;
						mensagem++;
					}

					else
					{
						velha[l][c] = 'X';
						opcaoInvalida = 0;

						if((velha[0][0] == 'X' && velha[0][1] == 'X' && velha[0][2] == 'X') ||
								(velha[1][0] == 'X' && velha[1][1] == 'X' && velha[1][2] == 'X') ||
								(velha[2][0] == 'X' && velha[2][1] == 'X' && velha[2][2] == 'X') ||
								(velha[0][0] == 'X' && velha[1][1] == 'X' && velha[2][2] == 'X') ||
								(velha[0][2] == 'X' && velha[1][1] == 'X' && velha[2][0] == 'X') ||
								(velha[0][0] == 'X' && velha[1][0] == 'X' && velha[2][0] == 'X') ||
								(velha[0][1] == 'X' && velha[1][1] == 'X' && velha[2][1] == 'X') ||
								(velha[0][2] == 'X' && velha[1][2] == 'X' && velha[2][2] == 'X') )
						{
							system("cls");
							cabecalho();

							for(int i = 0; i < 3; i++)
							{
								printf("\n\t\t\t\t");
								for(int j = 0; j < 3; j++)
								{
									if(j < 2) printf("%c|", velha [i][j]) ;
									else printf("%c", velha [i][j]) ;

								}
								if(i < 2)printf("\n\t\t\t       _______");
							}
							printf("\n\n\t\t\tjogador 2 venceu !!\n");
							printf("\n\n\t\t\tPaaraabeensss !!");
							fim++;
							for(int i = 0; i < 3; i++)
							{
								for(int j = 0; j < 3; j++) //zerar a matriz cade vez que alguem ganhar ou der velha
								{
									velha [i][j] = ' ';
								}
							}
						}
						for(int i = 0; i < 3; i++)
						{
							for(int j = 0; j < 3; j++)
							{
								if(velha [i][j] == 'X' || velha [i][j] == 'O')
								{
									cont++;
								}
							}
						}
						if(cont == 9)
						{
							system("cls");
							cabecalho();

							for(int i = 0; i < 3; i++)
							{
								printf("\n\t\t\t\t");
								for(int j = 0; j < 3; j++)
								{
									if(j < 2) printf("%c|", velha [i][j]) ;
									else printf("%c", velha [i][j]) ;

								}
								if(i < 2)printf("\n\t\t\t       _______");
							}
							printf("\n\n\t\t\tDeu velha !!\n");
							printf("\n\n\t\t\tNinguem ganhou !!\n");
							fim++;
							for(int i = 0; i < 3; i++)
							{
								for(int j = 0; j < 3; j++) //zerar a matriz cade vez que alguem ganhar ou der velha
								{
									velha [i][j] = ' ';
								}
							}
						}
						cont = 0;
					}
				}
				while(opcaoInvalida > 0);

				desejando++;
				opMenu = 1;
				break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 3:
				system("cls");
				cabecalho();

				do
				{

					srand(time(NULL));

					if(tudo == 0)
					{
						for(int i = 0; i < 3; i++)
						{
							printf("\n\t\t\t\t");
							for(int j = 0; j < 3; j++)
							{
								if(j < 2) printf("%c|", velha [i][j]) ;
								else printf("%c", velha [i][j]) ;

							}
							if(i < 2)printf("\n\t\t\t       _______");
						}
					}

					jogador = 2;

					do
					{
						if(jogador == 2)
						{
							do
							{
								colunaRandom = (rand() % 3) ;
								linhaRandom = (rand() % 3) ;
								if(velha[linhaRandom][colunaRandom] == 'O' || velha[linhaRandom][colunaRandom] == 'X')
								{
									voltaRandom++;
									tudo++;
								}
								else if(velha[linhaRandom][colunaRandom] == ' ')
								{
									velha[linhaRandom][colunaRandom] = 'X';
									voltaRandom = 0;
									jogador = 1;
									jogada++;
									Sleep(1000);
									system("cls");
									cabecalho();
									for(int i = 0; i < 3; i++)
									{
										printf("\n\t\t\t\t");
										for(int j = 0; j < 3; j++)
										{
											if(j < 2) printf("%c|", velha [i][j]) ;
											else printf("%c", velha [i][j]) ;

										}
										if(i < 2)printf("\n\t\t\t       _______");
									}
									tudo = 0;
								}
							}
							while(voltaRandom != 0);
						}

						else if(jogador == 1)  // tive que colocar o else senao ia roda de dois em dois no loop
						{
							//tira o comentario da linha 476 para testar comentario acima
							do
							{
								colunaRandom = (rand() % 3) ;
								linhaRandom = (rand() % 3) ;

								if(velha[linhaRandom][colunaRandom] == 'O' || velha[linhaRandom][colunaRandom] == 'X')
								{
									voltaRandom++;
									tudo++;
								}
								else if(velha[linhaRandom][colunaRandom] == ' ')
								{
									velha[linhaRandom][colunaRandom] = 'O';
									voltaRandom = 0;
									jogador = 2;
									jogada++;
									Sleep(1000);
									system("cls");
									cabecalho();
									for(int i = 0; i < 3; i++)
									{
										printf("\n\t\t\t\t");
										for(int j = 0; j < 3; j++)
										{
											if(j < 2) printf("%c|", velha [i][j]) ;
											else printf("%c", velha [i][j]) ;
										}
										if(i < 2)printf("\n\t\t\t       _______");
									}
									tudo = 0;
								}
							}
							while(voltaRandom != 0);
						}
						for(int i = 0; i < 3; i++)
						{
							for(int j = 0; j < 3; j++)
							{
								if(velha [i][j] == 'X' || velha [i][j] == 'O')
								{
									cont++;
								}
							}
						}
						if((velha[0][0] == 'X' && velha[0][1] == 'X' && velha[0][2] == 'X') ||
								(velha[1][0] == 'X' && velha[1][1] == 'X' && velha[1][2] == 'X') ||
								(velha[2][0] == 'X' && velha[2][1] == 'X' && velha[2][2] == 'X') ||
								(velha[0][0] == 'X' && velha[1][1] == 'X' && velha[2][2] == 'X') ||
								(velha[0][2] == 'X' && velha[1][1] == 'X' && velha[2][0] == 'X') ||
								(velha[0][0] == 'X' && velha[1][0] == 'X' && velha[2][0] == 'X') ||
								(velha[0][1] == 'X' && velha[1][1] == 'X' && velha[2][1] == 'X') ||
								(velha[0][2] == 'X' && velha[1][2] == 'X' && velha[2][2] == 'X') )
						{
							system("cls");
							cabecalho();

							for(int i = 0; i < 3; i++)
							{
								printf("\n\t\t\t\t");
								for(int j = 0; j < 3; j++)
								{
									if(j < 2) printf("%c|", velha [i][j]) ;
									else printf("%c", velha [i][j]) ;

								}
								if(i < 2)printf("\n\t\t\t       _______");
							}
							printf("\n\n\t\t\tjogador 2 do Computador venceu ganhou !!\n");
							printf("\n\n\t\t\tPaaraabeensss !!");
							fim++;
							jogada = 9;
							for(int i = 0; i < 3; i++)
							{
								for(int j = 0; j < 3; j++) //zerar a matriz cade vez que alguem ganhar ou der velha
								{
									velha [i][j] = ' ';
								}
							}
						}
						else if((velha[0][0] == 'O' && velha[0][1] == 'O' && velha[0][2] == 'O') ||
								(velha[1][0] == 'O' && velha[1][1] == 'O' && velha[1][2] == 'O') ||
								(velha[2][0] == 'O' && velha[2][1] == 'O' && velha[2][2] == 'O') ||
								(velha[0][0] == 'O' && velha[1][1] == 'O' && velha[2][2] == 'O') ||
								(velha[0][2] == 'O' && velha[1][1] == 'O' && velha[2][0] == 'O') ||  //condiçao para ver se ganho
								(velha[0][0] == 'O' && velha[1][0] == 'O' && velha[2][0] == 'O') ||
								(velha[0][1] == 'O' && velha[1][1] == 'O' && velha[2][1] == 'O') ||
								(velha[0][2] == 'O' && velha[1][2] == 'O' && velha[2][2] == 'O'))
						{
							system("cls");
							cabecalho();

							for(int i = 0; i < 3; i++)
							{
								printf("\n\t\t\t\t");
								for(int j = 0; j < 3; j++)
								{
									if(j < 2) printf("%c|", velha [i][j]) ;
									else printf("%c", velha [i][j]) ;

								}
								if(i < 2)printf("\n\t\t\t       _______");
							}
							printf("\n\n\t\t\tjogador 1 venceu do computador ganhou !!\n");
							printf("\n\n\t\t\tPaaraabeensss !!\n");
							fim++;
							jogada = 9;
							for(int i = 0; i < 3; i++)
							{
								for(int j = 0; j < 3; j++) //zerar a matriz cade vez que alguem ganhar ou der velha
								{
									velha [i][j] = ' ';
								}
							}
						}

						else if(cont == 9)
						{
							system("cls");
							cabecalho();

							for(int i = 0; i < 3; i++)
							{
								printf("\n\t\t\t\t");
								for(int j = 0; j < 3; j++)
								{
									if(j < 2) printf("%c|", velha [i][j]) ;
									else printf("%c", velha [i][j]) ;
								}
								if(i < 2)printf("\n\t\t\t       _______");
							}
							printf("\n\n\t\t\tDeu velha !!\n");
							printf("\n\n\t\t\tNinguem ganhou !!\n");
							fim++;
							for(int i = 0; i < 3; i++)
							{
								for(int j = 0; j < 3; j++) //zerar a matriz cade vez que alguem ganhar ou der velha
								{
									velha [i][j] = ' ';
								}
							}
						}
						cont = 0;
						//printf("\njogada: %i",jogada);
					}
					while(jogada < 9);

				}
				while(fim == 0);
				break;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 4:
				system("cls");
				cabecalho();
				printf("\n\n\n\t\t\tObrigado pela visita volte sempre\n\t\t\t");
				fim++;
				break;

			}

		}
		while(fim < 1);

		printf("\n\n\n\t\t\tDeseja volta ao menu pricipal?\n\n\t\t\t");
		printf("\n\t\t\t(1) Sim \t\t(2)Não\n\n\t\t\t\t\t");
		scanf("%d", &volta);
	}
	while(volta == 1);

	system("pause>null");
	return 0;
}
