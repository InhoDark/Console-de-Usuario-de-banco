#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <conio.h>
struct registro_conta{
	char nome [20];
	int conta;
	int agencia;
	int senha;
	float saldo;
};
registro_conta contas[10];
FILE *arquivo;

int main(){

setlocale(LC_ALL,"");
contas[0] = registro_conta{"João Paulo", 20180, 197, 1234, 1200};
contas[1] = registro_conta{"Maria Luiza", 32090, 109, 1234, 300.0f};
contas[2] = registro_conta{"Pedro José", 31092, 197, 1234, 600.0f};	

int IDContatr, contatr, agtr;
float valortr;
IDContatr=-1;
char buffer[256];
float tansf, saque, vsaq, saldotr;
int indicador, IDConta, senha, agencia, conta, escolha, menu;
indicador=0;
IDConta=-1;
	while(indicador<1){
		l26:
		printf("\nDigite sua agencia\n");
		scanf("%i", &agencia);
		printf("\nDigite sua conta\n");
		scanf("%i", &conta);
		printf("\nDigite sua senha\n");
		scanf("%i", &senha);
		
		for(IDConta=0; IDConta<10; IDConta++){
			if(conta==contas[IDConta].conta && agencia==contas[IDConta].agencia && senha==contas[IDConta].senha){
					sprintf(buffer,"%d %d .txt",contas[IDConta].conta ,contas[IDConta].agencia);
					arquivo=fopen(buffer, "w");
					menu=0;	
					printf("\nBem Vindo %s digite o número de acordo com o que gostaria de fazer\n", contas[IDConta].nome);
					
						
					while(menu<1){
						printf("\n1-SAQUE\n2-EXTRATO\n3-TRANSFERENCIA\n4-SAIR DA CONTA\n5-FINALIZAR SISTEMA\n");
						scanf("%i", &escolha);
						switch(escolha){
							case 1:
							printf("\nQuanto deseja sacar?\n");
							scanf("%f", &vsaq);
							if(contas[IDConta].saldo>=vsaq){
								fprintf(arquivo, "\nFoi sacado%.2f\n", vsaq);
								contas[IDConta].saldo= contas[IDConta].saldo-vsaq;
								printf("\Seu saldo atual agora é %.2f\n", contas[IDConta].saldo);
								printf("Gostaria de fazer mais alguma coisa ?");
							}else{
								printf("\nNão tem saldo suficiente\n");
								printf("\nGostaria de fazer outra alguma coisa ?\n");
								}
							break;
							
							case 2:
								printf("\Seu saldo atual é %.2f\n", contas[IDConta].saldo);
								printf("Gostaria de fazer mais alguma coisa ?");
							break;
							
							case 3:

								printf("\nDigite a conta desejada\n");
								scanf("%i", &contatr);
								printf("\nDigite a agencia desejada\n");
								scanf("%i", &agtr);
								printf("\nDigite o valor da transferencia\n");
								scanf("%f", &valortr);
								if(valortr<=contas[IDConta].saldo){
									for(IDContatr = 0; IDContatr < 10; IDContatr++){
										if(contatr==contas[IDContatr].conta && agtr==contas[IDContatr].agencia){
											FILE *arquivotr;
											char buffertr[256];
											sprintf(buffertr, "%d %d.txt", contas[IDContatr].conta, contas[IDContatr].agencia);
											arquivotr= fopen(buffertr, "w");
											fprintf(arquivo,"\nFoi Transferido para a conta:%d Agencia: %d\n o valor de %.2f", contas[IDContatr].conta, contas[IDContatr].agencia, valortr);
											fprintf(arquivotr,"\nFoi Recebido da conta:%d Agencia: %d\n o valor de %.2f", contas[IDConta].conta, contas[IDConta].agencia, valortr);
											contas[IDContatr].saldo= valortr+contas[IDContatr].saldo;
											contas[IDConta].saldo= contas[IDConta].saldo-valortr;
											printf("\nSeu saldo atual é: %.2f\n", contas[IDConta].saldo);
										}
									}
								}else{
									printf("Você não tem saldo suficiente, retornará ao menu");
								}
							break;
							
							case 4:
								printf("\nFazendo logoff\n");
								goto l26;
							break;
							
							case 5:
								system("pause");
								return 0;
							break;
							
							
						}

					}
				
			fclose(arquivo);	}
		}
	}
	
		
	

system("pause");
return 0;
}
