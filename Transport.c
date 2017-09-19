#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]){
	
	int m,n;
	scanf("%d%d",&m,&n);
	
	int** arr = (int**)malloc(m * sizeof(int*));
	for(int i =0;i < m;i++){
		arr[i] = (int*)malloc(n * sizeof(int));	
	}

	for(int i =0;i < m;i++){
		for(int j = 0;j < n;j++){
			scanf("%d",&arr[i][j]);	
		}	
	}

	for(int j = 0;j < n;j++){
		for(int i = 0;i < m;i++){
			printf("%d ",arr[i][j]);		
		}
		printf("\n");
	}

	for(int i = 0;i<m;i++){
		free(arr[i]);	
	}
	free(arr);
	return 0;
}
