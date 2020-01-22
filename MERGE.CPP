#include<iostream.h>
#include<conio.h>
void main()
{
	int a[20],b[20],c[40],m,n,i,j,k,t,index;
	clrscr();
	cout<<"\nEnter the size of first array::";
	cin>>m;
	cout<<"\nEnter the elements of 1st array::\n";
	for(i=0;i<m;++i)
		cin>>a[i];
	cout<<"\nEnter the size of second array::";
	cin>>n;
	cout<<"\nEnter the elements of 2nd array::\n";
	for(j=0;j<n;++j)
		cin>>b[j];
	i=j=k=0;
	while(i<m && j<n)
	{
		if(a[i]<=b[j])
		{
			c[k]=a[i];
			i++;
		}
		else
		{
			c[k]=b[j];
			j++;
		}
		k++;
	}
	if(i>=m)
	{
		while(j<n)
		{
			c[k]=b[j];
			j++;
			k++;
		}
	 }

	if(i<m)
	{
		while(j>=n)
		{

		c[k]=a[i];
		i++;
		k++;
		}

	}
	cout<<"\nMerge sort successfull......\n";
	t=m+n;
	for(i=0;i<t;++i)
	{
		cout<<c[i]<<"\t";
	}

	cout<<"\nEnter the index you want to delete::";
	cin>>index;
	if(index<t && index>=0)
	{

		while(index<t)
		{
			c[index]=c[index+1];
			index++;
		}
		t--;
		cout<<"\nDeleted succesfully.......\n";

	}
	else
	cout<<"\nIndex out of bound!!!!!!!!\n";
	for(i=0;i<t;++i)
		cout<<c[i]<<"\t";
	getch();
}

