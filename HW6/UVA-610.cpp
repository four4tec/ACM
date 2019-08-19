#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>g[1005];
int vfind[1005],visited[1005],findIdx;
int dfs(int nd, int p) {
visited[nd]=1;
vfind[nd]=++findIdx;
int mn=vfind[nd],i;
for(i=0;i<g[nd].size();i++) {
if(!visited[g[nd][i]]) {
int b=dfs(g[nd][i],nd);
        if(b>vfind[nd]){printf("%d %d\n",nd,g[nd][i]);printf("%d %d\n",g[nd][i],nd);}
        else{printf("%d %d\n",nd,g[nd][i]);}
        mn=min(mn,b);}
else{
        if(g[nd][i]!=p){
                if(vfind[nd]>=vfind[g[nd][i]])
                printf("%d %d\n",nd,g[nd][i]);
                mn=min(mn,vfind[g[nd][i]]);}}}
return mn;}
int main(){
int n,m,cases=0,i,x,y;
while(scanf("%d %d",&n,&m)==2&&n){
        for(i=1;i<=n;i++){g[i].clear(),visited[i]=0;}
        while(m--){scanf("%d %d",&x,&y);g[x].push_back(y);g[y].push_back(x);}
        printf("%d\n\n", ++cases);
        for(i=1;i<=n;i++){
                if(visited[i]==0){findIdx=0;dfs(i,-1);}}
                puts("#");}
return 0;}
