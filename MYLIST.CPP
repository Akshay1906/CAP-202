#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
typedef struct linked_list
{
	int info;
	struct linked_list *link;
}node;
node *head,*last;
void empty()
{
	head=NULL;
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
	}
	else
	{
		last->link=ptr;
		last=ptr;
	}
	ptr->link=NULL;
}
void traversal()
{
	node* ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->info<<"\t";
		ptr=ptr->link;
	}
}
void rev_list()
{
	node *ptr,*prev,*next;
	ptr=next=head;
	prev=NULL;
	while(ptr!=NULL)
	{
	       next=ptr->link;
	       ptr->link=prev;
	       prev=ptr;
	       ptr=next;
	}
	head=prev;

}
node * search(int item)
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->info==item)
			return ptr;

		else
		       ptr=ptr->link;
	}
	return ptr;
}
void insert_after(int item,int after)
{
	node *ptr,*loc;
	loc=search(after);
	if(loc==NULL)
		cout<<"\nCan`t insert the item!!!!";
	else if(loc->link==NULL)
	{
		ptr=(node *)malloc(sizeof(node));
		ptr->info=item;
		loc->link=ptr;
		ptr->link=NULL;
		cout<<"\nNode inserted successfully............";
	}
	else
	{
		ptr=(node *)malloc(sizeof(node));
		ptr->info=item;
		ptr->link=loc->link;
		loc->link=ptr;
		cout<<"\nNode inserted successfully............";
	}
}
void insert_before(int item,int before)
{
	node *ptr,*loc,*temp;
	loc=search(before);
	if(loc==NULL)
		cout<<"\nCan`t insert the item........";
	else
	{

		ptr=(node *)malloc(sizeof(node));
		ptr->info=item;
		if(loc==head)
		{
			ptr->link=head;
			head=ptr;
		}
		else
		{
			temp=head;
			while(temp->link!=loc)
				temp=temp->link;
			temp->link=ptr;
			ptr->link=loc;
		}
		cout<<"\nNode inserted successfully............";
	}
}
void del_after(int after)
{
	node *loc,*ptr;
	loc=search(after);
	if(loc==NULL)
		cout<<"\nItem not present in the given list !!!!!!!!";
	else
	{
	     if(loc->link==NULL)
		cout<<"\nNo node exist after the item !!!!!!";
	     else
	     {
		ptr=loc->link;
		if(ptr->link==NULL)
			loc->link=NULL;

		else
			loc->link=ptr->link;
		free(ptr);
	     }
	     cout<<"\nNode deleted successfully...............";
	}
}
void del_before(int before)
{
	node *loc,*ptr,*temp;
	loc=search(before);
	if(loc==NULL)
		cout<<"\nItem not present in the list !!!!!!!!!";
	 else
	 {
		if(loc==head)
			cout<<"\nNo node exist before this node !!!!";
		 else
		 {
			ptr=temp=head;
			while(ptr->link!=loc)
			{
				ptr=ptr->link;
			}
			if(ptr==head)
			{
				head=ptr->link;
				free(ptr);
			}
			else
			{
				while(temp->link!=ptr)
					temp=temp->link;
				temp->link=loc;
				free(ptr);
			}
		 }
	 }
}
void main()
{
	int ch,value,aft,bef;
	clrscr();
		for(;;)
	{
		cout<<"\nPress 1 for insertion";
		cout<<"\nPress 2 for insert after given node";
		cout<<"\nPress 3 for insert before given node";
		cout<<"\nPress 4 for forward traversal";
		cout<<"\nPress 5 for reversing the list";
		cout<<"\nPress 6 for delete after given node";
		cout<<"\nPress 7 for delete before given node";
		cout<<"\nPress 8 for exit";
		cout<<"\n------------------------------------------------";
		cout<<"\nPlease enter your choice::";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				insert(); break;
			}
			case 2:
			{
				cout<<"\nEnter the item and after value::";
				cin>>value>>aft;
				insert_after(value,aft);
				break;
			}
			case 3:
			{
				cout<<"\nEnter the item anf before value::";
				cin>>value>>bef;
				insert_before(value,bef);
				break;
			}
			case 4:
			{
			      traversal();
			      break;
			}
			case 5:
			{
				rev_list(); break;
			}
			case 6:
			{
				cout<<"\nEnter the  after value::";
				cin>>aft;
				del_after(aft);
				break;
			}
			case 7:
			{
				cout<<"\nEnter the before value::";
				cin>>bef;
				del_before(bef);
				break;
			}
			case 8:
			{
				exit(0);
			}

		}
	}

}                          \



