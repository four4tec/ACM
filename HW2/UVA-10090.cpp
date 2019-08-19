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
    long long int n,n1,n2,c1,c2,x,y,gcd,t,t1,t2,a1,a2,b1,b2;
    while(~scanf("%lld",&n) && n!=0){
        scanf("%lld %lld",&c1,&n1);
        scanf("%lld %lld",&c2,&n2);
        gcd=exgcd(n1,n2,x,y);
        if(n%gcd!=0){puts("failed");continue;}
        x=x*n/gcd;
        y=y*n/gcd;
        t1=n2/gcd;
        t2=n1/gcd;
        //
        if(x<0){
            t=-x/t1+(x%t1 != 0);
            x+=t*t1;
            y-=t*t2;
        }
        if(y<0){
            t=-y/t2+(y%t2 != 0);
            x-=t*t1;
            y+=t*t2;
        }
        if(x<0 || y<0){puts("failed");continue;}
        t=x/t1;
        x-=t*t1;
        y+=t*t2;
        a1=x;b1=y;

        t=y/t2;
        x+=t*t1;
        y-=t*t2;
        a2=x;b2=y;
        //
        if(a1*c1+b1*c2 < a2*c1+b2*c2)printf("%lld %lld\n",a1,b1);
        else printf("%lld %lld\n",a2,b2);
    }
    return 0;
}
