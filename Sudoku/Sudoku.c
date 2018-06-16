/* 
** Sudoku Validator
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


// Structure for pointing to data where threads should begin to validate
typedef struct
{
	int row;
	int col;
	int(*board)[9];
} parameters;

// Method for checking if rows contain all digits from 1 to 9 and returning 1 or 0 accordingly
void * check_rows(void * params) {
	parameters * data = (parameters *)params;
	int start_row = data->row;
	int start_col = data->col;

	int row[10] = { 0 };
	for (int j = start_col; j < 9; j++) {
		int value = data->board[start_row][j];
		if (row[value] != 0) {
			return (void *)0;
		}
		else {
			row[value] = 1;
		}
	}
	return (void *)1;
};

// Method for checking if columns contain all digits from 1 to 9 and returning 1 or 0 accordingly
void * check_columns(void * params) {
	parameters * data = (parameters *)params;
	int start_row = data->row;
	int start_col = data->col;

	int column[10] = { 0 };
	for (int j = start_row; j < 9; j++) {
		int value = data->board[j][start_col];
		if (column[value] != 0) {
			return (void *)0;
		}
		else {
			column[value] = 1;
		}
	}
	return (void *)1;
};

// Method for checking if 3x3 sized grids contain all digits from 1 to 9 and returning 1 or 0 accordingly
void * check_grids(void * params) {
	parameters * data = (parameters *)params;
	int start_row = data->row;
	int start_col = data->col;

	for (int i = start_row; i < start_row + 3; i++) {
		int grid[10] = { 0 };
		for (int j = start_col; j < start_col + 3; j++) {
			int value = data->board[i][j];
			if (grid[value] != 0) {
				return (void *)0;
			}
			else {
				grid[value] = 1;
			}
		}
	}
	return (void *)1;
};
