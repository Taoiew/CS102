#include <stdio.h>

int main() {
   int n;
   scanf("%d",&n);
   int num[n*n];
   int sum[n*n];
   
   int i,j;
   for(i=1;i<=n;i++)
   {
       for(j=n-1;j>=0;j--)
       {
           scanf("%d",&num[(n*i)-j]);
       }
   }
   //for(i=1;i<=n*n;i++){printf("%d\n",num[i]);}
   
   for(i=1;i<=n*n;i++)
   {
       for(j=i+1;j<=n*n;j++)
       {
           if(num[i]!=num[j])
           {
               
           }
           else 
           {
               printf("This is NOT magic square!");
               return 0;
           }
       }
   }
   
   int k,r;
   for(i=1;i<=n+n+2;i++)
   {
       sum[i]=0;
       if(i<=n)
       {
           for(j=1;j<=n*i;j++)
       {
           sum[i]=sum[i]+num[j];
       }
       }
       else if(i<=n+n)
       {
               r=i%n;
               for(k=1;k<=n*n;k++)
               {
                   if(k%n==r)
                   {
                       sum[i]=sum[i]+num[k];
                   }
               }
       }
       else if(i<=n+n+2)
       {
           for(j=1;j<=n*n;j=j+n)
           {
               sum[i]=sum[i]+num[j];
           }
       }
   }
   
   for(i=n;i>1;i--)
   {
       sum[i]=sum[i]-sum[i-1];
   }
    
    j=0;
    int sumre[n+n+2];
    for(i=n;i>0;i--)
    {
        j=j+1;
        sumre[j]=sum[i];
    }

   
   int p=0;
    for(i=0;i<n;i++)
    {
        if(sum[i]==sumre[i])
        {
            p=p+1;
        }
    }
    if(p==n)
    {
        printf("This is magic square!");
    }else { printf("This is NOT magic suare!");}

   
    return 0;
}