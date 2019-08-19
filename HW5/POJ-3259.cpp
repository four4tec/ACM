#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<map>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
#define mmax 5005
#define nmax 1005
#define wmax 505
int SSSP(long int n,long int t,long int u[],long int v[],long int w[],long int d[]){
    int f;
    for(long int i=0;i<=n;++i)d[i]=1<<30;
    d[1]=0;
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
    long int ans=0,i,j,t3,f,n,m,w,s[mmax+wmax+1],e[mmax+wmax+1],t[mmax+wmax+1],d[nmax+1];
    scanf("%ld",&f);
    while(f--){
        ans=0;
        scanf("%ld%ld%ld",&n,&m,&w);
        for(i=1;i<=m;++i)
            scanf("%ld%ld%ld",&s[i],&e[i],&t[i]);
        for(i=m+1;i<=m*2;++i){
            s[i]=e[i-m];
            e[i]=s[i-m];
            t[i]=t[i-m];
        }
        for(i=2*m+1;i<=2*m+w;++i){
            scanf("%ld%ld%ld",&s[i],&e[i],&t3);
            t[i]=-t3;
        }
        if(SSSP(n,2*m+w,s,e,t,d))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
