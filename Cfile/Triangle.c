#include <stdio.h>
#include <stdlib.h>

int main(void){
	int l,d,s;
	scanf("%d%d%d",&l,&d,&s);

	for(int i =0;i<l;i++){
		for(int j = 0;j <= s+d*(l-1)+d*i;j++){
			if(j>= s+d*(l-1)-d*i){
				printf("*");	
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
