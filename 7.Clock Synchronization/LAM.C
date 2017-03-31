#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct proc
{
  int procid,tslice,send,recive,sttime,rectime,flag;
}p[10];

void main()
{
   int i,n,ch,loop;
   clrscr();
   printf("\n enter no of processes:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
     printf("\nenter time slice for procid %d\t",i);
     scanf("%d",&p[i].tslice);
     p[i].procid=i;
   }
   printf("\n process id \t time slice");
   for(i=0;i<n;i++)
   {
     printf("\n%d\t  %d",p[i].procid,p[i].tslice);
   }
   ch=1;
   i=0;
   do
   {
   printf("\n enter sending process id:");
   scanf("%d",&p[i].send);
   printf("\n enter reciving process id:");
   scanf("%d",&p[i].recive);
   printf("\nEnter Event Start time:");
   scanf("%d",&p[i].sttime);
p[i].rectime=(((p[i].sttime/p[p[i].send].tslice)+1)*(p[p[i].recive].tslice));
   printf("\n want to continue:");
   scanf("%d",&ch);
   loop=i;
   i++;
   }while(ch!=0);
   printf("\nSender\tReceive\tStart time\tReceive Time");
   for(i=0;i<=loop;i++)
   {
 printf("\n%d\t%d\t%d\t\t%d",p[i].send,p[i].recive,p[i].sttime,p[i].rectime);
      p[i].flag=0;
   }

   printf("\n\nFinding Problematic Conditions:");
   printf("\nSender\tReceive\tStart time\tReceive Time");
   for(i=0;i<=loop;i++)
   {
	if(p[i].rectime<p[i].sttime)
	{
	   p[i].flag=1;
printf("\n%d\t%d\t%d\t\t%d",p[i].send,p[i].recive,p[i].sttime,p[i].rectime);
	}
   }
   printf("\n\nAfter Applying Lamport Algorithm.");
   for(i=0;i<=loop;i++)
   {
      if(p[i].flag==1)
       {
	  while(p[i].rectime<p[i].sttime)
	   {
	     p[i].rectime=p[i].rectime+p[p[i].recive].tslice;
	   }
printf("\n%d\t%d\t%d\t\t%d",p[i].send,p[i].recive,p[i].sttime,p[i].rectime);
printf("*");
	 }
	else
	 {
printf("\n%d\t%d\t%d\t\t%d",p[i].send,p[i].recive,p[i].sttime,p[i].rectime);
	 }
  }
getch();
}
