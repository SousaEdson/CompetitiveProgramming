#include<bits/stdc++.h>
using namespace std;

bool visitados[4000];

vector<int> primos;
int num;

bool isPrime(int num){
	for(int i=2; i*i<=num; i++)
		if(num%i==0) return false;
	return true;
}

void preenchePrimo(){
	vector<int> vetor;
	for(int i=2; i<num; i++){
		if(isPrime(i)) vetor.push_back(i);
	}
	primos.push_back(1);
	
	for(int i=1; i<vetor.size(); i++){
		primos.push_back((vetor[i] - vetor[i-1]));
	}		
}

int main(){
	
	while(scanf("%d", &num) && num!=0){
		memset(visitados, false, sizeof(visitados));
		int pos = 0;
		for(int i=0; i<num-1; i++){
			pos = (pos + proxPrimo(i))%num;
			
			if(!visitados[pos]) visitados[pos] = true;			 
			else{			
				while(visitados[pos]){
					pos = (pos+1)%num;
				}
				visitados[pos] = true;							
			}		
		}
	
		for(int i=0; i<num; i++){
			if(visitados[i]!=true){
				printf("%d\n", i+1);
				break;
			}
		}
	}

return 0;
}
