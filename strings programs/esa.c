#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>
int isPrime(int);

int main()
{
    int score,p,X,i;
    printf("No. of participants:\n");
    scanf("%d",&X);
   for(i=1;i<=X;i++)
   {
    printf("enter the score: ");
    scanf("%d",&score);
    if(score > INT_MAX)
      {
        printf("Invalid score\n");
        continue;
      }
    p=isPrime(score);
    if (p==1)
        printf("Winner\n");
    else if(p==0)
        printf("Looser\n");
    else
        printf("Invalid score\n");
   }
    return 0;
}

int isPrime(int N)
{
    int i;
      if(N<=1)
      {
       return -1;
      }

    for(i=2;i<=sqrt(N);i++)
    {

        if(N%i==0)
        return 0;
    }
        return 1;
}
