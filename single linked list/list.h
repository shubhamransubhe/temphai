#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    void* data;
    struct node* next;
};

void addatBeg (struct node ** head,void* e,int data_size)
{
    struct node * p;
    int i;
    p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL)
    {
        perror("");
        return;
    }
    p->data=malloc(data_size);
    p->next =*head;
    *head=p;
    char*m=(char*)e;
    char*n=(char*)(p->data);
    for(i=0;i<data_size;i++)
    {
        *n=*m;
        m++;
        n++;
    }

}

void displayList(struct node*head,void(*q)(void*))
{
    struct node * cur=head;
    while(cur)
    {
        (*q)(cur->data);
        cur=cur->next;
    }
}


