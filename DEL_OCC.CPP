#include<iostream.h>
#include<conio.h>
void main()
{
	int a[20],i,n,j,k;
	clrscr();
	cout<<"\nHow many elements you want to store::";
	cin>>n;
	cout<<"\nEnter elements::";
	for(i=0;i<n;++i)
		cin>>a[i];
	cout<<"\nInput array::\t";
	for(i=0;i<n;++i)
	{
		cout<<a[i]<<"\t";
	}
	for(i=0;i<n;++i)
	{
		for(j=i+1;j<n;++j)
		{
			if(a[i]==a[j])
			{
				a[j]=a[j+1];
				for(k=j;k<n;++k)
				{
				   a[k]=a[k+1];
				}
				n--;
				j--;
			}

	       }
	}
	cout<<"\nOutput array::\t";
	for(i=0;i<n;++i)
	{
		cout<<a[i]<<"\t";
	 }
	 getch();
}