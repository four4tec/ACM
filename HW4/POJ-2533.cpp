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
int LIS(int in[],int len){
    int ans=0,p[len+10],dp[len+10];
    for(int i=0;i<len;++i){
        p[i]=i;
        dp[i]=1;
    }
    for(int i=0;i<len;++i){
        int tmp=dp[i];
        for(int j=0;j<i;++j){
            if(in[j]<in[i] && dp[i]<=tmp+dp[j]){
                p[i]=j;
                dp[i]=tmp+dp[j];
            }
        }
    }
    for(int i=0;i<len;++i){
        if(ans<dp[i])ans=dp[i];
    }
    return ans;
}
int main(){
    int a[1000],n,c,d,f,g,k,i,j,p[1000],dp[1000];
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){scanf("%d",&a[i]);}
        printf("%d\n",LIS(a,n));
    }
    return 0;
}
