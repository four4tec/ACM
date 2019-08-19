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
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int main(){
    int n,c=1,i,j,k;
    int x[1001],y[1001];
    double d[1001][1001];
    while(scanf("%d",&n)&&n){
        for(i=1;i<=n;i++)
            scanf("%d %d",&x[i],&y[i]);
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                d[i][j]=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
                d[j][i]=d[i][j];
            }
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
        printf("Scenario #%d\n",c++);
        printf("Frog Distance = %.3f\n\n",d[1][2]);
    }
    return 0;
}
