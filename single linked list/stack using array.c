#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 100
struct stack
{
    int elements[SIZE];
    int top;
};

int main()
{
        struct stack s;
        int ch;
        initStack(&s);
        int e;
        while(1)
        {
            scanf("%d",&ch);
            switch(ch)
            {
                case 1 :
                    scanf("%d",&e);
                         push(&s,e);
                    break;
                case 2 :
                    if(isEmpty(&s))
                    {
                        printf("stack underflow\n");
                    }
                    else
                    {
                        e=pop(&s);
                        printf("%d\n",e);
                    }
                    break;
                case 3 :
                     e=peek(&s);
                        printf("%d\n",e);
                    break;

                case -1 : exit(0);
            }
        }


    return 0;
}
int isEmpty(struct stack*s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
void initStack(struct stack *s)
{
    s->top=-1;
}
void push(struct stack *s,int e)
{
    s->top++;
    s->elements[s->top]=e;
}
int pop(struct stack *s)
{
    int e = s->elements[s->top];
    s->top--;
    return e;
}
int peek(struct stack *s)
{
    int e=s->elements[s->top];
    return e;
}
