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
int main(){
    int ans;
    int n;
    int all[1010];
    while(scanf("%d",&n)!=EOF){
        ans=0;
        for(int i=0;i<n;++i){
            scanf("%d",&all[i]);
        }
        for(int i=0;i<n;++i){
            for(int j=n-1;j>i;--j){
                if(all[j]<all[j-1]){
                    all[j]^=all[j-1];
                    all[j-1]^=all[j];
                    all[j]^=all[j-1];
                    ++ans;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",ans);
    }
    return 0;
}
