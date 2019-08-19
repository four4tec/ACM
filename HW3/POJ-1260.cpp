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
    int a[1050],p[1050],sum[1050],dp[1050]={0},cases,c;
    scanf("%d",&cases);
    while(cases--){
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        scanf("%d",&c);
        for(int i=1;i<=c;++i){
            scanf("%d%d",&a[i],&p[i]);
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1;i<=c;++i){
            dp[i]=sum[i]*p[i]+10*p[i];
        }
        for(int i=1;i<=c;++i){
            for(int j=1;j<=i;++j){
                dp[i]=min(dp[i],(sum[i]-sum[j]+10)*p[i]+dp[j]);
            }
        }
        printf("%d\n",dp[c]);
    }
    return 0;
}
