#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> g[2020];
vector<int> rg[2020];
bool vis[2020];
stack<int>st;
int scc;
int id[2020];

// get topological ordering of nodes and
// goes through it on the reverse graph

void dfs(int x){
	
	vis[x] = true;
	
	for(int i = 0 ; i < g[x].size() ; i ++)
		if(!vis[g[x][i]]) dfs(g[x][i]);
	
	st.push(x);
}

void dfs2(int x){
	
	id[x] = scc;
	
	for(int i = 0 ; i < rg[x].size() ; i ++)
		if(id[rg[x][i]] == -1) dfs2(rg[x][i]);
}

int main(){
	
	ios::sync_with_stdio(false); cin.tie(0);
	
	memset(id, -1 ,sizeof id);
	
	int n, m;
	cin>>n>>m;
	
	for(int a, b, i = 0 ; i < m ; i ++){
		cin>>a>>b;	
		g[a].pb(b);
		rg[b].pb(a);
	}
	
	for(int i = 1 ; i <= n ; i ++)
		if(!vis[i]) dfs(i);
	
	while(!st.empty()){
		
		int u = st.top();
		st.pop();
		
		if(id[u] != -1) continue;
		
		id[u] = scc;
		
		dfs2(u);
		scc++;
	}
	
	for(int i = 1 ; i <= n ; i ++)
		cout<<"id["<<i<<"] = "<<id[i]<<"\n";
	
	return 0;
}
