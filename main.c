#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include<mmsystem.h>
#include"sudoku.h"

/********************************** SUDOKU GAME WITH 3 LEVELS ************************************/


int main()
{
    int choice,level,result,n_row,n_col,num,ifwin,check,mistakes=0,x;
    START_SOUND();
    printf("\033[1;31m");  // red color
    printf("\n\n     ---------------------------------------- W E L C O M E    TO   S U D O K U-------------------------------------  \n\n");
    printf("\033[0m");     //default color
    printf("\033[0;33m");  // yellow color
    printf("**    TO PLAY SELECT 1   **\n");
    printf("**    TO exit SELECT 2   **\n\n");
    printf("\033[0m");  //default color
    scanf("%d",&choice);
    while(mistakes!=3)
    {

        if (choice==1)
        {
            check=1;
            cmdClearScreen();
            printf("\033[0;32m");  // green color
            printf("**   select 1 for easy level   **\n");
            printf("\033[0;33m");  // yellow color
            printf("**   select 2 for medium level **\n");
            printf("\033[1;31m");  // red color
            printf("**   select 3 for hard level   **\n");
            printf("\033[0m");  // default color
            scanf("%d",&level);
            if (level==1)
            {
                cmdClearScreen();                           // clear cmd
                int arr[9][9]= {{0,0,0,9,0,0,0,0,0},
                    {8,0,4,0,5,0,9,0,0},
                    {0,0,5,7,0,2,0,4,0},
                    {0,0,3,4,0,9,0,8,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,9,0,3,0,8,1,0,0},
                    {0,3,0,6,0,7,4,0,0},
                    {0,0,6,0,9,0,3,0,1},
                    {0,0,0,0,0,5,0,0,0}
                };

                while(check==1)
                {
                    if(mistakes==3)   // check if the user lose
                    {
                        gameover_SOUND();
                        printf("\033[1;31m");  // red color
                        printf("\n                                         *** G a m e     O v e r *** \n\n");
                        printf("1-To Select Level\n");
                        printf("2-To exit\n");
                        printf("\033[0m");  // default color
                        scanf("%d",&x);
                        if (x==1)
                        {
                            mistakes=0;
                            break;
                        }
                        else if (x==2)
                        {
                            return 0;
                        }
                    }
                    printf("\033[1;31m");  // red color
                    printf("  ***you have 3 mistakes then you lose***  \n");
                    printf("           mistakes=%d\n\n",mistakes);
                    printf("\033[0m");    // default color
                    print_sudoku(arr,9,9);
                    printf("insert the row\n");
                    scanf("%d",&n_row);
                    printf("insert the col\n");
                    scanf("%d",&n_col);
                    printf("insert the number\n");
                    scanf("%d",&num);
                    result=insert_num(arr,9,9,num,n_row,n_col);
                    if (result==-1)
                    {
                        ERROR_SOUND();
                        printf("not valid Duplicate in same row\n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();
                    }
                    else if (result==-2)
                    {
                        ERROR_SOUND();
                        printf("not valid Duplicate in same column\n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();     // clear cmd
                    }
                    else if (result==-3)
                    {
                        ERROR_SOUND();
                        printf(" invalid number \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();     // clear cmd
                    }
                     else if(result==-4)
                    {
                        ERROR_SOUND();
                        printf(" not valid row \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();    // clear cmd
                    }
                    else if(result==-5)
                    {
                        ERROR_SOUND();
                        printf(" not valid column \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();    // clear cmd
                    }
                     else if(result==-6)
                    {
                        ERROR_SOUND();
                        printf(" not valid \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();    // clear cmd
                    }
                    else if (result==0)
                    {
                        ifwin=check_ifwin(arr,9,9);
                        if (ifwin==0)
                        {
                            WIN_SOUND();
                            cmdClearScreen();     // clear cmd
                            check=0;
                            printf("\033[0;32m");  // green color
                            printf("\n\n    ************** c o n g r a t u l a t i o n   y o u    w i n ***************** \n");
                            printf("\033[0m");  // default color
                            Sleep(3600);
                        }
                        else
                        {
                            cmdClearScreen();      // clear cmd
                        }

                    }
                }
            }
            if (level==2)
            {
                cmdClearScreen();
                int arr[9][9]= {{0,0,6,0,0,5,0,0,1},
                    {5,8,0,0,2,0,3,4,9},
                    {0,4,0,8,9,0,0,0,0},
                    {9,1,7,0,0,4,0,8,0},
                    {0,0,0,6,0,7,0,0,5},
                    {6,0,8,0,0,3,0,0,0},
                    {0,0,0,0,0,0,0,6,4},
                    {0,0,0,0,0,0,0,9,0},
                    {8,0,0,4,7,0,0,0,2}
                };

                while(check==1)
                {
                    if(mistakes==3)                  // check if the user lose
                    {
                        gameover_SOUND();
                        printf("\033[1;31m");        // red color
                        printf("\n                                         *** G a m e     O v e r *** \n\n");
                        printf("1-To Select Level\n");
                        printf("2-To exit\n");
                        printf("\033[0m");            // default color
                        scanf("%d",&x);
                        if (x==1)
                        {
                            mistakes=0;
                            break;
                        }
                        else if (x==2)
                        {
                            return 0;
                        }

                    }
                    printf("\033[1;31m");
                    printf("  ***you have 3 mistakes then you lose***  \n");
                    printf("           mistakes=%d\n\n",mistakes);
                    printf("\033[0m");
                    print_sudoku(arr,9,9);
                    printf("insert the row\n");
                    scanf("%d",&n_row);
                    printf("insert the col\n");
                    scanf("%d",&n_col);
                    printf("insert the number\n");
                    scanf("%d",&num);
                    result=insert_num(arr,9,9,num,n_row,n_col);
                    if (result==-1)
                    {
                        ERROR_SOUND();
                        printf("not valid Duplicate in same row\n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();
                    }
                    else if (result==-2)
                    {
                        ERROR_SOUND();
                        printf("not valid Duplicate in same column\n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();
                    }
                    else if (result==-3)
                    {
                        ERROR_SOUND();
                        printf(" not valid number \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                       cmdClearScreen();    // clear cmd
                    }
                    else if(result==-4)
                    {
                        ERROR_SOUND();
                        printf(" not valid row \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();    // clear cmd
                    }
                    else if(result==-5)
                    {
                        ERROR_SOUND();
                        printf(" not valid column \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();    // clear cmd
                    }
                    else if(result==-6)
                    {
                        ERROR_SOUND();
                        printf(" not valid \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();    // clear cmd
                    }
                    else if (result==0)
                    {
                        ifwin=check_ifwin(arr,9,9);
                        if (ifwin==0)
                        {
                            WIN_SOUND();
                            cmdClearScreen();
                            check=0;
                            printf("\033[0;32m");  // green color
                            printf("\n\n ************** c o n g r a t u l a t i o n   y o u    w i n ***************** \n");
                             printf("\033[0m");  // default color
                             Sleep(3600);
                        }
                        else
                        {
                            cmdClearScreen();
                        }

                    }
                }
            }
            if (level==3)
            {
                cmdClearScreen();
                int arr[9][9]= {{0,9,0,0,3,0,0,2,0},
                    {0,7,0,0,6,0,0,0,0},
                    {0,1,0,8,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,3,0,0,8,0,9,0},
                    {0,2,0,0,1,0,0,5,0},
                    {0,0,4,0,0,5,0,8,0},
                    {0,0,2,6,0,0,5,9,0},
                    {0,0,0,0,0,0,7,0,6}
                };

                while(check==1)
                {
                    if(mistakes==3)            // check if the user lose
                    {
                        gameover_SOUND();
                        printf("\033[1;31m");    // red color
                        printf("\n                                         *** G a m e     O v e r *** \n\n");
                        printf("1-To Select Level\n");
                        printf("2-To exit\n");
                        printf("\033[0m");       // default color
                        scanf("%d",&x);
                        if (x==1)
                        {
                            mistakes=0;
                            break;
                        }
                        else if (x==2)
                        {
                            return 0;
                        }
                    }
                    printf("\033[1;31m");
                    printf("  ***you have 3 mistakes then you lose***  \n");
                    printf("           mistakes=%d\n\n",mistakes);
                    printf("\033[0m");
                    print_sudoku(arr,9,9);
                    printf("insert the row\n");
                    scanf("%d",&n_row);
                    printf("insert the col\n");
                    scanf("%d",&n_col);
                    printf("insert the number\n");
                    scanf("%d",&num);
                    result=insert_num(arr,9,9,num,n_row,n_col);
                    if (result==-1)
                    {
                        ERROR_SOUND();
                        printf("not valid Duplicate in same row\n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();
                    }
                    else if (result==-2)
                    {
                        ERROR_SOUND();
                        printf("not valid Duplicate in same column\n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();
                    }
                    else if (result==-3)
                    {
                        ERROR_SOUND();
                        printf(" not valid number \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();   // clear cmd
                    }
                     else if(result==-4)
                    {
                        ERROR_SOUND();
                        printf(" not valid row \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();    // clear cmd
                    }
                    else if(result==-5)
                    {
                        ERROR_SOUND();
                        printf(" not valid column \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();    // clear cmd
                    }
                    else if(result==-6)
                    {
                        ERROR_SOUND();
                        printf(" not valid \n");
                        printf("===================\n");
                        Sleep(2000);
                        mistakes++;
                        cmdClearScreen();    // clear cmd
                    }
                    else if (result==0)
                    {
                        ifwin=check_ifwin(arr,9,9);
                        if (ifwin==0)
                        {
                            WIN_SOUND();
                            cmdClearScreen();
                            check=0;
                            printf("\033[0;32m");  // green color
                            printf("\n\n ************** c o n g r a t u l a t i o n   y o u    w i n ***************** \n");
                            printf("\033[0m");  // default color
                            Sleep(3600);
                        }
                        else
                        {
                            cmdClearScreen();
                        }

                    }
                }
            }
        }
        if (choice==2)
        {
            return 0;
        }

    }
    return 0;
}


