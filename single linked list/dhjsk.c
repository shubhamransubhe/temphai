#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    void* data;
    struct node* next;
};

void addatBeg (struct node ** head,void)
