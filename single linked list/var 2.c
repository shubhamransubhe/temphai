#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rollno;
    char name[20];
    int marks;
};
typedef struct student *stu;
struct node
{
    stu data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node *Node;
Node getnode(stu key)
{
    Node newn;
    newn=(Node)malloc(sizeof(struct node));
    if(newn==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        newn->data=key;
        newn->lchild=NULL;
        newn->rchild=NULL;
        return newn;
    }
}
Node createtree(Node root,stu key)
{
    if(root==NULL)
    {
        root=getnode(key);
        return root;
    }
    else if(root->data->rollno > key->rollno)
    {
        root->lchild=createtree(root->lchild,key);
        return root;
    }
    else if(root->data->rollno < key->rollno)
    {
        root->rchild=createtree(root->rchild,key);
        return root;
    }
}
void inorder(Node root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->lchild);
        printf("%d %s %d\n",root->data->rollno,root->data->name,root->data->marks);
        inorder(root->rchild);
    }
}
void preorder(Node root)
{
    if(root==NULL)
        return;
    else
    {
        printf("%d %s %d\n",root->data->rollno,root->data->name,root->data->marks);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(Node root)
{
    if(root==NULL)
        return;
    else
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d %s %d\n",root->data->rollno,root->data->name,root->data->marks);
    }
}
void search(Node root,int s)
{
    int flag=0;
    Node temp=root;
    while(temp)
    {
      if(s==temp->data->rollno)
      {
        flag=1;
        break;
      }
      else if(s>temp->data->rollno)
      {
          temp=temp->rchild;
      }
      else if(s<temp->data->rollno)
      {
          temp=temp->lchild;
      }
    }
    if(flag==1)
    {
        printf("%d %s %d is the student you were searching for\n",temp->data->rollno,temp->data->name,temp->data->marks);
    }
    else if(flag==0)
    {
        printf("Student not found\n");
    }
}
void max_marks(Node root)
{
    Node cur=root;
    while(cur && cur->rchild)
        cur=cur->rchild;
    printf("%d is the marks of %s",cur->data->marks,cur->data->name);
}
void min_marks(Node root)
{
    Node cur=root;
    while(cur && cur->lchild)
        cur=cur->lchild;
    printf("%d is the marks of %s",cur->data->marks,cur->data->name);
}
Node minvalue(Node root)
{
    Node cur=root;
    while(cur && cur->lchild)
        cur=cur->lchild;
    return cur;
}
Node deletetree(Node root,int key)
{
    if(root==NULL)
        return root;
    else if(root->data->rollno>key)
    {
        root->lchild=deletetree(root->lchild,key);
    }
    else if(root->data->rollno<key)
    {
        root->rchild=deletetree(root->rchild,key);
    }
    else if(root->data->rollno==key)
    {
        if(root->lchild==NULL)
        {
            Node temp=root->rchild;
            free(root);
            return temp;
        }
        if(root->rchild==NULL)
        {
            Node temp=root->lchild;
            free(root);
            return temp;
        }
        Node temp=minvalue(root->rchild);
        root->data->rollno=temp->data->rollno;
        root->rchild=deletetree(root->rchild,temp->data->rollno);
    }
    return root;
}
main()
{
    int ch,s,d;
    Node root=NULL;
    stu key;
    while(1)
    {
      printf("Enter\n1 to insert data\n2 to display in inorder fashion\n3 to display in preorder fashion\n4 to display in postorder fashion\n5 to search student\n6 to find maximum marks\n7 to find minimum marks\n8 to delete a student\n");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:printf("Enter student rollno,name and marks\n");
                 scanf("%d%s%d",&key->rollno,key->name,&key->marks);
                 root=createtree(root,key);
                 break;
          case 2:inorder(root);
                 break;
          case 3:preorder(root);
                 break;
          case 4:postorder(root);
                 break;
          case 5:printf("Enter the rollno whose information to be displayed\n");
                 scanf("%d",&s);
                 search(root,s);
                 break;
          case 6:max_marks(root);
                 break;
          case 7:min_marks(root);
                 break;
          /*case 8:printf("Enter the rollno of the student to be deleted\n");
                 scanf("%d",&d);
                 Node=deletetree(root,d);
                 break;*/
      }
    }
}
