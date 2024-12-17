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

void postorderoftree(struct node* root);
void preorderoftree(struct node* root);
void display(struct node* s);
void  readStudent(struct student* s);
struct node* createTree(struct node* root, struct student key);
void inorderoftree(struct node* root);

struct node* getnode(struct student key);


struct node* getnode(struct student key)
{
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

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
}

int main()
{
    int r;
    int v,x;
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
        printf("7 . delete node \n");

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
         case 7: printf("enter node to be deleted:\n");
                 scanf("%d",&x);
                 deleteNode(root,x);
                 break;
        }
    }
    return 0;
}

void  readStudent(struct student* s)
{
    printf("enter name\n");
    scanf("%s",s->name);
    printf("enter roll no\n");
    scanf("%d",&(s->roll));
    printf("enter usn\n");
    scanf("%s",s->usn);
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
    printf(" name: ");
    printf("%s\n",s->data.name);
    printf( " roll no :");
    printf("%d\n",(s->data.roll));
    printf(" usn: ");
    printf("%s\n",s->data.usn);
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

 struct node* deleteNode( struct node* root,int key)
 {
     if(root == NULL)
        return root;
    else if(key < root->data.roll)
        root->lchild = deleteNode(root->lchild,key);
    else if(key > root->data.roll)
        root->rchild = deleteNode(root->rchild,key);
    else
    {
        if(root->rchild == NULL && root->lchild == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        else if(root->rchild == NULL)
        {
            struct node* temp = root;
            root = root->lchild;
            free(root);
            return root;

        }
          else if(root->lchild == NULL)
        {
            struct node* temp = root;
            root = root->rchild;
            free(root);
            return root;

        }
        else
        {      struct node* temp = findMIn(root->rchild);

        }

    }


 }
