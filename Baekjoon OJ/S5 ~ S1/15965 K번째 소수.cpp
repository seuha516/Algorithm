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
#include <functional>
#include <stack>

using namespace std;

#define sosubumui 7400000 //���� �Ҽ� ����Ʈ�� ���� 
int number[sosubumui];
int sosulist[sosubumui];
int sosugaesoo;
void sosusetting(){
	number[0]=-1; number[1]=-1; //0�� 1�� �Ҽ��� �ƴϴ� 
	int sq_sosubumui=sqrt(sosubumui)+1;
	for(int i=2;i<=sq_sosubumui;i++){
    	int t=i+i;
    	while(t<=sosubumui){
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
void sosuprint(int start,int end){
   for(int i=0;i<sosugaesoo;i++){
      if(sosulist[i]>=start && sosulist[i]<=end) printf("%d��° �Ҽ�: %d\n",i,sosulist[i]);
   }
   printf("0~%d ���� �Ҽ��� ����: %d\n",sosubumui,sosugaesoo);
}


int main(){
	
	sosusetting(); 
	int n; scanf("%d",&n); printf("%d",sosulist[n-1]);
	
return 0;}


