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
/*
int SPFA(int n,int t,int u[],int v[],int w[],int d[]){
    queue<int>q;
    int inqueue[n+5];
    //initial
    memset(inqueue,0,sizeof(inqueue));
    for(int i=0;i<=n;++i)d[i]=1<<30;
    d[n]=0;
    inqueue[n]=1;
    q.push(n);
    //
    while(!q.empty()){
        int now=q.front();
        inqueue[now]=0;
        q.pop();
        for(int i=0;;++i){
            ;
        }
    }
    return 1;
}
*/
int main(){
    int n,m,s,i,j,a,b,now,nxt;
    double r[105][105]={0},c[105][105],d[105]={0};
    double v,rab,rba,cab,cba;
    vector<int>edge[105];
    queue<int>q;
    bool in[105]={0};
    scanf("%d %d %d %lf",&n,&m,&s,&v);
    for(i=0;i<m;i++){
        scanf("%d %d %lf %lf %lf %lf",&a,&b,&rab,&cab,&rba,&cba);
        r[a][b]=rab;
        r[b][a]=rba;
        c[a][b]=cab;
        c[b][a]=cba;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    d[s]=v;
    q.push(s);
    in[s]=true;
    while(!q.empty()){
        now=q.front();
        in[now]=false;
        q.pop();
        for(i=0;i<edge[now].size();i++){
            nxt=edge[now][i];
            if( d[nxt] < (d[now]-c[now][nxt])*r[now][nxt] ){
                d[nxt]=(d[now]-c[now][nxt])*r[now][nxt];
                if(!in[nxt]){
                    q.push(nxt);
                    in[nxt]=true;
                }
            }
        }
    }
    if(d[s]>v)printf("YES\n");
    else{printf("NO\n");}
    return 0;
}
