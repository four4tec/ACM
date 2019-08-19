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
int SSSP(long long int n,long long int t,long long int u[],long long int v[],long long int w[],long long int d[],long long int s){
    int f;
    for(long long int i=0;i<=n;++i)d[i]=1<<30;
    d[s]=0;
    for(long long int j=1;j<n;++j){
        f=1;
        for(long long int i=1;i<=t;++i){
            if(d[v[i]]>d[u[i]]+w[i]){
                d[v[i]]=d[u[i]]+w[i];
                f=0;
            }
        }
        if(f)break;
    }
    f=1;
    for(long long int i=1;i<=t;++i){
        if(d[v[i]]>d[u[i]]+w[i]){
            f=0;
        }
    }
    if(f)return 0;
    return 1;
}
int main(){
    long long int cases,n,m,s,t,c=0;
    long long int u[100005],v[100005],w[100005],d[100005];
    scanf("%lld",&cases);
    while(cases--){
        c++;
        scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
        for(int i=1;i<=m;++i){
            scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
            u[i+m]=v[i];
            v[i+m]=u[i];
            w[i+m]=w[i];
        }
        SSSP(n,2*m,u,v,w,d,s);
        printf("Case #%d: ",c);
        if(d[t]!=1<<30)printf("%d\n",d[t]);
        else puts("unreachable");
    }
    return 0;
}
