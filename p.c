#include<stdio.h>

 int main()
{
int flag=0;
int i,j,Allocate[10][10],max_need[10][10];
int Total[10],Available[10],need[10][10];

int r,p,a[10],TA[10],b=1;



printf("Enter no of resources and process\n");
scanf("%d %d",&r,&p);
printf("Enter the allocated values\n");
for(i=0;i<p;i++)
{
printf("Enter value of p %d\n",i);
for(j=0;j<r;j++)
{
printf("r%d\t",j);
scanf("%d",&Allocate[i][j]);
}
}
printf("Enter the max need values\n");
for(i=0;i<p;i++)
{
printf("Enter the values of p%d",i);
for(j=0;j<r;j++)
{
printf("r%d\t",j);
scanf("%d",&max_need [i][j]);
}
}
printf("Enter total value list\n");
for(j=0;j<r;j++)
{
printf("r%d\t",j);
scanf("%d",&Total[j]);
}
printf("Need values\n");
//need estimation
while(b==1){
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
{
need[i][j]=max_need[i][j]-Allocate[i][j];
printf("%d",need [i][j]);
}
printf("\n");
}
for(j=0;j<r;j++)
{
for(i=0;i<p;i++)
{
TA[j]+=Allocate[i][j];
}}
printf("Available is \n");
for(j=0;j<r;j++)
{
Available[j]=Total[j]-TA[j];
printf("%d\t",Available[j]);
}
for(i=0;i<3*p;i++)
{
for(j=0;j<r;j++)
{
if(need[j][i]<=Available[j])
flag++;
}
if(flag==r)
{
printf("process p %d is safe",i);
for(j=0;j<r;j++)
{
Available[j]= Allocate[j][i]+Available[j];
printf("%d\t",Available[j]);
}
printf("is new available list\n");
a[i]=1;
}
}
for (i=0;i<p;i++)
{
if(a[i]!=1)
{
printf("process p%d is unsafe\n",i);
}
printf("if you want to change request process otherways 0\n");
scanf("%d",&b);
if(b==1)
{
printf("Enter process Id which request resources :\n");
scanf("%d",&i);
for(j=0;j<r;j++)
{
printf("r%d",j);
scanf("%d",&Allocate[j][i]);
}
}//while ending
}
}
return 0;
}
