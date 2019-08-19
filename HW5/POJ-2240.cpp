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
    int n,m,cases=1,i,j,k;
    double r[35][35]={0};
    double rate;
    char a[100],b[100];
    bool ans;
    while(scanf("%d",&n)&&n){
        map<string,int>Map;
        memset(r,0,sizeof(r));
        for(i=0;i<n;++i)
            r[i][i]=1;
       	for(i=0;i<n;++i){
       	 	scanf("%s",a);
        	Map[a]=i;
        }
        scanf("%d",&m);
        for(i=0;i<m;++i){
        	scanf("%s %lf %s",a,&rate,b);
        	r[Map[a]][Map[b]]=rate;
        }
        for(k=0;k<n;++k)
            for(i=0;i<n;++i)
                for(j=0;j<n;++j)
                    r[i][j]=max(r[i][k]*r[k][j],r[i][j]);
        ans=false;
        for(i=0;i<n;++i){
            if(r[i][i]>1){
                ans=true;
                break;
            }
        }
        printf("Case %d: ",cases++);
        if(ans){printf("Yes\n");}
        else{printf("No\n");}
    }
    return 0;
}
