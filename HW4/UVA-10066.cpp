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
int LCS(int in1[],int len1,int in2[],int len2){
    int ans=0,all[len1+10][len2+10];
    memset(all,0,sizeof(all));
    for(int i=1;i<=len1;++i){
        for(int j=1;j<=len2;++j){
            if(in1[i]==in2[j])all[i][j]=all[i-1][j-1]+1;
            else all[i][j]= all[i-1][j]>all[i][j-1] ? all[i-1][j] : all[i][j-1];
        }
    }
    return all[len1][len2];
}
int main(){
    int i,j,n,m,c=0;
    while(1){
        scanf("%d%d",&n,&m);
        if(!n&&!m){break;}
        int s1[n+1],s2[m+1];
        for(i=1;i<=n;i++){scanf("%d",&s1[i]);}
        for(i=1;i<=m;i++){scanf("%d",&s2[i]);}
        printf("Twin Towers #%d\n",++c);
        printf("Number of Tiles : %d\n\n",LCS(s1,n,s2,m));
    }
    return 0;
}
