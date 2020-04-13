#include<iostream.h>
#include<conio.h>
int LOC=0;
void Quick(int a[],int N,int BEG,int END)
{
	int LEFT,RIGHT,temp;
	LEFT=BEG;
	RIGHT=END;
	LOC=BEG;
	while(1)
	{
	    while(a[LOC]<=a[RIGHT] && LOC!=RIGHT)
			RIGHT--;
	    if(LOC==RIGHT)
		return;
	    if(a[LOC]>a[RIGHT])
	    {
		temp=a[LOC];
		a[LOC]=a[RIGHT];
		a[RIGHT]=temp;
		LOC=RIGHT;
	    }
	    while(a[LOC]>=a[LEFT] && LOC != LEFT)
		LEFT++;
	    if(LOC==LEFT)
		return;
	    if(a[LEFT]>a[LOC])
	    {
		temp=a[LEFT];
		a[LEFT]=a[RIGHT];
		a[RIGHT]=temp;
		LOC=LEFT;
	    }
	}

}


void quickSort(int A[],int SIZE)
{
    int Lstack[10],Ustack[10],top=-1,beg,last;
	if(SIZE>1)
	{
		top++;
		Lstack[top]=0;
		Ustack[top]=SIZE-1;
	}
	while(top!=-1)
	{
		beg=Lstack[top];
		last=Ustack[top];
		top--;
		Quick(A,SIZE,beg,last);
		if(beg<LOC-1)
		{
			top++;
			Lstack[top]=beg;
			Ustack[top]=LOC-1;
		}
		if(LOC+1<last)
		{
			top++;
			Lstack[top]=LOC+1;
			Ustack[top]=last;
		}
	}

}



int main()
{
	int ar[50],n,i;
	clrscr();
	cout<<"\nHow many elements you want to enter::";
	cin>>n;
	for(i=0;i<n;i++)
	cin>>ar[i];
    quickSort(ar,n);
	cout<<"\nOUTPUT::";
	for(i=0;i<n;i++)
		cout<<ar[i]<<"\t";
	getch();
	return 0;
}



