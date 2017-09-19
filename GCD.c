#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
	int t;
	scanf("%d",&t);
	int** number = (int**)malloc(t*sizeof(int*));
	for(int j=0;j<t;j++){
		number[j] = (int*)malloc(2*sizeof(int));
		scanf("%d%d",&number[j][0],&number[j][1]);
	}

	for(int j = 0;j<t;j++){
		int a = number[j][0];
		int b = number[j][1];
		int r,n;
		do{
			if(a>b){
				n = a%b;
				r = b;
				a = n;
			}else{
				n = b%a;
				r = a;
				b = n;
			}
		}while(n != 0);
		printf("%d\n",r);
	}

	for(int j =0;j<t;j++){
		free(number[j]);	
	}
	free(number);
}
