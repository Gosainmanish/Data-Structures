#include<stdio.h>
#define N 10
int rear =-1;
int front=-1;
int q[N];

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
{int x;
    if(rear==N-1)
    {
        printf("\n QUEUE FULL - insertion not possible");
    }
    else
    {
        if(front==-1)
            front=0;
       printf("'\n enter the data : ");
       scanf("%d",&x);
        rear++;
        q[rear]=x;
    }
}

del()
{
    if(front==-1)
    {
        printf("\n QUEUE EMPTY - - deletion not possible");
    }
    else
    { printf("\n deleted element : %d",q[front]);
        q[front]=NULL;

        front++;
    }
}

display()
{
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("\n %d",q[i]);
    }
}
