#include <stdio.h>

struct Vector
{
    double x;
    double y;
    double z;
};

struct OfluFile
{
    char ext[4];
    struct Vector position;
};


void CreateFile()
{
    char text[] = "napan be";
    FILE *file = fopen("test.oflu", "w");

    int len = sizeof(char) / sizeof(text[0]);

    fwrite(text, sizeof(char), len, file);
    fclose(file);
}

void ReadFile()
{
    int buffer[5];
    FILE *file = fopen("test.oflu", "r");

    fread(buffer, sizeof(int), 5, file);

    for (int i = 0; i < 5; i++)
    {
        printf("Element %d: %d \n", i+1, buffer[i]);
    }
    
    fclose(file);
}

int main()
{
    CreateFile();
    ReadFile();
    return 0;
}