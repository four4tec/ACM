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
int main(){
    int cases,n;
    int all[160][160];
    int sum[160][160];
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                scanf("%d",&all[i][j]);
                all[i+n][j+n]=all[i][j];
                all[i][j+n]=all[i][j];
                all[i+n][j]=all[i][j];
            }
        }
        //count sum
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=2*n;++i){
            int tmpsum=0;
            for(int j=1;j<=2*n;++j){
                tmpsum+=all[i][j];
                sum[i][j]=tmpsum+sum[i-1][j];
            }
        }
        //find max
        int ans=-1*(1<<25);
        for(int i=1;i<=2*n;++i){
            for(int j=1;j<=2*n;++j){
                for(int k=max(0,i-n-1);k<i;++k){
                    for(int l=max(0,j-n-1);l<j;++l){
                        if(j-l<=n && i-k<=n){
                            ans=max(ans,sum[i][j]-sum[i][l]-sum[k][j]+sum[k][l]);
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
