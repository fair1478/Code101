#include<stdio.h>
int P[1000];
main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&P[i]);

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(P[j]<P[i])
            {
                int l=P[j];
                P[j]=P[i];
                P[i]=l;
            }
        }
    }

    
        printf("%d\n%d",P[0],P[n-1]);

}
