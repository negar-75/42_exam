#include "flood_fill.h"
#include <stdio.h>
#include <stdlib.h>

void fill(char **matrix, t_point dimensions, t_point start, char target) {
    if (start.x < 0 || start.x >= dimensions.x || start.y < 0 || start.y >= dimensions.y || matrix[start.y][start.x] != target)
        return;
    
    matrix[start.y][start.x] = 'F';

    // Check and fill neighbors recursively
    fill(matrix, dimensions, (t_point){start.x - 1, start.y}, target);
    fill(matrix, dimensions, (t_point){start.x + 1, start.y}, target);
    fill(matrix, dimensions, (t_point){start.x, start.y - 1}, target);
    fill(matrix, dimensions, (t_point){start.x, start.y + 1}, target);
}


void  flood_fill(char **tab, t_point size, t_point begin)
{
    fill(tab, size, begin,tab[begin.y][begin.x]);
}
void printMatrix(char **matrix, t_point dimensions) {
    for (int i = 0; i < dimensions.y; i++) {
        for (int j = 0; j < dimensions.x; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example usage
    t_point dimensions = {5, 5};
    char **matrix = (char **)malloc(dimensions.y * sizeof(char *));
    for (int i = 0; i < dimensions.y; i++) {
        matrix[i] = (char *)malloc(dimensions.x * sizeof(char));
    }

    // Initialize matrix
    for (int i = 0; i < dimensions.y; i++) {
        for (int j = 0; j < dimensions.x; j++) {
            if(i % 2 == 0)
                matrix[i][j] = 'A';
            else
                matrix[i][j] = 'B';
        }
    }

    // Print original matrix
    printf("Original matrix:\n");
    printMatrix(matrix, dimensions);

    // Apply flood fill starting from point (2, 2)
    t_point start = {2, 3};
    flood_fill(matrix, dimensions, start);

    // Print flooded matrix
    printf("\nFlood filled matrix:\n");
    printMatrix(matrix, dimensions);

    // Free memory
    for (int i = 0; i < dimensions.y; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}