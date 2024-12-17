#include<stdio.h>
int main()
{
    int a[100];
    int n,s,key,ch;
    scanf("%d",&n);
    printf("1. read array\n");
    printf("2. display array\n");
    printf("3. search key\n");
    printf("4. bubble sort\n");
   while(1)
   {


    scanf("%d",&ch);

    switch(ch)
    {
    case 1: readArray(a,n);
             break;
    case 2: displayArray(a,n);
            break;
    case 3: printf("\nEnter key: ");
    scanf("%d",&key);
   s= searchkey(a,n,key);

   if(s==1)
    printf("key found\n");
   else
    printf("key not found\n");
            break;
    case 4: bubblesort(a,n);

    }



}
}
void readArray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

}
void displayArray(int a[],int n)
{

     int i;
    for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}
int searchkey(int a[],int n, int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
            return 1;

    }
    return 0;
}
void bubblesort(int a[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
