#include<stdio.h>
#include<string.h>

char A[100];
int k,i,checkStr;
long long n=1;
main()
{
	scanf("%[^\n]",A);
	
	for(k=0;k<3;k++)
		{
			for(;A[i]!=','&&A[i]!='\0';i++)
				{
				if(A[i]>='a'&&A[i]<='z')
					n*=2;
				else if(A[i]>='A'&&A[i]<='Z')
					n*=3;
				else if(A[i]>='0'&&A[i]<='9')
					n*=5;
				else if(A[i]=='$'||A[i]=='@'||A[i]=='#')
					n*=7;
				}
			
			if(i-checkStr>=6&&i-checkStr<=12)
				if(n%2==0)
					if(n%3==0)
						if(n%5==0)
							if(n%7==0)
							{
								if(k==0)
									{
										for(int j=checkStr;j<i;j++)
											printf("%c",A[j]);
										printf(" (Kob)");
									}
								if(k==1)
									{
										for(int j=checkStr;j<i;j++)
											printf("%c",A[j]);
										printf(" (Romtham)");
									
									}
								if(k==2)
									{
										for(int j=checkStr;j<i;j++)
											printf("%c",A[j]);
										
										printf(" (Jojo)");
									}
								
								n=1;
								break;
							}
		n=1;
		i++;
		checkStr=i;
		}	
		
}
