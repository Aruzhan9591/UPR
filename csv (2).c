#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#include "utils.h"


int load_csv(const char *filename, Database *db) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening input file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];  
    db->rows = 0;
    db->cols = 0;

    while (fgets(line, sizeof(line), file)) {
        if (db->rows >= MAX_ROWS) {
            fprintf(stderr, "Error: Maximum row limit exceeded.\n");
            fclose(file);
            return 1;
        }

        line[strcspn(line, "\n")] = 0;

        int col = 0;
        char *token = strtok(line, ",");
        while (token) {
            if (col >= MAX_COLS) {
                fprintf(stderr, "Error: Maximum column limit exceeded.\n");
                fclose(file);
                return 1;
            }

            db->data[db->rows][col] = my_strdup(token); 
            if (!db->data[db->rows][col]) {
                fprintf(stderr, "Error: Memory allocation failed.\n");
                fclose(file);
                return 1;
            }
            token = strtok(NULL, ",");
            col++;
        }

        db->rows++;
        db->cols = col > db->cols ? col : db->cols; 
    }

    fclose(file);
    return 0;
}

int save_csv(const char *filename, Database *db) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening output file");
        return 1;
    }

    for (int i = 0; i < db->rows; i++) {
        for (int j = 0; j < db->cols; j++) {
            if (db->data[i][j]) {
                fprintf(file, "%s", db->data[i][j]);
            } else {
                fprintf(file, " "); 
            }

            if (j < db->cols - 1) {
                fprintf(file, ",");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return 0;
}

void free_database(Database *db) {
    for (int i = 0; i < db->rows; i++) {
        for (int j = 0; j < db->cols; j++) {
            free(db->data[i][j]); 
        }
    }
    db->rows = 0;
    db->cols = 0;
}

void print_statistics(Database *db) {
    printf("File statistics:\n");
    printf("Rows: %d\n", db->rows);
    printf("Columns: %d\n", db->cols);
}
