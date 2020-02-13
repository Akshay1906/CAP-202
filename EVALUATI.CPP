#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
typedef struct single
{
	int info;
	struct single *link;
}node;
node *head,*last;
void empty()
{
	head=last=NULL;
}
void traverse()
{
	node *ptr=head;
	if(ptr==NULL)
		cout<<"\nList is empty!!!!!!!!!";
	else
	{
		while(ptr!=NULL)
		{
			cout<<ptr->info<<"\t";
			ptr=ptr->link;
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
		head=last=ptr;
		head->link=NULL;
	}
	else
	{
		last->link=ptr;
		ptr->link=NULL;
		last=ptr;
	}
}
void insertSum(int item)
{
	node *ptr,*loc;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	if(head==NULL)
	{
		head=ptr;
		ptr->link=NULL;
	}
	else
	{
	      loc=head;
	      while(loc->link!=NULL)
			loc=loc->link;
	      loc->link=ptr;
	      ptr->link=NULL;
	}
}
void delPrime()
{
	node *ptr=head;
	node *loc=head;

	int sum=0,i,flag=0;
	if(head==NULL)
		cout<<"\nNo node exist::";
	else
	{
		while(ptr!=NULL)
		{
			flag=0;
			for(int i=2;i<=(ptr->info/2);i++)
			{
				if(ptr->info%i==0)
				{
					flag=-1;
					break;
				}
				else
				{
					flag=0;

				}
			}
			if(flag==0)
			{
				sum=sum+ptr->info;
				if(ptr==head)
				{
					head=head->link;
					free(ptr);
					ptr=head;
					loc=head;

				}
				else if(head->link==NULL)
				{
					free(head);
					break;
				}
				else
				{
					loc->link=ptr->link;
					free(ptr);
					ptr=loc->link;

				}



			}

			else
			{
				if(loc!=ptr)
					loc=loc->link;
				else
					ptr=ptr->link;

			}

		}

	}
	if(sum!=0)
	{
		insertSum(sum);
		cout<<"\n\nSum= "<<sum;
	}
}

void main()
{
	int i=0,n;

	clrscr();
	empty();
	cout<<"\nHow many nodes you want to enter::";
	cin>>n;
	while(i<n)
	{
		insert();
		i++;
	}
	cout<<"\nOUTPUT::";
	traverse();
	delPrime();
	cout<<"\nOUTPUT::";
	traverse();

	getch();
}