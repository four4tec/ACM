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
int main(){
    int t,w,n,f=0;
    while(~scanf("%d%d",&t,&w)){
        int d[40],v[40];
        int dp[1050],b[1050];
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d%d",&d[i],&v[i]);
            d[i]*=(3*w);
        }
        if(f)puts("");
        else f=1;
        memset(dp,0,sizeof(dp));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;++i){
            for(int j=t+5;j>=0;--j){
                if(j-d[i]>=0){
                    if(dp[j]<dp[j-d[i]]+v[i]){
                        dp[j]=dp[j-d[i]]+v[i];
                        b[j]=b[j-d[i]]+(1<<i);
                    }
                }
            }
        }
        int allbit=0;
        printf("%d\n",dp[t]);
        for(int i=0;i<31;++i){
            if( (1<<i) & b[t] )allbit++;
        }
        printf("%d\n",allbit);
        for(int i=0;i<31;++i){
            if( (1<<i) & b[t] )printf("%d %d\n",d[i]/3/w,v[i]);
        }
    }
    return 0;
}
