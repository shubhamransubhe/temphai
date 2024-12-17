#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct process
{
    int ID;
    int time;
};

struct node
{
    struct process data;
    struct node* next;
};

struct queue
{
    struct node* front;
    struct node* rear;
} ;

void initQueue(struct queue* );
void EnQueue(struct queue* ,struct process );
void process(struct queue* , int , int ,int );
struct process DeQueue(struct queue* );
 void DisplayQ(struct queue* );


int main()
{
   struct queue q;
    initQueue(&q);
    struct process s;
    int N,K,Q;
    scanf("%d",&N);
    if(N<=0)
        exit(0);
    for(int i=0;i<N;i++)
    {
         scanf("%d",&s.ID);
         scanf("%d",&s.time);
        EnQueue(&q,s);
    }
    scanf("%d",&Q);
    if(Q<=0)
        exit(0);
    scanf("%d",&K);
    if(K<=0)
        exit(0);
    process( &q , Q , K ,N);
     return 0;
}
void initQueue(struct queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}

void EnQueue(struct queue* q,struct process s)
{
    struct node* p=( struct node*)malloc(sizeof( struct node));
      if(p==NULL)
      {
          perror("");
          return;
      }
    p->data = s;
    p->next = NULL;
    if(q->front==NULL || q->rear==NULL)
    {
        q->front=p;
        q->rear=p;
    }
    else
    {
        (q->rear)->next=p;
        q->rear=p;
    }
}
void process(struct queue* q, int Q, int K,int N )
{
    struct process t;
    for(int i=0;i<K;i++)
    {

        for(i=0;i<N;i++)
        {
            t=DeQueue(q);
            t.time = t.time-2;
            if(t.time>0)
            {
                EnQueue(q,t);
            }
            else
            EnQueue(q,t);

        }
    }
    DisplayQ(q);
}

 struct process DeQueue(struct queue* q)
{
    struct node* cur= q->front;
    struct process e = cur->data;
    if(q->front == q->rear)
    {
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        q->front = (q->front)->next;
    }
    free(cur);
    return e;

}

 void DisplayQ(struct queue* q)
 {
      struct node* cur= q->front;
         while(cur!=NULL)
         {
             printf("process in ready queue\n");
             if(cur->data.time>0)
             printf("%d %d\n",cur->data.ID,cur->data.time);
             else
             {
                  printf("process completed execution\n");
                 printf("%d ",cur->data.ID);
             }
               cur=cur->next;

         }


 }
