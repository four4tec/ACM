#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long int n,m;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        if(n==0){break;}
        if(n>m){n^=m;m^=n;n^=m;}
        printf("%lld\n",n*m*(m-1)+n*m*(n-1)+4*(2*(n*(n-1)*(n-2)/6)+(m-n+1)*n*(n-1)/2));
    }
    return 0;
}