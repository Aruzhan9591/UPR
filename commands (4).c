#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "utils.h"

int process_command(const char *command, Database *db) {
    if (strncmp(command, "addrow", 6) == 0) {
        char *data[MAX_COLS];
        char *token = strtok((char *)command + 7, ",");
        int col = 0;

        while (token) {
            data[col++] = token;
            token = strtok(NULL, ",");
        }

        if (col != db->cols) {
            fprintf(stderr, "Error: Invalid number of columns.\n");
            return 1;
        }

        for (int i = 0; i < col; i++) {
            db->data[db->rows][i] = my_strdup(data[i]);
        }

        db->rows++;
        printf("Row added successfully.\n");


    } else if(strncmp(command, "min" , 3) == 0){
        char *col_name = (char *)command + 4;
        int col_index = -1;

        for( int i=0; i < db->cols; i++){
            if(strcmp(db->data[0][i], col_name)==0){
                col_index = i;
                break;
            }
        }

        if(col_index ==-1){
            fprintf(stderr , "Error: Column not found.\n");
            return 1;
        }

        double min_value =__DBL_MAX__;
        for (int i= 1; i<db->rows; i++){
            double value = atof(db->data[i][col_index]);

            if(value < min_value){
                min_value = value;
            }
        }

        printf("Min value in colum %s: %.2f\n", col_name, min_value);


    } else if(strncmp(command, "max" , 3) == 0){
        char *col_name = (char *)command + 4;
        int col_index = -1;

        for(int i=0; i<db->cols; i++){
            if (strcmp(db->data[0][i], col_name) ==0){
                col_index = i;
                break;
            }
        }

        if(col_index == -1){
            fprintf(stderr , "Error: Column not found.\n");
            return 1;
        }

        double max_value = -__DBL_MAX__;
        for (int i= 1; i<db->rows; i++){
            double value = atof(db->data[i][col_index]);

            if(value > max_value){
                max_value = value;
            }
        }

        printf("Max value in colum %s: %.2f\n", col_name, max_value);



    } else if (strncmp(command, "addcol", 6) == 0) {
        char *args = my_strdup(command + 7);
        char *col_name = strtok(args, " ");
        char *values = strtok(NULL, "");

        if (!col_name || !values) {
            fprintf(stderr, "Error: Invalid addcol syntax.\n");
            free(args);
            return 1;
        }

        if (db->cols >= MAX_COLS) {
            fprintf(stderr, "Error: Maximum column limit exceeded.\n");
            free(args);
            return 1;
        }

        db->data[0][db->cols] = my_strdup(col_name);

        char *value = strtok(values, ",");
        int row = 1;

        while (value) {
            if (row >= db->rows) {
                fprintf(stderr, "Error: Number of values does not match number of rows.\n");
                free(args);
                return 1;
            }
            db->data[row][db->cols] = my_strdup(value);
            value = strtok(NULL, ",");
            row++;
        }

        if (row != db->rows) {
            fprintf(stderr, "Error: Number of values does not match number of rows.\n");
            free(args);
            return 1;
        }

        db->cols++;
        printf("Column '%s' added successfully.\n", col_name);
        free(args);

    } else if (strncmp(command, "sum", 3) == 0) {
        char *col_name = (char *)command + 4;
        int col_index = -1;

        for (int i = 0; i < db->cols; i++) {
            if (strcmp(db->data[0][i], col_name) == 0) {
                col_index = i;
                break;
            }
        }

        if (col_index == -1) {
            fprintf(stderr, "Error: Column not found.\n");
            return 1;
        }

        double sum = 0;
        for (int i = 1; i < db->rows; i++) {
            sum += atof(db->data[i][col_index]);
        }
        printf("Sum of column %s: %.2f\n", col_name, sum);

    } else if (strncmp(command, "average", 7) == 0) {
        char *col_name = (char *)command + 8;
        int col_index = -1;

        for (int i = 0; i < db->cols; i++) {
            if (strcmp(db->data[0][i], col_name) == 0) {
                col_index = i;
                break;
            }
        }

        if (col_index == -1) {
            fprintf(stderr, "Error: Column not found.\n");
            return 1;
        }

        double sum = 0;
        int count = 0;

        for (int i = 1; i < db->rows; i++) {
            double value = atof(db->data[i][col_index]);
            sum += value;
            count++;
        }

        if (count > 0) {
            printf("Average of column %s: %.2f\n", col_name, sum / count);
        } else {
            printf("Average of column %s: 0.00\n", col_name);
        }

    } else {
        fprintf(stderr, "Error: Unknown command.\n");
        return 1;
    }

    return 0;
}
