#include <stdio.h>
#include <math.h>
#include <assert.h>

double x1 = NAN;
double x2 = NAN;

double a = NAN;
double b = NAN;
double c = NAN;

const int NO_ROOTS = -1;

void ScanCoefficients(void);

int SolveSquare();

void PrintResult(void);


int main()
{

    ScanCoefficients();
    SolveSquare(); 
    PrintResult();


    return 0;
}

void ScanCoefficients()
{
    printf("Enter coefficients\n");
    scanf("%lf %lf %lf", &a, &b, &c);
}

int SolveSquare()
{
    double discr = 0;

    discr = (b * b) - 4 * a * c;

    if (a != 0)
    {
        if (discr > 0)
        {
            x1 = (-b + sqrt(discr)) / (2 * a);
            x2 = (-b - sqrt(discr)) / (2 * a);                   
            return 2;
        }
        else if (discr < 0)
        {
            return NO_ROOTS;
        }
        else if (discr == 0)
        {   
            x1 = -b / (2 * a);
            return 1;
        }
    }
    else
    {
        if (b != 0)
        {                                       
            x1 = -c / b;
            return 0;
        }
        else
        {
            return NO_ROOTS;
        }
    }    
}

void PrintResult()
{

    switch(SolveSquare())
    {
        case 2:
            printf("Your solutions: %lf %lf\n", x1, x2);
            break;

        case 1:
            printf("Your solution: %lf\n", x1);
            break;

        case 0: 
            printf("You have linear equation\n");
            printf("Your solution: %lf\n", x1);
            break;

        case -1:
            printf("No solutions\n");
            break;

        default:
            break;       
    }
}


