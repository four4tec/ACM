#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long int i,n,m;
	while(1){
		scanf("%lld",&n);
		if(n==-1)break;
		m=n;
		for(i=2;i<sqrt(n);i++){
			if(n%i==0){printf("    %lld\n",i);
				n=n/i;
				i--;
			}
			if(n==1){break;}
		}
		if(n!=1){printf("    %lld\n",n);}
		printf("\n");
	}
	return 0;
}
