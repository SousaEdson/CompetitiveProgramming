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

struct node{
	int homem, elefante, rato;
};

class Segtree{
	public:				
		int lazy[4*MAX];
		struct node st[4*MAX];	
				
		Segtree(int n){
			fill(lazy, 0);
			build(1, 1, n);
		}
		
		struct node combine(struct node& a, struct node& b){
			struct node c;
			c.homem    = a.homem	 + b.homem;
			c.elefante = a.elefante  + b.elefante;
			c.rato 	   = a.rato      + b.rato;
			return c;
		}
		
		void rotate(struct node& n){
			int aux    = n.rato;
			n.rato     = n.elefante;
			n.elefante = n.homem;
			n.homem    = aux;		
		}
		
		void build(int idx, int l, int r){
			if(l<r){
				int mid = (l+r)/2;
				build(2*idx, l, mid);
				build(2*idx+1, mid+1, r);
				st[idx] = combine(st[2*idx], st[2*idx+1]);							
			}else{
				st[idx].elefante = 0;
				st[idx].rato     = 0;
				st[idx].homem    = 1;
			}		
		}
		
		void update(int idx, int i, int j, int l, int r){
			if(lazy[idx]%3 != 0){
				if(i!=j){
					lazy[2*idx]   += lazy[idx];
					lazy[2*idx+1] += lazy[idx];
				}
			
				fori(i, 0, lazy[idx]%3) rotate(st[idx]);
				lazy[idx] = 0;			
			}
			
			if(j<l || i>r) return ;
			if(i>=l && j<=r){
				rotate(st[idx]);
				if(i!=j){
					lazy[2*idx]++;
					lazy[2*idx+1]++;	
				}		
				return ;
			}
			
			int mid = (i+j)/2;
			update(2*idx, i, mid, l, r);
			update(2*idx+1, mid+1, j, l, r);
			st[idx] = combine(st[2*idx], st[2*idx+1]);		
		}
		
		struct node query(int idx, int i, int j, int l, int r){
			if(lazy[idx]%3 != 0){
				if(i!=j){
					lazy[2*idx]   += lazy[idx];
					lazy[2*idx+1] += lazy[idx];
				}
				fori(i, 0,lazy[idx]%3) rotate(st[idx]);
				lazy[idx] = 0;
			}
		
			if(i>r || j<l){
				struct node aux;
				aux.elefante = aux.rato = aux.homem = 0;
				return aux;			
			}
			
			if(i>=l && j<=r) return st[idx];			
			int mid = (i+j)/2;
			struct node p1 = query(2*idx, i, mid, l, r);
			struct node p2 = query(2*idx+1, mid+1, j, l, r);
			return combine(p1, p2);		
		}
};

int main(){
	int n, m;	
	
	while(scanf("%d %d", &n, &m ) == 2){
		char op;
		int u, v;		
		
		Segtree st(n);	
		while(m--){			
			scanf(" %c %d %d", &op, &u, &v);	
			if(op == 'C'){
				struct node a;
				a = st.query(1, 1, n, u, v);
				printf("%d %d %d\n", a.homem, a.elefante, a.rato);		
			}else st.update(1, 1, n, u, v);		
		}
		printf("\n");		
	}
		
	return 0;
}
