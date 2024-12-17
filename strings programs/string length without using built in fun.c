#include<stdio.h>
int main()
{
    char str[100];
    int c;
    printf("enter the string:");
    scanf("%s",str);
    c = stringLength(str);
    printf("string length:\n");
    printf("%d\n",c);
    return 0;
}

int stringLength(char str[])
{
    int i;
    for(i=0;str[i];i++)
    {
        ;
    }
    return i;
}

