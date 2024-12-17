#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define ROW 100
#define COL 100

int main()
{
    int n;
   int a[ROW][COL]={10};
   int b[ROW][COL]={10};
   int c[ROW][COL]={10};
    printf("enter n \n");
   scanf("%d",&n);

    char from = 'A';
    char aux = 'B';
    char to = 'C';


    clock_t st,et;
    st = clock();
      readArray(a,n);
       readArray(b,n);
       multiplymatrix(a,b,c,n);
    et = clock();
    double time_taken = ((double)et - st)/CLOCKS_PER_SEC;
    printf("fun() took %f seconds to execute\n",time_taken);
    return 0;

}


      void readArray(int a[ROW][COL],int n)
      {
          int i,j;
          for(i=0;i<n;i++)
       {
           for(j=0;j<n;j++)
            a[i][j]=rand()%10000;

       }
      }
void addmatrix(int a[ROW][COL],int b[ROW][COL],int c[ROW][COL],int n)
{
        int i,j;
          for(i=0;i<n;i++)
       {
           for(j=0;j<n;j++)
            c[i][j] = a[i][j] + b[i][j];

       }
}

void multiplymatrix(int a[ROW][COL],int b[ROW][COL],int res[ROW][COL],int n)
{
     int i,j,k;
      for(i=0;i<n;i++)
        { for(k=0;k<n;k++)
         {
             res[i][j]=res[i][j]+a[i][k]*b[k][j];
         }

       }
}
