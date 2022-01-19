#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *sp=(struct node*)0;
int stat;
void main()
{
  void push(int);
  int pop();
  int search(int);
  int c,d,k=1,m;
  do
  {
    printf("\n");
    printf("***singly linked stack***\n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.search\n");
    printf("4.exit\n");
    printf("enter the option:");
    scanf("%d",&c);
    switch(c)
    {
       case 1:printf("enter some data to push:\n");
              scanf("%d",&d);
              push(d);
              
              break;
      case 2:pop();
             if(stat==1)
             printf("popped item is:%d\n",d);
             
             break;
      case 3:printf("enter the data to search:\n");
             scanf("%d",&m);
             k=search(m);
             if(k==1)
             {
              printf("item not found...\n");
             }
             break;
      case 4:printf("exiting...\n");
             exit(0);
    }

   }//end of do function
   while(1);

}
//function for pushing an item
    
       void push(int x)
       {
         struct node *newnode;
         newnode=(struct node*)malloc(sizeof(struct node));
         newnode->data=x;
         newnode->next=sp;
         sp=newnode;
       }

//function for poping an item
int pop()
{
   int a;
   struct node *temp;
   if(sp==(struct node*)0)
   {
     printf("empty stack\n");
     stat=0;
   }
 
  else
   {
     a=sp->data;
     temp=sp;
     sp=sp->next;
     free(temp);
     stat=1;
     return a;
   }

}//end of pop function

//function for serach
int search(int x)
{
  struct node *ptr;
  ptr=sp;
  while(ptr!=(struct node*)0)
  {
    if(ptr->data==x)
    {  
     printf("item found...\n");
     return 0;
    }
    ptr=ptr->next;
  }
  return 1;
}//end of search function
