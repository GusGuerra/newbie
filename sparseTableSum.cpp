#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101010;
const int LOGN = 25;

int st[MAXN][LOGN];
int v[MAXN];

int querie(int L, int R){
	
	// lenghts of intervals are powers of 2
	// 1, 2, 4, 8, 16, 32, ...
	
	//iterate through powers until power <= desired lenght
	
	// first part will be [L , L + 2^(j - 1) - 1]
	// second part will be [L + 2^(j - 1) , L + 2^(j) - 1]
	// and so on..
	
	long long sum = 0LL;
	
	for(int j = LOGN ; j >= 0 ; j --)
		if((1<<j) <= R - L + 1){
			sum += st[L][j];
			L += 1<<j;
		}
	
	return sum;
}

//range sum query

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin>>n;
	
	for(int i = 0 ; i < n ; i ++)
		cin>>v[i];
	
	// sparse table
	// splitting array in
	// various arrays with lenghts
	// equal to power of 2
	
	for(int i = 0 ; i < n ; i ++)
		st[i][0] = v[i];
	
	// st[i][j] representa
	// intervalo compreendendo [i , i + 2^(j) - 1] , de comprimento 2^j
	// que eh a soma dos intervalos
	// [i , i + 2^(j - 1) - 1] + [i + 2^(j - 1) , i + 2^(j) - 1]
	
	for(int j = 1 ; j <= LOGN ; j ++) // going through powers
		for(int i = 0 ; i + (1<<j) <= n ; i ++)
			st[i][j] = st[i][j - 1] + st[i + (1<<(j - 1))][j - 1];
	
	int q;
	cin>>q;
	
	for(int i = 0 ; i < q ; i ++){
		int l, r;
		cin>>l>>r;
		cout<<querie(l, r)<<"\n";
	}
	
	return 0;
}
