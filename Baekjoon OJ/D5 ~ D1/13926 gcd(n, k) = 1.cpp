#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <stack>
#include <queue>
#include <utility>
#define ll long long
#define ull unsigned long long

using namespace std;

vector<ull> a_list={2,325,9375,28178,450775,9780504,1795265022};
template <typename T>
T gcd(T a, T b){  
	return a%b==0? b : gcd(b,a%b);
}

ull addmod(ull x,ull y,ull mod){
	x%=mod; y%=mod; return (x>=mod-y? x-(mod-y) : x+y);
}
ull mulmod(ull x,ull y,ull mod){
	x%=mod; y%=mod; 
	ull ret=0ULL;
	while(y){
		if(y&1) ret=addmod(ret,x,mod);
		x=addmod(x,x,mod);
		y>>=1;
	}
	return ret;
}
ull powmod(ull x,ull y,ull mod){
	x%=mod;
	ull ret=1ULL;
	while(y){
		if(y&1) ret=mulmod(ret,x,mod);
		x=mulmod(x,x,mod);
		y>>=1;
	}
	return ret;
}
bool miller_rabin(ull n,ull a){
	ull d=n-1;
	while(!(d&1)){
		if(powmod(a,d,n)==n-1) return true;
		d>>=1;
	}
	ull temp=powmod(a,d,n);
	return temp==n-1 || temp==1;
}
bool is_prime(ull n){
	if(n<=1) return false;
	if(n<=10000000000ULL){
		for(unsigned long long i=2;i*i<=n;i++) if(n%i==0) return false;
		return true;
	}
	for(ull a : a_list) if(!miller_rabin(n,a)) return false;
	return true;
}
ull rho_f(ull x,ull c,ull mod){
	return addmod(mulmod(x,x,mod),c,mod);
}
ull rho(ull n,ull x0,ull c){
	ull x=x0, y=x0, ret=1;
	while(ret==1){
		x=rho_f(x,c,n);
		y=rho_f(y,c,n); y=rho_f(y,c,n);
		ret=gcd(x>y?x-y:y-x,n);
	}
	return ret;
} 
ull find_soinsoo(ull n){
	if(n==1ULL) return 1;
	if(n<=10000000000ULL){
		for(unsigned long long i=2;i*i<=n;i++) if(n%i==0) return i;
		return n;
	}
	if(is_prime(n)) return n;
	ull ret=rho(n,1,1);
	if(ret==n) ret=rho(n,1,-1);
	int temp_c=2;
	while(ret==n) ret=rho(n,1,temp_c++);
	return ret;
}
vector<ull> soinsoos; 
void soinsoo_divide(ull n){
	if(n==1) return;
	if(find_soinsoo(n)==n){
		soinsoos.push_back(n); return;
	}
	soinsoo_divide(find_soinsoo(n));
	soinsoo_divide(n/find_soinsoo(n));
	return;
}


int main(){
	
	ull x; scanf("%llu",&x); soinsoo_divide(x);
	if(x==1ULL){printf("1");return 0;}
	vector<ull> realsoinsoo; realsoinsoo.push_back(soinsoos[0]);
	for(int i=1;i<soinsoos.size();i++){
		if(soinsoos[i-1]!=soinsoos[i]) realsoinsoo.push_back(soinsoos[i]);
	}
	for(int i=0;i<realsoinsoo.size();i++){
		x/=realsoinsoo[i]; x*=(realsoinsoo[i]-1);
	}
	printf("%llu",x);
		
	return 0;
}

