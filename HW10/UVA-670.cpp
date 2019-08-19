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
int out[105];
bool bi_dfs(int now,vector<int>g[],int llink[],int rlink[],bool used[]){
    for(int i=0;i<g[now].size();++i){
        int nxt=g[now][i];
        if(used[nxt])continue;
        used[nxt]=true;
        if(rlink[nxt]==-1 || bi_dfs(rlink[nxt],g,llink,rlink,used)){
            llink[now]=nxt;
            rlink[nxt]=now;
            return true;
        }
    }
    return false;
}
int bi_match(int n,int m,vector<int>g[]){
    int ans=0;
    int llink[n+5],rlink[m+5];
    bool used[m+5];
    fill(llink,llink+n,-1);
    fill(rlink,rlink+m,-1);
    for(int i=0;i<n;++i){
        fill(used,used+m,false);
        if(bi_dfs(i,g,llink,rlink,used))
            ans++;
    }
    for(int i=0;i<n;++i){
        out[i]=llink[i];
    }
    return ans;
}
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int n,m;
        int x1[105],y1[105];
        int x2[105],y2[105];
        vector<int>g[105];
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;++i){
            scanf("%d %d",&x1[i],&y1[i]);
            g[i].clear();
        }
        for(int i=0;i<m;++i){
            scanf("%d %d",&x2[i],&y2[i]);
        }
        for(int i=0;i<n-1;++i){
            double len=2*sqrt((x1[i]-x1[i+1])*(x1[i]-x1[i+1])+(y1[i]-y1[i+1])*(y1[i]-y1[i+1]));
            for(int j=0;j<m;++j){
                double len1=sqrt((x1[i]-x2[j])*(x1[i]-x2[j])+(y1[i]-y2[j])*(y1[i]-y2[j]));
                double len2=sqrt((x1[i+1]-x2[j])*(x1[i+1]-x2[j])+(y1[i+1]-y2[j])*(y1[i+1]-y2[j]));
                if(len1+len2<=len)
                    g[i].push_back(j);
            }
        }
        printf("%d\n",n+bi_match(n,m,g));
        for(int i=0;i<n;++i){
            if(i!=0){putchar(' ');}
            printf("%d %d",x1[i],y1[i]);
            if(out[i]!=-1){
                printf(" %d %d",x2[out[i]],y2[out[i]]);
            }
        }
        printf("\n");
        if(cases){printf("\n");}
    }
    return 0;
}
