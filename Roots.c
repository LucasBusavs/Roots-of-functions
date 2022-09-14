#include <stdio.h>      // Standard input-output header
#include <math.h>       // Math equations
//#include <string.h>      To manipulate Strings, only necessary if use "void enterFunction()"
#include <stdlib.h>     // Standard library
//#include <ctype.h>       Most of the functions in this library serve to sort ASCII characters,  only necessary if use "void enterFunction()"
#include <windows.h>    // Contains declarations for all Windows API functions
 
//char function[100]; Probably need to use the GSL
float err = 0;      // Global variable 
int inter = 0;      // Global variable

/*  
Probably need to use the GSL
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
*/

// Function to calculate the f(x)
double f(double x){
    double fun;
    fun = exp(-x)-x;    // (e^-x)-x
    return fun;
}

// Function to calculate the derivate of f(x)
double fdx(double x){
    double fundx;
    fundx = -exp(-x)-1;     // (-e^-x)-1
    return fundx;
}

// Function to enter with the error to stop the program
void initialError(){
    printf("\n\n\t\t Enter error to stop: ");
    scanf("%f", &err);
    if(err >= 1){
       printf("\n\n\t\t Error to stop entered too big, enter again: ");
       scanf("%f", &err);
    }
    system("cls");
}

// Function to enter with the amount of interections that the program has to execute
void interaction(){
    printf("\n\n\t\t Enter the amount of interaction: ");
    scanf("%d", &inter);
    while (inter < 1)
    {
        printf("\n\n\t\t Amount of interaction less then 1, enter again: ");
        scanf("%d", &inter);
    }
    system("cls");
}

// Function to calculate the absolute value of any real value
double absol(double x){
    if(x < 0){
        return -x;
    }
    else{
        return x;
    }
}

// Function to calculate the relative error [(xn - xn-1)/xn]
double relativeError(double xk, double xkl1){
    double calc_error;
    calc_error = absol((xk - xkl1)/xk);     // Error must always be positive
    return calc_error;
}

// Function to calculate xk for the Bisection Method
double xkBisection(double a, double b){
    double xk;
    xk = (a+b)/2;   // Average Value
    return xk;
}

//  Void Function to realize the Bisection Method
void bisection(){
    double a, b;
    double fa, fb;
    double x0[inter], f0[inter];
    double err1 = 1;
    double signal;
    int i = 0;

    printf("\n\n\t\t Enter with value of a: ");
    scanf("%lf", &a);
    printf("\n\n\t\t Enter with value of b: ");
    scanf("%lf", &b);

    fa = f(a);
    fb = f(b);
    signal = fa*fb;

    if(signal < 0){
        printf("\n\n\t\t INT \t\t A \t\t\t F(A) \t\t\t B \t\t\t F(B) \t\t\t XK \t\t\t F(XK) \t\t\t ERR");   
        while (err1 > err && inter > i){
            x0[i] = xkBisection(a, b);      // Calculate the xk and store it in a vector
            f0[i] = f(x0[i]);               // Calculate f(xk)
            if(i > 0){
                err1 = relativeError(x0[i], x0[i-1]);    // Calculate error   
            }
            else{
                err1 = 0;       // The first error
            }
            printf("\n\n\t\t %d \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf", i, a, fa, b, fb, x0[i], f0[i], err1);      // Printing results row by row
            // Keeping the theorem always valid
            if(f0[i]*fa < 0){
                b = x0[i];
                fb = f0[i];
            }
            else if(f0[i]*fb < 0){
                a = x0[i];
                fa = f0[i];
            }
            if(i == 0){
                err1 = 1;
            }
            i++;    
        }
        if (err1 > err){
            printf("\n\n\n");
            printf("\n\n\t\t Number of interactions wasn't enough");
        }
        printf("\n\n\n");
        printf("\n\t\t Result: %lf", x0[i-1]);
        printf("\n\t\t Interactions: %d", i);
        printf("\n\t\t Error: %lf", err1);
        printf("\n\n\n");
        printf("\t\t Press any key to continue ");
        getchar();      //Capture \n 
        getchar();
    }
    else{
        printf("\n\n\t\t Interval does not respect the Intermediate Value Theorem");    // The base of bissection method
        Sleep(3500);
    }
}

// Function to calculate xk for the False Position Method
double xkFalsePosition(double a, double b){
    double xk;
    double num, den;
    num = a*f(b) - b*f(a);
    den = f(b) - f(a);
    xk = num/den;   
    return xk;
}

//  Void Function to realize the False Position Method using the same logic of Bisection Method, just changing how to calculate x0
void falsePosition(){
    double a, b;
    double fa, fb;
    double x0[inter], f0[inter];
    double err1 = 1;
    double signal;
    int i = 0;

    printf("\n\n\t\t Enter with value of a: ");
    scanf("%lf", &a);
    printf("\n\n\t\t Enter with value of b: ");
    scanf("%lf", &b);

    fa = f(a);
    fb = f(b);
    signal = fa*fb;

    if(signal < 0){
        printf("\n\n\t\t INT \t\t A \t\t\t F(A) \t\t\t B \t\t\t F(B) \t\t\t XK \t\t\t F(XK) \t\t\t ERR");
        while (err1 > err && inter > i){
            x0[i] = xkFalsePosition(a, b); 
            f0[i] = f(x0[i]);
            if(i > 0){
                err1 = relativeError(x0[i], x0[i-1]);
            }
            else{
                err1 = 0;
            }
            printf("\n\n\t\t %d \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf", i, a, fa, b, fb, x0[i], f0[i], err1);
            if(f0[i]*fa < 0){
                b = x0[i];
                fb = f0[i];
            }
            else if(f0[i]*fb < 0){
                a = x0[i];
                fa = f0[i];
            }
            if(i == 0){
                err1 = 1;
            }
            i++;    
        }
        if (err1 > err){
            printf("\n\n\n");
            printf("\n\n\t\t Number of interactions wasn't enough");
        }
        printf("\n\n\n");
        printf("\n\t\t Result: %lf", x0[i-1]);
        printf("\n\t\t Interactions: %d", i);
        printf("\n\t\t Error: %lf", err1);
        printf("\n\n\n");
        printf("\t\t Press any key to continue ");
        getchar();
        getchar();
    }
    else{
        printf("\n\n\t\t Interval does not respect the Intermediate Value Theorem");
        Sleep(3500);
    }
}

// Function to calculate xk for the Newton Method
double xkNewton(double x){
    double xk;
    xk = x - (f(x)/fdx(x));
    return xk;
}

// Void Function to realize the Newton Method
void newton(){
    double x0;
    double xk[inter], fk[inter], fdk[inter];
    double err1 = 1;
    double fx0, fdx0;
    int i = 0;

    printf("\n\n\t\t Enter with value of X0: ");
    scanf("%lf", &x0);      // Can be changed by a the first position on xk vector

    fx0 = f(x0);    
    fdx0 = fdx(x0);

    printf("\n\n\t\t INT \t\t X \t\t\t F(X) \t\t\t F'(X) \t\t\t XK \t\t\t F(XK) \t\t\t F'(XK) \t\t\t ERR");
    while (err1 > err && inter > i){
        if(i == 0){
            xk[i] = xkNewton(x0);
            fk[i] = f(xk[i]);
            fdk[i] = fdx(xk[i]);
            err1 = 0;
            printf("\n\n\t\t %d \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf", i, x0, fx0, fdx0, xk[i], fk[i], fdk[i], err1);
            err1 = 1;
        }
        else{
           xk[i] = xkNewton(xk[i-1]);
           fk[i] = f(xk[i]);
           fdk[i] = fdx(xk[i]);
           err1 = relativeError(xk[i], xk[i-1]);
           printf("\n\n\t\t %d \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf", i, xk[i-1], fk[i-1], fdk[i-1], xk[i], fk[i], fdk[i], err1);
        }
        i++;
    }
    if (err1 > err){
        printf("\n\n\n");
        printf("\n\n\t\t Number of interactions wasn't enough or will diverge");    // This Method doesn't ensure the convergence
    }
    printf("\n\n\n");
    printf("\n\t\t Result: %lf", xk[i-1]);
    printf("\n\t\t Interactions: %d", i);
    printf("\n\t\t Error: %lf", err1);
    printf("\n\n\n");
    printf("\t\t Press any key to continue ");
    getchar();
    getchar();
}

// Function to calculate xk for the Secant Method
double xkSecant(double xkl1, double xk){
    double xkm1;
    double num, den;
    num = xkl1*f(xk) - xk*f(xkl1);
    den = f(xk) - f(xkl1);
    xkm1 = num/den; 
    return xkm1;
}

//  Void Function to realize the Secant Method using the same logic of False Position Method, just changing the entries
void secant(){
    double xk[inter], fk[inter];
    double err1 = 1;
    int i = 0;

    printf("\n\n\t\t Enter with value of XO: ");
    scanf("%lf", &xk[0]);
    printf("\n\n\t\t Enter with value of X1 : ");
    scanf("%lf", &xk[1]);

    fk[0] = f(xk[0]);
    fk[1] = f(xk[1]);

    printf("\n\n\t\t INT \t\t A \t\t\t F(A) \t\t\t B \t\t\t F(B) \t\t\t XK \t\t\t F(XK) \t\t\t ERR");
    while (err1 > err && inter > i){
        xk[i+2] = xkSecant(xk[i], xk[i+1]);
        fk[i+2] = f(xk[i+2]);
        if(i > 0){
            err1 = relativeError(xk[i+2], xk[i+1]);
        }
        else{
            err1 = 0;
        }
        printf("\n\n\t\t %d \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf \t\t %lf", i, xk[i], fk[i], xk[i+1], fk[i+1], xk[i+2], fk[i+2], err1);
        if(i == 0){
            err1 = 1;
        }
        i++;    
    }
    if (err1 > err){
        printf("\n\n\n");
        printf("\n\n\t\t Number of interactions wasn't enough or will diverge");    // This Method doesn't ensure the convergence
    }
    printf("\n\n\n");
    printf("\n\t\t Result: %lf", xk[i+1]);
    printf("\n\t\t Interactions: %d", i);
    printf("\n\t\t Error: %lf", err1);
    printf("\n\n\n");
    printf("\t\t Press any key to continue ");
    getchar();
    getchar();
}

// Initializing the program
int main(){
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
           interaction();
           initialError();
           system("cls");
           //enterFunction();
        }

        switch (choose)
        {
        case 1:
            bisection();
            system("cls");
            break;
        
        case 2:
            falsePosition();
            system("cls");
            break;

        case 3:
            newton();
            system("cls");
            break;

        case 4:
            secant();
            system("cls");
            break;
        }
    }while (choose != 5);
    printf("\n\n\t\t\t\t\t\t\t That's it \2"); //🙂
    Sleep(500);
    return 0;
}