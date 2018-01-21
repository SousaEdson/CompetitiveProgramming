#include<bits/stdc++.h>
using namespace std;

class word{
	public:
		int pos;
		char p[55];
};

bool operator<(word a, word b){
	if(strlen(a.p) > strlen(b.p)) return true;
	else return a.pos > b.pos;
}


int main(){
	int n;
	
	scanf("%d", &n);
	
	while(n--){	
		char aux[3000];
		gets(aux);	
		word w[60];
		int pos = 0, j = 0;;	
		for(int i=0; i<strlen(aux); i++){
			if(aux[i]!=' '){
				 w[pos].p[j] = aux[i];
				 j++;
			}else{
				while(aux[i+1]==' ')i++;
				w[pos].p[j] = '\0';
				pos++;
			}
		}	
		sort(w, w+pos);
		for(int i=0; i<pos; i++) printf("%s ", w[i].p);
			
	}
	
	
	

	return 0;
}
