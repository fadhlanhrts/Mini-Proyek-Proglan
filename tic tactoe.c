
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <MMsystem.h>
#include "display.h"

char matrix[3][3];
char check(void);
void init_matrix(void);
void pemain(void);
void pemain2(void);
void computer(void);
void disp_matrix(void);

void fullscreen()
{
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
void printd(char* x, int y)
{
	int i;
	for(i=0;i<strlen(x);i++)
	{
		printf("%c",x[i]);
		Sleep(y);
	}
}

void arrowHere(int posisiAsli,int posisiArrow){
	if(posisiAsli == posisiArrow){
		printf("--> -");
	} else{
		printf("     ");
	}
}

int Exit(){
	system("cls");
	int p;
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t");
	for(p=0;p<33;p++)
	{
		printf("=");
		Sleep(20);
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t\tSee U Next Time\n\t\t\t\t\t\t\t\t\t\t");
	for(p=0;p<33;p++)
	{
		printf("=");
		Sleep(20);
	}
	return 0;
}
int checkwin();
void board();
int main(){
	int i;
	int position = 1;
	int keyPressed = 0;
	fullscreen();
    system ("Color 06");
	system ("cls");
	printf("\t\t\t\t\t\t\t\t\t\t");
	for(i=0;i<49;i++)
	{
		printf("=");
		Sleep(25);
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t|\t\tTic Tac Toe\t\t\t|\n\t\t\t\t\t\t\t\t\t\t");
	for(i=0;i<49;i++)
	{
		printf("=");
		Sleep(25);
	}

	while (keyPressed != 13){
	system ("cls");
    printf("\t\t\t\t\t\t\t\t\t\t");
	for(i=0;i<49;i++)
	{
		printf("=");
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t|\t\tTic Tac Toe\t\t\t|\n\t\t\t\t\t\t\t\t\t\t");

	for(i=0;i<49;i++)
	{
		printf("=");
	}
	printf("\n\n");
	printf("Select\n");
	arrowHere(1,position); printf("1. New game\n");
	arrowHere(2,position); printf("2. Exit\n");

	keyPressed = getch();
	if(keyPressed == 80 && position != 2){
		position++;
	} else if (keyPressed == 72 && position != 1){
		position--;
	}else{
		position = position;
	}
}
	switch(position){
		case 1:
			position == '1';
			NG();
			break;
		case 2:
			position == '2';
			Exit();
			break;
	}
}

int NG()
{
    int i;
	int position = 1;
	int keyPressed = 0;
    system("cls");
    while (keyPressed != 13){
	system ("cls");
    printf("\t\t\t\t\t\t\t\t\t\t");
	for(i=0;i<49;i++)
	{
		printf("=");
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t|\t\tTic Tac Toe\t\t\t|\n\t\t\t\t\t\t\t\t\t\t");

	for(i=0;i<49;i++)
	{
		printf("=");
	}
	printf("\n\n");
	printf("Select\n");
	arrowHere(1,position); printf("1. Singleplayer\n");
	arrowHere(2,position); printf("2. Multiplayer\n");

	keyPressed = getch();
	if(keyPressed == 80 && position != 2){
		position++;
	} else if (keyPressed == 72 && position != 1){
		position--;
	}else{
		position = position;
	}
}
	switch(position){
		case 1:
			position == '1';
			Singleplayer();
			break;
		case 2:
			position == '2';
			Multiplayer();
			break;
	}
}



int Singleplayer()
{
    int i;
	int position = 1;
	int keyPressed = 0;
    system("cls");
    while (keyPressed != 13){
	system ("cls");
    printf("\t\t\t\t\t\t\t\t\t\t");
	for(i=0;i<49;i++)
	{
		printf("=");
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t|\t\tTic Tac Toe\t\t\t|\n\t\t\t\t\t\t\t\t\t\t");

	for(i=0;i<49;i++)
	{
		printf("=");
	}
	printf("\n\n");
	printf("Select\n");
	arrowHere(1,position); printf("1. Mode 1\n");
	arrowHere(2,position); printf("2. Mode 2\n");

	keyPressed = getch();
	if(keyPressed == 80 && position != 2){
		position++;
	} else if (keyPressed == 72 && position != 1){
		position--;
	}else{
		position = position;
	}
}
	switch(position){
		case 1:
			position == '1';
			Mode1();
			break;
		case 2:
			position == '2';
			Mode2();
			break;
	}
}
int Mode1()
{
    char done;

  printf("SinglePlayer Tic Tac Toe \n");
  printf("Pemain (O) & CPU (X) \n");

  done =  ' ';
  init_matrix();

  do {
    disp_matrix();
    pemain();
    done = check(); /* check */
    if(done!= ' ') break;
    computer();
    done = check(); /* check */
  } while(done== ' ');

  disp_matrix();
  if(done=='O') printf("You won!\n");
  else printf("I won!!!!\n");

  return 0;
}
int Multiplayer()
{
    char done;

  printf("SinglePlayer Tic Tac Toe \n");
  printf("Player1 (O) & Player2 (X) \n");

  done =  ' ';
  init_matrix();

  do {
    disp_matrix();
    pemain();
    done = check(); /* check */
    if(done!= ' ') break;
    pemain2();
    done = check(); /* check */
  } while(done== ' ');

disp_matrix(); /* menunjukkan matriks*/
  if(done=='O') printf("Player 1 Won!\n");
  else printf("Player 2 Won!\n");


  return 0;
}

int Mode2()
{
  char done;

  printf("SinglePlayer Tic Tac Toe \n");
  printf("Pemain (O) & CPU (X) \n");

  done =  ' ';
  init_matrix();

  do {
    disp_matrix();
    computer();
    done = check(); /* check */
    if(done!= ' ') break;
    pemain();
    done = check(); /* check */
  } while(done== ' ');

  disp_matrix();
  if(done=='O') printf("You won!\n");
  else printf("I won!!!!\n");

  return 0;
}



void init_matrix(void)
{
  int i, j;

  for(i=0; i<3; i++)
    for(j=0; j<3; j++) matrix[i][j] =  ' ';
}


void pemain (void)
{
  int x, y;

  printf("Masukkan Koordinat Baris dan Kolom  (contoh 1 1 atau 1 2) : \n ");
  scanf("%d%*c%d", &x, &y);

  x--; y--;

  if(matrix[x][y]!= ' '){
    printf("Invalid move \n");
    pemain();
  }
  else matrix[x][y] = 'O';
}
void pemain2 (void)
{
  int x, y;

  printf("Masukkan Koordinat Baris dan Kolom  (contoh 1 1 atau 1 2) : \n ");
  scanf("%d%*c%d", &x, &y);

  x--; y--;

  if(matrix[x][y]!= ' '){
    printf("Invalid move \n");
    pemain();
  }
  else matrix[x][y] = 'X';
}

void computer(void)
{
  int i, j;
  for(i=0; i<3; i++){
    for(j=0; j<3; j++)
      if(matrix[i][j]==' ') break;
    if(matrix[i][j]==' ') break;
  }


  if(i*j==9)  {
    printf("draw\n");
    exit(0);
  }
  else
    matrix[i][j] = 'X';
}
void computer2()
{
    int i,j;
    srand(time(NULL));


 while(i = rand() % (2 + 1 - 0) + 0)
 {
     while(j=rand() % (2 + 1 - 0) + 0)
     {
        if(matrix[i][j]==' ')break;
     }
     if(matrix[i][j]==' ') break;
 }
 if(i*j==9)  {
    printf("draw\n");
    exit(0);
  }
  else
    matrix[i][j] = 'X';
}



void disp_matrix(void) /*menunjukkan matrix*/
{
  int t;

  for(t=0; t<3; t++) {
    printf(" %c | %c | %c ",matrix[t][0],
            matrix[t][1], matrix [t][2]);
    if(t!=2) printf("\n---|---|---\n");
  }
  printf("\n");
}


char check(void)
{
  int i;

  for(i=0; i<3; i++)  /*baris*/
    if(matrix[i][0]==matrix[i][1] &&
       matrix[i][0]==matrix[i][2]) return matrix[i][0];

  for(i=0; i<3; i++)  /* kolom */
    if(matrix[0][i]==matrix[1][i] &&
       matrix[0][i]==matrix[2][i]) return matrix[0][i];

  /* diagonal */
  if(matrix[0][0]==matrix[1][1] &&
     matrix[1][1]==matrix[2][2])
       return matrix[0][0];

  if(matrix[0][2]==matrix[1][1] &&
     matrix[1][1]==matrix[2][0])
       return matrix[0][2];

  return ' ';
}

