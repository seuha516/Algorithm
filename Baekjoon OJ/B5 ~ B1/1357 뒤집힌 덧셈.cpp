#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int rev(int a){
	int x,y,z,zz;
	if(a<10){
		return a;
	}else if(a<100){
		x=a/10;
		y=a%10;
		return 10*y+x;
	}else if(a<1000){
		x=a/100;
		y=(a%100)/10;
		z=a%10;
		return 100*z+10*y+x;
	}else{
		x=a/1000;
		y=(a%1000)/100;
		z=(a%100)/10;
		zz=a%10;
		return 1000*zz+100*z+10*y+x;
	}
}

int main(){
	
	int x; scanf("%d",&x);
	
	int xx; scanf("%d",&xx);
	
	printf("%d",rev(rev(x)+rev(xx)));

	return 0;

}

