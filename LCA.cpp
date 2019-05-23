#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

const int MAXN = 4321;
const int LOGN = 13;

vector<int> g[MAXN];
int n;
int h[MAXN];
int pai[MAXN][LOGN];

void inicializa(){
	for(int i = 0 ; i < n ; i++)
		pai[i][0]=i;
}

void dfs(int x){
	
	for(int i = 0 ; i < g[x].size() ; i++){
		
		int y = g[x][i];
		if(y == pai[x][0]) continue;
		
		h[y] = h[x] + 1;
		pai[y][0] = x;
		
		dfs(y);
	}
	
}

void calc(){
	for(int j = 1  ; j < LOGN ; j++)
		for(int i = 0 ; i < n ; i++)
			pai[i][j] = pai [pai[i][j - 1]][j - 1];
}

int lca(int x, int y){
	
	if(h[x] < h[y]) swap(x , y);
	int d = h[x] - h[y];
	
	for(int i = 0 ; i < LOGN ; i++)
		if(d & (1<<i)) x = pai[x][i];
	
	if(x==y) return x;
	
	for(int i = LOGN - 1 ; i >= 0 ; i--){
		if(pai[x][i] != pai[y][i]){
			x = pai[x][i];
			y = pai[y][i];
		}
	}
	
	return pai[x][0];
}
