#include<stdio.h>
int main()
{
    char str[100];
    int c;
    printf("enter the string:");
    gets(str);
    c = countVowel(str);
    printf("no. of vowels:\n");
    printf("%d\n",c);
    return 0;
}

int countVowel(char str[])
{
    int i,count=0;
    for(i=0;str[i];i++)
    {
        if (str[i]=='A' || str[i]=='a')
            count++;
        else if (str[i]=='E' || str[i]=='e')
            count++;
        else if (str[i]=='I' || str[i]=='i')
            count++;
        else if (str[i]=='O' || str[i]=='o')
            count++;
        else if (str[i]=='U' || str[i]=='u')
            count++;
    }
    return count;
}
