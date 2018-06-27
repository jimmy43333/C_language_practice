#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n,tmp;
	scanf("%d\n",&n);
	int arr[n];
	for(int i =0;i<n;i++){
		scanf("%d",&arr[i]);	
	}

	for(int i = 0;i<n-1;i++){
		for(int j = 0;j<n-i;j++){
			if(arr[j]>arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}

	for(int i =0;i<n;i++){
		printf("%d ",arr[i]);
	}

	return 0;
}

