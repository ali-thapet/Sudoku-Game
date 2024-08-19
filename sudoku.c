#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<mmsystem.h>
#include"sudoku.h"





void print_sudoku(int arr[][9],int row,int col)
{
    short i,j,x=0;
    printf("       0   1   2     3   4   5     6   7   8\n");
    printf("   --------------------------------------------\n");

    for (i=0; i<row; i++)
    {
        if (i==3||i==6)
        {
            printf("   --------------------------------------------\n");
        }
        for (j=0; j<col; j++)
        {
            if (j==0)
            {
                printf(" %d |",x);
                x++;
            }

            if (arr[i][j]==0)
            {
                printf("\033[0;34m");  // blue color
            }
            printf("%4d",arr[i][j]);

                printf("\033[0m");    // default color


            if (j==2||j==5)
            {
                printf(" |");
            }

            if (j==col-1)
            {
                printf("  |");
            }
        }
        if (i==row-1)
        {
            printf("\n   --------------------------------------------\n");
        }
        else
        {
            printf("\n");
        }
    }
}

int Check_NUM(int arr[][9],int row,int col,int num,int n_row,int n_col)
{
    int i,j,flag=0;
    if (num>9||num<1)            // function check if number between 1&9
    {
        return invalid_num;
    }
    if (n_row>8||n_row<0)         // function check if row between 0&8
    {
        return invalid_row;
    }
    if (n_col>8||n_col<0)          // function check if column between 0&8
    {
        return invalid_col;
    }
    if (arr[n_row][n_col]!=0)       // function check if it is valid place or not
    {
        return invalid;
    }
    for (i=0; i<col; i++)          //check if we find the number in same row
    {
        if (num==arr[n_row][i])
        {
            flag=1;
            return duplicate_row;
        }
    }
    for (i=0; i<row; i++) //check if we find the number in same col
    {
        if (num==arr[i][n_col])
        {
            flag=1;
            return duplicate_col;
        }
    }
    if (flag==0)
    {
        return DONE;
    }

}

int insert_num(int arr[][9],int row,int col,int num,int n_row,int n_col)
{
    int r;
    r=Check_NUM(arr,row,col,num,n_row,n_col);
    if (r==0)
    {
        arr[n_row][n_col]=num;
        return DONE;
    }
    else if (r==-1)
    {
        return duplicate_row;
    }
    else if (r==-2)
    {
        return duplicate_col;
    }
    else if (r==-3)
    {
        return invalid_num;
    }
    else if (r==-4)
    {
        return invalid_row;
    }
    else if (r==-5)
    {
        return invalid_col;
    }
    else if (r==-6)
    {
        return invalid;
    }
}

int check_ifwin(int arr[][9],int row,int col)
{
    int i,j;
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            if (arr[i][j]==0)
            {
                return 1;
            }
        }
    }
    return DONE;
}
void cmdClearScreen(void)
{
    //system("@cls||clear");
	system("cls"); //from windows APIs
}

void START_SOUND(void)
{
    PlaySound("E:\\embedded course\\TOOLS\\Projects\\sudoku.project\\sounds\\success-fanfare-trumpets-6185.wav", NULL, SND_ASYNC);    // play start sound function

}
void ERROR_SOUND(void)
{
    PlaySound("E:\\embedded course\\TOOLS\\Projects\\sudoku.project\\sounds\\buzzer-15-187758.wav", NULL, SND_ASYNC);    // play error sound function

}
void WIN_SOUND(void)
{
    PlaySound("E:\\embedded course\\TOOLS\\Projects\\sudoku.project\\sounds\\level-win-6416.wav", NULL, SND_ASYNC);    // play win sound function

}
void gameover_SOUND(void)
{
    PlaySound("E:\\embedded course\\TOOLS\\Projects\\sudoku.project\\sounds\\failure-drum-sound-effect-1-46093.wav", NULL, SND_ASYNC);    // play game over sound function

}
