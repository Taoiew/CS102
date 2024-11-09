#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    
    int i=0;
    float num[n];
    float sum=0,avg=0;
    for(i=1;i<=n;i++)
    {
        scanf("%f",&num[i]);
        sum=sum+num[i];
    }
    
    int j=0,maxid,minid;
    float max=0,min=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(num[i]>num[j])
            {
                if(num[i]>max)
                {
                max=num[i];
                maxid=i;
                }
            }else 
            {
                if(num[j]>max)
                {
                max=num[j]; 
                maxid=j;
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(num[i]<num[j])
            {
                if(num[i]<min)
                {
                min=num[i];
                minid=i;
                }
            }else 
            { 
                if(num[j]<min)
                {
                min=num[j]; 
                minid=j;
                }
            }
        }
    }
    printf("Maximum value: %.2f",max);
    printf("\nMinimum value: %.2f",min);
    printf("\nMaxinum index: %d",maxid-1);
    printf("\nMininum index: %d",minid-1);
    avg=sum/n;
    printf("\nAverage = %.2f",avg);
    
    printf("\nReverse order:");
    for(i=n;i>0;i--)
    {
        printf(" %.2f ",num[i]);
    }
    
    float aboveavg[n];
    j=0;
    for(i=1;i<=n;i++)
    {
        if(num[i]>avg)
        {
            j=j+1;
            aboveavg[j]=num[i];
        }
    }
    printf("\nAbove average list: ");
    while(j>0)
    {
        printf("%.2f ",aboveavg[j]);
        j=j-1;
    }
    
    float negative[n];
    j=0;
    for(i=1;i<=n;i++)
    {
        if(num[i]<0)
        {
            j=j+1;
            negative[j]=num[i];
        }
    }
    printf("\nNegative coordinates: ");
    if(j>1)
    {
        while(j>0)
    {
        for(i=1;i<=j;i++)
        {
            if(negative[j]!=negative[i])
            {
                printf("(%.2f, %.2f), ",negative[j],negative[i]);
            }
        }
        j=j-1;
    }
    }
    

    return 0;
}