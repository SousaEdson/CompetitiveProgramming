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

class Bit{
	public:
		ll ft[MAX];
		int n;
		
		void create(int n){
			this->n = n;
			fill(ft, 0);
		}
		
		void update(int idx, ll v){
			while(idx<=n){
				ft[idx] += v;
				idx += (idx&(-idx));
			}
		}
		
		void update(int l, int r, int v){
			update(l, v);
			update(r+1, -v);		
		}
		
		ll query(int idx){
			ll sum = 0;
			while(idx>0){
				sum += ft[idx];
				idx -= (idx&(-idx));
			}
			return sum;
		}				
};

class Fenwick{
	public:
		Bit bit1, bit2;
		
		Fenwick(int n){
			bit1.create(n);
			bit2.create(n);
		}
		
		void update(int l, int r, ll v){
			bit1.update(l, r, v);
			bit2.update(l, v*(l-1));
			bit2.update(r+1, -v*r);		
		}
		
		ll query(int idx){
			return bit1.query(idx)*idx - bit2.query(idx);
		}
		
		ll query(int l, int r){
			return query(r) - query(l-1);
		}
};

int main(){
	int ct;
	
	scanf("%d", &ct);
	while(ct--){
		int n, c, l, r;		
		ll val;
		
		scanf("%d %d", &n, &c);
		Fenwick ft(n);
		
		while(c--){
			int op;
			scanf("%d", &op);
			if(op==0){
				scanf("%d %d %lld", &l, &r, &val);
				ft.update(l, r, val);			
			}else{
				scanf("%d %d", &l, &r);
				printf("%lld\n", ft.query(l, r));
			}
		}
	}		
				
	return 0;
}
