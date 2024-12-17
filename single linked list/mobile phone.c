#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
struct message
{
    char message[100];
};
struct node
{
    struct node* prev;
    struct message data;
    struct node* next;
};


int main()
{
    struct node* head = NULL;
    struct node* cur = NULL;
   struct message m;
 struct message n;
    int x;

    while(1)
    {
        printf("1.enter 'a' to add new message\n" );
        printf("2.enter 'f' to display all messages\n" );
        printf("1.enter 's' to search a message by senders name\n" );
        printf("4.enter 'd' to delete message\n" );
        if(kbhit())
        {
            char ch = getch();
            switch(ch)
            {
              case 72 :
              case 75 :
                       movetoPrevmessage(&cur);
                       break;

               case 77 :
               case 80 :
                       movetoNextmessage(&cur);
                       break;
               case 'a' :
                       printf("enter message :\n");
                       scanf("%s",m);
                       addnewMessage(&head,&cur,m);
                       break;
               case 'f' :
                       displayAllmessage(&head);
                       break;
               case 's' :
                        printf("enter name :\n");
                        scanf("%s",n);
                        searchMessage(&head,n);
                        if(x==1)
                           printf("message found\n");
                        else
                            printf("message not found\n");
                         break;
            }
        }
    }
}

void movetoPrevmessage(struct node**cur)
{
    while(*cur&& (*cur)->next)
    {
        *cur=(*cur)->next;
        printf("%s\n",(*cur)->data);
        return;
    }

}
void movetoNextmessage(struct node**cur)
{
    while(*cur && (*cur)->next)
    {
        *cur=(*cur)->prev;
        printf("%s\n",(*cur)->data);
        return;
    }

}

void addnewMessage(struct node** head,struct node** cur,struct message m)
{
    struct node* p= (struct node*)malloc(sizeof(struct node));
      if(p==NULL)
      {
          perror("");
          return;
      }
      strcpy(p->data,m.message);
      p->next=NULL;
      p->prev=NULL;
      if(*head==NULL)
      {
          *head=p;
          *cur=p;
          return;
      }
      p->next=(*cur)->next;
      p->prev=*cur;
      if((*cur)->next!= NULL)
        (*cur)->next->prev=p;
        (*cur)->next=p;
        *cur=p;
}

void displayAllmessage(struct node** head)
{
    struct node* cur = *head;
    while(cur)
    {
        printf("%s\n",cur->data);
        cur=cur->next;
    }

}

 int searchMessage(struct node** head,struct message n)
 {
     int y;
      struct node* cur = *head;
    while(cur)
    {
        y=strcasecmp(cur->data,n.message);
        if(y==0)
            return 1;
        cur=cur->next;
    }
    return 0;

 }
