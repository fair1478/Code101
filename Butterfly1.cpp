#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int x=1;x<2*n;x++){
        for(int y=1;y<2*n;y++)
		{
            if(y<=x&&x+y<=n*2||y>=x&&x+y>=n*2){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}
