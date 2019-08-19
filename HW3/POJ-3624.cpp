#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
#define max(a,b) a>b?a:b
using namespace std;
int main(){
    int n,m,i,j;
	scanf("%d%d",&n,&m);
	int v[n],w[n];
	for(i=0;i<n;i++){scanf("%d%d",&w[i],&v[i]);}
	int c[m+1];
	for(i=0;i<=m;i++){c[i]=0;}
	for(j=0;j<n;j++){for(i=m;i>=w[j];i--){c[i]=max(c[i],c[i-w[j]]+v[j]);}}
	printf("%d",c[m]);
    return 0;
}
