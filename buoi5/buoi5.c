#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *filenguon, *fileso, *filechu, *filekitu;
    int ch;

    filenguon = fopen("D:\\dev c\\test.txt", "r");

    if (filenguon == NULL) {
        perror("save file");
        return 1;
    }

    fileso = fopen("so.txt", "w");
    filechu = fopen("chu.txt", "w");
    filekitu = fopen("kitu.txt", "w");

    if (fileso == NULL || filechu == NULL || filekitu == NULL) {
        perror("");
        fclose(filenguon);
        return 1;
    }

    
    while ((ch = fgetc(filenguon)) != EOF) {
       
        printf("%c", ch);

        if (isdigit(ch)) {
            fputc(ch, fileso);
        } else if (isalpha(ch)) {
            fputc(ch, filechu);
        } else if (ispunct(ch)) {
            fputc(ch, filekitu);
        }
    }

    fclose(filenguon);
    fclose(fileso);
    fclose(filechu);
    fclose(filekitu);


    return 0;
}
