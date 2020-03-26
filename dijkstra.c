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
	int i,u,v,s,sum=0,f=1,*a,l,j,c,m,g,node;
	printf("Enter the number of nodes :");
	scanf("%d",&n);
	d=(int *)malloc(n*sizeof(int));
	p=(int *)malloc(n*sizeof(int));
	a=(int *)malloc(n*sizeof(int));
	w=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		w[i]=(int *)malloc(n*sizeof(int));
	printf("Enter the adjacency matrix with (only positive) weight (0 for no edge) :");
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
		a[i]=i;
	}
	d[s]=0;



		l=n-1;
		for(j=n-1;j>=0;j--)
		{
			i=(j-1)/2;
			c=0;
			if((2*i+1)<=l)
			{
				if((2*i+2)<=l && d[a[2*i+1]]>d[a[2*i+2]])
					m=2*i+2;
				else
					m=2*i+1;
				if(d[a[m]]<d[a[i]] && m<=l)
				{
					g=a[m];
					a[m]=a[i];
					a[i]=g;
					c=1;	
				}
			}
			i=m;
			while(i<=(n/2-1) && c==1)
			{
				c=0;
				if((2*i+1)<=l)
				{
					if((2*i+2)<=l && d[a[2*i+1]]>d[a[2*i+2]])
						m=2*i+2;
					else
						m=2*i+1;
					if(d[a[m]]<d[a[i]] && m<=l)
					{
						g=a[m];
						a[m]=a[i];
						a[i]=g;
						c=1;
					}
				}
				i=m;	
			}
		}
		for(v=0;v<n;v++)
			if(w[a[0]][v]!=0)
				relax(a[0],v);
		g=a[n-1];
		a[n-1]=a[0];
		a[0]=g;
		for(i=n-2;i>0;i--)
		{
			l=i;
			node=0;
			while(node<=(l-1)/2)
			{
				if((2*node+2)<=l && d[a[2*node+1]]>d[a[2*node+2]])
					m=2*node+2;
				else
					m=2*node+1;
				if(d[a[m]]<d[a[node]])
				{
					g=a[m];
					a[m]=a[node];
					a[node]=g;
					node=m;
				}
				else
					break;
			}
			for(v=0;v<n;v++)
				if(w[a[0]][v]!=0)
					relax(a[0],v);

			g=a[i];
			a[i]=a[0];
			a[0]=g	;
		}
		for(v=0;v<n;v++)
			if(w[a[0]][v]!=0)
				relax(a[0],v);

		printf("\nThe costs are :\n");
		for(i=0;i<n;i++)
			printf("%d  ",d[i]);
		printf("\nThe parents are :\n");
		for(i=0;i<n;i++)
			printf("%d  ",p[i]);
		printf("\n");

}
