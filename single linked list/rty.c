#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void addatend(struct node** head,int e);
void deleteBeg(struct node **head);
void display(struct node* head);
int main()
{
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    int e,m,n,i,x,y;
    scanf("%d",&m);
    if(m<=0 || m>100)
        exit(0);
     scanf("%d",&n);
     if(n<=0 || n>100)
        exit(0);
    for(i=0;i<m;i++)
    {
              scanf("%d",&e);
             addatend(&head1,e);
    }
    for(i=0;i<n;i++)
    {
              scanf("%d",&e);
             addatend(&head2,e);
    }
      scanf("%d",&x);
    if(x<=0 || x>100)
        exit(0);
      scanf("%d",&y);
    if(y<=0 || y>100)
        exit(0);
      for(i=0;i<x;i++)
    {
             deleteBeg(&head1);
    }
      for(i=0;i<y;i++)
    {
             deleteBeg(&head2);
    }
    if(head1 == NULL)
        printf("Gate 1 empty.\n");
    else
    {
          display(head1);
        printf("\n");
    }

    if(head2 == NULL)
        printf("Gate 2 empty.\n");
      else
    {
          display(head2);
        printf("\n");
    }
    return 0;
}
void addatend(struct node** head,int e)
{
    struct node* cur = *head;
    struct node*p = (struct node*)malloc(sizeof(struct node));
    p->data=e;
    p->next=NULL;
    if(*head==NULL)
        *head=p;
    else
    {
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=p;
    }
}
void deleteBeg(struct node **head)
{
    struct node* cur=*head;
    *head=(*head)->next;
    free(cur);
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
