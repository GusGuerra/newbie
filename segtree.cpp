//Segment Tree
//With Lazy Propagation

const int MAXN = 101010;

int st[4*MAXN];
int v[MAXN];


//at == where Im at
//d == destination to be updated
//x == updating element

void lazyprop (int at, int l, int r){
	
	if(!lazyv[at]) return; //no updates to be done
	
	st[at] += lazyv[at]; //updating
	
	if(l != r){ //if the update is within a range
				//must propagate it to children nodes
		lazyv[at<<1] += lazyv[at];
		lazyv[(at<<1) + 1] += lazyv[at];
	}
	
	lazyv[at] = 0; //updated
}

void build (int at, int l, int r){
	if(l == r){
		st[at] = v[l];
		return;
	}
	
	int mid = (l + r)>>1;
	
	build (at<<1, l, mid);
	build ((at<<1) + 1, mid + 1, r);
	
	st[at] = st[at<<1] + st[(at<<1) + 1];
}

void update (int at, int l, int r, int d, int x){
	
	lazyprop (at, l, r);
	
	if(pos < l || pos > r) return;
	
	if(l == r){
		st[at] = x;
		return ;
	}
	
	int mid = (l + r)>>1;
	
	if(d <= mid)
		update(at<<1, l, mid, d, x);
	else
		update((at<<1) + 1, mid + 1, r, d, x);
	
	st[at] = st[at<<1] + st[(at<<1) + 1];
}

// [ll , rr] == search
// [l , r] == am at

int query (int at, int l, int r, int ll, int rr){
	
	lazyprop (at, l, r);
	
	if(rr < l || r < ll) return 0;
	if(l <= ll && rr <= r) return st[at];
	
	int mid = (l + r)>>1;
	
	int lq =  query (at<<1, l, mid, ll, rr) 
	int rq = query ((at<<1) + 1, mid + 1, r, ll, rr);
	
	return lq + rq;
}
