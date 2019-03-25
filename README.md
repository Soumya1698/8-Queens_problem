# 8-Queens_problem

The eight queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other; thus, a solution requires that no two queens share the same row, column, or diagonal.
There are 92 possible solutions of which 12 are distinct solutions.
We have already executed this problem in our ongoing campus recuritment training once, which I've inferred and executed as same. 

The ASCII chart used for drawing the chessboard of 8x8 is placed below:

![Image of ASCII chart](https://github.com/Soumya1698/8-Queens_problem/blob/master/ascii.png)

Also, **4 Queens problem** is explained in the documemt [file above!](https://github.com/Soumya1698/8-Queens_problem/blob/master/4_Queens.docx)

*POINTS TO REMEMBER:* 
- The above program can only be executed in **TURBO C++**.
- Whenever you goto next row,col, start from col=0
  * check if it is safe.
  * If it is safe, placequeen -> user's view, update queen's column position.
  * goto next row.
- Backtrack (checking for safety at column value)
  * if(col==8), remove Queen at user's view, assign -1 at programmer's view too. 
  * Start from the previous location after backtracking, copy of the column value.
  * We only check safety at left dialgonal, right diagonal, and up from the position(i.e,previous location after backtracking).
