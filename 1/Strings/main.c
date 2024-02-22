#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

char* read_string(const char* const);
char* get_characters_in_range(const char* const, const char, const char);

int main()
{
    const char LOWER_BOUND = 65;
    const char UPPER_BOUND = 90;

    const char* string = read_string("Enter a string: ");
    const char* result = get_characters_in_range(string, LOWER_BOUND, UPPER_BOUND);
    
    for (int i = 0; *(result + i) != '\0'; ++i)
        printf("%c: %3d\n", *(result + i), *(result + i));

    free(string);
    free(result);

    return 0;
}

char* read_string(const char* const message)
{
    char* const input_buffer = (char*)malloc(UCHAR_MAX);

    if (input_buffer == NULL)
    {
        perror("Failed to allocate memory.");
        exit(1);
    }

    do
    {
        printf("%s", message);

        if (fgets(input_buffer, UCHAR_MAX, stdin) != NULL)
            break;

        printf("Invalid input. Please enter a valid string value.\n");

    } while (1);

    *(input_buffer + strlen(input_buffer) - 1) = '\0';

    return input_buffer;
}

char* get_characters_in_range(const char* const string, const char min_code, const char max_code)
{
    int index = 0;
    int length = strlen(string);
    char* result = (char*)malloc(length + 1);

    if (result == NULL)
    {
        perror("Failed to allocate memory.");
        exit(-1);
    }

    for (int i = 0; i < length; ++i)
    {
        if (*(string + i) >= min_code && *(string + i) <= max_code)
            *(result + index++) = *(string + i);
    }

    *(result + index) = '\0';

    return result;
}
