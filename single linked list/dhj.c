#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int a[100][100];
    int n;
    int x;
    printf("enter no of students\n");
    scanf("%d",&n);
    printf("enter no of evaluations\n");
    scanf("%d",&x);
    readArray(a,n,x);
    displayArray(a,n,x);
    avgArray(a,n,x);
    avgEvaluation(a,n,x);

}

void displayArray(int a[100][100],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d   ",a[i][j]);
            printf("\n");
    }

}

void readArray(int a[100][100],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    }

}

void avgArray(int a[100][100],int r,int c)
{
    int sum=0;
    int i,j;
    double avg;
    for(i=0;i<r;i++)
    {
        sum=0;
        for(j=0;j<c;j++)
        {
           sum=sum+a[i][j];

        }
        avg=(double)sum/c;
       printf(" avg of marks of student %d =%lf\n ",i+1,avg );
    }
}
void avgEvaluation(int a[100][100],int r,int c)
{
     int sum=0;
    int i,j;
    double avg;
    for(j=0;j<c;j++)
    {
        sum=0;
        for(i=0;i<r;i++)
        {
           sum=sum+a[i][j];

        }
        avg=(double)sum/r;
       printf(" avg of evaluation %d : %lf\n ",j+1,avg );
    }


}
