#include <stdio.h>

void processFileAndPrintByteLengthByChar(char *fileName);

void main()
{
    printf("Initiliazing FileReader...\n");

    processFileAndPrintByteLengthByChar("src/resources/testFile.txt");

    printf("Finishing FileReader...\n");
}

void processFileAndPrintByteLengthByChar(char *fileName)
{
    FILE *file;

    file = fopen(fileName, "r");

    int characterValue;
    
    if (file == NULL)
    {
        perror("Error! File not found");
        return;
    }

    while ((characterValue = fgetc(file)) != EOF)
    {
        // 0x80 = 128
        // Here, we checking if the
        if ((characterValue & 0x80) != 0x00)
        {
            printf("Character using more than one byte to be represented found. Char: %c\n",(char) characterValue);
            break;
        }

        printf("Character using just one byte to be represented. Char: %c\n", (char) characterValue);
    }

    fclose(file);
}