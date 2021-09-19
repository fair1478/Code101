#include<stdio.h>
int A[100][100],B[50],C[50],D,E;
main(){
	
	int n,i,j,t=0,count;
	//rubkanhad
	scanf("%d",&n);
	//rub4edge
	for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }

	//+non			
	for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            B[i]=B[i]+A[i][j];
        }
    }
    
    //+tung
	for(j=1;j<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            C[j]=C[j]+A[i][j];
        }
    }
    
    //tayangRight
    for(i=1,j=1;i<=n;i++,j++)
    	{
    		D=D+A[i][j];
		}
	
	//tayangLeft	
	for(i=1,j=n;i<=n;i++,j--)
			{
				E=E+A[i][j];	
			}
			
	do
	{
		//check non = 34?
		for(i=1;i<=n;i++)
			if(B[i]!=B[1])
    		{
				t=1;
			}
		
		//check tung = 34?
	  	for(i=1;i<=n;i++)
			if(C[i]!=B[1])
    		{
				t=1;
			}
		//check tayangRight
		if(D!=B[1])
			t=1;
		//check tayangLeft
		if(E!=B[1])
			t=1;
				
		count=1;
		
	}while(t==0&&count==0);
	
	//check Yes or No
	if(t)
		printf("No");
	else
		printf("Yes");
}
	
