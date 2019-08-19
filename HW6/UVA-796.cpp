#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define oo 1000
using namespace std;
int link[100][100],n,depth[100],low[100],used[100],cutBridge[100][100];
int DFS(int node, int d, int parent){
int i,back=oo,tmp;
depth[node]=d;
for(i=0;i<n;i++){if(link[node][i]==1){if(used[i]==0){
        used[i]=1;tmp=DFS(i,d+1,node);
        if(tmp>d){cutBridge[node][i]=1;cutBridge[i][node]=1;}
        back=back<tmp?back:tmp;}
        else{if(i!=parent){back=back<depth[i]?back:depth[i];}}}}
low[node]=back;
return low[node];}
int main(){
int x,y,m,i,j,Case=0;
while(scanf("%d",&n)==1){
        memset(link,0,sizeof(link));memset(depth,0,sizeof(depth));memset(low,0,sizeof(low));memset(used,0,sizeof(used));memset(cutBridge,0,sizeof(cutBridge));
        for(i=0;i<n;i++){
                scanf("%d ",&x);
                scanf("(%d)",&m);
                while(m--){
                        scanf("%d",&y);
                        link[x][y]=1;link[y][x]=1;}}
        for(i=0;i<n;i++){if(used[i]==0){used[i]=1;DFS(i,1,-1);}}
        int ans=0;
        for(i=0;i<n;i++){for(j=i+1;j<n;j++){if(cutBridge[i][j]!=0){ans++;}}}
        printf("%d critical links\n",ans);
        for(i=0;i<n;i++){for(j=i+1;j<n;j++){if(cutBridge[i][j]!=0){printf("%d - %d\n",i,j);}}}
        puts("");}
return 0;}
