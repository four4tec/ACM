#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int SSSP(long int n,long int t,long int u[],long int v[],long int w[],long int d[]){
    int f;
    for(long int i=0;i<=n;++i)d[i]=1<<30;
    d[n]=0;
    for(long int j=1;j<n;++j){
        f=1;
        for(long int i=1;i<=t;++i){
            if(d[v[i]]>d[u[i]]+w[i]){
                d[v[i]]=d[u[i]]+w[i];
                f=0;
            }
        }
        if(f)break;
    }
    f=1;
    for(long int i=1;i<=t;++i){
        if(d[v[i]]>d[u[i]]+w[i]){
            f=0;
        }
    }
    if(f)return 0;
    return 1;
}
int main(){
    long int cases,n,m;
    long int u[2005],v[2005],w[2005];
    long int d[1005];
    scanf("%ld",&cases);
    while(cases--){
        memset(d,0,sizeof(d));
        scanf("%ld%ld",&n,&m);
        for(long int i=1;i<=m;++i)
            scanf("%ld%ld%ld",&u[i],&v[i],&w[i]);
        if(SSSP(n,m,u,v,w,d))puts("possible");
        else puts("not possible");
    }
    return 0;
}
