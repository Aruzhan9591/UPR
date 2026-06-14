#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *s) {
    char *dup = malloc(strlen(s) + 1); // Выделяем память для копии строки
    if (dup) {
        strcpy(dup, s); // Копируем строку в выделенную память
    }
    return dup;
}
