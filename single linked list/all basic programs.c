#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
    int data;
    struct node * next;
};

int main()
{
     int ch,e,pos,L,key,s;
    struct node* head=NULL;
    while(1)
    {

        printf("1.display list\n");
        printf("2.Add at Beginning\n");
        printf("3.delete at Beginning\n");
        printf("4.add data at end of list\n");
        printf("5.delete data at end of list\n");
        printf("6.add at any position\n");
        printf("7. delete at any position\n");
        printf("8.length of list\n");
        printf("9. search given key\n");
        printf("10. reverse the list\n");
        printf("11. delete all nodes that have greater value on LHS\n");
         printf("12. delete all nodes that have greater value on RHS\n");

        printf("enter choice : ");
        scanf("%d",&ch);


        switch(ch)
        {   case 1 : display(head);
                    break;
            case 2 : printf("enter data : ");
                    scanf("%d",&e);
                    addAtBeg(&head,e);
                    break;

            case 3 : if (head==NULL)
                     printf("list empty\n");
                     else
                     {
                         e= deleteBeg(&head);
                         printf("deleted data : %d\n",e);
                     }
                     break;
            case 4 : printf("enter data : ");
                    scanf("%d",&e);
                    addAtEnd(&head,e);
                    break;

            case 5 :  if (head==NULL)
                     printf("list empty\n");
                     else
                     {
                         e= deleteEnd(&head);
                         printf("deleted data : %d\n",e);
                     }
                     break;
             case 6 :
                    printf("enter position : ");
                    scanf("%d",&pos);
                    printf("enter data : ");
                    scanf("%d",&e);
                    addAtPos(&head,e,pos);
                    break;
             case 7 :   if (head==NULL)
                     printf("list empty\n");
                     else
                     {
                    printf("enter position : ");
                    scanf("%d",&pos);
                    e=deleteAtPos(&head,pos);
                    printf("deleted data : %d\n",e);
                     }
                     break;
             case 8 : L=length(head);
                      printf("length of list : %d\n",L);
                      break;
             case 9 : printf("enter key : ");
                      scanf("%d",&key);
                      s=searchKey(head,key);
                      if(s==1)
                        printf("key found\n");
                      else
                        printf("key not found\n");
                         break;
             case 10 : reverse(&head);
                         break;
             case 11 : deleteLHS(head);
                         break;

              case 12 : deleteRHS(&head);
                         break;


        }

    }
}

void addAtBeg(struct node **head,int e)
{
    struct node * p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=e;
    p->next=*head;
    *head=p;

}

void display(struct node *head)
{
    while(head!=NULL)
    {
        printf("%d\n",head->data);
        head=head->next;

    }
}

int deleteBeg(struct node **head)
{   int e;
    struct node* cur=*head;
    *head=(*head)->next;
    e=cur->data;
    free(cur);
}
void addAtEnd(struct node **head,int e)
{   struct node *cur=*head;
    struct node*p=(struct node *)malloc(sizeof(struct node));
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

int deleteEnd(struct node **head)
{
    int e;
    struct node * cur=*head;
    struct node * prev= NULL;
    if((*head)->next==NULL)
    {
         e=cur->data;
        *head=NULL;
        free(cur);
        return e;
    }
      while(cur->next!=NULL)
      {
          prev=cur;
          cur=cur->next;
      }
      e=cur->data;
      prev->next=NULL;
      free(cur);
      return e;

}
void addAtPos(struct node **head,int e,int pos)
{
    int i;
    struct node * cur=*head;
    struct node * prev= NULL;
     struct node*p=(struct node *)malloc(sizeof(struct node));
     if(p==NULL)
     {
         perror("memory full error:");
         return;
     }
     p->data=e;
     p->next=NULL;
     if(pos<=0 || *head==NULL)
     {
         p->next=*head;
         *head=p;
         return;
     }
      for(i=0;i<pos&&cur!=NULL;i++)
      {
          prev=cur;
          cur=cur->next;
      }
      p->next = cur;
      prev->next= p;

}

int deleteAtPos(struct node **head,int pos)
{
    int e,i;
    struct node * cur=*head;
    struct node * prev= NULL;
    if (pos<=0 || (*head)->next==NULL)
    {
        e=cur->data;
        *head=(*head)->next;
        free(cur);
        return e;
    }

      for(i=0;i<pos && cur->next!=NULL;i++)
      {
          prev=cur;
          cur=cur->next;
      }
      e=cur->data;
      prev->next=cur->next;
      free(cur);
      return e ;
}

int length(struct node * head)
{
    int C=0;
    while(head!=NULL)
    {
        C++;
        head=head->next;
    }

    return C;
}
int searchKey(struct node * head,int key)
{
    while(head!=NULL)
    {
        if(head->data==key)
            return 1;//for frequency of key just do count++
            head=head->next;
    }

    return 0;
}
void reverse(struct node **head)
{
    struct node *p=*head;
    struct node *q=NULL;
    struct node *r;
     if(p!=NULL)
    q=p->next;
     if(q!=NULL)
    r=q->next;
    while(q!=NULL)
    {
        q->next = p;
        p=q;
        q=r;
        if(r!=NULL)
        r=r->next;
    }
    if(*head!=NULL)
    (*head)->next = NULL;
    *head=p;
}
void deleteLHS(struct node *head)
{
    struct node* cur=head;
    struct node* prev=NULL;
    int max=INT_MIN;
    while(cur!=NULL)
    {
        if(cur->data>max)
        {
            max=cur->data;
            prev=cur;
            cur=cur->next;
        }
        else
        {
            prev->next=cur->next;
            free(cur);
            cur=prev->next;

        }
    }
}

void deleteRHS(struct node **head)
{
    reverse(head);
    deleteLHS(*head);
    reverse(head);
}
