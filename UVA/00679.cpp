#include<bits/stdc++.h>
using namespace std;
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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int>    vi;
typedef vector<ii>    vii;
typedef vector<iii>  viii;

int main(){
	int tc, d, qtd;
	
	while(scanf("%d", &tc) && tc != -1){
		while(tc--){
	
			scanf("%d %d", &d, &qtd); qtd--; d--;
		
			int ans = 1;
			while(d--){
		
				if(qtd % 2 == 0) ans = ans << 1;
				else ans = (ans<<1) + 1;
				qtd = qtd/2;		
			
			}printf("%d\n", ans);	
			
		}	
	
	}
	
	return 0;
}
