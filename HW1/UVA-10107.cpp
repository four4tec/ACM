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
    int n=0;
    int in;
    int all[10005];
    memset(all,0,sizeof(all));
    while(scanf("%d",&in)!=EOF){
        int t=n;
        for(int i=0;i<n;++i){
            if(all[i]>in){
                for(int j=n;j>=i;--j){
                    all[j]=all[j-1];
                }
                t=i;
                break;
            }
        }
        ++n;
        all[t]=in;
        //
        printf("%d\n",n%2?(all[n/2]):((all[n/2]+all[n/2-1])/2));
    }
    return 0;
}
