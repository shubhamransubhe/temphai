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
void compare(struct stack* s1,struct stack* s2);
int isEmpty(struct stack *s);
int pop(struct stack* s);
int peek(struct stack* s);
int main()
{
    struct stack s1;
    struct stack s2;
    int e,i,N;
    initStack(&s1);
      initStack(&s2);
    scanf("%d",&N);
    if(N<1 || N>100)
    {
        printf("Invalid input.\n");
        exit(0);
    }
    for(i=0;i<N;i++)
    {
        scanf("%d",&e);
        push(&s1,e);
    }
    for(i=0;i<N;i++)
    {
        scanf("%d",&e);
        push(&s2,e);
    }
     compare(&s1,&s2);

    return 0;
}
void initStack(struct stack* s)
{
    s->top = NULL;
}
void push(struct stack* s,int e)
{
    struct node* p=(struct node* )malloc(sizeof(struct node));
    p->data=e;
    p->next=s->top;
    s->top=p;
}
void compare(struct stack* s1,struct stack* s2)
{
    int x=0;
    int y=0;
    while((!isEmpty(s1)) && (!isEmpty(s2)) )
    {
        if(peek(s1)*peek(s2)>0)
        {
            pop(s1);
            pop(s2);
            printf("%d ",0);
            x++;
        }
        else if(peek(s1)*peek(s2)<0)
        {
             pop(s1);
            pop(s2);
            printf("%d ",1);
            y++;

        }
        else
        {
            if(peek(s1)==0)
                pop(s1);
            else
                pop(s2);
        }
    }
    printf("\n%d\n",y);
    printf("%d\n",x);

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
    int e=(s->top)->data;
    return e;
}
