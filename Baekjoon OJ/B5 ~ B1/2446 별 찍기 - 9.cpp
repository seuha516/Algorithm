#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=n;i>=1;i--){	
		for(int j=1;j<=(n-i+1)-1;j++){
			printf(" ");
		}
		for(int j=1;j<=2*i-1;j++){
			printf("*");
		}
		printf("\n");
	}
	for(int i=2;i<=n;i++){	
		for(int j=1;j<=(n-i+1)-1;j++){
			printf(" ");
		}
		for(int j=1;j<=2*i-1;j++){
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
