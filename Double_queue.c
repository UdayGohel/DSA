#include<stdio.h>
int r=-1, f=-1, size=5;
int deq[5];

int infront(int x)
{
	if((r==size-1 && f==0) || f == r+1)
	{
		printf("Queue is full!!");
		return 0;
	}
	else
	{
		if(f==-1)
		{
			r=0;
			f=0;
		}
		else
		{
			if(f==0)
				f=size-1;
			else
				f=f-1;
		}
	}
	deq[f]=x;
}

int inrear(int y)
{
	if((r==size-1 && f==0) || f==r+1)
	{
		printf("Queue is full!!");
		return 0;
	}
	else
	{
		if(f==-1)
		{
			f=0;
			r=0;
		}
		else
		{
			if(r==size-1)
				r=0;
			else
				r=r+1;
		}
	}
	deq[r]=y;
}

void defront()
{
	if(f==-1 && r==-1)
	{
		printf("Queue is empty!!");
	}
	else
	{
		if(f==r)
		{
			f=-1;
			r=-1;
		}
		else
		{
			if(f==size-1)
				f=0;
			else
				f=f+1;
		}
	}
}

void derear()
{
	if(f==-1 && r==-1)
	{
		printf("Queue is empty!!");
	}
	else
	{
		if(f==r)
		{
			f=-1;
			r=-1;
		}
		else
		{
			if(r==0)
				r=size-1;
			else
				r=r-1;
		}
	}
}