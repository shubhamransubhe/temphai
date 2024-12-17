#include"list.h"
struct student
{
    int rno;
    char name[20];
};

int main()
{
    struct node* head=NULL;
    struct student e;
    int ch;
    while(1)
    {
        printf("1.Add at beginning of list\n");
        printf("delete from beg\n");
        printf("Display list\n");
        printf("exit(0)");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("enter rno: ");
                    scanf("%d",&e.rno);
                    printf("enter name : ");
                    scanf("%s",e.name);
                    addatBeg(&head,&e,sizeof(struct student));
                    break;



        }

    }
}
void printStudent(void*q)
{

}
