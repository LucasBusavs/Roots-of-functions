#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char const *argv[])
{
    int choose;
    char function[100];

    printf("\n\n\t\t ********************************************************************");
    printf("\n\t\t                      WELCOME TO THE ROOTS DISCOVERER");
    printf("\n\t\t ********************************************************************");

    printf("\n\n\t\t Insert your function of x: ");
    scanf("%s", &function);

    printf("\n\n\t\t %s", &function);


    printf("\n\n\t\t %d", strlen(function));
   



    return 0;
}