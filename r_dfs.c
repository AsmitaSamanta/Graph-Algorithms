#include<stdio.h>
#include<stdlib.h>
int **a,*v,n;
void dfs(int i)
{
int j;
printf("%d\t",i);
for(j=0;j<n;j++)
	if(a[i][j]==1 && v[j]==0)
	{
		v[j]=1;
		//printf("%d\t",j);
		dfs(j);
	}
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
i=0;
v[i]=1;
printf("\nAll the nodes, which are reachable from the first node, are :\n");
dfs(i);
for(i=0;i<n;i++)
	if(v[i]==0)
	{
		printf("\nThe graph is not connected.\nThe above nodes form one connected component.\nThe other components are :\n");
		f=0;
		break;
	}
if(f==1)
	printf("\nThe graph is connected.\n");
while(f==0)
{
	f=1;
	printf("\nComponent :\n");
	v[i]=1;
	dfs(i);
	printf("\n");
	for(i=0;i<n;i++)
		if(v[i]==0)
		{
			f=0;
			break;
		}
}
}
