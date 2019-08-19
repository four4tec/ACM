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
int exLIS(int in[],int len,int out[]){
    int ans=1,t,top;
    int chk[len+10],tmp[len+10];
    tmp[0]=in[0];
    chk[0]=1;
    for(int i=1;i<len;++i){
        t=lower_bound(tmp,tmp+ans,in[i])-tmp;
        tmp[t]=in[i];
        chk[i]=t+1;
        ans=t+1>ans?t+1:ans;
    }
    top=ans;
    for(int i=len-1;i>=0;--i){
        if(chk[i]==top){
            out[--top]=in[i];
        }
    }
    return ans;
}
int main() {
    int cases,n,t,all[4005],out[4005];
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&t);
            all[n+i]=t;
            all[n-i-1]=t;
        }
        if(n)printf("%d\n",exLIS(all,2*n,out));
        else printf("0\n");
    }
    return 0;
}
