#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

void check_unique(int a[][2],int n)
{
int i;
for(i=0;i<n;i++)
	{
	if(a[i][0]==a[n][0] && a[i][1]==a[n][1])
		{
		a[n][0]=1+rand()%10;
		a[n][1]=1+rand()%10;
		check_unique(a,n);
		}
	}
}

void generate_pair(int a[10][2])
{
int i,j;
for(i=0;i<10;i++)
	{
	for(j=0;j<2;j++)
		{
		a[i][j]=1+rand()%10;
		}
	check_unique(a,i);
	}
}

void similarity(int a[][2],float b[][2], float c[][2])
{
int j,i=0,m=1,n=1;
float s,p,d1,d2;
for(i=0;i<10;i++)
	{
	if(a[i][0]==b[0][0] && a[i][1]==b[0][1])
		continue;
	if(a[i][0]==c[0][0] && a[i][1]==c[0][1])
		continue;
	s=b[0][0]-a[i][0];
	s=s*s;
	p=b[0][1]-a[i][1];
	p=p*p;
	s=s+p;
	d1=sqrt(s);
	s=c[0][0]-a[i][0];
	s=s*s;
	p=c[0][1]-a[i][1];
	p=p*p;
	s=s+p;
	d2=sqrt(s);
	if(d1<d2)
		{
		b[m][0]=a[i][0];
		b[m][1]=a[i][1];
		m++;
		}
	else
		{
		c[n][0]=a[i][0];
		c[n][1]=a[i][1];
		n++;
		}
	}
b[m][0]=999;
c[n][0]=999;
printf("\n\nthe classes are-\n");
for(i=0;i<m;i++)
	{
	for(j=0;j<2;j++)
		printf("%f ",b[i][j]);
	printf("\n");
	}
printf("\n");
for(i=0;i<n;i++)
	{
	for(j=0;j<2;j++)
		printf("%f ",c[i][j]);
	printf("\n");
	}
}

int avg(float b[][2])
{
int i=0;
float x=0,y=0;
while(b[i][0]!=999)
	{
	x=x+b[i][0];
	y=y+b[i][1];
	i++;
	}
x=x/i;
y=y/i;
if(fabs(x-b[0][0])<0.05 && fabs(y-b[0][1])<0.05)
	{
	b[0][0]=x;
	b[0][1]=y;
	return(1);
	}
else
	{
	b[0][0]=x;
	b[0][1]=y;
	return(0);
	}
}

int main()
{
int i,m,s,t,a[10][2],j,w=1;
float x=0,y=0,b[12][2],c[12][2];
clrscr();
srand(time(0));
generate_pair(a);
printf("the coordinates are -\n");
for(i=0;i<10;i++)
	{
	for(j=0;j<2;j++)
		printf("%d ",a[i][j]);
	printf("\n");
	}
s=rand()%10;
t=rand()%10;
while(s==t)
	s=rand()%10;
printf("\nrandom pair -\n%d %d\n%d %d",a[s][0],a[s][1],a[t][0],a[t][1]);
b[0][0]=a[s][0];b[0][1]=a[s][1];
c[0][0]=a[t][0];c[0][1]=a[t][1];
while(w)
	{
	similarity(a,b,c);
	s=avg(b);
	t=avg(c);
	if(s==1 && t==1)
		{
		printf("\nMinimum threshold found after %d th iteration",w);
		break;
		}
	w++;
	}
getch();
return(0);
}