#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <deque>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <cstdlib>
#include <map>
#include <unordered_map>
#define ll long long
#define ull unsigned long long

using namespace std;

int n; string s; 
vector<int> dap;

int calc(string x){
	vector<int> v;
	vector<char> op;
	for(int i=0;i<x.length();i++){
		char now=x[i];
		if(now=='('){
			string temp="";
			while(1){
				i++; if(x[i]==')') break;
				temp+=x[i];
			}
			v.push_back(calc(temp));
		}else if(now=='+'||now=='-'||now=='*'){
			op.push_back(now);
		}else{
			v.push_back(now-'0');
		}
	}
	int ret=v[0];
	for(int i=1;i<v.size();i++){
		if(op[i-1]=='+') ret+=v[i];
		else if(op[i-1]=='-') ret-=v[i];
		else ret*=v[i];
	}
	return ret;
}
void go(string now,int last){
	if(last>=n-1){
		if(last==n-1) now+=s[last];
		dap.push_back(calc(now));
		return;
	}
	go(now+s[last]+s[last+1],last+2);

	for(int i=3;i<=3;i+=2){
		string next=now+"(";
		for(int j=0;j<i;j++) next+=s[last+j];
		next+=")";
		if(last+i!=n){
			next+=s[last+i];
			go(next,last+i+1);
		} 
		else go(next,last+i);
	}
}

int main(){
	
	cin >> n >> s;
	go("",0);
	sort(dap.begin(),dap.end());
	printf("%d",dap[dap.size()-1]);
	
	return 0;
}

