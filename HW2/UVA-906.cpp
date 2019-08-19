#include<cstdio>
#include<iostream>
#include<cmath>
#define eps 1e-8
using namespace std;
int main(){
    long long int i,a,b,c;
	while(scanf("%llu%llu",&a,&b)!=EOF){
		long double ab=(long double)a/b;
		double n;
		scanf("%lf",&n);
		for(i=1;;i++){
            c=(long long int)(ab*i);
            while(a*i>=b*c){c++;}
            long double t=(long double)c/i;
            if((t-ab)<=n){printf("%llu %llu\n",c,i);break;}
		}
	}
	return 0;
}
