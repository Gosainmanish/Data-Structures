#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;

}*head,*temp,*temp1;

void create(int);
void insert_beginning();
void insert_end();
void insert_middle();
void delete_beginning();
void delete_end();
void delete_middle();
void display();

main()
{
    int n,a,b;
    printf("\n enter the number of nodes in the list : ");
    scanf("%d",&n);
    create(n);
    display();
    printf("\n 1 - insert at beginning ");
	printf("\n 2 - insert at middle");
	printf("\n 3 - insert at end ");
	scanf("%d",&a);

	switch(a)
	{
		case 1:insert_beginning();
			break;
		case 2:insert_middle();
			break;
		case 3:insert_end();
			break;
	}

		display();

	printf("\n 1 - delete at beginning ");
	printf("\n 2 - delete at middle");
	printf("\n 3 - delete at end ");

scanf("%d",&b);

	switch(b)
	{
		case 1: delete_beginning();
			break;
		case 2: delete_middle();
			break;
		case 3: delete_end();
			break;
	}
display();

}

void create(int n)
{
    int i=0;

    struct node *newnode;
    for(i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\n enter the data of node %d: ",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
}
void display()
{
    int i=0;
    temp=head;
printf("\n DISPLAYING THE SINGLY LINKED LIST \n");
	if (head==NULL)
		{
			printf("\n LIST IS EMPTY");
		}
    else
    {
        while(temp!=NULL)
        {
            i++;
            printf("\n node %d : %d",i,temp->data);
        temp=temp->next;
        }
    }
}

void insert_beginning()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n enter data :");
    scanf("%d",&newnode->data);
    temp=head;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }

}

void insert_end()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n enter data :");
    scanf("%d",&newnode->data);
    temp=head;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
    }
}

void insert_middle()
{
    int sv;
    printf("\n enter search val:");
    scanf("%d",&sv);
    char found;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n enter data of newnode to be inserted at middle :");
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==sv)
        {
            found='y';
            break;

        }

        else
        {found='n';
            temp1=temp;
            temp=temp->next;
        }
    }
        if(found='y')
        {	temp1=temp->next;
            newnode->next=temp->next;
            newnode->prev=temp;
		temp1->prev=newnode;
		temp->next = newnode;

        }
    else
    {
            printf("\n not possible");
    }
}
void delete_beginning()
{
    temp=head;
    head=temp->next;
    head->prev=NULL;
    free(temp);
}

void delete_end()
{
    temp=head;

        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;

        }
        temp1->next=NULL;
        free(temp);
}

void delete_middle()
{
    int dv;
    char found;
    printf("\n enter data to be deleted : ");
    scanf("%d",&dv);

    temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==dv)
        {
            found='y';
            break;
        }

        else
        {
            temp1=temp;
			temp=temp->next;
            found='n';
        }
    }

    if(found='y')
    {
        temp1->next=temp->next;
    free(temp);


    }

    else
{
    printf("\n NOT POSSIBLE");
}
}
