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
	int ct, r, vetor[30005], hi=-1000000, lo = 1000000;
	scanf("%d", &ct);
	
	while(ct--){
		scanf("%d", &r);
		fori(i, 0, r){
			int u;
			scanf("%d", &vetor[i]);
			hi = max(hi, vetor[i]);
			lo = min(lo, vetor[i]);		
		}
		int ans = 10000000;
		fori(i, lo, hi+1){
			int aux = 0;
			fori(j, 0, r){
				aux += abs(i-vetor[j]);			
			}
			ans = min(ans, aux);
		}
		printf("%d\n", ans);
	}
	return 0;
}
