#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int has369(int a){
	int t=0;
	while(a){
		t+=a%10;
		a/=10;
	}
	return t;
}
int main(){	
	int a=0;
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		if(i%has369(i)==0){
			a++;
		}
	}
	printf("%d",a);
	
	return 0;
}


