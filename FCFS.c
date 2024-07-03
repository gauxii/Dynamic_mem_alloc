#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct process
{
    char pname[20];
    int at,bt,tt,wt,status;
}p[20],temp;
struct ghant
{
    char name[20];
    int st,ct;
}g[20];
void main()
{
    int n,i,k=0,j;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    while(k<n)
    {
        printf("Enter the process name\n");
        scanf(" %s",p[k].pname);
        printf("Enter the arrival time\n");
        scanf("%d",&p[k].at);
        printf("Enter the burst time\n");
        scanf("%d",&p[k].bt);
        p[k].status=0;
        k++;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    int idle=0,num=0;
    i=0;
    for(k=0;k<n;)
    {
        if(p[k].at<=i&&p[k].status==0)
        {
            if(idle==1)
            {
                g[num].ct=i;
                num++;
            }
            strcpy(g[num].name,p[k].pname);
            g[num].st=i;
            g[num].ct=i+p[k].bt;
            p[k].tt=g[num].ct-p[k].at;
            p[k].wt=p[k].tt-p[k].bt;
            i=g[num].ct;
            p[k].status=1;
            k++;
            num++;
            idle=0;
        }
        else if(idle==0)
        {
            strcpy(g[num].name,"idle");
            g[num].st=i;
            i++;
            idle=1;
        }
        else
        {
            i++;
        }
    }
    printf("\nProcess name\t\t\tarrival time\t\t\tburst time\t\t\tcompletion time\t\t\tturnaround time\t\t\twaiting time\t\t\t\n");
    for(i=0,num=0;i<n;i++,num++)
    {
        printf("\n%s\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t\t\n",p[i].pname,p[i].at,p[i].bt,g[num].ct,p[i].tt,p[i].wt);
    }
    for(i=0;i<n;i++)
    {
        printf("______________");
    }
    printf("\n|");
    for(i=0;i<num;i++)
    {
        printf("%s\t",g[i].name);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("_______________");
    }
    printf("|\n");
    printf("%d\t",g[0].st);
    for(i=0;i<num;i++)
    {
        printf("%d\t",g[i].ct);
    }
    float sumtt=0,sumwt=0,avgtt,avgwt;
    for(i=0;i<n;i++)
    {
        sumtt=sumtt+p[i].tt;
        sumwt=sumwt+p[i].wt;
    }
    avgtt=(float)(sumtt/n);
    avgwt=(float)(sumwt/n);
    printf("The average turnaround time is %f\n",avgtt);
    printf("The average waiting time is %f\n",avgwt);
}