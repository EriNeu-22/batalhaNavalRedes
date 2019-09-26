/************* UDP SERVER CODE *******************/

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <locale.h>

#define linha 11
#define coluna 11

//TABULEIRO DO JOGADOR
char myTable[linha][coluna];

//TABULEIRO INIMIGO
char enemyTable[linha][coluna];

void ZerarMapa(char Mapa[linha][coluna]) {
  int y, x;
  for (x = 0; x < coluna; x++) {
    for (y = 0; y < linha; y++) {
      Mapa[y][x] = ' ';
    }
  }
}

void Submarino(char Mapa[linha][coluna]) {
	//Esse codigo impede que barcos aparecam perto demais
	//Representado pelo numero 1
	
	int i, c, d, rx, ry;
	int valido = 1;
	for(i = 0; i <4 ;i ++) {
		do{
			printf("Nos de a coordenada X para a localização do submarino %d:", i);		
			scanf("%d", &rx);
			if(rx < 0 || rx >9) printf("isso nao me parece muito certo, vamos tentar algo melhor");
		}while (rx < 0 || rx >9);
		do{
			printf("Nos de a coordenada Y para a localização do submarino%d:", i);
			scanf("%d", &ry);
			if(ry < 0 || ry >9) printf("isso nao me parece muito certo, vamos tentar algo melhor\n");
		}while (ry < 0 || ry >9);
		for (d = 0; d < 3; d++) {
			for (c = 0; c < 3; c++) {
				if(rx == 0 && c == 0) c = c + 1;
				if(ry == 0 && d == 0) d = d + 1;  
				if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
					valido = 0;
			}
		}
		
		if(valido == 1)
			Mapa[ry][rx] = '¬';
		else{ 
			printf("isso nao me parece muito certo, vamos tentar algo melhor\n");
			i--; valido = 1;
		}
	}
}


void Cruzador(char Mapa[linha][coluna]) {
	
	//Esse codigo impede que barcos aparecam perto demais
	//Representado pelo numero 2
	
	int i, c, d, rx, ry, dir;
	int valido = 1;
	for(i = 0; i <3 ;i ++) {
		do{
			printf("Nos de a coordenada X para a localização do Cruzador %d:", i);		
			scanf("%d", &rx);
			if(rx < 0 || rx >9) printf("isso nao me parece muito certo, vamos tentar algo melhor");
		}while (rx < 0 || rx >9);
		do{
			printf("Nos de a coordenada Y para a localização doCruzador %d:", i);
			scanf("%d", &ry);
			if(ry < 0 || ry >9) printf("isso nao me parece muito certo, vamos tentar algo melhor\n");
		}while (ry < 0 || ry >9);
		do
		{
			printf("Devemos deixa-lo na horizontal (digite 0).\nOu Devemos deixa-lo na vertical (digite 1).\n");
			scanf("%d",&dir);
		} while (dir != 0 && dir != 1); 
		if(dir == 0){
			for (d = 0; d < 3; d++) {
				for (c = 0; c < 4; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		if(dir == 1){
			for (d = 0; d < 4; d++) {
				for (c = 0; c < 3; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		
		if(valido == 1) {
			
			Mapa[ry][rx] = '&';
			if(dir == 0) Mapa[ry][rx + 1] = '&';
			if(dir == 1) Mapa[ry + 1][rx] = '&';
			
		}
		else{
			printf("essa posicao pode nos trazer problemas, vamos tentar outra\n");
			i--; valido = 1;
		}
	}

}

void Encouracado(char Mapa[linha][coluna]) {
	
	//Esse codigo impede barcos aparecerem perto demais
	//Representado pelo numero 3
	
	int i, c, d, t, rx, ry, dir;
	int valido = 1;
	for(i = 0; i <2 ;i ++) {
		do{
			printf("Nos de a coordenada X para a localização do Encouracado %d:", i);		
			scanf("%d", &rx);
			if(rx < 0 || rx >9) printf("isso nao me parece muito certo, vamos tentar algo melhor");
		}while (rx < 0 || rx >9);
		do{
			printf("Nos de a coordenada Y para a localização do Encouracado %d:", i);
			scanf("%d", &ry);
			if(ry < 0 || ry >9) printf("isso nao me parece muito certo, vamos tentar algo melhor");
		}while (ry < 0 || ry >9);
		do
		{
			printf("Devemos deixa-lo na horizontal (digite 0).\nOu Devemos deixa-lo na vertical (digite 1).\n");
			scanf("%d",&dir);
		}while (dir != 0 && dir != 1);
 
		if(dir == 0){
			for (d = 0; d < 3; d++) {
				for (c = 0; c < 5; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		if(dir == 1){
			for (d = 0; d < 5; d++) {
				for (c = 0; c < 3; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		
		if(valido == 1) {
			
			Mapa[ry][rx] = '$';
			if(dir == 0){
				Mapa[ry][rx + 1] = '$';
				Mapa[ry][rx + 2] = '$';
			}
			if(dir == 1) {
				Mapa[ry + 1][rx] = '$';
				Mapa[ry + 2][rx] = '$';
			}
		}
		else{
			printf("isso nao me parece muito certo, vamos tentar algo melhor\n");
			i--; valido = 1;
		}
	}	
}


void PortaAviao(char Mapa[linha][coluna]) {
	
	//Esse eh o primeiro barco a ser inserido, nao precisa verificar
	//Representado pelo numero 4
	
	int i, c, d, t, rx, ry, dir;
	int valido = 1;
	for(i = 0; i < 1 ;i ++) {
		do{
			printf("Atencao comodoro estamos em aguas hostis necessitamos de sua lideranca para organizar a frota\n e termos vantagem sobre o inimigo, de as ordens%d:", i);
			printf("Nos de a coordenada X para a localização do Porta Avioes:");		
			scanf("%d", &rx);
			if(rx < 0 || rx >9) printf("isso nao me parece muito certo, vamos tentar algo melhor");
		}while (rx < 0 || rx >9);
		do{
			printf("Nos de a coordenada Y para a localização do Porta Avioes:");
			scanf("%d", &ry);
			if(ry < 0 || ry >9) printf("isso nao me parece muito certo, vamos tentar algo melhor");
		}while (ry < 0 || ry >9);
		do
		{
			printf("Devemos deixa-lo na horizontal (digite 0).\nOu Devemos deixa-lo na vertical (digite 1).\n");
			scanf("%d",&dir);
		} while (dir != 0 && dir != 1); 
		if(dir == 0){
			for (d = 0; d < 3; d++) {
				for (c = 0; c < 6; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		if(dir == 1){
			for (d = 0; d < 6; d++) {
				for (c = 0; c < 3; c++) {
					if(rx == 0 && c == 0) c = c + 1;
					if(ry == 0 && d == 0) d = d + 1;  
					if(Mapa[ry + (- 1 + d)][rx + (- 1 + c)] != ' ')
						valido = 0;
				}
			}
		}
		
		if(valido == 1) {
			
			Mapa[ry][rx] = '%';
			if(dir == 0){
				Mapa[ry][rx + 1] = '%';
				Mapa[ry][rx + 2] = '%';
				Mapa[ry][rx + 3] = '%';
			}
			if(dir == 1) {
				Mapa[ry + 1][rx] = '%';
				Mapa[ry + 2][rx] = '%';
				Mapa[ry + 3][rx] = '%';
			}
		}
		else{
			printf("essa posicao pode nos trazer problemas, vamos tentar outra\n");
			i--; valido = 1;
		}
	}	
}

int ganhou = 0;//VARIAVEL PARA TESTAR SE A CONDICAO DE VITORIA OU DERROTA FOI ALCANCADA

int contarNavios()
//ESSE METODO SERVE PARA CONFERIR SE AINDA EXISTE ALGUM NAVIO DO JOGADOR OU DO INIMIGO
{
	int i,j;
	ganhou = 1;

	for(i = 0;i<10;i++)
	{
		for(j = 0;j<10;j++)
		{
			if(enemyTable[i][j] == '¬' || enemyTable[i][j] == '&' || enemyTable[i][j] == '$' || enemyTable[i][j] == '%')
			{
				ganhou = 0;
				break;
			}
		}
	}

	if(ganhou == 1)
	//SE NAO TEM MAIS NAVIU PARA SER DESTRUIDO, ESSE JOGADOR VENCEU
	{
		printf("\nEH ISSO NOS GANHAMOS!!");
		return 0;
	}
	//SE AINDA HOUVER NAVIUS SEGUE O CODIGO ABAIXO
	for(i = 0;i<10;i++)
		{
			for(j = 0;j<10;j++)
			{
				if(enemyTable[i][j] == '¬' || enemyTable[i][j] == '&' || enemyTable[i][j] == '$' || enemyTable[i][j] == '%')
				{
					ganhou = 0;
					break;
				}
			}
		}
	if(ganhou == 1)
	//APOS CONFERIR SE O JOGADOR VENCEU, CONFERE SE O JOGADOR AINDA POSSUI ALGUM NAVIO
	{
		printf("\nA SITACAO SAIU DO CONTROLE, TALVEZ SEJA MELHOR RECUARMOS!!");
		return 0;
	}
}

int Attack(int y, int x)
//ESSE METODO SERVE PARA ATACAR O TABULEIRO IMIMIGO COM AS COORDENADAS DIGITADAS*/
{
	printf("atacado em: %c %c",y,x);
	printf("atacado em: %c",enemyTable[y][x]);
	switch(enemyTable[y][x])
	{
		case' ':
		/*CASO A CASA ATACADA FOR VAZIA PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O TIRO
		  FOI ERRADO OU SEJA (O);
		 */
		{
			enemyTable[y][x] = 'O';
			break;
		}
		case'¬':
		/*CASO A CASA ATACADA POSSUIR UM NAVIO PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O
		  TIRO FOI CERTEIRO OU SEJA (X);
		*/
		{
			enemyTable[y][x] = 'X';
			printf("Voce acertou um Submarino deles, continue atirando.\n");
			do
			{
				printf("digite posicao x:\n");
				scanf("%d",&x);
				printf("digite posicao y:\n");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("essas coordenadas me parecem estar fora do campo de batalha comodoro");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);	
			break;
		}
		case'&':
		/*CASO A CASA ATACADA POSSUIR UM NAVIO PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O
		  TIRO FOI CERTEIRO OU SEJA (X);
		*/
		{
			enemyTable[y][x] = 'X';
			printf("Voce acertou um Cruzador deles, continue atirando.\n");
			do
			{
				printf("digite posicao x:\n");
				scanf("%d",&x);
				printf("digite posicao y:\n");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("essas coordenadas me parecem estar fora do campo de batalha comodoro");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);
			break;
		}
		case'$':
		/*CASO A CASA ATACADA POSSUIR UM NAVIO PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O
		* TIRO FOI CERTEIRO OU SEJA (X);
		*/
		{
			enemyTable[y][x] = 'X';
			printf("Voce acertou um Encouracado deles, continue atirando.\n");
			do
			{
				printf("digite posicao x:\n");
				scanf("%d",&x);
				printf("digite posicao y:\n");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("essas coordenadas me parecem estar fora do campo de batalha comodoro");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);
			break;
		}
		case'%':
		/*CASO A CASA ATACADA POSSUIR UM NAVIO PREENCHE COM UM SIMBOLO QUE SIGNIFICA QUE O
		* TIRO FOI CERTEIRO OU SEJA (X);
		*/
		{
			enemyTable[y][x] = 'X';
			printf("VocÃª acertou o Porta AviÃµes deles, continue atirando.\n");
			do
			{
				printf("digite posicao x:\n");
				scanf("%d",&x);
				printf("digite posicao y:\n");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("essas coordenadas me parecem estar fora do campo de batalha comodoro");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);
			break;
		}
		case'X':
		/*CASO A CASA ATACADA JA ESTIVER SIDO ATACADA, PROBLEMA DO JOGADOR, NADA Ã‰ ACERTADO
		  E A CASA CONTINUA COM O SIMBOLO DE ACERTO (X)
		 */
		{
			enemyTable[y][x] = 'X';
			printf("Nao me parece uma boa opcao, nos ja tentamos ai antes.\n");
			do
			{
				printf("digite posicao x:\n");
				scanf("%d",&x);
				printf("digite posicao y:\n");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("essas coordenadas me parecem estar fora do campo de batalha comodoro");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);
			break;
		}
		case'O':
		/*CASO A CASA ATACADA JA ESTIVER SIDO ATACADA E ERRRADA, PROBLEMA DO JOGADOR,
		 NADA Ã‰ ACERTADO E A CASA CONTINUA COM O SIMBOLO DE ACERTO (O)
		*/
		{
			enemyTable[y][x] = 'O';
			printf("Nao me parece uma boa opcao, nos ja tentamos ai antes.\n");
			do
			{
				printf("digite posicao x:\n");
				scanf("%d",&x);
				printf("digite posicao y:\n");
				scanf("%d",&y);
				if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("essas coordenadas me parecem estar fora do campo de batalha comodoro");
			} while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  		Attack(y,x);
			break;
		}
	}
	return 0;
}


int PrintTable()
//ESSE METODO IMPRIMI O TABULEIRO DO JOGADOR E DO INIMIGO NA TELA
{
	int i,j;
	printf("\nESSAS SAO AS POSICOES DOS NOO BACOS CAPITAO\n");
	printf("  0123456789\n");
	printf("------------\n");

	for(i = 0;i<10;i++)	//coluna
	{
		printf("%d|",i);
		for(j = 0;j<10;j++)	//linha
		{
			printf("%c",myTable[i][j]);
		}
		printf("\n");
	}

		printf("VAMOS USAR ISSO COMO BASE PARA ACERTALOS\n");
		printf("  0123456789\n");
		printf("------------\n");

		for(i = 0;i<10;i++)	//coluna
		{
			printf("%d|",i);
			for(j = 0;j<10;j++)	//linha
			{
				char temp = enemyTable[i][j];
				if (temp == '¬' || temp == '&' || temp == '$' || temp == '%' )
				/*POR SE TRATAR DO TABULEIRO INIMIGO, NAO SE PODE MOSTRAR AS CASAS QUE
				  POSSUEM NAVIO, LOGO O SIMBOLO DO NAVIO Ã‰ MASCARADO POR UM VAZIO
				 */
				{
					temp = ' ';
				}
				printf("%c",temp);
			}
			printf("\n");
		}
	return 0;
}

int main(){
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));
  int udpSocket, nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;
  int i;

  /*Create UDP socket*/
  udpSocket = socket(PF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("10.0.0.3");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  //Bind socket with address struct
  bind(udpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  //Initialize size variable to be used later on*
  addr_size = sizeof serverStorage;
  
  ZerarMapa(myTable);
  PortaAviao(myTable);
  Encouracado(myTable);
  Cruzador(myTable);
  Submarino(myTable);

  recvfrom(udpSocket,enemyTable,sizeof(enemyTable),0,(struct sockaddr *)&serverStorage, &addr_size);
  sendto(udpSocket,myTable,sizeof(myTable),0,(struct sockaddr *)&serverStorage,addr_size);

  printf("VOCE EH O SERVIDOR, JOGA DEPOIS PORQUE SIM");
  PrintTable();

  while(1){

	  printf("\nAGUARGANDO ADVERSARIO...\n");
	  recvfrom(udpSocket,myTable,sizeof(myTable),0,(struct sockaddr *)&serverStorage, &addr_size);
	  printf("\n----------------------------\nTURNO INIMIGO:\n");
	  PrintTable();

	  contarNavios();
	  //CHECA SE ESSE JOGADOR PERDEU ANTES DE PERMITIR QUE ELE JOGUE
	  if(ganhou == 1)
	  {
		  break;
	  }

	  int y, x;
	  do
	  {
		printf("seu turno:\n");
		printf("digite posicao x:\n");
		scanf("%d",&x);
		printf("digite posicao y:\n");
		scanf("%d",&y);
		if((x < 0 || x > 9) || (y < 0 || y > 9)) printf("essas coordenadas me parecem estar fora do campo de batalha comodoro");
	  } while ((x < 0 || x > 9) || (y < 0 || y > 9));
	  
	  printf("seu turno:\n");
	  printf("digite posicao x:\n");
	  scanf("%d",&x);
	  printf("digite posicao y:\n");
	  scanf("%d",&y);

	  printf("\n----------------------------\nSEU TURNO:\n");
	  Attack(y,x);
	  PrintTable();
	  sendto(udpSocket,enemyTable,sizeof(enemyTable),0,(struct sockaddr *)&serverStorage,addr_size);

	  contarNavios();
	  //CHECA SE ESSE JOGADOR VENCEU ANTES DE PERMITIR O MOVIMENTO ADVERSARIO
	  if(ganhou == 1)
	  {
		  break;
	  }
  }

  return 0;
}
