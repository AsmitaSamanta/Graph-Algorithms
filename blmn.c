#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,*d,*p,**w;
void relax(int u,int v)
{
	if(d[v]>d[u]+w[u][v])
	{
		d[v]=d[u]+w[u][v];
		p[v]=u;
	}	
}

int main()
{
	int i,u,v,s,sum=0,f=1;
	printf("Enter the number of nodes :");
	scanf("%d",&n);
	d=(int *)malloc(n*sizeof(int));
	p=(int *)malloc(n*sizeof(int));
	w=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		w[i]=(int *)malloc(n*sizeof(int));
	printf("Enter the adjacency matrix with weight (0 for no edge) :");
	for(u=0;u<n;u++)
		for(v=0;v<n;v++)
		{
			scanf("%d",&w[u][v]);
			sum=sum+abs(w[u][v]);
		}
	printf("Enter the source node :");
	scanf("%d",&s);
	for(i=0;i<n;i++)
	{
		d[i]=sum+5;
		p[i]=-1;
	}
	d[s]=0;
	for(i=1;i<n;i++)
		for(u=0;u<n;u++)
			for(v=0;v<n;v++)
				if(w[u][v]!=0)
					relax(u,v);
	for(u=0;u<n;u++)
	{
		for(v=0;v<n;v++)
			if(w[u][v]!=0)
				if(d[v]>d[u]+w[u][v])
				{
					printf("There is a negative cycle in the graph.\n");
					f=0;
					break;
				}
		if(f==0)
			break;
	}
	if(f==1)
	{
		printf("\nThe costs are :\n");
		for(i=0;i<n;i++)
			printf("%d  ",d[i]);
		printf("\nThe parents are :\n");
		for(i=0;i<n;i++)
			printf("%d  ",p[i]);
		printf("\n");
	}
}
