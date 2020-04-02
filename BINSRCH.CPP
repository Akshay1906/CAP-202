#include<iostream.h>
#include<conio.h>
void main()
{
	int a[10],n,value,beg,mid,end,i;
	clrscr();
	cout<<"\nHow many elements you want to enter::";
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	cout<<"\nEnter the value to search::";
	cin>>value;
	beg=0;
	end=n-1;
	mid=(beg+end)/2;
	while(beg<=end)
	{
		if(a[mid]<value)
			beg=mid+1;
		else if(a[mid]==value)
		{
			cout<<"\nItem found at location "<<mid+1;
			break;
		}
		else
			end=mid-1;
		mid=(beg+end)/2;

	}
	if(beg>end)
		cout<<"\nItem not found...........";
	getch();

}