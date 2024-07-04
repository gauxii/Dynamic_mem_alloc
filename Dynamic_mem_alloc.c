#include <stdio.h>
#include <stdlib.h>
int *partitions;
int *partition_allocated;
int *requests;
int num_partitions;
int num_requests;
void first()
{
    printf("First Fit\n");
    for(int i=0;i<num_requests;i++)
    {
        int request=requests[i];
        int j;
        for(j=0;j<num_partitions;j++)
        {
            if(!partition_allocated[j]&&partitions[j]>=request)
            {
                printf("\nAllocate %d to %d\n",request,j+1);
                partitions[j]=partitions[j]-request;
                partition_allocated[j]=1;
                printf("Current partitions\n");
                for(int k=0;k<num_partitions;k++)
                {
                    printf("%d\t",partitions[k]);
                }
                break;
            }
        }
        if(j==num_partitions)
        {
            printf("\nRequest not allocated\n");
        }
    }
}
void worst()
{
    printf("Worst Fit\n");
    for(int i=0;i<num_requests;i++)
    {
        int request=requests[i];
        int max=-1,j;
        for(j=0;j<num_partitions;j++)
        {
            if(!partition_allocated[j]&&partitions[j]>=request&&(max==-1||partitions[j]>partitions[max]))
            {
                max=j;
            }
        }
            if(max!=-1)
            {
                printf("Allocate %d to %d",request,max+1);
                partitions[max]=partitions[max]-request;
                partition_allocated[max]=1;
                printf("Current partitions\n");
                for(int k=0;k<num_partitions;k++)
                {
                    printf("%d\t",partitions[k]);
                    printf("\n");
                }
            }
            else
            {
                printf("\nRequest %d cannot be allocated\n",request);
            }
    }
}
void best()
{
    printf("Best Fit");
    for(int i=0;i<num_requests;i++)
    {
        int request=requests[i];
        int min=-1,j=0;
        for(j=0;j<num_partitions;j++)
        {
            if(!partition_allocated[j]&&partitions[j]>=request&&(min==-1||partitions[j]<partitions[min]))
            {
                min=j;
            }
        }
        if(min!=-1)
        {
            printf("\nAllocate %d to %d\n",request,min+1);
            partitions[min]=partitions[min]-request;
            partition_allocated[min]=1;
            printf("Current partitions\n");
            for(int k=0;k<num_partitions;k++)
            {
                printf("%d\t",partitions[k]);
            }
        }
        else
        {
            printf("Request %d cannot be alloacted\n",request);
        }
    }
}
void main()
{
    int ch;
    do
    {
        printf("1.First Fit\n2.Worst Fit\n3.Best Fit\nSELECT\n");
        scanf("%d",&ch);
        printf("Enter the number of partitions\n");
        scanf("%d",&num_partitions);
        partitions=(int*)malloc(num_partitions*sizeof(int));
        partition_allocated=(int*)malloc(num_partitions*sizeof(int));
        printf("Enter the partitions\n");
        for(int i=0;i<num_partitions;i++)
        {
            scanf("%d",&partitions[i]);
            partition_allocated[i]=0;
        }
        printf("aaaaa");
        printf("Enter the number of requests\n");
        scanf("%d",&num_requests);
        requests=(int*)malloc(num_requests*sizeof(int));
        printf("Enter the requests\n");
        for(int i=0;i<num_requests;i++)
        {
            scanf("%d",&requests[i]);
        }
        switch(ch)
        {
            case 1:first();
            break;
            case 2:worst();
            break;
            case 3:best();
            break;
            default:printf("INVALID\n");
            break;
        }
    } while (ch<=3);
    
}