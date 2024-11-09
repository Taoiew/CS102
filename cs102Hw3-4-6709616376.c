#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    
    int i=0;
    float num[n];
    float *numPtr=num;
    float sum=0,avg=0;
    for(i=1;i<=n;i++)
    {
        scanf("%f",&*(numPtr+i));
        sum=sum+*(numPtr+i);
    }
    
    int j=0,maxid,minid;
    float max=0,min=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(*(numPtr+i)>*(numPtr+j))
            {
                if(*(numPtr+i)>max)
                {
                max=*(numPtr+i);
                maxid=i;
                }
            }else 
            {
                if(*(numPtr+j)>max)
                {
                max=*(numPtr+j); 
                maxid=j;
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(*(numPtr+i)<*(numPtr+j))
            {
                if(*(numPtr+i)<min)
                {
                min=*(numPtr+i);
                minid=i;
                }
            }else 
            { 
                if(*(numPtr+j)<min)
                {
                min=*(numPtr+j); 
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
        printf(" %.2f ",*(numPtr+i));
    }
    
    float aboveavg[n];
    float *aboveavgPtr=aboveavg;
    j=0;
    for(i=1;i<=n;i++)
    {
        if(*(numPtr+i)>avg)
        {
            j=j+1;
            *(aboveavgPtr+j)=*(numPtr+i);
        }
    }
    printf("\nAbove average list: ");
    while(j>0)
    {
        printf("%.2f ",*(aboveavgPtr+j));
        j=j-1;
    }
    
    float negative[n];
    float *negativePtr=negative;
    j=0;
    for(i=1;i<=n;i++)
    {
        if(*(numPtr+i)<0)
        {
            j=j+1;
            *(negativePtr+j)=*(numPtr+i);
        }
    }
    printf("\nNegative coordinates: ");
    if(j>1)
    {
        while(j>0)
    {
        for(i=1;i<=j;i++)
        {
            if(*(negativePtr+j)!=*(negativePtr+i))
            {
                printf("(%.2f, %.2f), ",*(negativePtr+j),*(negativePtr+i));
            }
        }
        j=j-1;
    }
    }
    

    return 0;
}