#include<stdio.h>
#include<stdlib.h>
#define size 10

struct node
{
 int data;
 struct node *left,*right;
};
struct node *start=(struct node*)0;

void main()
{
   void insert(int);
   struct node*search(int);
   void delet(int);
   struct node *temp;
   int c,a,b;
   int data;
   do
   {
     printf("**doubly link**\n");
     printf("1.insert\n");
     printf("2.search\n");
     printf("3.delet\n");
     printf("4.exit\n");
     printf("enter the choice:");
     scanf("%d",&c);
     switch(c)
     {
     case 1:printf("enter data to insert:\n");
            scanf("%d",&a);
            insert(a);
            break;
     case 2:printf("enter data to search:\n");
            scanf("%d",&b);
            temp=search(b);
            if(temp==(struct node*)0)
            printf("item not found..\n");

            else
            printf("item found..\n");
            break;
     case 3:printf("enter data to delet:\n");
            scanf("%d",&a);
            delet(a);

            break;
     case 4:printf("exiting...\n");
            exit(0);
     } //end of switch
    }
    while(1);
}

//fun to insert a node @ begining of a doubly linked list
void insert(int x)
{
 struct node*newnode;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=x;

 if(start==(struct node*)0)  //case of empty list
  {
  newnode->left=(struct node*)0;
  start=newnode;
  }
 else //case of atleast one node
  {
  newnode->left=(struct node*)0;
  newnode->right=start;

  start->left=newnode;
  start=newnode;
 }
printf("item inserted is: %d",x);
}
//fun to search an item
struct node*search(int d)
  {
  struct node *ptr;
  ptr=start;
  while(ptr!=(struct node*)0 && ptr->data!=d)
  {                       //ptr not equal to zero
  ptr=ptr->right;
  }
  return ptr;//ptr 0 implies not found,1 implies found
 }

//fun to delet
void delet (int x)
 {
 struct node*t;
 t=search(x);//calling search to find whether that data
 if(t==0)
 {
 printf("not found..\n");
 }

 else//elements exits case
  {
  printf("item deleted...\n");
  
  if(t==start)//case of first node
   
  if(t->right==(struct node*)0)//one and only node
   {
    start=(struct node*)0;
   }

  else//case of having more than one node
   {
     t->right->left=(struct node*)0;
     start=t->right;
   }
  else if
     (t->right=(struct node*)0)//case of last node
   {
     t->left->right=t->right;
   }

  else//case of an interior node
   {
     t->left->right=t->right;
     t->right->left=t->left;
   }

  free(t);
  }
} 
  


