#include <stdio.h>

int main() {
    system("chcp 1251");
    char line[1000];
    printf("Введите строку: ");
    fgets(line, sizeof(line), stdin);

    int i = 0;
    printf("Слова с тире:\n");

    while (line[i]) {
        while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' ||
            line[i] == ',' || line[i] == '.' || line[i] == '!' ||
            line[i] == '?' || line[i] == ';' || line[i] == ':') {
            i++;
        }

        int start = i;
        int has_dash = 0;

        while (line[i]) {
            char c = line[i];
            if (c == ' ' || c == '\t' || c == '\n' ||
                c == ',' || c == '.' || c == '!' ||
                c == '?' || c == ';' || c == ':') {
                break;
            }
            if (c == '-') {
                has_dash = 1;
            }
            i++;
        }

        if (has_dash) {
            for (int j = start; j < i; j++) {
                putchar(line[j]);
            }
            printf("\n");
        }
    }
    return 0;
}

