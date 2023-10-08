#include <stdlib.h>
#include <float.h>
#include <stdio.h>
#include <math.h>

//double readDouble(const char*, double, double);

int main()
{
    // check for overflow



    //double a = readDouble("Enter a double value: ");

    //double z1 = cos(a) + sin(a) + cos(3 * a) + sin(3 * a);
    //double z2 = 2 * sqrt(2) * cos(a) * sin(M_PI / 4.0 + 2 * a);

    //printf("Z1 = %lf\n", z1);
    //printf("Z2 = %lf\n", z2);

    return 0;
}

double readDouble(const char* message)
{
    double value;
    char inputBuffer[255];

    while (1) 
    {
        printf(message);

        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL)
        {
            printf("Enter a valid input.\n");
            continue;
        }

        if (sscanf_s(inputBuffer, "%f", &value) == 1)
            return value;
        else 
            printf("Invalid input. Please enter a valid double value.\n");
    }

    return value;
}
