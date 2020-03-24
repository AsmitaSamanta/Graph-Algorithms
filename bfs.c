#include<stdio.h>
#include<stdlib.h>
struct link
{
int x;
struct link *next;
};
typedef struct link node;
int main()
{
int **a,*v,i,j,n,f=1;
node *in,*out,*new;
in=NULL;
out=NULL;
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
new=(node *)malloc(1*(sizeof(node)));
new->x=i;
new->next=NULL;
in=new;
out=new;
v[i]=1;
printf("\nAll the nodes, which are reachable from the first node, are :\n");
while(out!=NULL)
{
i=out->x;
for(j=0;j<n;j++)
	if(a[i][j]==1 && v[j]==0)
	{
		new=(node *)malloc(1*(sizeof(node)));
		new->x=j;
		new->next=NULL;
		in->next=new;
		in=new;
		v[j]=1;
		//printf("j%d\t",j);
	}
printf("%d\t",out->x);
out=out->next;
}
for(i=0;i<n;i++)
	if(v[i]==0)
	{
		printf("\nThe graph is not connected.\n");
		f=0;
		break;
	}
if(f==1)
	printf("\nThe graph is connected.\n");
}
