#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int a,int b){return (a==0)?b:gcd(b%a,a);}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		printf("%10d%10d",n,m);
		if(gcd(n,m)==1){printf("    Good Choice\n\n");}
		else{printf("    Bad Choice\n\n");}
	}
	return 0;
}
