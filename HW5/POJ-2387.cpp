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
#define MAXN 2005
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
            if(d[u[i]]>d[v[i]]+w[i]){
                d[u[i]]=d[v[i]]+w[i];
                f=0;
            }
        }
        if(f)break;
    }
    return 1;
}
int main(){
	long int t,n,u[MAXN],v[MAXN],w[MAXN],d[MAXN],i,j;
	scanf("%ld %ld",&t,&n);
	for(i=1;i<=t;i++){scanf("%ld %ld %ld",&u[i],&v[i],&w[i]);}
	SSSP(n,t,u,v,w,d);
	printf("%ld\n",d[1]);
	return 0;
}
