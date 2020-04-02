#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
typedef struct CLL
{
	int info;
	struct CLL *link;
}node;

node *head,*last;
void emptyList()
{
	head=last=NULL;
}
void insert()
{
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	cout<<"\nEnter the element::";
	cin>>ptr->info;
	if(head==NULL)
	{
		last=head=ptr;
		ptr->link=head;
	}
	else
	{
	       last->link=ptr;
	       ptr->link=head;
	       last=ptr;
	}
}
void traverse()
{
	node *ptr=head;
	if(head==NULL)
		cout<<"\nList is empty !!!!!!";
	else
	{
		while(ptr->link!=head)
		{
			cout<<ptr->info<<"\t";
			ptr=ptr->link;
		}
	}
	cout<<ptr->info;
}
node * search(int item)
{
	node *ptr;
	if(head==NULL)
		cout<<"\nList is Empty !!!!!!!!!";
	else
	{
		ptr=head;
		do
		{
		       if(ptr->info==item)
			return ptr;
		       else
			ptr=ptr->link;
		}while(ptr!=head);
	}
	return NULL;
}
void insertBeg(int item)
{
	node *ptr,*loc;
	ptr=(node *)malloc(sizeof(node));
	ptr->info=item;
	if(head==NULL)
	{
		head=ptr;
		ptr->link=head;
	}
	else
	{
		loc=head;
		while(loc->link!=head)
			loc=loc->link;

		ptr->link=head;
		head=ptr;
		loc->link=ptr;
	}
}
void insertEnd(int item)
{
	node *ptr,*loc;
	ptr=(node *)malloc(sizeof(node));
	ptr->info=item;
	if(head==NULL)
	{
		head=ptr;
		ptr->link=head;
	}
	else
	{
		loc=head;
		do
		{
			loc=loc->link;
		}while(loc->link!=head);
		loc->link=ptr;
		ptr->link=head;
	}

}
void deleteAll()
{
	node *ptr,*loc;
	if(head==NULL)
		cout<<"\nList is empty !!!!!!!";
	else
	{
		while(head->link!=head)
		{
			ptr=loc=head;
			do
			{
				loc=loc->link;

			}while(loc->link!=head);
			head=ptr->link;
			loc->link=head;
			free(ptr);
		}
		if(ptr->link==head)
		{
			free(ptr);
			head=NULL;
		}
		cout<<"\nDeleted..........";
	}

}

void delete_(int item)
{
      node *ptr,*loc,temp;
      int p=item;
      loc=search(p);
      if(loc!=NULL)
      {
	ptr=head;
	if(loc==ptr)
	{
		do
		{
			loc=loc->link;
		}while(loc->link!=head);

		head=ptr->link;
		loc->link=head;
		free(ptr);
	}
	else if(loc->link==head)
	{

		while(ptr->link!=loc)
		{
			ptr=ptr->link;
		}
		ptr->link=head;
		free(loc);
	}
	else
	{
		while(ptr->link!=loc)
		{
			ptr=ptr->link;
		}
		ptr->link=loc->link;
		free(loc);
	}
	cout<<"\nDeleted.......";
      }
      else
      {
	cout<<"\Unable to delete !!!!!!!!!!!!";
      }

}
void deleteBeg()
{
	node *ptr,*loc;
	ptr=head;
	if(head==NULL)
		cout<<"\nList is empty !!!!!!!";
	else if(ptr->link==head)
	{
		head=NULL;
		cout<<"\nDeleted..........";
	}
	else
	{
		loc=head;
		while(loc->link!=head)
			loc=loc->link;
		head=loc->link=ptr->link;
		free(ptr);
		cout<<"\nDeleted.......";
	}
}
void deleteEnd()
{
	node *ptr,*loc;
	ptr=head;
	if(head==NULL)
		cout<<"\nList is empty !!!!!!!!!!";
	else if(ptr->link==head)
	{
		head=NULL;
		cout<<"\nDeleted.........";
	}
	else
	{
		ptr=head;
		loc=ptr->link;
		while(loc->link!=head)
		{
			ptr=ptr->link;
			loc=loc->link;
		}
		free(loc);
		ptr->link=head;
		cout<<"\nDeleted.........";
	}
}
void main()
{
	int ch,value;
	node *loc;
	clrscr();
	for(;;)
	{
		cout<<"\nPress 1 to insert";
		cout<<"\nPress 2 for insert at Beg";
		cout<<"\nPress 3 for insert at End";
		cout<<"\nPress 4 to search";
		cout<<"\nPress 5 to delete the element";
		cout<<"\nPress 6 to delete whole list";
		cout<<"\nPress 7 to delete beg";
		cout<<"\nPress 8 to delete end";
		cout<<"\nPress 9 for exit";
		cout<<"\nPress 10 for traversal";
		cout<<"\n-----------------------------------";
		cout<<"\nPlease Enter your choice::";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				insert();
				break;
			}
			case 2:
			{
				cout<<"\nEnter the item::";
				cin>>value;
				insertBeg(value);
				break;
			}
			case 3:
			{
				cout<<"\nEnter the item::";
				cin>>value;
				insertEnd(value);
				break;
			}
			case 4:
			{
				cout<<"\nEnter the item to search::";
				cin>>value;
				loc=search(value);
				if(loc!=NULL)
					cout<<"\nItem found......";
				else
					cout<<"\nItem not found !!!!!!";
				break;
			}
			case 5:
			{
				cout<<"\nEnter the element to delete";
				cin>>value;
				delete_(value);
				break;
			}
			case 6:
			{
				deleteAll();
				break;
			}
			case 7:
			{

				deleteBeg();
				break;
			}
			case 8:
			{
				deleteEnd();
				break;
			}
			case 10:
			{
				traverse();
				break;
			}
			case 9:
				exit(0);
			default:
				cout<<"\nInvalid choice !!!!!!";
		}
	}
}