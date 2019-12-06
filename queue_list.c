#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void insert();
void del();
void display();

main()
{
     int ch;
    while(1)
    {
        printf("\n 1.insert 2.delete 3. display 4. exit \n");
        printf("\n enter choice :");
        scanf("%d",&ch);
            switch(ch)
            {
                case 1:insert();
                        break;
                case 2:del();
                        break;
                case 3:display();
                        break;
                case 4:exit(1);
                        break;
                        default:printf("\n wrong choice");
            }
    }
}

insert()
{
    struct node *newnode;
    newnode=(struct node*) malloc(sizeof(struct node));

    printf("\n enter data of newnode:");
    scanf("%d",&newnode->data);

    newnode->next=NULL;

    if(front == NULL)
    {
       front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
     printf("\nInsertion is Success!!!\n");
}

del()
{
    if(front==NULL)
    {
        printf("\n  QUEUE IS EMPTY - deletion not possible");
    }

    else
    {
        struct node *temp=front;
        front=front->next;
        printf("\n %d -- element deleted SUCCESS!!!",temp->data);
        free(temp);
    }
}

display()
{
    if(front == NULL)
      printf("\nQueue is Empty!!!\n");

      else
{
    struct node *temp = front;
      while(temp->next!=NULL)
      {
          printf("%d--->",temp->data);
          temp=temp->next;
      }
      printf("%d--->NULL \n",temp->data);
}
}
