#include <stdio.h>

int main(){
	int n,m,i,j,k;
	printf("Enter no.of Process : ");
	scanf("%d",&n);
	printf("Enter no.of Resources : ");
	scanf("%d",&m);
	int allocation[n][m];
	printf("Enter Allocation Matrix : ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&allocation[i][j]);
		}
	}
	int max[n][m];
	printf("Enter Max Matrix : ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&max[i][j]);
		}
	}
	int available[m];
	printf("Enter Available Matrix : ");
	for(i=0;i<m;i++){
		scanf("%d",&available[m]);
	}
	printf("Allocation Matrix :\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d\t",allocation[i][j]);
		}
		printf("\n");
	}
	printf("Max Matrix :\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d\t",max[i][j]);
		}
		printf("\n");
	}
	printf("Available Matrix :\n");
	for(i=0;i<m;i++){
		printf("%d\t",available[m]);
	}
	printf("\n");
	
	int finish[n], ans[n], ind=0;
	for(i=0;i<n;i++){
		finish[i] = 0;
	}
	int need[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	
	printf("Need matrix is :\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d\t",need[i][j]);
		}
		printf("\n");
	}
	
	int y;
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(finish[i] == 0){
				int flag = 0;
				for(j=0;j<m;j++){
					if(need[i][j] > available[j]){
						flag = 1;
						break;
					}
				}
				
				if(flag == 0){
					ans[ind++] = i;
					for(y=0;y<m;y++){
						available[y] += allocation[i][y];
					}
					finish[i] = 1;
				}
			}
		}
	}
	
	int flag = 1;
	for(int i=0;i<n;i++){
		if(finish[i] == 0){
			flag = 0;
			printf("The following system is not safe\n");
			break;
		}
	}
	
	if(flag == 1){
		printf("Following is the safe sequesnce :\n");
		for(i=0;i<n;i++){
			printf("P%d ->",ans[i]);
		}
		printf("P%d\t",ans[n-1]);
	}
	return 0;
}
