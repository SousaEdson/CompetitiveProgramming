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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int>    vi;
typedef vector<ii>    vii;
typedef vector<iii>  viii;
///////////////////////////////////////////////////////////////////////////////

int main(){
	
	int tc;
	scanf("%d", &tc);
	
	while(tc--){
		unordered_map<int, int> m;		
		int n, ans = 0, lo = 0;
		
		scanf("%d", &n);			
		fori(i, 0, n){	
			int u;
			scanf("%d", &u);		
			if(m.find(u) != m.end()) lo = max(m[u] + 1, lo);				
			ans = max(ans, i-lo+1);
			m[u] = i;						
		}
		
		printf("%d\n", ans);
	
	}	
	
	return 0;
}
