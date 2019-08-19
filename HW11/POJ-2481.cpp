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
typedef struct ns{
    int e,s,id;
}cow;
bool com(cow in1,cow in2){
    if(in1.e==in2.e)return in1.s<in2.s;
    return in1.e>in2.e;
}
//
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
int main(){
    int n;
    int s,e;
    cow all[100005];
    while(scanf("%d",&n) && n){
        for(int i=0;i<n;++i){
            scanf("%d %d",&s,&e);
            ++s;
            ++e;
            all[i].s=s;
            all[i].e=e;
            all[i].id=i;
        }
        sort(all,all+n,com);
        //
        int et=-1,st=-1;
        int cnt=0;
        int ans[100005]={0};
        bin_index_tree tib;
        tib.s.clear();
        tib.s.resize(100005);
        tib.maxsize=100005;
        for(int i=0;i<n;++i){
            if(all[i].e==et && all[i].s==st){
                ++cnt;
            }
            else{
                cnt=0;
                st=all[i].s;
                et=all[i].e;
            }
            ans[all[i].id]=(tib.sum(all[i].s)-cnt);
            tib.update(all[i].s,1);
        }
        for(int i=0;i<n;++i){
            printf("%d ",ans[i]);
        }
        puts("");
    }
    return 0;
}
