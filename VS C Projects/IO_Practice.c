#include <stdio.h>
#include <stdlib.h>

#define GP_ARRAY_SIZE 10

void exercise1_7()
{
    int c;

    while((c = getchar()) != EOF){
        putchar(c);
        printf("%ld", EOF);
    }
}

void exercise1_8()
{
    int c;

    int b, t, n;

    b = t = n = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ') 
            ++b;
        if(c == '\t') 
            ++t;
        if(c == '\n') 
            ++n;
    }
    
    printf("Amount of blanks:%6d\n", b);
    printf("Amount of tabs:%6d\n", t);
    printf("Amount of newlines:%6d\n", n);
}

void exercise1_9()
{
    int c, count;

    count = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            ++count;
        }
        else
        {
            count = 0;
        }
        if(count < 2)
        {
            putchar(c);
        }
    }  
    
}

void exercise1_10()
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if(c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        else if(c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else putchar(c);
    }  
    
}


void exercise1_11()
{
    int IN = 1;
    int OUT = 0;

    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while((c = getchar()) != EOF){
        nc++;
        if(c == '\n'){
            nl++;
        }
        if(c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
        }
        else if(state == OUT){
            state = IN;
            nw++;
        }
    }
    printf("nl: %d\tnw: %d\tnc: %d\n", nl, nw, nc);
}

/*
    Q. How would you test the above barebones UNIX wc program? What inputs would be likely to produce bugs?

    A. I would feed it other escape characters, such as \r or \b and see how the logic for determining lines and words
    holds up. ***A very large input could overflow each variable eventually, also.***
*/

void exercise1_12()
{
    int IN = 1;
    int OUT = 0;

    int c, state, len;

    int *buf;

    state = len = OUT;


    while((c = getchar()) != EOF){
       
        if(c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
            printf("\n");
        }
        else if(state == OUT){
            state = IN;
        }
        if(state == IN){
            printf("%c", c);
        }
    }
    
}


void main()
{
    //exercise1_7();
    //exercise1_8();
    //exercise1_9();
    //exercise1_10();
    //exercise1_11();
    exercise1_12();


    
}