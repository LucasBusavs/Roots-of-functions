#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    int choose;
    char function[100];
    int i;

    printf("\n\n\t\t ********************************************************************");
    printf("\n\t\t                      WELCOME TO THE ROOTS DISCOVERER");
    printf("\n\t\t ********************************************************************");

    printf("\n\n\t\t Insert your function of x: ");
    scanf("%s", &function);

    printf("\n\n\t\t %s", &function);

    for ( i = 0; i < strlen(function); i++){
        function[i] = tolower(function[i]);
    }

    printf("\n\n\t\t %s", &function);

    return 0;
}