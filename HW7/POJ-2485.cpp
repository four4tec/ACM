
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
int ans;
int prim(int n,vector<int>g[])
{
    int visit[n+5],parent[n+5],dis[n+5];
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n+4;++i)
        dis[i]=1<<30;
    dis[0]=0;
    parent[0]=0;
    for(int i=0;i<n;++i){
        int minn=-1,mind=1<<30;
        for (int j=0;j<n;++j){
            if(!visit[j]&&dis[j]<mind){
                minn=j;
                mind=dis[j];
            }
        }
        if(minn==-1)break;
        if(mind>ans){ans=mind;}
        visit[minn]=true;
        for(int j=0;j<n;j++){
            if(!visit[j] && g[minn][j]<dis[j]){
                dis[j]=g[minn][j];
                parent[j]=minn;
            }
        }
    }
    return 1;
}
int main(){
    int cases,n,t;
    vector<int>g[502];
    scanf("%d",&cases);
    while(cases--){
        ans=0;
        scanf("%d",&n);
        for(int i=0;i<n+1;++i)
            g[i].clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&t);
                g[i].push_back(t);
            }
        }
        prim(n,g);
        printf("%d\n",ans);
    }
    return 0;
}
