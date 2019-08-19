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
    int a[100000],in[100000],b=0,c=0,d,e=0,g,i,j,k;
    while(1){
        b=0;e++;
        for(i=0;scanf("%d",&a[i])!=EOF&&a[i]!=-1;i++){b=i+1;}
        if(b==0){break;}
        if(e!=1){printf("\n");}
        for(int i=0;i<b;++i){in[i]=a[b-i-1];}
        printf("Test #%d:\n  maximum possible interceptions: %d\n",e,LIS(in,b));
        c=0;
    }
    return 0;
}
