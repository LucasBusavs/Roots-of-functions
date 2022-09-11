#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char function[100];

int main()
{
    int choose;
    do{
        printf("\n\n\t\t ********************************************************************");
        printf("\n\t\t                      WELCOME TO THE ROOTS DISCOVERER");
        printf("\n\t\t ********************************************************************");
        printf("\n\n\t\t 1 - Bisection Method\n");
		printf("\n\n\t\t 2 - False Position Method\n");
		printf("\n\n\t\t 3 - Newton Method\n");
		printf("\n\n\t\t 4 - Secant Method\n");
        printf("\n\n\t\t 5 - Exit\n");
		printf("\n\n\t\t Choose an option: ");
        scanf("%d", &choose);
        while(choose < 1 || choose > 5){
			printf("\n\n\t\t Choose a right option: ");
			scanf("%d", &choose);
		}



    }while (choose != 5);
  
    
    return 0;
}

void enterFunction(){

    int i;
    char correct;

    printf("\n\n\t\t Insert your function of x: ");
    scanf("%s", &function);
    getchar();

    for ( i = 0; i < strlen(function); i++){
        function[i] = tolower(function[i]);
    }

    do{
        printf("\n\n\t\t This is your f(x) = %s, is it correct? y/n ", &function);
        scanf("%c", &correct);
        correct = tolower(correct);
        getchar();
        if(correct != 'y'){
            printf("\n\n\t\t Insert your function of x again: ");
            scanf("%s", &function);
            getchar();
            for ( i = 0; i < strlen(function); i++){
                function[i] = tolower(function[i]);
             }
        }
    }while (correct != 'y');
}