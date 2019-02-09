#include "life.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * get_grid creates new memory for a "grid".
 * x is the height and y is the width.
 */
char** get_grid(int x, int y){

	// create memory for height
        // https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
	char** grid = (char**) malloc(x * sizeof(char*));

	// check if all memory is consumed
	if (grid == NULL) {
		fprintf(stderr, "Failed to allocate memory.\n");
        	exit(-1);
	}

	// create memory for width
	for (int i = 0; i < x; i++) {
		grid[i] = (char*) malloc(y * sizeof(char));
                // check if all memory is consumed
                if (grid[i] == NULL) {
                        fprintf(stderr, "Failed to allocate memory.\n");
                        exit(-1);
                }
	}

	return grid;
}

/*
 * print_grid attempts to print an x height
 * by y width grid stored at the location
 * provided by grid
 */
void print_grid(int x, int y, char** grid){

	printf("\n");
	
	// row loop
	for (int row = 0; row < x; row++) {
                printf("\n");
		// col loop
		for (int col = 0; col < y; col++) {
			printf("%c", grid[row][col]);
		}
	}
}

/*
 * mutate takes a grid and mutates that grid
 * according to Conway's rules.  A new grid
 * is returned.
 */
char** mutate(int x, int y, char** grid){
        int neighbors;
        char** new_grid = get_grid(x, y);

        // row loop
        for (int row = 0; row < x; row++) {
                // col loop
                for (int col = 0; col < y; col++) {
                        neighbors = get_neighbors(row, col, x, y, grid);
                        // "living" cell
                        if ( grid[row][col] == 1 ) {
                                // less than two neighbors - dies
                                if ( neighbors < 2 ) {
                                        new_grid[row][col] = 0;
                                }
                                // 2 or 3 neighbors - lives
                                if ( neighbors == 2 || neighbors == 3 ) {
                                        new_grid[row][col] = 1;
                                }
                                // more than 3 neighbors - dies
                                if ( neighbors > 3 ) {
                                        new_grid[row][col] = 0;
                                }
                        }
                        // "dead" cell
                        else {
                                // more than 3 neighbors - becomes alive
                                if ( neighbors > 3 ) {
                                        new_grid[row][col] = 1;
                                }
                        }

                }
        }

        // free the memory of the "old" grid
        for (int i = 0; i < x; i++) {
                free(grid[i]);
        }
        free(grid);
}

/* get_neighbors is a helper method that returns
 * the number of live neighbors a cell has.
 */
int get_neighbors(int i, int j, int x, int y, char** grid){

	int count = 0;

	// top left corner
	if (i == 0 && j == 0) {
		
		// south
		if (grid[i+1][j] == 1) {
			count++;
		}
		// southeast
		if (grid[i+1][j+1] == 1) {
                        count++;
                }
		// east
		if (grid[i][j+1] == 1) {
                        count++;
                }
	}	

	// top right corner
	else if (i == 0 && j == y) {
		
		// west
		if (grid[i][j-1] == 1) {
                        count++;
                }
		// south
		if (grid[i+1][j] == 1) {
                        count++;
                }
		// southwest
		if (grid[i+1][j-1] == 1) {
                        count++;
                }
        }

	// bottom left corner
	else if (i == x && j == 0) {
		
		// north
		if (grid[i-1][j] == 1) {
                        count++;
                }
		// east
		if (grid[i][j+1] == 1) {
                        count++;
                }
		// northeast
		if (grid[i-1][j+1] == 1) {
                        count++;
                }
        }

	// bottom right corner
	else if (i == x && j == y) {
		
		// north
                if (grid[i-1][j] == 1) {
                        count++;
                }
                // west
                if (grid[i][j-1] == 1) {
                        count++;
                }
                // northwest
                if (grid[i-1][j-1] == 1) {
                        count++;
                }
        }

	// top
	else if (i == 0) {
		
		// west
		if (grid[i][j-1] == 1) {
                        count++;
                }
		// southwest
                if (grid[i+1][j-1] == 1) {
                        count++;
                }
		// south
                if (grid[i+1][j] == 1) {
                        count++;
                }
                // southeast
                if (grid[i+1][j+1] == 1) {
                        count++;
                }
                // east
                if (grid[i][j+1] == 1) {
                        count++;
                }
        }

	// bottom
	else if (i == x) {
		
		// west
		if (grid[i][j-1] == 1) {
                        count++;
                }
		// northwest
		if (grid[i-1][j-1] == 1) {
                        count++;
                }
		// north
		if (grid[i-1][j] == 1) {
                        count++;
                }
		// northeast
		if (grid[i-1][j+1] == 1) {
                        count++;
                }
		// east
		if (grid[i][j+1] == 1) {
                        count++;
                }
        }

	// left
	else if (j == 0) {
		
		// north
		if (grid[i-1][j] == 1) {
                        count++;
                }
		// northeast
		if (grid[i-1][j+1] == 1) {
                        count++;
                }
		// east
		if (grid[i][j+1] == 1) {
                        count++;
                }
		// southeast
		if (grid[i+1][j+1] == 1) {
                        count++;
                }
		// south
		if (grid[i+1][j] == 1) {
                        count++;
                }
        }

	// right
	else if (j == y) {
		
		// north
		if (grid[i-1][j] == 1) {
                        count++;
                }
		// northwest
		if (grid[i-1][j-1] == 1) {
                        count++;
                }
		// west
		if (grid[i][j-1] == 1) {
                        count++;
                }
		// southwest
		if (grid[i+1][j-1] == 1) {
                        count++;
                }
		// south
		if (grid[i+1][j] == 1) {
                        count++;
                }
        }
	
	// middle
	else {
		
		// north
                if (grid[i-1][j] == 1) {
                        count++;
                }
                // northwest
                if (grid[i-1][j-1] == 1) {
                        count++;
                }
                // west
                if (grid[i][j-1] == 1) {
                        count++;
                }
                // southwest
                if (grid[i+1][j-1] == 1) {
                        count++;
                }
                // south
                if (grid[i+1][j] == 1) {
                        count++;
                }
		// northeast
                if (grid[i-1][j+1] == 1) {
                        count++;
                }
                // east
                if (grid[i][j+1] == 1) {
                        count++;
                }
                // southeast
                if (grid[i+1][j+1] == 1) {
                        count++;
                }
	}
	return count;
}