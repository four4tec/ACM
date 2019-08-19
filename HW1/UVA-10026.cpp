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
#include <set>
using namespace std;
typedef struct ns{
    int num;
    int day;
    int cost;
}work;
bool operator<(const work &a, const work &b){
    return ((double)a.cost/(double)a.day)>((double)b.cost/(double)b.day);
}
int main(){
    int cases;
    int n;
    work all[1005];
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d%d",&all[i].day,&all[i].cost);
            all[i].num=i+1;
        }
        sort(all,all+n);
        /*for(int i=0;i<n;++i){
            printf("%d %d %d\n",all[i].num,all[i].day,all[i].cost);
        }*/
        for(int i=0;i<n;++i){
            printf("%d",all[i].num);
            if(i!=n-1)putchar(' ');
        }
        puts("");
        if(cases)puts("");
    }
    return 0;
}
