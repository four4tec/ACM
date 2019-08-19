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
    int a1[22],a2[22],all[22][22]={0};
    int a[22],b,c=1,d,i,j;
    scanf("%d",&b);
    for(i=1;i<=b;i++){scanf("%d",&a[i]);}
    for(i=1;i<=b;i++){a1[a[i]]=i;}
    while(1){
        for(i=1;i<=b;i++){if(scanf("%d",&a[i])==EOF){return 0;;}}
        for(i=1;i<=b;i++){a2[a[i]]=i;}
        printf("%d\n",LCS(a1,b,a2,b));
    }
return 0;
}
