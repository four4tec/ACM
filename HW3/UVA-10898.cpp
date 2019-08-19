#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cmath>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int test(int all,int combo){
    while(all>0 || combo>0){
        if(all%10 < combo%10)return 0;
        all/=10;
        combo/=10;
    }
    return 1;
}
int main(){
    int n,item[10];
    int c,comboitem[10],comboprice[10];
    int tmp=0;
    int cases;
    vector<int>dp;
    dp.resize(1000010);
    while(~scanf("%d",&n)){
        dp.clear();
        dp.resize(1000010);
        memset(item,0,sizeof(item));
        memset(comboitem,0,sizeof(comboitem));
        memset(comboprice,0,sizeof(comboprice));
        for(int i=0;i<n;++i){
            scanf("%d",&item[i]);
        }
        scanf("%d",&c);
        for(int i=0;i<c;++i){
            for(int j=0;j<n;++j){
                scanf("%d",&tmp);
                comboitem[i]*=10;
                comboitem[i]+=tmp;
            }
            scanf("%d",&comboprice[i]);
        }
        //
        int maxprice=0,t=0;
        for(int i=0;i<pow(10,n)+5;++i){
            t=i;
            maxprice=0;
            for(int j=0;j<n;j++){
                dp[i]+=(t%10)*item[n-1-j];
                t/=10;
            }
        }
        dp[0]=0;
        for(int i=0;i<c;++i){
            for(int j=0;j<=pow(10,n)+4;++j){
                if(test(j,comboitem[i]) && j>=comboitem[i]){
                    dp[j]=min(dp[j],dp[j-comboitem[i]]+comboprice[i]);
                }
            }
        }
        //for(int i=0;i<pow(10,n)+4;++i){printf("%5d",dp[i]);if(i%10==9)puts("");}puts("");
        //
        scanf("%d",&cases);
        while(cases--){
            int tmp,in=0;
            for(int i=0;i<n;++i){
                scanf("%d",&tmp);
                in*=10;
                in+=tmp;
            }
            //printf("%d\n",in);
            printf("%d\n",dp[in]);
            //for(int i=0;i<n;i++){scanf}
        }
    }
    return 0;
}
