#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

char* readString(const char* const);
char* getCharactersInRange(const char* const, const char, const char);

int main()
{
    const char LOWER_BOUND = 65;
    const char UPPER_BOUND = 90;

    char* string = readString("Enter a string: ");
    char* result = getCharactersInRange(string, LOWER_BOUND, UPPER_BOUND);
    
    for (int i = 0; *(result + i) != '\0'; ++i)
        printf("%c: %3d\n", *(result + i), *(result + i));

    free(string);
    free(result);

    return 0;
}

char* readString(const char* const message)
{
    char* inputBuffer = malloc(UCHAR_MAX);

    if (inputBuffer == NULL)
    {
        perror("Failed to allocate memory.");
        return NULL;
    }

    do
    {
        printf("%s", message);

        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL)
            break;

        printf("Invalid input. Please enter a valid string value.\n");

    } while (1);

    *(inputBuffer + strlen(inputBuffer) - 1) = '\0';

    return inputBuffer;
}

char* getCharactersInRange(const char* const string, const char minCode, const char maxCode)
{
    int index = 0;
    int length = strlen(string);
    char* result = malloc(length + 1);

    if (result == NULL)
    {
        perror("Failed to allocate memory.");
        return NULL;
    }

    for (int i = 0; i < length; ++i)
    {
        if (*(string + i) >= minCode && *(string + i) <= maxCode)
            *(result + index++) = *(string + i);
    }

    *(result + index) = '\0';

    return result;
}
