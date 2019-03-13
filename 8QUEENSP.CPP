#include<stdio.h>
#include<conio.h>
#include<dos.h>
#define LT 218
#define RT 191
#define CROSS 197
#define HL 196
#define VL 179
#define TT 194
#define BT 193
#define LST 195
#define RST 180
#define LB 192
#define RB 217
#define BS 8
#define SPACE 32
#define WIDTH 7
#define HEIGHT 1
#define DIM 8
#define SAFE 1
#define UNSAFE 0
void drawBox();
void placeQueen(int,int);
void removeQueen(int rowBox, int colBox);
int isSafe(int,int);
int queenPosition[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int main()
{
 int row,col,safeCol,solCtr=0;
 clrscr();
 drawBox();
 row=0;
 safeCol=-1;
 gotoxy(7,3);
 printf("EIGHT QUEENS");
 gotoxy(60,3);
 printf("SolCtr : %2d " ,solCtr);
while(1)
{
while(row<DIM)
{
  for(col = safeCol +1  ;col < DIM ; col++)
 {
  if(isSafe(row,col) == SAFE)
  {
   placeQueen(row,col);      //user
   queenPosition[row] = col ;  //pro view
   safeCol = -1;
   row++;
   break;
  }
 }
 if(col == DIM)//backtracking
 {
  row--;
  safeCol = queenPosition[row];
  removeQueen(row,queenPosition[row]); //user
  queenPosition[row] = -1;             //pro view
 }
}
 solCtr++;
 gotoxy(60,3);
 printf("SolCtr : %2d " ,solCtr);
 delay(500);
 if(solCtr==92) break;
  row--;
  safeCol = queenPosition[row];
  removeQueen(row,queenPosition[row]); //user
  queenPosition[row] = -1;             //pro view

}
 getch();
 return 0;
}
 int isSafe(int grow,int gcol)
 {
  int crow,ccol;
  //left dia
  for(crow = grow-1, ccol = gcol-1; ccol>=0 && crow>=0 ; crow--,ccol--)
  if(queenPosition[crow] == ccol)
     return UNSAFE;
  //up
  for(crow = grow-1, ccol = gcol;  crow>=0 ; crow--)
  if(queenPosition[crow] == ccol)
     return UNSAFE;
  // right dia
  for(crow = grow-1, ccol = gcol+1; ccol<DIM && crow>=0 ; crow--,ccol++)
  if(queenPosition[crow] == ccol)
     return UNSAFE;
 return SAFE;
 }

void placeQueen(int rowBox, int colBox)
{
  int brow,bcol;
  bcol= (80-(DIM*WIDTH + DIM  + 1))/2;
  brow= (25-(DIM*HEIGHT + DIM  + 1))/2;
  bcol  =bcol + 2;
  brow= brow+1;
 gotoxy(colBox *(WIDTH+1) +bcol, rowBox*(HEIGHT+1) + brow);
 textcolor(rowBox+1);
 cprintf("QUEEN");
}
void removeQueen(int rowBox, int colBox)
{
  int brow,bcol;
  bcol= (80-(DIM*WIDTH + DIM  + 1))/2;
  brow= (25-(DIM*HEIGHT + DIM  + 1))/2;
  bcol  =bcol + 2;
  brow= brow+1;
 gotoxy(colBox *(WIDTH+1) +bcol, rowBox*(HEIGHT+1) + brow);
 printf("     ");
}
void drawBox()//home
{
  int brow,bcol;
  int ctr1,ctr2,ctr3;
  clrscr();
  bcol= (80-(DIM*WIDTH + DIM  + 1))/2;
  brow= (25-(DIM*HEIGHT + DIM  + 1))/2;
//  printf("%d %d ",brow,bcol);
  gotoxy(bcol,brow);
   printf("%c",LT);
   for(ctr2=1 ; ctr2 <= DIM ; ctr2++)
   {
   for(ctr1= 1; ctr1<=WIDTH ; ctr1++)
    printf("%c",HL);
   printf("%c",TT);
   }
   printf("%c%c",BS,RT);
   //end of first line
   for(ctr3=1 ; ctr3 <= DIM ; ctr3++)
   {
   gotoxy(bcol,++brow);
   for(ctr2=1 ; ctr2 <= DIM+1 ; ctr2++)
  {
   printf("%c",VL);
   for(ctr1= 1; ctr1<=WIDTH ; ctr1++)
    printf("%c",SPACE);
  }
   gotoxy(bcol,++brow);
   printf("%c",LST);
   for(ctr2=1 ; ctr2 <= DIM ; ctr2++)
   {
   for(ctr1= 1; ctr1<=WIDTH ; ctr1++)
    printf("%c",HL);
   printf("%c",CROSS);
  }
   printf("%c%c",BS,RST);
  }//end of body
  gotoxy(bcol,brow);
   printf("%c",LB);
   for(ctr2=1 ; ctr2 <= DIM ; ctr2++)
   {
   for(ctr1= 1; ctr1<=WIDTH ; ctr1++)
    printf("%c",HL);
   printf("%c",BT);
   } 
   printf("%c%c",BS,RB);
   //end of last line
}


