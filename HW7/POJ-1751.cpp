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
#include<set>
using namespace std;
int prim(int n,vector<float>g[]){
    int visit[n+5],parent[n+5];
    float dis[n+5];
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n+4;++i)
        dis[i]=999999999;
    dis[0]=0;
    parent[0]=0;
    for(int i=0;i<n;++i){
        int minn=-1;
        float mind=999999999;
        for (int j=0;j<n;++j){
            if(!visit[j]&&dis[j]<mind){
                minn=j;
                mind=dis[j];
            }
        }
        if(minn==-1)break;
        visit[minn]=true;
        for(int j=0;j<n;j++){
            if(!visit[j] && g[minn][j]<dis[j]){
                dis[j]=g[minn][j];
                parent[j]=minn;
            }
        }
    }
    for(int i=0;i<n;++i){
        if(parent[i]==i || g[parent[i]][i]==0)continue;
        printf("%d %d\n",parent[i]+1,i+1);
    }
    return 1;
}
int main(){
    int n,m,t1,t2;
    int city_x[1000],city_y[1000];
    vector<float>g[1000];
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        g[i].clear();
    }
    for(int i=0;i<n;++i){
        scanf("%d %d",&city_x[i],&city_y[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            float tmpx=(city_x[i]-city_x[j])*(city_x[i]-city_x[j]);
            float tmpy=(city_y[i]-city_y[j])*(city_y[i]-city_y[j]);
            g[i].push_back(sqrt(tmpx+tmpy));
        }
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d %d",&t1,&t2);
        g[t1-1][t2-1]=0;
        g[t2-1][t1-1]=0;
    }
    prim(n,g);
    return 0;
}
