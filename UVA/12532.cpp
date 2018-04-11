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

class SegTree{
	public:
		int *v, sz, st[4*MAX];
		
		SegTree(int sz, int* v){
			this->sz = sz;
			this->v  = v;
			fori(i, 1, sz+1){
				if(v[i]>0) v[i] = 1;
				if(v[i]<0) v[i] = -1;				
			}
			build(1, 1, sz+1);		
		}
		
		void build(int idx, int l, int r){
			
			if(l<r){
				int mid = (l+r)/2;
				build(2*idx, l, mid);
				build(2*idx+1, mid+1, r);
				st[idx] = st[2*idx]*st[2*idx+1];			
			}else{
				st[idx] = v[l];				
			}	
		}
		
		int query(int idx, int i, int j, int l, int r){
			if(i>r || j<l) return 1;
			if(i>=l && j<=r) return st[idx];		
			
			int mid = (i+j)/2;
			int p1 = query(2*idx, i, mid, l, r);
			int p2 = query(2*idx+1, mid+1, j, l, r);
			return p1*p2;	
		}
		
		int query(int l, int r){
			return query(1, 1, sz+1, l, r);
		}
		
		void update(int idx, int l, int r, int pos, int n){
			if(l>pos || r<pos) return ;			
			if(l<r){
				int mid = (l+r)/2;
				update(2*idx, l, mid, pos, n);
				update(2*idx+1, mid+1, r, pos, n);			
				st[idx] = st[2*idx]*st[2*idx+1];
				
			}else{
				st[idx] = n;			
			}		
		}
		
		void update(int pos, int n){
			if(n>0) n = 1;
			if(n<0) n = -1;			
			update(1, 1, sz+1, pos, n);
		}

};

int main(){
	
	int n, m, v[MAX];
	
	while(scanf("%d %d", &n, &m) == 2){
		
		fori(i, 1, n+1) scanf("%d", &v[i]);
		SegTree st(n+1, v);		
		while(m--){
			int a, b;
			char c;
			scanf(" %c %d %d", &c, &a, &b);
			
			if(c=='C'){
				st.update(a, b);
			}else{
				int q = st.query(a, b);
				if(q>0)printf("+");
				else if(q<0)printf("-");
				else printf("0");				
			}		
		}
		printf("\n");	
	}
	
	return 0;
}
