#include <stdio.h>

int main()
{
	int n,w,h,l; scanf("%d %d %d %d",&n,&w,&h,&l);
	printf("%d",(n<=(w/l)*(h/l))? n : (w/l)*(h/l));
    return 0;
}
