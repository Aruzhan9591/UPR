#ifndef CSV_H
#define CSV_H

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char *data[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;
} Database;

int load_csv(const char *filename, Database *db);
int save_csv(const char *filename, Database *db);
void free_database(Database *db);
void print_statistics(Database *db);

#endif // CSV_H
