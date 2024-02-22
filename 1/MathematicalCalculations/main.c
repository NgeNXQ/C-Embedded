#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <stdlib.h>

double read_double(const char* const);

int main()
{
    double a = read_double("Enter a double value: ");

    double z1 = 2 * pow(sin(3 * M_PI - 2 * a), 2) * pow(cos(5 * M_PI + 2 * a), 2);
    double z2 = 1.0 / 4 - 1.0 / 4 * sin(5.0 / 2 * M_PI - 8 * a);

    printf("Z1 = %lf\n", z1);
    printf("Z2 = %lf\n", z2);

    return 0;
}

double read_double(const char* const message)
{
    double number;
    long double temp_number;
    char input_buffer[UCHAR_MAX];
    char* p_end;

    do
    {
        printf(message);

        if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL)
        {
            temp_number = strtod(input_buffer, &p_end);

            if (*(p_end) == '\n' || *(p_end) == '\0')
            {
                if (temp_number >= -DBL_MAX && temp_number <= DBL_MAX)
                {
                    number = (double)temp_number;
                    break;
                }
            }
        }

        printf("Invalid input. Please enter a valid double value.\n");

    } while (1);

    return number;
}
