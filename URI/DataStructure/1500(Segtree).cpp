#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fori(a, l, f) for(int a = l; a<f; ++a)
#define ford(a, l, f) for(int a=l; a>=f; --a)
#define pq priority_queue
#define checkBit(mask, i) ((mask & (1 << i)) != 0) ? true:false
#define setBit(mask, i) mask = mask | (1 << i)
#define debug(x) cout<<x<<endl
#define fill(x, y) memset(x, y, sizeof x)
#define MAX 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int>    vi;
typedef vector<ii>    vii;
typedef vector<iii>  viii;
///////////////////////////////////////////////////////////////////////////////

class Segtree{
	public:
	ll st[4*MAX], lazy[4*MAX];
	int n;
	
	Segtree(int n){
		this->n = n;	
		fill(lazy, 0);
		fill(st, 0);
	}
	
	void update(int idx, int i, int j, int l, int r, ll v){	
		
		if(lazy[idx] != 0){			
			if(i!=j){
				lazy[2*idx]   += lazy[idx];
				lazy[2*idx+1] += lazy[idx];		
			}	
			st[idx] += lazy[idx]*(j-i+1);		
			lazy[idx] = 0;
		}
		if(i>r || j<l) return ;	
		if(i>=l && j<=r){
			st[idx] += v*(j-i+1);
			if(i!=j){
				lazy[2*idx]   += v;
				lazy[2*idx+1] += v;				
			} 
			return ;			
		}
		
		int mid = (i+j)/2;
		update(2*idx, i, mid, l, r, v);
		update(2*idx+1, mid+1, j, l, r, v);
		st[idx] = st[2*idx] + st[2*idx+1];	
	}
	
	ll query(int idx, int i, int j, int l, int r){		
		if(lazy[idx] != 0){
			st[idx] += (j-i+1)*lazy[idx];
			if(i != j){
				lazy[2*idx]   += lazy[idx];
				lazy[2*idx+1] += lazy[idx];				
			}			
			lazy[idx] = 0;			
		}		
		if(i>r || j<l) return 0;
		if(i>=l && j<=r) return st[idx];
		
		int mid = (i+j)/2;
		return (query(2*idx, i, mid, l, r) + query(2*idx+1, mid+1, j, l, r));	
	}
};

int main(){
	int tc;
	
	scanf("%d", &tc);
	
	while(tc--){
		int n, c, p, q;
		ll val;
		
		scanf("%d %d", &n, &c);	
		Segtree st(n);
	
		while(c--){
			int op;
			scanf("%d", &op);
			if(op == 0){
				scanf("%d %d %lld", &p, &q, &val);				
				st.update(1, 1, n, p, q, val);
			}else{
				scanf("%d %d", &p, &q);
				printf("%lld\n", st.query(1, 1, n, p, q));		
			}		
		}	
	}
		
	return 0;
}
