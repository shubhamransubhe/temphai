#include<stdio.h>
#include<stdlib.h>
struct student
{
    int roll;
    char usn[10];
    char name[10];
};
struct node
{
    struct student data;
    struct node* lchild;
     struct node* rchild;

};

struct node* getnode(struct student key)
{
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
};

struct node* createTree(struct node* root, struct student key)
{
    if(root == NULL)
    {
        root = getnode(key);
        return root;
    }
    if(root->data.roll < key.roll)
    {
        root->rchild = createTree(root->rchild , key);
        return root;
    }
    if(root->data.roll > key.roll)
    {
        root->lchild = createTree(root->lchild , key);
        return root;
    }
};
int main()
{
    int r;
    int v;
    struct student key;
    struct node* root = NULL;
    int choice;

    while(1)
    {
        printf("1. add student details\n");
        printf("2. search student\n");
        printf("3. exit\n");
        printf("4 . inorderoftree\n");
        printf("5 . preorderoftree\n");
        printf("6 . postorderoftree\n");
        printf("7 . leftviewoftree\n");
        printf("8. topviewoftree\n");

        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            readStudent(&key);
            root = createTree(root,key);
            break;
        case 2:
            printf("enter roll no \n");
            scanf("%d",&r);
           v = searchStudent(root,r);
           if(v==1)
           {
                printf("student found\n");

           }

           else
            printf("student not found\n");
           break;

        case 3:
            exit(0);

         case 4: inorderoftree(root);
                 break;
        case 5: preorderoftree(root);
                 break;
        case 6: postorderoftree(root);
                 break;
        case 7: leftviewTree(root);
                  break;
          case 8: topviewTree(root);
                  break;
        }
    }
}

void  readStudent(struct student* s)
{

    printf("enter roll no\n");
    scanf("%d",&(s->roll));

}
int searchStudent(struct node* root,int r)
{
    while(root)
    {
        if(r>root->data.roll)
            root = root->rchild;
        else if(r<root->data.roll)
             root = root->lchild;
        else
        {
              display(root);
              return 1;
        }

    }
    return 0;
}
void display(struct node* s)
{
    printf( " roll no :");
    printf("%d\n",(s->data.roll));
}

void inorderoftree(struct node* root)
{
    if(root == NULL)
        return;
    inorderoftree(root->lchild);
    display(root);
    inorderoftree(root->rchild);
}


void preorderoftree(struct node* root)
{
    if(root == NULL)
        return;
          display(root);
    preorderoftree(root->lchild);

    preorderoftree(root->rchild);
}

void postorderoftree(struct node* root)
{
    if(root == NULL)
        return;
    postorderoftree(root->lchild);

    postorderoftree(root->rchild);
      display(root);
}

void leftviewTree(struct node* root)
{
    if(root==NULL)
        return;
    leftviewTree(root->lchild);
     display(root);
}
void topviewTree(struct node* root)
{
    if(root==NULL)
        return;
   topviewTree(root->lchild);
     display(root);

}
