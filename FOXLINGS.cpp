/*
    Problem: https://www.spoj.com/problems/FOXLINGS/
    Standard problem for DSU
    Author: Prakash Tiwari
*/


#include <iostream>
#include <cstring>
#include <unordered_map>
#define ll long long

using namespace std;

int root(int i, unordered_map <int, int> &m){
	while(m[i]!=i){
		m[i] = m[m[i]];
		i = m[i];
	}
	return i;
}

void union1(int a, int b, unordered_map <int, int> &m, unordered_map <int, int> &siz){
	int ra = root(a, m);
	int rb = root(b, m);
	if(ra==rb) return;

	if(siz[ra]>siz[rb]){
		m[rb] = ra;
		siz[ra] += siz[rb];
	}
	else{
		m[ra] = rb;
		siz[rb] += siz[ra];
	}
}

int main(){
	int n, ed;
	cin>>n>>ed;

	unordered_map <int, int> m, siz, vis;
    int cnt = 0;
	int a, b;
	for(int i=0; i<ed; i++){
		cin>>a>>b;
		if(m.find(a)==m.end()){
            cnt++;
			m[a] = a;
			siz[a] = 1;
			vis[a] = 0;
		}
		if(m.find(b)==m.end()){
		    cnt++;
			m[b] = b;
			siz[b] = 1;
			vis[b] = 0;
		}
		union1(a, b, m, siz);
	}
	int c = 0;
	unordered_map <int, int>::iterator it;
	for(it = m.begin(); it!=m.end(); it++){
        int p = it->first, q = it->second;
		if(m.find(p)==m.end()) c++;
		else{
			int r = root(p, m);
			if(vis[r]==0){
				c++;
				vis[r] = 1;
			}
		}
	}
	cout<<c+n-cnt;
}
