#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

long long int sipn(long long int n,long long int jisoo){
	long long int t=1;
	while(--jisoo){
		t*=n;
	}
	return t;
}

long long dap=0;

int main() {
	
	for(int y=0;y<2;y++){
		long long int x; scanf("%lld",&x);  
		if(y==0){
			x--;
		}
		if(x<=0){
			continue;
		}
		long long int arr[10]={0,};
		long long int num=x;
		long long int ttem=x;
		long long int temp=x; long long int jarisoo=0;
		while(x){
			x/=10;jarisoo++;
		}
		long long int ttemjarisoo=jarisoo;
	
		while(1){
			if(jarisoo==1){
				break;
			}
			for(int i=0;i<(num/(sipn(10,jarisoo)));i++){
				long long int t;
				t=jarisoo-1; t*=sipn(10,jarisoo); t/=10;
				for(int j=0;j<10;j++){
					arr[j]+=t;
				}
				arr[i]+=sipn(10,jarisoo);
			}
			arr[num/(sipn(10,jarisoo))]+=num%(sipn(10,jarisoo))+1;
			num%=(sipn(10,jarisoo)); jarisoo--;
		}
		for(int i=0;i<=num;i++){
			arr[i]+=1;
		}
		long long int ttt=9; long long int totalzero=ttemjarisoo;
		for(int i=0;i<ttemjarisoo-1;i++){
			totalzero+=(ttemjarisoo-i-1)*ttt;
			ttt*=10;
		}
		arr[0]-=totalzero;
		for(int i=0;i<10;i++){
			if(y==0){
				dap-=arr[i]*i;
			}else{
				dap+=arr[i]*i;
			}
		}
	}
	
	printf("%lld",dap);
	
	return 0;
	
}
