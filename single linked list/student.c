#include"list.h"
struct student
{
    int rno;
    char name[20];
};
void printStudent(void*q);
int main()
{
    struct node* head=NULL;
    struct student e;
    int ch;
    void* q;
    while(1)
    {
        printf("1.Add at beginning of list\n");
        printf("2.delete from beg\n");
        printf("3.Display list\n");
        printf("4.exit(0)\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter rno: ");
                    scanf("%d",&e.rno);
                    printf("enter name : ");
                    scanf("%s",e.name);
                    addatBeg(&head,&e,sizeof(struct student));
                    break;
            case 2: displayList(head,printStudent);


            case 4: exit(0);


        }

    }
}
void printStudent(void*q)
{
 struct student *m=(struct student *)q;
 printf("%s\n",m->name);
  printf("%d\n",m->rno);
}

