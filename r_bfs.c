#include<stdio.h>
#include<stdlib.h>
int **a,*v,*l,n;
void bfs()
{
	int i,j,f=1;
	for(i=0;i<n;i++)
	{
		if(l[i]==1)
		{
			printf("%d\t",i);
			for(j=0;j<n;j++)
				if(a[i][j]==1 && v[j]==0)
				{
					l[j]=2;
					v[j]=1;
					f=0;
				}
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		if(l[i]==1)
			l[i]=0;
		if(l[i]==2)
			l[i]=1;
	}
	if(f==0)
		bfs();
	else
		for(i=0;i<n;i++)
			if(l[i]==1)
				printf("%d\t",i);
}

int main()
{
int i,j,f=1;
printf("\nEnter the number of nodes :");
scanf("%d",&n);
v=(int *)malloc(n*(sizeof(int)));
for(i=0;i<n;i++)
	v[i]=0;

a=(int **)malloc(n*(sizeof(int *)));
for(i=0;i<n;i++)
	a[i]=(int *)malloc(n*(sizeof(int)));
printf("\nEnter the adjacency matrix :\n\n");
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
printf("\nAll the nodes, which are reachable from the first node, are :\n");
l=(int *)malloc(n*(sizeof(int)));
l[0]=1;
for(i=1;i<n;i++)
	l[i]=0;
v[0]=1;
bfs();

for(i=0;i<n;i++)
	if(v[i]==0)
	{
		printf("\n\nThe graph is not connected.\nThe above nodes form one connected component.\nThe other components are :\n");
		f=0;
		break;
	}
if(f==1)
	printf("\nThe graph is connected.\n");

while(f==0)
{
	f=1;
	for(j=0;j<n;j++)
	{
		if(j==i)
			l[j]=1;
		else
			l[j]=0;
	}
	printf("\nComponent :\n");
	v[i]=1;
	bfs();
	for(i=0;i<n;i++)
		if(v[i]==0)
		{
			f=0;
			break;
		}
}

}
