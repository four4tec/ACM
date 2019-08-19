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
#define max_n (1<<25)
using namespace std;
typedef struct b_i_t{
    //
    vector<int>s;
    int maxsize;
    //
    int lowbit(int in){
        return in&(-in);
    }
    long long int sum(int index){
        long long int ans=0;
        while(index>0){
            ans+=s[index];
            index-=lowbit(index);
        }
        return ans;
    }
    int update(int index,int delta){
        for(int i=index;(i!=0 && i<=maxsize);i+=lowbit(i)){
            s[i]+=delta;
        }
    }
}bin_index_tree;
//
int main(){
    int n;
    int cache[35];
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&cache[i]);
    }
    //
    char input[100];
    int stop=0;
    int vis[max_n]={0};
    int now=0;
    int ans[35]={0};
    bin_index_tree tib;
    tib.s.clear();
    tib.s.resize(max_n);
    tib.maxsize=max_n;
    while(scanf("%s",input)){
        switch(input[0]){
            case 'E':
                stop=1;
                break;
            case 'A':
                int x;
                scanf("%d",&x);
                if(vis[x]){
                    int len=tib.sum(now)-tib.sum(vis[x]-1);
                    for(int i=0;i<n;++i){
                        if(cache[i]>=len)break;
                        ++ans[i];
                    }
                    tib.update(vis[x],-1);
                }
                else{
                    for(int i=0;i<n;++i){
                        ++ans[i];
                    }
                }
                ++now;
                vis[x]=now;
                tib.update(now,1);
                break;
            case 'R':
                int b,y,k;
                scanf("%d %d %d",&b,&y,&k);
                for(int j=0;j<k;++j){
                    int tmp=b+y*j;
                    if(vis[tmp]){
                        int len=tib.sum(now)-tib.sum(vis[tmp]-1);
                        for(int i=0;i<n;++i){
                            if(cache[i]>=len)break;
                            ++ans[i];
                        }
                        tib.update(vis[tmp],-1);
                    }
                    else{
                        for(int i=0;i<n;++i){
                            ++ans[i];
                        }
                    }
                    ++now;
                    vis[tmp]=now;
                    tib.update(now,1);
                }
                break;
            case 'S':
                for(int i=0;i<n;++i){
                    printf("%d",ans[i]);
                    if(i==(n-1)){printf("\n");}
                    else{printf(" ");}
                }
                memset(ans,0,sizeof(ans));
                break;
        }
        if(stop)break;
    }
    return 0;
}
