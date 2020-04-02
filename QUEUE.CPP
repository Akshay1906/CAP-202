#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
# define MAX 5
int queue[MAX],front,rear;
void emptyQueue()
{
	front=rear=0;
}
void traversal()
{
	if(front==0 && rear==0 || front > rear)
	{
		cout<<"\nQueue is empty........";
	}

	else
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<queue[i]<<"\t";
		}

	}
}
void enqueue(int item)
{
	if(front==0)
		front++;
	rear++;
	if(front==1 && rear==MAX)
	{
		cout<<"\nOverflow........";
		rear--;
	 }

	else
		queue[rear]=item;

}
void dequeue()
{
	if(front==0 && rear==0)
		cout<<"\nQueue is empty..........";

	else if(front>rear)
	{
		cout<<"\nQueue Underflow !!!!!!";
		emptyQueue();
	}
	else
	{
		front++;
		cout<<"\nDequeued.....";

	}
}

void main()
{
	int ch,element;
	clrscr();
	emptyQueue();
	while(1)
	{
		cout<<"\nPress 1 for Enqueue";
		cout<<"\nPress 2 for Dequeue";
		cout<<"\nPress 3 for Traversal";
		cout<<"\nPress 4 for exit";
		cout<<"\n----------------------------";
		cout<<"\nPlease Enter your choice::";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"\nEnter the element::";
				cin>>element;
				enqueue(element);
				break;
			}
			case 2:
			{
				dequeue();
				break;
			}
			case 3:
			{
				traversal();
				break;
			}
			case 4:
			{
				exit(0);
			}
		}

	}
}