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

// Main method
int main(void)
{
	// User input for creating sudoku board
	int board[9][9], i, j;
	char row_i[10], column_j[10];

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			snprintf(row_i, 10, "%d", i + 1);
			snprintf(column_j, 10, "%d", j + 1);

			printf("Enter value for row %s, column %s:\t", &row_i, &column_j);

			// Value from user to row i & column j
			scanf("%d", &board[i][j]);
		}
	}

	/*
	* Valid example:
	* 6, 2, 4, 5, 3, 9, 1, 8, 7
	* 5, 1, 9, 7, 2, 8, 6, 3, 4
	* 8, 3, 7, 6, 1, 4, 2, 9, 5
	* 1, 4, 3, 8, 6, 5, 7, 2, 9
	* 9, 5, 8, 2, 4, 7, 3, 6, 1
	* 7, 6, 2, 3, 9, 1, 4, 5, 8
	* 3, 7, 1, 9, 5, 6, 8, 4, 2
	* 4, 9, 6, 1, 8, 2, 5, 7, 3
	* 2, 8, 5, 4, 7, 3, 9, 1, 6
	*/

	// Parameters for threads
	parameters * data_1 = (parameters *)malloc(sizeof(parameters));
	data_1->row = 0;
	data_1->col = 0;
	data_1->board = board;

	parameters * data_2 = (parameters *)malloc(sizeof(parameters));
	data_2->row = 0;
	data_2->col = 3;
	data_2->board = board;

	parameters * data_3 = (parameters *)malloc(sizeof(parameters));
	data_3->row = 0;
	data_3->col = 6;
	data_3->board = board;

	parameters * data_4 = (parameters *)malloc(sizeof(parameters));
	data_4->row = 3;
	data_4->col = 0;
	data_4->board = board;

	parameters * data_5 = (parameters *)malloc(sizeof(parameters));
	data_5->row = 3;
	data_5->col = 3;
	data_5->board = board;

	parameters * data_6 = (parameters *)malloc(sizeof(parameters));
	data_6->row = 3;
	data_6->col = 6;
	data_6->board = board;

	parameters * data_7 = (parameters *)malloc(sizeof(parameters));
	data_7->row = 6;
	data_7->col = 0;
	data_7->board = board;

	parameters * data_8 = (parameters *)malloc(sizeof(parameters));
	data_8->row = 6;
	data_8->col = 3;
	data_8->board = board;

	parameters * data_9 = (parameters *)malloc(sizeof(parameters));
	data_9->row = 6;
	data_9->col = 6;
	data_9->board = board;

	parameters * data_10 = (parameters *)malloc(sizeof(parameters));
	data_10->row = 1;
	data_10->col = 0;
	data_10->board = board;

	parameters * data_11 = (parameters *)malloc(sizeof(parameters));
	data_11->row = 2;
	data_11->col = 0;
	data_11->board = board;

	parameters * data_12 = (parameters *)malloc(sizeof(parameters));
	data_12->row = 3;
	data_12->col = 0;
	data_12->board = board;

	parameters * data_13 = (parameters *)malloc(sizeof(parameters));
	data_13->row = 4;
	data_13->col = 0;
	data_13->board = board;

	parameters * data_14 = (parameters *)malloc(sizeof(parameters));
	data_14->row = 5;
	data_14->col = 0;
	data_14->board = board;

	parameters * data_15 = (parameters *)malloc(sizeof(parameters));
	data_15->row = 6;
	data_15->col = 0;
	data_15->board = board;

	parameters * data_16 = (parameters *)malloc(sizeof(parameters));
	data_16->row = 7;
	data_16->col = 0;
	data_16->board = board;

	parameters * data_17 = (parameters *)malloc(sizeof(parameters));
	data_17->row = 8;
	data_17->col = 0;
	data_17->board = board;

	parameters * data_18 = (parameters *)malloc(sizeof(parameters));
	data_18->row = 0;
	data_18->col = 1;
	data_18->board = board;

	parameters * data_19 = (parameters *)malloc(sizeof(parameters));
	data_19->row = 0;
	data_19->col = 2;
	data_19->board = board;

	parameters * data_20 = (parameters *)malloc(sizeof(parameters));
	data_20->row = 0;
	data_20->col = 3;
	data_20->board = board;

	parameters * data_21 = (parameters *)malloc(sizeof(parameters));
	data_21->row = 0;
	data_21->col = 4;
	data_21->board = board;

	parameters * data_22 = (parameters *)malloc(sizeof(parameters));
	data_22->row = 0;
	data_22->col = 5;
	data_22->board = board;

	parameters * data_23 = (parameters *)malloc(sizeof(parameters));
	data_23->row = 0;
	data_23->col = 6;
	data_23->board = board;

	parameters * data_24 = (parameters *)malloc(sizeof(parameters));
	data_24->row = 0;
	data_24->col = 7;
	data_24->board = board;

	parameters * data_25 = (parameters *)malloc(sizeof(parameters));
	data_25->row = 0;
	data_25->col = 8;
	data_25->board = board;

	// Worker threads
	pthread_t thread_row_1, thread_row_2, thread_row_3, thread_row_4, thread_row_5, thread_row_6, thread_row_7, thread_row_8, thread_row_9,
			  thread_column_1, thread_column_2, thread_column_3, thread_column_4, thread_column_5, thread_column_6, thread_column_7, thread_column_8, thread_column_9,
			  thread_grid_1, thread_grid_2, thread_grid_3, thread_grid_4, thread_grid_5, thread_grid_6, thread_grid_7, thread_grid_8, thread_grid_9;

	// Values for threads to return
	void * row_1;
	void * row_2;
	void * row_3;
	void * row_4;
	void * row_5;
	void * row_6;
	void * row_7;
	void * row_8;
	void * row_9;

	void * column_1;
	void * column_2;
	void * column_3;
	void * column_4;
	void * column_5;
	void * column_6;
	void * column_7;
	void * column_8;
	void * column_9;

	void * grid_1;
	void * grid_2;
	void * grid_3;
	void * grid_4;
	void * grid_5;
	void * grid_6;
	void * grid_7;
	void * grid_8;
	void * grid_9;

	// Initialization of threads
	pthread_create(&thread_grid_1, NULL, check_grids, (void *)data_1);
	pthread_create(&thread_grid_2, NULL, check_grids, (void *)data_2);
	pthread_create(&thread_grid_3, NULL, check_grids, (void *)data_3);
	pthread_create(&thread_grid_4, NULL, check_grids, (void *)data_4);
	pthread_create(&thread_grid_5, NULL, check_grids, (void *)data_5);
	pthread_create(&thread_grid_6, NULL, check_grids, (void *)data_6);
	pthread_create(&thread_grid_7, NULL, check_grids, (void *)data_7);
	pthread_create(&thread_grid_8, NULL, check_grids, (void *)data_8);
	pthread_create(&thread_grid_9, NULL, check_grids, (void *)data_9);
	
	pthread_create(&thread_column_1, NULL, check_columns, (void *)data_1);
	pthread_create(&thread_column_2, NULL, check_columns, (void *)data_10);
	pthread_create(&thread_column_3, NULL, check_columns, (void *)data_11);
	pthread_create(&thread_column_4, NULL, check_columns, (void *)data_12);
	pthread_create(&thread_column_5, NULL, check_columns, (void *)data_13);
	pthread_create(&thread_column_6, NULL, check_columns, (void *)data_14);
	pthread_create(&thread_column_7, NULL, check_columns, (void *)data_15);
	pthread_create(&thread_column_8, NULL, check_columns, (void *)data_16);
	pthread_create(&thread_column_9, NULL, check_columns, (void *)data_17);

	pthread_create(&thread_row_9, NULL, check_rows, (void *)data_1);
	pthread_create(&thread_row_1, NULL, check_rows, (void *)data_18);
	pthread_create(&thread_row_2, NULL, check_rows, (void *)data_19);
	pthread_create(&thread_row_3, NULL, check_rows, (void *)data_20);
	pthread_create(&thread_row_4, NULL, check_rows, (void *)data_21);
	pthread_create(&thread_row_5, NULL, check_rows, (void *)data_22);
	pthread_create(&thread_row_6, NULL, check_rows, (void *)data_23);
	pthread_create(&thread_row_7, NULL, check_rows, (void *)data_24);
	pthread_create(&thread_row_8, NULL, check_rows, (void *)data_25);

	// Wait process for worker threads to exit
	pthread_join(thread_row_1, &row_1);
	pthread_join(thread_row_2, &row_2);
	pthread_join(thread_row_3, &row_3);
	pthread_join(thread_row_4, &row_4);
	pthread_join(thread_row_5, &row_5);
	pthread_join(thread_row_6, &row_6);
	pthread_join(thread_row_7, &row_7);
	pthread_join(thread_row_8, &row_8);
	pthread_join(thread_row_9, &row_9);

	pthread_join(thread_column_1, &column_1);
	pthread_join(thread_column_2, &column_2);
	pthread_join(thread_column_3, &column_3);
	pthread_join(thread_column_4, &column_4);
	pthread_join(thread_column_5, &column_5);
	pthread_join(thread_column_6, &column_6);
	pthread_join(thread_column_7, &column_7);
	pthread_join(thread_column_8, &column_8);
	pthread_join(thread_column_9, &column_9);

	pthread_join(thread_grid_1, &grid_1);
	pthread_join(thread_grid_2, &grid_2);
	pthread_join(thread_grid_3, &grid_3);
	pthread_join(thread_grid_4, &grid_4);
	pthread_join(thread_grid_5, &grid_5);
	pthread_join(thread_grid_6, &grid_6);
	pthread_join(thread_grid_7, &grid_7);
	pthread_join(thread_grid_8, &grid_8);
	pthread_join(thread_grid_9, &grid_9);

	// Final result when all threads are completed
	int threads_completed = (int)row_1 +
							(int)row_2 +
							(int)row_3 +
							(int)row_4 +
							(int)row_5 +
							(int)row_6 +
							(int)row_7 +
							(int)row_8 +
							(int)row_9 +
							(int)column_1 +
							(int)column_2 +
							(int)column_3 +
							(int)column_4 +
							(int)column_5 +
							(int)column_6 +
							(int)column_7 +
							(int)column_8 +
							(int)column_9 +
							(int)grid_1 +
							(int)grid_2 +
							(int)grid_3 +
							(int)grid_4 +
							(int)grid_5 +
							(int)grid_6 +
							(int)grid_7 +
							(int)grid_8 +
							(int)grid_9;

	if (threads_completed == 27) {
		printf("Your sudoku solution is valid!");
	}
	else {
		printf("Your sudoku solution is not valid...");
	}

	// Exit
	return 0;
}
