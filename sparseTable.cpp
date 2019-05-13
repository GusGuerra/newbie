#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101010;
const int LOGN = 25;

int logue[MAXN + 1];
int st[MAXN][LOGN];
int v[MAXN];

// fastest range minimum query
// in the west

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	
	// precompute log
	logue[1] = 0;
	for(int i = 2 ; i <= MAXN ; i ++)
		logue[i] = logue[i/2] + 1;
	//doing it to get log(interval lengh) fast
	
	int n;
	cin>>n;
	
	for(int i = 0 ; i < n ; i ++)
		cin>>v[i];
	
	// sparse table
	// splitting array in
	// two overlapping segments
	// of an equal lengh power of 2
	
	// we will get min of range [L , R]
	// doing min(st[L][j] , st[R - 2^(j) - 1][j]);
	
	for(int i = 0 ; i < MAXN ; i ++)
		st[i][0] = v[i];
	
	for(int j = 1 ; j <= LOGN ; j ++) // going through powers
		for(int i = 0 ; i + (1<<j) <= n ; i ++)
			st[i][j] = min(st[i][j - 1] , st[i + (1<<(j - 1))][j - 1]);
	
	int q;
	cin>>q;
	
	for(int i = 0 ; i < q ; i ++){
		int l, r;
		cin>>l>>r;
		
		int len = logue[r - l + 1];
		cout<<min(st[l][len] , st[r - (1<<len) + 1][len])<<"\n";
		//O(1) ... wow
	}
	
	return 0;
}
