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
#include <cstdlib>
#include <set>

using namespace std;

#define sosubumui 15000 //구할 소수 리스트의 범위 
int number[sosubumui];
int sosulist[sosubumui];
int sosugaesoo=0;
void sosusetting(){
   number[0]=-1; number[1]=-1;
   for(int i=2;i<=sqrt(sosubumui);i++){
      int t=i+i;
      while(t<sosubumui){
         number[t]=-1;      
         t+=i;
      }
   }
   for(int i=0;i<sosubumui;i++){
      if(number[i]==0){
         sosulist[sosugaesoo++]=i;
      }
    }
}
int isitsosu(int a){
   if(a==1){
      return 0;
   }
   
   int divided=0;
   for(int i=0;sosulist[i]<=a&&i<sosugaesoo;i++){
      if(a%sosulist[i]==0){
         a/=sosulist[i];
         divided=1; break;
      }
   }
   if(divided&&a==1){
      return 1;
   }else if(!divided){
      return 1;
   }else{
      return 0;
   }
}

int main(){
	
	sosusetting();
	
	int a,b;scanf("%d %d",&a,&b);
	if(isitsosu(a)&&isitsosu(b*1000000+a)){
		printf("Yes");
	}else{
		printf("No");
	}
	return 0;
}



