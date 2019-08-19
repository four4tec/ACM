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
    int x,y;
}city;
bool compare(city in1,city in2){
    if(in1.x==in2.x)return in1.y<in2.y;
    return in1.x<in2.x;
}
//----
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
//----
//
int main(){
    int cases=0,t;
    int n,m,k;
    long long int ans=0;
    city all[1000005];
    scanf("%d",&t);
    while(cases!=t){
        ++cases;
        ans=0;
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<k;++i){
            scanf("%d %d",&all[i].x,&all[i].y);
        }
        sort(all,all+k,compare);
        //
        bin_index_tree tib;
        tib.s.clear();
        tib.s.resize(11000);
        tib.maxsize=m;
        for(int i=0;i<k;++i){
            ans+=(i-tib.sum(all[i].y));
            tib.update(all[i].y,1);
            //for(int j=0;j<m;++j){printf("%d ",tib.s[j]);}puts("");printf("%d\n",ans);
        }
        printf("Test case %d: %lld\n",cases,ans);
    }
    return 0;
}
