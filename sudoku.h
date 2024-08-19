
#ifndef SUDOKU_H
#define SUDOKU_H


#define duplicate_row -1
#define duplicate_col -2
#define invalid_num   -3
#define invalid_row   -4
#define invalid_col   -5
#define invalid       -6
#define DONE           0



void print_sudoku(int arr[][9],int row,int col);
int Check_NUM(int arr[][9],int row,int col,int num,int n_row,int n_col);
int insert_num(int arr[][9],int row,int col,int num,int n_row,int n_col);
int check_ifwin(int arr[][9],int row,int col);
void cmdClearScreen(void);
void START_SOUND(void);
void ERROR_SOUND(void);
void WIN_SOUND(void);
void gameover_SOUND(void);

#endif // SUDOKU_H
