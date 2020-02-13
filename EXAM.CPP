#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
typedef struct DLL
{
	struct DLL *prev;
	int info;
	struct DLL *next;
}node;

node *head,*tail,*last;

void empty()
{
	head=tail=last=NULL;
}
void traverse()
{
	node *ptr=head;
	if(head==NULL)
		cout<<"\nNo node exist!!!";
	else
	{
		while(ptr!=NULL)
		{
			cout<<ptr->info<<"\t";
			ptr=ptr->next;
		}
	}
}
void insert()
{
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	cout<<"\nEnter the element::";
	cin>>ptr->info;
	if(head==NULL)
	{
		head=tail=last=ptr;
		head->prev=tail->next=NULL;
	}
	else
	{
		last->next=ptr;
		ptr->prev=last;
		ptr->next=NULL;
		last=tail=ptr;
	}
}
node * search(int item)
{
	node *ptr=head;
	if(head==NULL)
	{
		cout<<"\nNo node exist!!!";
	}
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->info==item)
			{
				return ptr;
			}
			ptr=ptr->next;
		}

	}
	return NULL;
}
void insert_end(int item)
{
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->info=item;
	if(head==NULL)
	{
		head=tail=last=ptr;
		head->prev=tail->next=NULL;
	}
	else
	{
		last->next=ptr;
		ptr->prev=last;
		ptr->next=NULL;
		last=tail=ptr;
	}
}


void delAfter(int item)
{
	node *ptr,*loc;
	loc=search(item);
	if(head->next==NULL)
		cout<<"\nNo Node exist to delete......";
	else if(loc->next==NULL)
		cout<<"\nNO node exist to delete......";

	else
	{
		ptr=ptr->next;
		ptr->prev=loc;
		ptr=loc->next;
		loc->next=ptr->next;
		free(ptr);

	}
}


void main()
{
	int n,i=0,value;
	node *k;
	clrscr();
	empty();
	cout<<"\nHow many node you want to insert::";
	cin>>n;
	while(i<n)
	{
		insert();
		i++;
	}
	cout<<"\nOUTPUT::";
	traverse();
	cout<<"\nEnter the item to add::";
	cin>>value;
	k=search(value);
	if(k!=NULL)
	{
		cout<<"\nItem is already present in the list....";
		delAfter(value);
	}

	else
	{
		insert_end(value);
		cout<<"\nNode inserted successfully......";
	}
	cout<<"\nOUTPUT::";
	traverse();
	getch();
}