#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct stack
{
    struct node *top;
};
void initStack(struct stack* s);
void push(struct stack* s,int e);
int isEmpty(struct stack *s);
int pop(struct stack* s);
int peek(struct stack* s);
void winnerStatus(struct stack* s,int M);


int main()
{
    struct stack s;
    initStack(&s);
    int N,M,i,e;
    scanf("%d",&N);
    if(N<0)
    {
        printf("Invalid number of customers\n");
        exit(0);
    }
    scanf("%d",&M);
    if(M<0)
    {
        exit(0);
    }
    for(i=0;i<N;i++)
    {
        scanf("%d",&e);
        push(&s,e);
    }
    winnerStatus(&s,M);
    return 0;
}

void initStack(struct stack* s)
{
    s->top = NULL;
}
void push(struct stack* s,int e)
{
    struct node* p=(struct node* )malloc(sizeof(struct node));
    if(p==NULL)
    {
        perror("memory full\n");
        return;
    }
    p->data=e;
    p->next=s->top;
    s->top=p;
}
int isEmpty(struct stack *s)
{
    if(s->top==NULL)
        return 1;
    else
        return 0;
}
int pop(struct stack* s)
{
    struct node* cur=s->top;
    int e=cur->data;
    s->top=(s->top)->next;
    free(cur);
    return e;
}
int peek(struct stack* s)
{
    int c=(s->top)->data;
    return c;
}
void winnerStatus(struct stack* s,int M)
{
    int x=0;
    int y=0;

     while(!isEmpty(s))
    {
        if(peek(s)% M == 0)
        {
            pop(s);
            printf("%c ",'W');
            x++;
        }
        else
        {
           pop(s);
            printf("%c ",'L');
            y++;
        }

    }
    printf("\n");
    printf("No of winners=%d\n",x);
     printf("No of losers=%d\n",y);

}
