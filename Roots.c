#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char function[100];
float err = 0;
int inter = 0;

int main()
{
    int choose;
    do{
        printf("\n\n\t\t ********************************************************************");
        printf("\n\t\t                      WELCOME TO THE ROOTS DISCOVERER");
        printf("\n\t\t ********************************************************************");
        printf("\n\n\t\t 1 - Bisection Method");
		printf("\n\n\t\t 2 - False Position Method");
		printf("\n\n\t\t 3 - Newton Method");
		printf("\n\n\t\t 4 - Secant Method");
        printf("\n\n\t\t 5 - Exit");
		printf("\n\n\t\t Choose an option: ");
        scanf("%d", &choose);
        while(choose < 1 || choose > 5){
			printf("\n\n\t\t Choose a right option: ");
			scanf("%d", &choose);
		}

        system("cls");

        if (choose != 5){
           stopReason();
           //enterFunction();
        }

        switch (choose)
        {
        case 1:
            bisection();
            break;
        
        case 2:

            break;

        case 3:

            break;

        case 4:

            break;
        }
    }while (choose != 5);
    return 0;
}

double f(double x){
    double fun;
    fun = exp(-x)-x;
    return fun;
}

void bisection(){
    double a, b;
    double fa, fb;

    printf("\n\n\t\t Enter with value of a: ");
    scanf("%lf", &a);
    printf("\n\n\t\t Enter with value of b: ");
    scanf("%lf", &b);

    fa = f(a);
    fb = f(b);

    
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

void stopReason(){
    int stop;

    do
    {
        printf("\n\n\t\t 1 - Error");
        printf("\n\n\t\t 2 - Interaction");
        printf("\n\n\t\t Choose reason to stop: ");
        scanf("%d", &stop);
    } while (stop != 1 && stop != 2);

    system("cls");
    
    if (stop == 1){
        error();
    }
    else if(stop == 2){
        interaction();
    }
}

void interaction(){
    printf("\n\n\t\t Enter the amount of interaction: ");
    scanf("%d", &inter);
    system("cls");
}

void error(){
    printf("\n\n\t\t Enter error to stop: ");
    scanf("%f", &err);
    system("cls");
}