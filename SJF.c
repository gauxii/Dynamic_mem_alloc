#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct process
{
    char pname[20];
    int at,bt,tt,wt,status;
}p[20];
struct ghant
{
    char name[20];
    int st,ct;
}g[20];
void main()
{
    int n,k=0;
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
    int ls=0,idle=0,i=0,num=0;
    for(ls=0;ls<n;)
    {
        int found=0;
        for(int j=0;j<n;j++)
        {
            if(found==0&&p[j].at<=i&&p[j].status==0)
            {
                k=j;
                found++;
            }
            else if(found>0&&p[j].status==0&&p[j].at<=i)
            {
                if(p[j].bt<p[k].bt)
                {
                    k=j;
                }           
            }
        }
        if(found==0&&idle==0)
        {
            strcpy(g[num].name,"idle");
            g[num].st=i;
            i++;
            idle=1;
        }
        else if(found>0)
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
            ls++;
            num++;
            idle=0;
        }
        else
        {
            i++;
        }
    }
    printf("\nProcess name\t\t\tArrival time\t\t\tBurst time\t\t\tcompletion time\t\t\tturnaround time\t\t\twaiting time\n");
    for(i=0,num=0;i<n;i++,num++)
    {
        printf("\n%s\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\\t\t\t\t",p[i].pname,p[i].at,p[i].bt,g[num].ct,p[i].tt,p[i].wt);
    }
    for(i=0;i<n;i++)
    {
        printf("_____________");
    }
    printf("\n|");
    for(i=0;i<=num;i++)
    {
        printf("|%s",g[i].name);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
       // printf("________");
        printf("_____________");
    }
    printf("|\n");
    printf("%d\t",g[0].st);
    for(i=0;i<num;i++)
    {
        printf("%d\t",g[i].ct);
    }
    printf("%d",g[n].ct);
}