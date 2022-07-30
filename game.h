#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<unistd.h>


void greet(); //greet to user
void selectPlayer();
void singlePlayer();
void gameboard();
void multiPlayer();


int  winChance();
int takeIntegerInput();

char square[10]={'0','1','2','3','4','5','6','7','8','9'};


int takeIntegerInput() {

    int n;

    start:
    printf("\n\n\t\t\t\tEnter Your choice: ");

    while(!scanf("%d",&n))
    {
        printf("\n\t\t\t\tPlease Enter an Integer Input.......");
        fflush(stdin);
        goto start;
    }
    return n;
}

void greet() {

    puts("\t\t\t\t--------------------------------------------------------------------------------");
    puts("\t\t\t\t|------------------------------------------------------------------------------|");
    puts("\t\t\t\t|-------------------         TIC TAC TOE APPLICATION      ---------------------|");
    puts("\t\t\t\t|-------------------               WEL COME               ---------------------|");
    puts("\t\t\t\t|-------------------              TO THIS GAME            ---------------------|");
    puts("\t\t\t\t|------------------------------------------------------------------------------|");
    puts("\t\t\t\t--------------------------------------------------------------------------------");
}

void selectPlayer() {

    int choice,left=3;

    puts("\n\n\n\t\t\t\t--------------------------------------------------------------------------");
          puts("\t\t\t\t|                           SELECT PLAYERS                               |");
          puts("\t\t\t\t|                                                                        |");
          puts("\t\t\t\t|                          1. Single Player                              |");
          puts("\t\t\t\t|                          2. Multi  Players                             |");
          puts("\t\t\t\t|                          3. Quit the Game                              |");
          puts("\t\t\t\t--------------------------------------------------------------------------");

    start:
    usleep(1000000);
    choice = takeIntegerInput();

    switch( choice )
    {
    case 1:
        {
            singlePlayer();
            exit(0);
        }
    case 2:
        {
            multiPlayer();
            exit(0);
        }
    case 3:
        {
            exit(0);
        }
    default :
        {
            left--;

                if ( left == 0) {
                    exit(0);
                }
                puts("\n\t\t\t\tWRONG INPUT!!!!! Please Try Again..!!!!");
                printf("\n\t\t\t\tYou have %d chance left !!!.....\n",left);

            goto start;
        }
    }
}

void singlePlayer() {

    char player1,player2;
    int player = 1;
    int i;

    fflush(stdin);

    start:
    printf("\n\n\t\t\t\tPlayer %d choose your Symbol ('X' or 'O') : ",player);
    player1 = getchar() ;

    usleep(1000000);

    if ( player1 == 'O') {
        player2 = 'X';
    } else  if ( player1 == 'X') {
        player2 = 'O';
    } else if  ( player1 == 'x') {
        player2 = 'o';
    } else if  ( player1 == 'o') {
        player2 = 'x';
    } else {
        printf("\n\n\t\t\t\tYou have entered wrong choice.........\n\t\t\t\tPlease Choose the correct symbol.");
        fflush(stdin);
        goto start;
    }

    usleep(2000000);
    printf("\n\n\t\t\t\tPress enter to continue..............");
    getch();

    char mark;
    int choice,p1choice,p2choice;

    do
    {
        system("cls");
        gameboard();

        player = (player % 2)?1:2;//player number
        mark = (player == 1)?player1:player2; //symbol

        if ( player == 1) {
                printf("\n\t\t\t\tPlayer %d , select your choice: ",player);
                scanf("%d",&choice);
                fflush(stdin);
                p1choice = choice;
        } else if( player == 2) {
                srand(time(NULL));
                choice = (rand() % 9 ) + 1; //1,2,3,4,5,6,7,8,9

                if ( choice == p1choice ) {
                    usleep(1000000);
                    continue;
                }
                 printf("\n\t\t\t\tPlayer %d , select choice: %d ",player,choice);
        }

        if ( choice == 1 && square[1] == '1') {
                square[1] = mark;
        } else if ( choice == 2 && square[2] == '2') {
                square[2] = mark;
        } else if ( choice == 3 && square[3] == '3') {
                square[3] = mark;
        } else if ( choice == 4 && square[4] == '4') {
                square[4] = mark;
        } else if ( choice == 5 && square[5] == '5') {
                square[5] = mark;
        } else if ( choice == 6 && square[6] == '6') {
                square[6] = mark;
        } else if ( choice == 7 && square[7] == '7') {
                square[7] = mark;
        } else if ( choice == 8 && square[8] == '8') {
                square[8] = mark;
        } else if ( choice == 9 && square[9] == '9') {
                square[9] = mark;
        }
        player++;

        i = winChance();

    } while (i == -1);

    gameboard();

    if ( i == 1)
    {
            printf("\n\n\n\t\t\t\t****************  Player %d win  ***************",--player);
    } else {
            printf("\n\n\n\t\t\t\t*****************  Match Draw  *****************");
    }
}
void multiPlayer() {

    char player1,player2;
    int player = 1;
    int i;

    fflush(stdin);

    start:
    printf("\n\n\t\t\t\tPlayer %d choose your Symbol ('X' or 'O') : ",player);
    player1 = getchar() ;

    usleep(1000000);

    if ( player1 == 'O' ) {
        player2 = 'X';
    } else  if ( player1 == 'X' ) {
        player2 = 'O';
    }   else {
        printf("\n\n\t\t\t\tYou have entered wrong choice.........\n\t\t\t\tPlease Choose the correct symbol.");
        fflush(stdin);
        goto start;
    }

    usleep(2000000);
    printf("\n\n\t\t\t\tPress enter to continue..............");
    getch();

    char mark;
    int choice,p1choice,p2choice;

    do
    {
        system("cls");
        gameboard();

        player = (player % 2)?1:2;//player number
        mark = (player == 1)?player1:player2; //symbol

        if ( player == 1) {
                printf("\n\t\t\t\tPlayer %d , select your choice: ",player);
                scanf("%d",&choice);
                fflush(stdin);
        } else if( player == 2) {
                printf("\n\t\t\t\tPlayer %d , select your choice: ",player);
                scanf("%d",&choice);
                fflush(stdin);
        }

        if ( choice == 1 && square[1] == '1') {
                square[1] = mark;
        } else if ( choice == 2 && square[2] == '2') {
                square[2] = mark;
        } else if ( choice == 3 && square[3] == '3') {
                square[3] = mark;
        } else if ( choice == 4 && square[4] == '4') {
                square[4] = mark;
        } else if ( choice == 5 && square[5] == '5') {
                square[5] = mark;
        } else if ( choice == 6 && square[6] == '6') {
                square[6] = mark;
        } else if ( choice == 7 && square[7] == '7') {
                square[7] = mark;
        } else if ( choice == 8 && square[8] == '8') {
                square[8] = mark;
        } else if ( choice == 9 && square[9] == '9') {
                square[9] = mark;
        } else {
                player--;
                printf("\n\n\t\t\t\tInvalid input");
                getch();

        }
        player++;

        i = winChance();

    } while (i == -1);

    gameboard();

    if ( i == 1)
    {
            printf("\n\n\n\t\t\t\t****************  Player %d win  ***************",--player);
    } else {
            printf("\n\n\n\t\t\t\t*****************  Match Draw  *****************");
    }
}

void gameboard() {


  printf("\n\n\n\t\t\t\t               |                 |              \n");
        printf("\t\t\t\t               |                 |              \n");
        printf("\t\t\t\t       %c       |       %c         |      %c      \n",square[1],square[2],square[3]);
        printf("\t\t\t\t               |                 |              \n");
        printf("\t\t\t\t               |                 |              \n");
        printf("\t\t\t\t --------------|-----------------|--------------\n");
        printf("\t\t\t\t               |                 |              \n");
        printf("\t\t\t\t               |                 |              \n");
        printf("\t\t\t\t       %c       |       %c         |      %c      \n",square[4],square[5],square[6]);
        printf("\t\t\t\t               |                 |              \n");
        printf("\t\t\t\t               |                 |              \n");
        printf("\t\t\t\t --------------|-----------------|--------------\n");
        printf("\t\t\t\t               |                 |              \n");
        printf("\t\t\t\t               |                 |              \n");
        printf("\t\t\t\t       %c       |       %c         |      %c      \n",square[7],square[8],square[9]);
        printf("\t\t\t\t               |                 |              \n");
        printf("\t\t\t\t               |                 |              \n");
}

int  winChance() {

    if ( square[1] == square[5] && square[5] == square[9] ) {
        return 1;
    }  else  if ( square[1] == square[4] && square[4] == square[7] ) {
        return 1;
    }  else  if ( square[2] == square[5] && square[5] == square[8] ) {
        return 1;
    }  else  if ( square[3] == square[6] && square[6] == square[9] ) {
        return 1;
    }  else  if ( square[3] == square[5] && square[5] == square[7] ) {
        return 1;
    }  else  if ( square[1] == square[2] && square[2] == square[3] ) {
        return 1;
    }  else  if ( square[4] == square[5] && square[5] == square[6] ) {
        return 1;
    }  else  if ( square[7] == square[8] && square[8] == square[9] ) {
        return 1;
    }  else  if ( square[3] == square[5] && square[5] == square[7] ) {
        return 1;
    }  else if ( square[1] != '1'  && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9') {
        return 0;
    }  else {
        return -1;
    }
}
