//Segment Tree
//With Lazy Propagation

const int MAXN = 101010;

int st[4*MAXN];
int v[MAXN];
int lazy[4*MAXN];

void build(int at, int l, int r){
	
	if(l == r){
		st[at] = v[l];
		return;
	}
	
	int mid = (l + r)>>1;
	
	build((at<<1), l, mid);
	build((at<<1) + 1, mid + 1, r);
	
	st[at] = st[at<<1] + st[(at<<1) + 1];
}

//node "at" comprehends interval [l , r]
//updating interval [lu, ru] with val "x"

void update(int at, int l, int r, int lu, int ru, int x){
	
	if(lazy[at]){
		
		st[at] += (r - l + 1) * lazy[at]; //updates node with lazy array value
		
		if(l != r){ // spread lazyness to children
			lazy[at<<1] += lazy[at];
			lazy[(at<<1) + 1] += lazy[at];
		}
		
		lazy[at] = 0;
	}
	
	if(r < lu || l > ru) return;
	
	if(lu <= l && r <= ru){
		
		st[at] += (r - l + 1) * x; // updates node
		
		if(l != r){ // updates children's lazyness
			lazy[at<<1] += x;
			lazy[(at<<1) + 1] += x;
		}
		
		return;
		
	}
	
	int mid = (l + r)>>1;
	
	update((at<<1), l, mid, lu, ru, x);
	update((at<<1) + 1, mid + 1, r, lu, ru, x);
	
	st[at] = st[at<<1] + st[(at<<1) + 1];
}

//node "at" comprehends interval [l , r]
//querying interval [lq , rq]

int query(int at, int l, int r, int lq, int rq){
	
	if(lazy[at]){
		
		st[at] += (r - l + 1) * lazy[at]; // update lazy array
		
		if(l != r){ // spread lazyness to children
			st[at<<1] += lazy[at];
			st[(at<<1) + 1] += lazy[at];
		}
		
		lazy[at] = 0;
	}
	
	if(r < lq || l > rq) return 0;
	
	if(lq <= l && r <= rq) return st[at]; //we can return immediately if updated
	
	int mid = (l + r)>>1;
	
	return query((at<<1), l, mid, lq, rq) + query((at<<1) + 1, mid + 1, r, lq, rq);
}
