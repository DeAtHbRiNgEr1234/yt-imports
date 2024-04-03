#include <stdio.h>
#include <stdbool.h>

#define N 9

bool is_valid(int board[N][N], int row, int col, int num) {
    // Check if the number already exists in the row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // Check if the number already exists in the column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // Check if the number already exists in the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool find_empty_location(int board[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (board[*row][*col] == 0) {
                return true; // Found an empty cell
            }
        }
    }
    return false; // No empty cell found
}

bool solve_sudoku(int board[N][N]) {
    int row, col;

    if (!find_empty_location(board, &row, &col)) {
        return true; // If there are no empty cells, the puzzle is solved
    }

    for (int num = 1; num <= 9; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;

            if (solve_sudoku(board)) {
                return true;
            }

            // If placing the number at position (row, col) doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    return false; // If no number can be placed at position (row, col), backtrack
}

void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Original Sudoku Puzzle:\n");
    print_board(board);
    printf("\nSolving...\n\n");

    if (solve_sudoku(board)) {
        printf("Solved Sudoku Puzzle:\n");
        print_board(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}

