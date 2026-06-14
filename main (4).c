
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#include "commands.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s --input <input.csv> --output <output.csv>\n", argv[0]);
        return 1;
    }

    char *input_file = NULL;
    char *output_file = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--input") == 0) {
            input_file = argv[++i];
        } else if (strcmp(argv[i], "--output") == 0) {
            output_file = argv[++i];
        }
    }

    if (!input_file || !output_file) {
        fprintf(stderr, "Error: Missing input or output file argument.\n");
        return 1;
    }

    Database db;
    if (load_csv(input_file, &db) != 0) {
        return 1;
    }

    print_statistics(&db);

    char command[256];
    while (1) {
        printf("Enter command: ");
        if (!fgets(command, sizeof(command), stdin)) {
            break;
        }

        command[strcspn(command, "\n")] = 0; 
        if (strcmp(command, "exit") == 0) {
            break;
        }

        if (process_command(command, &db) != 0) {
            fprintf(stderr, "Error processing command.\n");
        }
    }

    if (save_csv(output_file, &db) != 0) {
        return 1;
    }

    free_database(&db);
    return 0;
}



