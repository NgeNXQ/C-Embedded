#define _USE_MATH_DEFINES

#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdio.h>
#include <math.h>

double readDouble(const char*);

int main()
{
    double a = readDouble("Enter a double value: ");

    double z1 = 2 * pow(sin(3 * M_PI - 2 * a), 2) * pow(cos(5 * M_PI + 2 * a), 2);
    double z2 = 1.0 / 4 - 1.0 / 4 * sin(5.0 / 2 * M_PI - 8 * a);

    printf("Z1 = %lf\n", z1);
    printf("Z2 = %lf\n", z2);

    return 0;
}

double readDouble(const char* message)
{
    double number;
    long double tempNumber;
    char inputBuffer[255];

    do
    {
        printf(message);

        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL)
        {
            if (sscanf_s(inputBuffer, "%lf", &tempNumber) == 1)
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
