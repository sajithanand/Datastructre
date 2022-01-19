#include<stdio.h>
#include<stdlib.h>
#define size 10
int front=0;
int rear=0;
int q[size];

void main()
{
    void insert(int);
    int delet();
    int search(int);
    int c,d,k=0;
    do
    {

    printf("1.insertion\n");
    printf("2.deletion\n");
    printf("3.search\n");
    printf("4.exit\n");
    printf("enter your choice\n");
    scanf("%d",&c);
    

        switch(c)
        {
            case 1:printf("enter a value to insert../n");
                  scanf("%d",&d);
                  insert(d);
                  break;
            case 2:d=delet();
                  printf("the deleted item is:%d/n",d);
                  break;
            case 3:printf("enter a value to search:\n");
                  scanf("%d",&d);
                  k=search(d);
                  if(k==0)
                  printf("item not found....\n");
                  break;
            case 4:printf("exiting....\n");
                  exit(0);
        }
   }
   while(1);


 }

 void insert(int x)
 {
     int t;
     t=(rear+1)%size;
     if(front==t)
     {
         printf("queue is full....\n");
     }
     else
     {

         rear=t;
         q[rear]=x;
         printf("item inserted..\n");

     }

  }

  int delet()
  {
      int r;
      if(front==rear)
      {
          printf("queue empty...\n");
      }
      else
      {
          front=(front+1)%size;


          return q[front] ;


      }
 }

 int search(int item)
 {
      int f,r;
      f=front;
      r=rear;
      while(f!=r)
      {
          f=(f+1)%size;
          if(q[f]==item)
          {
              printf("item found..\n");
          
          }

      }
      return 0;

 }
  

    
 

