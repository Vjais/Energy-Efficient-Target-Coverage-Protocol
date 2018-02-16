#include<stdio.h>
#include<conio.h>
#include<math.h>
#define Rand_Max 1;

int main()
{ 
int x[100],y[100],a[100],b[100];
int i,j,k,T,S,t,u,m,n,p,q,X=0,Y=0,v=0,w=0;
float d[100][100],tr[100][100],cov[100][100],P[100][100],Q[100][100];
float temp=0;
int s[100],tar[100],aset[100],targets[100];

printf("Enter the number of nodes:\n");
scanf("%d",&S);

printf("Enter the number of targets:\n");
scanf("%d",&T);

printf("\n");

for(i=0;i<S;i++)
	s[i]=i;
	
for(j=0;j<T;j++)
	tar[j]=j;

for(i=0;i<S;i++)
{
x[i]=rand()%50+1;	
y[i]=rand()%50+1;
printf("The coordinates of node %d is:(%d,%d)\n",i,x[i],y[i]);
}

for(j=0;j<T;j++)
{
	a[j]=rand()%50+1;
	b[j]=rand()%50+1;
	printf("The coordinates of target %d is:(%d,%d)\n",j,a[j],b[j]);
}
for(i=0;i<S;i++)
{
	for(j=0;j<T;j++)
	{
		t=x[i]-a[j];
		m=t*t;
		u=y[i]-b[j];
		n=u*u;
		d[i][j]=(sqrt(m+n));
	printf("Distance between the node %d and the target %d is %.2f\n",i,j,fabs(d[i][j]));
if(d[i][j]<35)
cov[i][j]=1;
else if(15<d[i][j]&&d[i][j]<35)
cov[i][j]=0.7;
else if(d[i][j]>15)
cov[i][j]=0;
continue;
}
}

printf("The distance matrix is:\n");
for(i=0;i<S;i++)
{
	for(j=0;j<T;j++)
	printf("%.2f\t",d[i][j]);
	}
printf("\n");

printf("The coverage matrix w. r.t distance is as follows:\n");
printf("\n");
for(i=0;i<S;i++)
{
	
for(j=0;j<T;j++)
printf("%.2f\t",cov[i][j]);
}
printf("\n");

for(i=0;i<S;i++)
{
	for(j=0;j<T;j++)
	tr[i][j]=(float)((rand()%10)*0.1);
}
printf("\n");
printf("The trust matrix is as follows:\n");
printf("\n");
for(i=0;i<S;i++)
{
	
	for(j=0;j<T;j++)
    printf("%.2f\t",tr[i][j]);
}

for(i=0;i<S;i++)
{
	for(j=0;j<T;j++)
	P[i][j]=cov[i][j]*tr[i][j];
}

printf("\n");
printf("The probabilty matrix of coverage is:\n");
printf("\n");

for(i=0;i<S;i++)
{
for(j=0;j<T;j++)
	printf("%.2f\t",P[i][j]);
	
}

for(i=0;i<S;i++)
{
for(j=0;j<T;j++)
	Q[i][j]=P[i][j];
}

for(i=0;i<S;i++)
{
	for(j=0;j<T;j++)
	{
		for(p=0;p<S;p++)
		{
			for(q=0;q<T;q++)
			{
				if(Q[i][j]>Q[p][q])
				{
				    temp=Q[p][q];
					Q[p][q]=Q[i][j];
					Q[i][j]=temp;
				}
                }

			}
	
		}
}

				
printf("\n");
printf("The sorted array is:\n");
printf("\n");
for(i=0;i<S;i++)
{
	for(j=0;j<T;j++)
		printf("%.2f\t",Q[i][j]);
}

getch();
}

