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
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int e,f,n;
        int w[510],p[510],dp[10005]={0};
        scanf("%d%d",&e,&f);
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d%d",&p[i],&w[i]);
        }
        if(f<e){
            puts("This is impossible.");
            continue;
        }
        for(int i=0;i<f-e+10;++i){
            dp[i]=1<<25;
        }
        dp[0]=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<f-e+10;++j){
                if(j-w[i]>=0){
                    dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
                }
            }
        }
        //for(int i=0;i<f-e+10;++i){printf("%d ",dp[i]);}
        if(dp[f-e]==1<<25)puts("This is impossible.");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f-e]);
    }
    return 0;
}
