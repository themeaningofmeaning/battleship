// Dylan Goldfus
// My version of BattleShip...just compile and run
/*		
			GAME DESCRIPTION:
*******************************************************************************
Each player will secretly deploy 5 ships of different sizes into a 10x10 board.
The 5 ships are: aircraft carrier (a) of size 5, battleship (b) of size 4, 
cruiser (c) of size 3, submarine (s) of size 3, and patrol boat (p) of size 2.
Each ship will take that same number of consecutive squares on the board as 
itssize, either horizontally or vertically. For example, a battleship will take 
4 squares.  The players will take turns to guess the location of the opponent’s 
ships and shoot. A ship is sunk if all the squares it occupies are shot. The 
player who sinks all the opponent’s ships first will win the game.  Each Player
is given exactly 6 turns with 3 guesses each to sink all the ships.
******************************************************************************
*******************************************************************************
---------Important Note:----------- 
I suggest opening this file using VIM for clear & organized viewing 
(color coded,etc.)
*******************************************************************************
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE !FALSE

int main(int argc, char *argv[]) {
	FILE *f1,*f2,*f3;
	int ship, row;
	int count, agcol, agrow, bgrow, bgcol, done, no;
	char ch, ascan[5][4], bscan[5][4], p1[10][10], p2[10][10], p1shot[10][10],p2shot[10][10];
	int aplayer[5][4], bplayer[5][4];
	int a=0,b=0,c=0,d=0,i=0,j=0,k=0,x[10],y[10],first,last,g,h;
	int shipax[10],shipay[10],shipbx[10],shipby[10],shipcx[10],shipcy[10],
	    shipdx[10],shipdy[10],shipex[10],shipey[10];

// verify that user has specified 4 arguments.

  if (argc != 4)
  { printf("\n\n****************************************\nYou have not entered 4 arguments\n****************************************\nPlease enter the program name followed by:\n\n1. Name of desired input file for player 1 ship placement\n2. Name of desired input file for player 2 ship placement\n3. Name of desired output file for battleship game\n\n\n");
	  exit(0);
  }

//Open input file(f1) to read and open first output(f2) file to write

  f1 = fopen(argv[1], "r");
  f2 = fopen(argv[2], "r");
  f3 = fopen(argv[3], "w");

// safety check

  if (f1 == NULL)
  { printf("File %s cannot open!\n", argv[1]);
    exit(0);
  }
  if (f2 == NULL)
  { printf("File %s cannot open!\n", argv[2]);
    exit(0);
  }

//scan the input file of player1

for (a=0; a<5; a++) {
	for(b=0; b<4; b++){
	fscanf(f1, " %c", &ascan[a][b]);
//	printf("%c",ascan[a][b]);
	switch(ascan[a][b]){
				case 'A':
				case '0':
					aplayer[a][b]=0;
					break;
				case 'B':
				case '1':
					aplayer[a][b]=1;
					break;
				case 'C':
				case '2':
					aplayer[a][b]=2;
					break;
				case 'D':
				case '3':
					aplayer[a][b]=3;
					break;
				case 'E':
				case '4':
					aplayer[a][b]=4;
					break;
				case 'F':
				case '5':
					aplayer[a][b]=5;
					break;
				case 'G':
				case '6':
					aplayer[a][b]=6;
					break;
				case 'H':
				case '7':
					aplayer[a][b]=7;
					break;
				case 'I':
				case '8':
					aplayer[a][b]=8;
					break;
				case 'J':
				case '9':
					aplayer[a][b]=9;
					break;
	}
	}
}

//scan the input file of player2
//printf("\n");					//test successful fscanf
a=0;
b=0;
for (a=0; a<5; a++) {
	for(b=0; b<4; b++){
	fscanf(f2, " %c", &bscan[a][b]);
	switch(bscan[a][b]){
				case 'A':
				case '0':
					bplayer[a][b]=0;
					break;
				case 'B':
				case '1':
					bplayer[a][b]=1;
					break;
				case 'C':
				case '2':
					bplayer[a][b]=2;
					break;
				case 'D':
				case '3':
					bplayer[a][b]=3;
					break;
				case 'E':
				case '4':
					bplayer[a][b]=4;
					break;
				case 'F':
				case '5':
					bplayer[a][b]=5;
					break;
				case 'G':
				case '6':
					bplayer[a][b]=6;
					break;
				case 'H':
				case '7':
					bplayer[a][b]=7;
					break;
				case 'I':
				case '8':
					bplayer[a][b]=8;
					break;
				case 'J':
				case '9':
					bplayer[a][b]=9;
					break;
	}
//	printf("%d ", bplayer[a][b]);		//test successful fscanf
	}
//	printf("\n");				//test successful fscanf
}

//Scan in results to convert to [10][10] ship layout board for player 1
a=0;
b=0;
for (a=0; a<5; a++)
{	if (aplayer[a][2]-aplayer[a][0] == 0)
   	 { ship = (aplayer[a][3]-aplayer[a][1])+1;
   	     { switch (ship){
			case 5:
				{ for(i=aplayer[a][1]; i<=aplayer[a][3]; i++)
					p1[aplayer[a][0]][i] = 'a';
				}
				break;
			case 4:
				{ for(i=aplayer[a][1]; i<=aplayer[a][3]; i++)
					p1[aplayer[a][0]][i] = 'b';
				}
				break;
			case 3:
				{if(no!=1){
					for(i=aplayer[a][1]; i<=aplayer[a][3]; i++){
					p1[aplayer[a][0]][i] = 'c';
					no=1;}
					}
				if(no=1){
					for(i=aplayer[a][1]; i<=aplayer[a][3]; i++){
					p1[aplayer[a][0]][i] = 's';}
				}
	
				}
				break;
			case 2:
				{ for(i=aplayer[a][1]; i<=aplayer[a][3]; i++)
					p1[aplayer[a][0]][i] = 'p';
				}
				break;
		}
	     }
   	 }
	else
   	 { ship = (aplayer[a][2]-aplayer[a][0])+1;
   	     { switch (ship){
			case 5:
				{ for(i=aplayer[a][0]; i<=aplayer[a][2]; i++)
					p1[i][aplayer[a][1]] = 'a';
				}
				break;
			case 4:
				{ for(i=aplayer[a][0]; i<=aplayer[a][2]; i++)
					p1[i][aplayer[a][1]] = 'b';
				}
				break;
			case 3:
				{if(no!=1){
					for(i=aplayer[a][0]; i<=aplayer[a][2]; i++){
					p1[i][aplayer[a][1]] = 'c';
					no=1;}
					}
				if(no=1){
					for(i=aplayer[a][0]; i<=aplayer[a][2]; i++){
					p1[i][aplayer[a][1]] = 's';}
				}
	
				}
				break;
			case 2:
				{ for(i=aplayer[a][0]; i<=aplayer[a][2]; i++)
					p1[i][aplayer[a][1]] = 'p';
				}
				break;
		}
	 }
   	 }
}

//Scan in '-' for empty spaces for player 1

int blank1=0, blank2=0;

for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		if(p1[blank1][blank2] != 'a' && p1[blank1][blank2] != 'b' && p1[blank1][blank2] != 'c' && p1[blank1][blank2] != 's' && p1[blank1][blank2] != 'p')
			p1[blank1][blank2] = '-';
	}
}

//Scan in results to convert to [10][10] ship layout board for player 2
a=0;
b=0;
for (a=0; a<5; a++)
{	if (bplayer[a][2]-bplayer[a][0] == 0)
   	 { ship = (bplayer[a][3]-bplayer[a][1])+1;
   	     { switch (ship){
			case 5:
				{ for(i=bplayer[a][1]; i<=bplayer[a][3]; i++)
					p2[bplayer[a][0]][i] = 'a';
				}
				break;
			case 4:
				{ for(i=bplayer[a][1]; i<=bplayer[a][3]; i++)
					p2[bplayer[a][0]][i] = 'b';
				}
				break;
			case 3:
				{if(no!=1){
					for(i=bplayer[a][1]; i<=bplayer[a][3]; i++){
					p2[bplayer[a][0]][i] = 'c';
					no=1;}
					}
				if(no=1){
					for(i=bplayer[a][1]; i<=bplayer[a][3]; i++){
					p2[bplayer[a][0]][i] = 's';}
				}
	
				}
				break;
			case 2:
				{ for(i=bplayer[a][1]; i<=bplayer[a][3]; i++)
					p2[bplayer[a][0]][i] = 'p';
				}
				break;
		}
	     }
   	 }
	else
   	 { ship = (bplayer[a][2]-bplayer[a][0])+1;
   	     { switch (ship){
			case 5:
				{ for(i=bplayer[a][0]; i<=bplayer[a][2]; i++)
					p2[i][bplayer[a][1]] = 'a';
				}
				break;
			case 4:
				{ for(i=bplayer[a][0]; i<=bplayer[a][2]; i++)
					p2[i][bplayer[a][1]] = 'b';
				}
				break;
			case 3:
				{if(no!=1){
					for(i=bplayer[a][0]; i<=bplayer[a][2]; i++){
					p2[i][bplayer[a][1]] = 'c';
					no=1;}
					}
				if(no=1){
					for(i=bplayer[a][0]; i<=bplayer[a][2]; i++){
					p2[i][bplayer[a][1]] = 's';}
				}
	
				}
				break;
			case 2:
				{ for(i=bplayer[a][0]; i<=bplayer[a][2]; i++)
					p2[i][bplayer[a][1]] = 'p';
				}
				break;
		}
	 }
   	 }
}

//Scan in '-' for empty spaces for player 2

blank1=0;
blank2=0;

for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		if(p2[blank1][blank2] != 'a' && p2[blank1][blank2] != 'b' && p2[blank1][blank2] != 'c' && p2[blank1][blank2] != 's' && p2[blank1][blank2] != 'p')
			p2[blank1][blank2] = '-';
	}
}

//clear screen

system("clear");

//print player 1 ship deployment board
blank1=0; 
blank2=0;
for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		printf("%c",p1[blank1][blank2]);
	}
	printf("\n");
}

//Verify Ship Deployment for Player1

done = FALSE;
printf("\n\nPlayer 1: confirm the ship deployment: ");
	while(!done)
	{
		printf("Enter Y or N (Y/N) : ");
		fflush(stdin);
		ch = getchar();
		switch(ch)
		{
			case 'N':
			case 'n':
				printf("Player 1 fails to confirm the ship deployment!\nGoodbye\n");
				fprintf(f3, "Player 1 fails to confirm the ship deployment!");
				exit(0);
				break;
			case 'Y':
			case 'y':
				system("clear");
				printf("Player 1 confirms ship deployment\n\n");
				fprintf(f3, "Player 1 confirms ship deployment\n\n");
				done = TRUE;
				break;
			default:
				printf("You must enter Y or N!\n");
				fflush(stdin);
		}
	}

//print player 2 ship deployment board
blank1=0; 
blank2=0;
for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		printf("%c",p2[blank1][blank2]);
	}
	printf("\n");
}

//Verify Ship Deployment for Player2

done = FALSE;

printf("\n\nPlayer 2:confirm the ship deployment: ");
	while(!done)
	{
		printf("Enter Y or N (Y/N) : ");
		fflush(stdin);
		ch = getchar();
		switch(ch)
		{
			case 'N':
			case 'n':
				printf("Player 2 fails to confirm the ship deployment!\nGoodbye\n");
				fprintf(f3, "Player 2 fails to confirm the ship deployment!");
				exit(0);
				break;
			case 'Y':
			case 'y':
				system("clear");
				printf("Player 2 confirms ship deployment\n\n");
				fprintf(f3, "Player 2 confirms ship deployment\n\n");
				done = TRUE;
				break;
			default:
				printf("You must enter Y or N!\n");
				fflush(stdin);
		}
	}

//prompt player1 and player2 to enter guessing data

int p1turn=0, p2turn=0;
char char1,char2;
i=0;

//limit amount of guessing rounds

while(i<6){

//player 1 enter guess

printf("Player 1 turn to guess\n");
printf("You have 3 attempts in this turn\n");
for (p1turn=0;p1turn<3;p1turn++){		//guesses/turn for player1
done = FALSE;

//create player 1 shot board

blank1=0;
blank2=0;
for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		if(p1shot[blank1][blank2] != 'a' && p1shot[blank1][blank2] != 'b' && p1shot[blank1][blank2] != 'c' && p1shot[blank1][blank2] != 's' && p1shot[blank1][blank2] != 'p'  && p1shot[blank1][blank2] != 'o' &&p1shot[blank1][blank2] != 'x')
			p1shot[blank1][blank2] = '-';
	}
}
blank1=0; 			//print player 1 shot board 
blank2=0;
printf("\n\nPlayer 1 guess board:\n");
for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		printf("%c",p1shot[blank1][blank2]);
	}
	printf("\n");
}

//Prompt player 1 to enter a row

printf("please enter a row : ");
	while(!done)
	{
		fflush(stdin);
		char1 = getchar();
		switch(char1){
				case 'A':
				case 'a':
					agrow=0;
					done = TRUE;
					break;
				case 'B':
				case 'b':
					agrow=1;
					done = TRUE;
					break;
				case 'C':
				case 'c':
					agrow=2;
					done = TRUE;
					break;
				case 'D':
				case 'd':
					agrow=3;
					done = TRUE;
					break;
				case 'E':
				case 'e':
					agrow=4;
					done = TRUE;
					break;
				case 'F':
				case 'f':
					agrow=5;
					done = TRUE;
					break;
				case 'G':
				case 'g':
					agrow=6;
					done = TRUE;
					break;
				case 'H':
				case 'h':
					agrow=7;
					done = TRUE;
					break;
				case 'I':
				case 'i':
					agrow=8;
					done = TRUE;
					break;
				case 'J':
				case 'j':
					agrow=9;
					done = TRUE;
					break;
				case 'Q':
				case 'q':
					printf("Goodbye\n");
					exit(0);
					break;
				default:
				printf("You must enter a valid guess (A-J) or Q to quit!\n");
				fflush(stdin);
			}
	}
printf("please enter a column : ");		//player 1 enter column
scanf("%d",&agcol);
system("clear");		//clear screen
if(agcol<0 || agcol>9)
	printf("Invalid Column!  You have wasted a turn.\n");
if(p1[agrow][agcol] =='-'){
	p1shot[agrow][agcol] = 'o';
	p1[agrow][agcol] = 'o';
	printf("\nMiss!\n\n");
}
if(p1[agrow][agcol] =='a' || p1[agrow][agcol] =='b' || p1[agrow][agcol] =='c' || p1[agrow][agcol] =='p' || p1[agrow][agcol] =='s'){
	p1shot[agrow][agcol] = 'x';
	p1[agrow][agcol] = 'x';
	printf("\nHit!\n\n");
}
if(p1turn>2)
	printf("Player 1: End of turn");
}

//player 2 enter guess

printf("Player 2 turn to guess\n");
printf("You have 3 attempts in this turn\n");
for (p2turn=0;p2turn<3;p2turn++){		//guesses/turn for player 2
done = FALSE;

//create player 2 shot board

blank1=0;
blank2=0;
for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		if(p2shot[blank1][blank2] != 'a' && p2shot[blank1][blank2] != 'b' && p2shot[blank1][blank2] != 'c' && p2shot[blank1][blank2] != 's' && p2shot[blank1][blank2] != 'p'  && p2shot[blank1][blank2] !='o' && p2shot[blank1][blank2] != 'x')
			p2shot[blank1][blank2] = '-';
	}
}
blank1=0; 			//print player 1 shot board 
blank2=0;
printf("\n\nPlayer 2 guess board:\n");
for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		printf("%c",p2shot[blank1][blank2]);
	}
	printf("\n");
}

printf("please enter a row : ");		//player2 enter row
	while(!done)
	{
		fflush(stdin);
		char2 = getchar();
		switch(char2){
				case 'A':
				case 'a':
					bgrow=0;
					done = TRUE;
					break;
				case 'B':
				case 'b':
					bgrow=1;
					done = TRUE;
					break;
				case 'C':
				case 'c':
					bgrow=2;
					done = TRUE;
					break;
				case 'D':
				case 'd':
					bgrow=3;
					done = TRUE;
					break;
				case 'E':
				case 'e':
					bgrow=4;
					done = TRUE;
					break;
				case 'F':
				case 'f':
					bgrow=5;
					done = TRUE;
					break;
				case 'G':
				case 'g':
					bgrow=6;
					done = TRUE;
					break;
				case 'H':
				case 'h':
					bgrow=7;
					done = TRUE;
					break;
				case 'I':
				case 'i':
					bgrow=8;
					done = TRUE;
					break;
				case 'J':
				case 'j':
					bgrow=9;
					done = TRUE;
					break;
				case 'Q':
				case 'q':
					printf("Goodbye\n");
					exit(0);
					break;
				default:
				printf("You must enter a valid guess (A-J) or Q to quit!\n");

					fflush(stdin);
			}
	}
printf("please enter a column : ");				//player 2 enter column
scanf("%d",&bgcol);
system("clear");		//clear screen
if(bgcol<0 || bgcol>9)
	printf("Invalid Column!  You have wasted a turn.\n");
if(p2[bgrow][bgcol] == '-'){
	p2shot[bgrow][bgcol] = 'o';
	p2[grow][bgcol] = 'o';
	printf("\nMiss!\n\n");
}
if(p2[bgrow][bgcol]=='a' || p2[bgrow][bgcol]=='b' || p2[bgrow][bgcol]=='c' || p2[bgrow][bgcol]=='p' || p2[bgrow][bgcol]=='s')
{
	p2shot[bgrow][bgcol] = 'x';
	p2[bgrow][bgcol] = 'x';
	printf("\nHit!\n\n");
}
if(p2turn>2)
	printf("Player 2: End of turn");

}
i++;
}
system("clear");		//clear screen
printf("\n\n\n*************************************\n*************************************\n\n            GAME OVER!!!");

//Determine which player is the winner
int winnera=0, winnerb=0;
//player 1:
blank1=0;
blank2=0;
for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		if(p1shot[blank1][blank2]=='o')
			winnera=winnera+1;
	}
}
//player 2:
blank1=0;
blank2=0;
for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		if(p2shot[blank1][blank2]=='x')
			winnerb=winnerb+1;
	}
}
//print player 1 guess board to output file
fprintf(f3,"\n\n\nPlayer 1 guess board:\n");
blank1=0;
blank2=0;
printf("Player 1: final board: \n");
for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		printf("%c",p1shot[blank1][blank2]);
		fprintf(f3, "%c",p1shot[blank1][blank2]);
	}
	printf("\n");
	fprintf(f3,"\n");
}
//print player 2 guess board to output file
fprintf(f3,"\n\n\n\n\nPlayer 2 guess board:\n");
blank1=0;
blank2=0;
printf("player 2 final board:\n");
for (blank1=0;blank1<10;blank1++){
	for(blank2=0;blank2<10;blank2++){
		printf("%c",p2shot[blank1][blank2]);
		fprintf(f3, "%c",p2shot[blank1][blank2]);
	}
	printf("\n");
	fprintf(f3,"\n");
}
//Announce the winner
if(winnera>winnerb){
	printf("\n\n\n         Player 1 wins!!!\n\n\n");
	fprintf(f3,"\n\n\nPlayer 1 wins!!!");
}
if(winnerb>winnera){
	printf("\n\n\n     Player 2 wins!!!\n\n\n");
	fprintf(f3,"\n\n\nPlayer 2 wins!!!");
}
printf("\n*************************************\n*************************************\n\n\n\n\n\n\n\n");
//close input files and output file

fclose (f1);
fclose (f2);
fclose (f3);

//close program

  return 0;
  }

