#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <stdlib.h>

double readDouble(const char* const);

int main()
{
    double a = readDouble("Enter a double value: ");

    double z1 = 2 * pow(sin(3 * M_PI - 2 * a), 2) * pow(cos(5 * M_PI + 2 * a), 2);
    double z2 = 1.0 / 4 - 1.0 / 4 * sin(5.0 / 2 * M_PI - 8 * a);

    printf("Z1 = %lf\n", z1);
    printf("Z2 = %lf\n", z2);

    return 0;
}

double readDouble(const char* const message)
{
    double number;
    long double tempNumber;
    char inputBuffer[UCHAR_MAX];
    char* pEnd;

    do
    {
        printf(message);

        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL)
        {
            tempNumber = strtod(inputBuffer, &pEnd);

            if (*(pEnd) == '\n' || *(pEnd) == '\0')
            {
                if (tempNumber >= -DBL_MAX && tempNumber <= DBL_MAX)
                {
                    number = (double)tempNumber;
                    break;
                }
            }
        }

        printf("Invalid input. Please enter a valid double value.\n");

    } while (1);

    return number;
}