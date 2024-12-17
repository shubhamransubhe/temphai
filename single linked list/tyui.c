#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int data;
    struct node* next;
};
int main()
{
    struct node* head=NULL;
    int i,n,e,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&e);
        addatBeg(&head,e);
    }
    m=deleteMax(&head);
    printf("Allowed for worship: %d\n",m);
    if(head==NULL)
        printf("No devotees to worship.");
    else
    {
        printf("Remaining devotees: ");
         display(head);
    }
}

void addatBeg( struct node** head,int e)
{
    struct node* p=( struct node*)malloc(sizeof( struct node));
    p->data=e;
    p->next=NULL;
    if(*head == NULL)
    {
        *head=p;
    }
    else
    {
        p->next=*head;
        *head=p;
    }
}
int deleteMax(struct node** head)
{
    struct node* cur=*head;
    struct node* max=NULL;
    struct node* prev=*head;
    int m = INT_MIN;
    while(cur)
    {
        if(cur->data>m)
        {
         m=cur->data;
         max=cur;
        }
        cur=cur->next;
    }
     if(*head==max)
     {
         *head=(*head)->next;
         free(max);
         return m;
     }
     while(prev->next!=max)
     {
         prev=prev->next;
     }
     prev->next=max->next;
     free(max);
     return m;
}

void display(struct node* head)
{
    struct node* cur = head;
    while(cur)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }

}
