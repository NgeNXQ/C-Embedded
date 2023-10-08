#include <stdio.h>

char* readString(const char*);
char* reverseString(const char*);

int main()
{
    //char* string = readString("Enter a string: ");
    //printf(string);
    long double l = 15.5;
    printf("%d", sizeof(l));

    //printf(reverseString());
    return 0;
}

char* readString(const char* message)
{
    char* string = (char*)malloc(101 * sizeof(char));

    if (string == NULL)
    {
        perror("Memory allocation failed");
        return NULL;
    }

    printf("%s", message);
    scanf_s("%s", string);

    return string;
}

char* reverseString(const char* string)
{
    int length = strlen(string);
    char* newString = (char*)malloc((length + 1) * sizeof(char));

    if (newString == NULL) 
    {
        perror("Memory allocation failed");
        return NULL;
    }

    for (int i = length - 1, j = 0; i >= 0; i--, j++) 
        newString[j] = string[i];

    newString[length] = '\0';

    return newString;
}