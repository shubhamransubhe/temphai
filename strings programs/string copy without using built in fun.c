#include<stdio.h>
int main()
{
    char src[100];
    char dest[100];
    printf("enter the string: ");
    scanf("%s",src);
    stringCopy(src,dest);
    printf("Dest = %s\n",dest);
    return 0;
}

int stringCopy(char src[],char dest[])
{
    int i;
    for(i=0;src[i];i++)
    {
        dest[i]=src[i];
    }

}


