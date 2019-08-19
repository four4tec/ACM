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
#define INF 9999999
using namespace std;
int FLOYD(int n,vector<vector<int> >&dis){
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
    return 1;
}
int main(){
    vector<vector<int> >d;
    int n,i,j,k;
    d.resize(101);
    for(int i=0;i<101;++i)d[i].resize(101);
    while(scanf("%d",&n)&&n){
        for(i=1;i<=n;i++){
        	for(j=1;j<=n;j++){d[i][j]=INF;}
        	d[i][i]=0;
        }
        for(i=1;i<=n;i++){
        	int t,x,w;
        	scanf("%d",&t);
        	for(j=0;j<t;j++){scanf("%d %d",&x,&w);d[i][x]=w;}
        }
        FLOYD(n,d);
        int minl=INF,minpos,dis=1;
        for(i=1;i<=n;i++){
            int maxl=0,r=1;
            for(j=1;j<=n;j++){
                if(d[i][j]==INF){r=0;break;}
                else if(d[i][j]>maxl){maxl=d[i][j];}
            }
            if(r){
                dis=0;
                if(maxl<minl){
                    minl=maxl;
                    minpos=i;
                }
            }
        }
        if(dis)printf("disjoint\n");
        else printf("%d %d\n",minpos,minl);
    }
    return 0;
}
