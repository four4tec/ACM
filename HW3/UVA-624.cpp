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
    int n;
    while(~scanf("%d",&n)){
        int track;
        int last[30];
        int dp[5000],b[5000];
        scanf("%d",&track);
        for(int i=0;i<track;++i){
            scanf("%d",&last[i]);
        }
        memset(b,0,sizeof(b));
        memset(dp,0,sizeof(dp));
        //
        for(int i=0;i<track;++i){
            for(int j=n+1;j>=0;--j){
                if(j-last[i]>=0){
                    if(dp[j]<dp[j-last[i]]+last[i]){
                        dp[j]=dp[j-last[i]]+last[i];
                        b[j]=b[j-last[i]]+(1<<i);
                    }
                }
            }
        }
        for(int i=0;i<=21;++i){
            if( (1<<i) & b[n] ){
                printf("%d ",last[i]);
            }
        }
        printf("sum:%d\n",dp[n]);
        //
    }
    return 0;
}
