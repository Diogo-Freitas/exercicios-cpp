#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int main(void)
{
    int a,b,*p,*c;
    a=10;
    p=&a;
    c=&b;
    *c=7;
    *p=3;
    printf("%d\t%d\n",a,b);
    p=c;
    *p=5;
    a++;
    (*c)++;
    printf("%d\t%d\n",a,b);
    getch();
    return 0;
}
