#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
typedef struct DLL
{
	int info;
	struct DLL *prev;
	struct DLL*next;
}node;
node *head,*tail,*last;
void empty_list()
{
	head=tail=NULL;
}
void insert()
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	cout<<"\nEnter the element::";
	cin>>ptr->info;
	if(head==NULL)
	{
		head=last=tail=ptr;
		ptr->prev=NULL;
		ptr->next=NULL;
	}
	else
	{
		tail=ptr;
		last->next=ptr;
		ptr->prev=last;
		last=ptr;
	}
		ptr->next=NULL;
}
void forward_traversal()
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->info<<"\t";
		ptr=ptr->next;
	}
}
void reverse_traversal()
{
	node *ptr=tail;
	while(ptr!=NULL)
	{
		cout<<ptr->info<<"\t";
		ptr=ptr->prev;
	}
}
void insert_beg(int item)
{
		node *ptr;
		ptr=(node *)malloc(sizeof(node));
		ptr->info=item;
		if(head==NULL)
		{
		      head=tail=ptr;
		      ptr->prev=NULL;
		      ptr->next=NULL;
		}
		else
		{
		   ptr->next=head;
		   ptr->prev=NULL;
		   head->prev=ptr;
		   head=ptr;
		}
		cout<<"\nNode inserted successfully.............";
}
void insert_end(int item)
{
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	ptr->info=item;
	if(tail==NULL)
	{
		ptr->prev=ptr->next=NULL;
		head=tail=ptr;
	}
	else
	{
		tail->next=ptr;
		ptr->prev=tail;
		ptr->next=NULL;
		tail=ptr;
	}
       cout<<"\nNode inserted successfully...........";
}
node * search(int item)
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->info==item)
		return ptr;
		else
		ptr=ptr->next;
	}
	return ptr;
}
void insert_after(int item,int after)
{
	node *ptr,*loc;
	loc=search(after);
	if(loc==NULL)
	cout<<"\nSorry item not exist after which the node has to be inserted::";
	else if(loc->next==NULL)
	{       ptr=(node *)malloc(sizeof(node));
		ptr->info=item;
		loc->next=ptr;
		ptr->prev=loc;
		ptr->next=NULL;
		tail=ptr;
		cout<<"\nNode inserted successfully................";
	}

	else
	{
	    ptr=(node *)malloc(sizeof(node));
	    ptr->info=item;
	    ptr->next=loc->next;
	    loc->next=ptr;
	    ptr->prev=loc;
	    loc=ptr;
	    ptr=ptr->next;
	    ptr->prev=loc;
	    cout<<"\nNode inserted successfully................";
	}

}
void insert_before(int item,int before)
{
	node *loc,*ptr;
	loc=search(before);
	if(loc==NULL)
		cout<<"\nSorry item does not exist before which node has to be inserted !!!";
	else if(loc->next==NULL)
	{
	    ptr=(node *)malloc(sizeof(node));
	    ptr->info=item;
	    if(loc==head)
	    {
		head=ptr;
		ptr->prev=NULL;
		ptr->next=loc;
		loc->prev=ptr;
	    }
	    else
	    {
		ptr->next=loc;
		loc=loc->prev;
		loc->next=ptr;
		ptr->prev=loc;
		loc=ptr->next;
		loc->prev=ptr;
	    }
	    cout<<"\nNode inserted successfully............";

	}
	else
	{
	      ptr=(node *)malloc(sizeof(node));
	      ptr->info=item;
	      if(loc==head)
	      {
		head=ptr;
		ptr->prev=NULL;
		ptr->next=loc;
		loc->prev=ptr;
	      }
	      else
	      {
		 ptr->next=loc;
		 ptr->prev=loc->prev;
		 loc->prev=ptr;
		 loc=ptr->prev;
		 loc->next=ptr;
		 cout<<"\nNode inserted successfully...........";
	      }
	}

}
void del_after(int aft)
{
	node *ptr,*loc,*temp;
	loc=search(aft);
	if(loc==NULL)
		cout<<"\nItem does not exist!!!!";
	else if(loc->next==NULL)
	{
		cout<<"\n\nSorry no node exist after this item";
	}
	else
	{
		ptr=loc->next;
		loc->next=ptr->next;
		temp=ptr->next;
		temp->prev=loc;
		free(ptr);
		cout<<"\n\nNode deleted successfully.......\n";
	}
}
void del_before(int before)
{
	node *ptr,*loc,*temp;
	loc=search(before);
	if(loc==NULL)
		cout<<"\nItem does not exist!!";
	else if(loc->prev==NULL)
		cout<<"\nNo node exist before the item!!";
	else
	{
		ptr=loc->prev;
		if(ptr->prev==NULL)
		{
			head=loc;
			loc->prev=NULL;
			free(ptr);
			cout<<"\n\nNode deleted successfully......";
		}
		else
		{
			loc->prev=ptr->prev;
			temp=ptr->prev;
			temp->next=loc;
			free(ptr);
			cout<<"\n\nNode deleted successfully......";
		}
	}
}

void main()
{       int ch,value,aft,bef;
	clrscr();
	for(;;)
	{
		cout<<"\nPress 1 for insertion";
		cout<<"\nPress 2 for insert at beginning";
		cout<<"\nPress 3 for insert at end";
		cout<<"\nPress 4 for insert after given node";
		cout<<"\nPress 5 for insert before given node";
		cout<<"\nPress 6 for forward traversal";
		cout<<"\nPress 7 for reverse traversal";
		cout<<"\nPress 8 for delete after given node";
		cout<<"\nPress 9 for delete before given node";
		cout<<"\nPress 10 for exit";
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
				cout<<"\nEnter the item::";
				cin>>value;
				insert_beg(value);
				break;
			}
			case 3:
			{
				cout<<"\nEnter the item::";
				cin>>value;
				insert_end(value);
				break;
			}
			case 4:
			{
				cout<<"\nEnter the item and after value::";
				cin>>value>>aft;
				insert_after(value,aft);
				break;
			}
			case 5:
			{
				cout<<"\nEnter the item anf before value::";
				cin>>value>>bef;
				insert_before(value,bef);
				break;
			}
			case 6:
			{
			      forward_traversal();
			      break;
			}
			case 7:
			{
				reverse_traversal(); break;
			}
			case 8:
			{
				cout<<"\nEnter the  after value::";
				cin>>aft;
				del_after(aft);
				break;
			}
			case 9:
			{
				cout<<"\nEnter the before value::";
				cin>>bef;
				del_before(bef);
				break;
			}
			case 10:
			{
				exit(0);
			}

		}
	}

}