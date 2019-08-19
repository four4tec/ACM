#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cmath>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
long long int exgcd(long long int a,long long int b,long long int &x,long long int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    else{
        long long int gcd=exgcd(b,a%b,x,y);
        long long int temp=x;
        x=y;
        y=temp-(a/b)*y;
        return gcd;
    }
}
int main(){
    long long int in1,in2,x,y,gcd;
    while(~scanf("%lld %lld",&in1,&in2)){
        gcd=exgcd(in1,in2,x,y);
        printf("%lld %lld %lld\n",x,y,gcd);
    }
    return 0;
}
