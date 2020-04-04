#include <iostream>


#define UNASSIGNED 0  
int grid[2000][2000];

// N is used for the size of Sudoku grid.  
// Size will be NxN  
// This function finds an entry in grid  
// that is still unassigned  
bool FindUnassignedLocation(int &row, int &col, int n);  
  
// Checks whether it will be legal  
// to assign num to the given row, col  
bool isSafe(int row, 
                   int col, int num, int n);  
  
/* Takes a partially filled-in grid and attempts  
to assign values to all unassigned locations in  
such a way to meet the requirements for 
Sudoku solution (non-duplication across rows, 
columns, and boxes) */
bool SolveSudoku(int n)  
{  
    int row, col;  
  
    // If there is no unassigned location, 
    // we are done  
    if (!FindUnassignedLocation(row, col, n))  
        return true; // success!  
  
    // consider digits 1 to 9  
    for (int num = 1; num <= 2 * n - 1; num++)  
    {  
        // if looks promising  
        if (isSafe(row, col, num, n))  
        {  
            // make tentative assignment  
            grid[row][col] = num;  
  
            // return, if success, yay!  
            if (SolveSudoku(n))  
                return true;  
  
            // failure, unmake & try again  
            grid[row][col] = UNASSIGNED;  
        }  
    }  
    return false; // this triggers backtracking  
}  
  
/* Searches the grid to find an entry that is  
still unassigned. If found, the reference  
parameters row, col will be set the location  
that is unassigned, and true is returned.  
If no unassigned entries remain, false is returned. */
bool FindUnassignedLocation(int &row, int &col, int N)  
{  
    for (row = 0; row < N; row++)  
        for (col = 0; col < N; col++)  
            if (grid[row][col] == UNASSIGNED)  
                return true;  
    return false;  
}  
  
/* Returns a boolean which indicates whether  
an assigned entry in the specified row matches 
the given number. */
bool UsedInRow(int row, int num, int N)  
{  
    for (int col = 0; col < N; col++)  
        if (grid[row][col] == num)  
            return true;  
    return false;  
}  
  
/* Returns a boolean which indicates whether  
an assigned entry in the specified column 
matches the given number. */
bool UsedInCol(int col, int num, int N)  
{  
    for (int row = 0; row < N; row++)  
        if (grid[row][col] == num)  
            return true;  
    return false;  
}  
  
/* Returns a boolean which indicates whether  
it will be legal to assign num to the given  
row, col location. */
bool isSafe(int row,  
                   int col, int num, int n)  
{  
    /* Check if 'num' is not already placed in  
    current row, current column and current 3x3 box */
    return  !UsedInRow(row, num, n) &&  
            !UsedInCol(col, num, n) &&  
            grid[row][col] == UNASSIGNED;  
}  
  
/* A utility function to print grid */
void printGrid(int N)  
{  
    for (int row = 0; row < N; row++)  
    {  
    for (int col = 0; col < N; col++)  
            std::cout << grid[row][col] << " ";  
        std::cout << std::endl; 
    }  
}  

int main() {
    int t;
    std::cin>>t;
    for(int i = 0; i < t; i++) {
        int n;
        std::cin>>n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                grid[i][j] = UNASSIGNED;
        for(int i = 0; i < n; i++)
            grid[0][i] = i;
        for(int i = 0; i < n; i++)
            grid[i][0] = i;
        if(SolveSudoku(n)) {
            std::cout<<"Hooray"<<std::endl;
            printGrid(n);
        }
        else 
            std::cout<<"Boo"<<std::endl;
    }
    return 0;
}