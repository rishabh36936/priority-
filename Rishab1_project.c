#include<stdio.h>
int cur_time,burst=0;
struct process
{
	int priority;
	int arr_time;
	int burst_time;
	int pid;
	int w_time;
};
int t=-1,a[30],i=-1;
struct process q[30],result[30],swap;
int number()
{
	int l;
	printf("Enter the number of processes: ");
	scanf("%d",&l);
	return l;
}
void calc()
{	
	if(t>=0)
	{	
	int w,e,r,y;
	if(burst!=0 && q[0].burst_time!=0)
	{
		q[0].burst_time--;
		burst--;
		q[0].priority++;
		q[0].arr_time=cur_time+1;

		for(w=1;w<=t;w++)
	{
		q[w].priority+=2;
		q[w].w_time=++q[w].w_time;
		
	}
	}
	
	if(q[0].burst_time==0)
	{	
		
		i++;
		result[i]=q[0];
		for(w=0;w<t;w++)
		{
			q[w]=q[w+1];
		}
		t--;
	}
	for(w=0;w<t;w++)
	{
		for(e=0;e<t;e++)
		{
			if(q[w].priority<=q[e].priority)
			{
				swap=q[w];
				q[w]=q[e];
				q[e]=swap;
			}
		}
	}
	
	if(q[0].priority<=q[1].priority && t>=1)
	{
		swap=q[0];
		for(w=0;w<t;w++)
		{
			q[w]=q[w+1];
		}
		q[t]=swap;
	}
	
	}
}
void main()
{	
	int l,min,n=number(),j,c=0;
	float avg_w_time=0;
	struct process p[n];
	for(l=0;l<n;l++)
	{
	p[l].pid=l+1;
	printf("\nEnter the arrival time of %d process: ",l+1);
	scanf("%d",&p[l].arr_time);
	printf("\nEnter the burst time of %d process: ",l+1);
	scanf("%d",&p[l].burst_time);
	p[l].priority=0;
	p[l].w_time=0;
	burst=burst+p[l].burst_time;
	}
	for(l=0;l<n;l++)
	{
	
	for(j=0;j<n;j++)
	{
	if(p[l].arr_time<p[j].arr_time)
	{
		swap=p[l];
		p[l]=p[j];
		p[j]=swap;
	}
	if(p[l].arr_time==p[j].arr_time)
	{
		if(p[l].burst_time<p[j].burst_time)
		{
		swap=p[l];
		p[l]=p[j];
		p[j]=swap;
		}
	}
	}
	
}
		printf("YOU ENTERED:\n*(TABLE IS SORTED ACCORDING TO THE ARRIVAL TIME)\n\n");
		printf("              PROCESS TABLE  \n");
		printf("----------------------------------------------\n");
		printf("  PID          ARRIVAL TIME       SERVICE TIME  \n");
		printf("----------------------------------------------\n");
	for(l=0;l<n;l++)
	{
		printf("  %d               %d                 %d\n",p[l].pid,p[l].arr_time,p[l].burst_time);
	}
	cur_time=p[0].arr_time;
	for(j=p[0].arr_time;j<=p[n-1].arr_time;j++)
	{   
		for(l=0;l<n;l++)
		{
			if(p[l].arr_time==j && c!=n)
			{	
				t++;
				q[t]=p[l];
				c++;
			}
			if(c==n)
			break;
		}
		calc();
		cur_time++;
	while(burst!=0 && c==n)
	{
		calc();
		cur_time++;
	}
	if(c==n)
		break;
	}	
		printf("\nPROCESS IN ORDER OF THEIR COMPLETION:\n\n");
		printf("                          FINAL PROCESS EXECUTION TABLE  \n\n");

		printf("  PID\t\tARRIVAL TIME\t\tCOMPLETION TIME\t\tSERVICE TIME\t\tWAITING TIME  \n\n");

	for(l=0;l<n;l++)
	{
		for(j=0;j<n;j++)
		{
		if(result[l].pid==p[j].pid)
		{
		printf("  %d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",result[l].pid,p[j].arr_time,result[l].arr_time,p[j].burst_time,result[l].w_time);
		break;
		}
	   }
	 avg_w_time+=(result[l].w_time);
	}
	printf("AVERAGE WAITING TIME: %fs\n",avg_w_time/n);
	
}

