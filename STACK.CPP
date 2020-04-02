#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX],top;
void emptyStack()
{
	top = 0;
}
void traversal()
{
	if(top == 0)
		cout<<"\nStack is Empty !!!!!!";

	else
	for(int i=1; i<=top;i++)
	{
		cout<<stack[i]<<endl;

	}
}
void push(int item)
{
	if(top==MAX)
		cout<<"\nStack Overflow .......";
	else
	{
		top++;
		stack[top]=item;
	}
}
void pop()
{
	if(top==0)
		cout<<"\nStack Undeflow !!!!!!!!!";
	else
	{
		top--;
		cout<<"\nItem Popped .......";
	}
}
void main()
{
	int ch,value,num;
	clrscr();
	emptyStack();
	while(1)
	{

		cout<<"\nPress 1 for push";
		cout<<"\nPress 2 for pop";
		cout<<"\nPress 3 for traversal";
		cout<<"\nPress 4 for exit";
		cout<<"\n\n-----------------------------";
		cout<<"\nPlease Eter your Choice::";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{


					cout<<"\nEnter item::";
					cin>>value;
					push(value);
					break;
			}
			case 2:
			{
				pop();
				break;
			}
			case 3:
			{
				traversal();
				break;
			}
			case 4:
				exit(0);
		}
	}

}