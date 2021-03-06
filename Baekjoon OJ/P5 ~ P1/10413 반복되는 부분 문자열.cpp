#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Comparator{
	const vector<int> &group;
	int t;
	Comparator(const vector<int> &_group,int _t): group(_group), t(_t){}
	bool operator () (int a,int b){
		if(group[a]!=group[b]) return group[a]<group[b];
		return group[a+t]<group[b+t];
	}
};
vector<int> suffix_array(const string &s){
	int n=s.size();
	int t=1;
	vector<int> group(n+1);
	for(int i=0;i<n;i++) group[i]=s[i];
	group[n]=-1;
	vector<int> ret(n);
	for(int i=0;i<n;i++) ret[i]=i;
	while(t<n){
		Comparator cp(group,t);
		sort(ret.begin(),ret.end(),cp);
		t*=2;
		if(t>=n)break;
		vector<int> newgroup(n+1);
		newgroup[n]=-1;
		newgroup[ret[0]]=0;
		for(int i=1;i<n;i++){
			if(cp(ret[i-1],ret[i])) newgroup[ret[i]]=newgroup[ret[i-1]]+1;
			else newgroup[ret[i]]=newgroup[ret[i-1]];
		}
		group=newgroup;
	}
	return ret;
}
vector<int> lcp(const string &s,const vector<int> &sa){
	vector<int> pos(s.size());
	vector<int> ret(s.size());
	for(int i=0;i<s.size();i++){
		pos[sa[i]]=i;
	}
	for(int i=0,k=0;i<sa.size();i++,k=max(k-1,0)){
		if(pos[i]==0) continue;
		for(int j=sa[pos[i]-1];s[i+k]==s[j+k];k++);
		ret[pos[i]]=k;
	}
	return ret;
}


int main(){
	
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		string s; cin >> s;
		vector<int> suf=suffix_array(s);
		vector<int> lc=lcp(s,suf);
		int dap=0;
		for(int i=1;i<s.size();i++){
			if(lc[i-1]<lc[i]){
				dap+=lc[i]-lc[i-1];
			}
		}
		printf("%d\n",dap);		
	}
	
	
	
	return 0;
}
