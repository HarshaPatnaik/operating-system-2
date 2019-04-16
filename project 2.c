#include<stdio.h>
#include<conio.h>
int main()
{
    int i,n,j=0,k=0,x=0,l,req[50],mov=0,cp,ub,end,pv, lower[100],upper[100], temp,a[100];
    printf("Enter total number of cylinders present \n");    
    scanf("%d",&ub);
	printf("Enter the current position\n");
    scanf("%d",&cp);
    printf("Enter the previous position\n");
    scanf("%d",&pv);
    printf("Enter the number of elements in the queue\n");
    scanf("%d",&n);
    printf("Enter the request queue\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    
    
    for(i=0;i<n;i++)
    {
        if(req[i]<cp)
        {
            lower[j]=req[i];
            j++;
        }
        if(req[i]>cp)
        {
            upper[k]=req[i];
            k++;
        }
    }
    
   
    for(i=0;i<j;i++)
    {
        for(l=0;l<j-1;l++)
        {
            if(lower[l]<lower[l+1])
            {
                temp=lower[l];
                lower[l]=lower[l+1];
                lower[l+1]=temp;
            }
        }
    }
    
   
    for(i=0;i<=k;i++)
    {
        for(l=0;l<k-1;l++)
        {
            if(upper[l]>upper[l+1])
            {
                temp=upper[l];
                upper[l]=upper[l+1];
                upper[l+1]=temp;
            }
        }
    }
        
    printf("Enter the end to which the head should move \n 0 - towards lower end of cylinder \n 1 - towards upper end of cylinder \n");
    scanf("%d",&end);
    switch(end)
    {
        case 0:
            for(i=0;i<j;i++)
            {        
                a[x]=lower[i];    
                x++;            
            }
            a[x]=0; 
            x++;
            for(i=0;i<k;i++)
            {        
                a[x]=upper[i];
                x++;                
            }
        break;
        case 1:
            for(i=0;i<k;i++)
            {        
                a[x]=upper[i];    
                x++;            
            }
            a[x]=ub; 
            x++;
            for(i=0;i<j;i++)
            {        
                a[x]=lower[i];
                x++;                
            }
	    break;
    }
    printf("\nDisk scheduled queue:\n");
    mov=mov+abs(cp-a[0]);
    printf("%d , %d",cp,a[0]);
    for(i=1;i<x;i++)
    {
        mov=mov+abs(a[i]-a[i-1]);
        printf(" , %d",a[i]);
    }
    printf("\n");
    printf("total distance covered = %d\n",mov);
}

