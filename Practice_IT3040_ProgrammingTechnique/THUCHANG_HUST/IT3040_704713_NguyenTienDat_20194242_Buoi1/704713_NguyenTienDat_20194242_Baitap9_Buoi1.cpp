#include <stdio.h> 

int main() {
	printf("Ho ten: Nguyen Tien Dat\nMSSV: 20194242\n\n");
	// day cho truoc: 
	int arr[] = {1,3,4,2};
	int n = 4;
	printf("Day cho truoc: \n");
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\nCac day con: \n");
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = i; k <= j; k++) {
				printf("%d ", arr[k]);
			}
			printf("\n");
		}
	}
}
