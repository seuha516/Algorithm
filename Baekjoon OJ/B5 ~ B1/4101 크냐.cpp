#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;

int main()
{
    while(1){
    	int a,b;scanf("%d %d",&a,&b);
    	if(a==0&&b==0){break;
		}
    	if(a>b){printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
    
    return 0; 
}

