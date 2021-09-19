#include<stdio.h>
int A[100][100],B[50],C[50],D,E;
main(){
	
	int n,i,j,t=0;
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
	
	//check non with non
	for(i=1;i<=n;i++)
			if(B[i]!=B[i+1]&&i<n)
    		{
				t=1;
			}
	 
	//check non with tung,tayangRight and tanyangLeft 
	  for(i=1;i<=n;i++)
    {
        for(int l=1;l<=n;l++)
        {
            if(B[i]!=C[l])
            	t=1;
        }
    	if(B[i]!=D)
    		t=1;
    	if(B[i]!=E)
			t=1;	
	}
	//check tung with tung
		for(i=1;i<=n;i++)
			if(C[i]!=C[i+1]&&i<n)
    		{
				t=1;
			}			
	
	//check tung with tayangRight and tanyangLeft
	  for(i=1;i<=n;i++)
    {
    	if(C[i]!=D)
    		t=1;
    	if(C[i]!=E)
			t=1;	
	}
	
	//check tayangRight with tanyangLeft
	if(D!=E)
		t=1;
		
	//check Yes or No
	if(t)
		printf("No");
	else
		printf("Yes");
							
	return 0;	
}
