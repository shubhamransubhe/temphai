#include<stdio.h>
int isValidate(char []);
int main()
{
    char card[16];
    int v;
    printf("enter debit card no.: ");
    scanf("%s",card);
    v = isValidate(card);
    if(v==1)
    printf("Debit Card no. is valid\n");
    else
    printf("Debit Card no. is invalid\n");
    return 0;
}

int isValidate(char card[])
{
    int i,y;
    int sum=0;
    for(i=0 ; i<16 ; i=i+2)
    {
        y = card[i]-48;
        y = y*2;
        if(y>9)
          y = y-9;
        sum = sum+y;
    }
    for(i=1 ; i<16 ; i=i+2)
    {
        y = card[i]-48;
        sum = sum+y;
    }

    if(sum%10==0)
        return 1;
    else
        return 0;
}
