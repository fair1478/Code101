#include<stdio.h>
#include<string.h>
char P1[100],P2[100],P3[100];
int a[10],b[10],c[10];
main()
{
	scanf("%[^,],%[^,],%[^\n]",P1,P2,P3);
	
	if(strlen(P1)>=6&&strlen(P1)<=12)	
		for(int i=0;i<strlen(P1);i++)
			{
				if(P1[i]>='a'&&P1[i]<='z')
					{
					a[1]=1;
					}
				else if(P1[i]>='A'&&P1[i]<='Z')
					{
					a[2]=1;
					}
				else if(P1[i]>='0'&&P1[i]<='9')
					{
					a[3]=1;
					}
				else if(P1[i]=='$'||P1[i]=='@'||P1[i]=='#')
					{
					a[4]=1;
					}
								
			}
	if(strlen(P2)>=6&&strlen(P2)<=12)	
		for(int i=0;i<strlen(P2);i++)
			{
				if(P2[i]>='a'&&P2[i]<='z')
					{
					b[1]=1;
					}
				else if(P2[i]>='A'&&P2[i]<='Z')
					{
					b[2]=1;
					}
				else if(P2[i]>='0'&&P2[i]<='9')
					{
					b[3]=1;
					}
				else if(P2[i]=='$'||P2[i]=='@'||P2[i]=='#')
					{
					b[4]=1;
					}
								
			}
	
	if(strlen(P3)>=6&&strlen(P3)<=12)	
		for(int i=0;i<strlen(P3);i++)
			{
				if(P3[i]>='a'&&P3[i]<='z')
					{
					c[1]=1;
					}
				else if(P3[i]>='A'&&P3[i]<='Z')
					{
					c[2]=1;
					}
				else if(P3[i]>='0'&&P3[i]<='9')
					{
					c[3]=1;
					}
				else if(P3[i]=='$'||P3[i]=='@'||P3[i]=='#')
					{
					c[4]=1;
					}
								
			}
	
	for(int i=1;i<4;i++)
		{
			a[i+1]+=a[i];
		}
	for(int i=1;i<4;i++)
		{
			b[i+1]+=b[i];
		}
	for(int i=1;i<4;i++)
		{
			c[i+1]+=c[i];
		}
	if(a[4]==4)
		printf("%s (Kob)",P1);
	else if(b[4]==4)
		printf("%s (Romtham)",P2);
	else if(c[4]==4)	
		printf("%s (Jojo)",P3);
		
}
