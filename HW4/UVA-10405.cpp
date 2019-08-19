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
int LCS(char in1[],int len1,char in2[],int len2){
    int ans=0,all[len1+10][len2+10];
    memset(all,0,sizeof(all));
    for(int i=1;i<=len1;++i){
        for(int j=1;j<=len2;++j){
            if(in1[i-1]==in2[j-1])all[i][j]=all[i-1][j-1]+1;
            else all[i][j]= all[i-1][j]>all[i][j-1] ? all[i-1][j] : all[i][j-1];
        }
    }
    return all[len1][len2];
}
int main(){
    int i,j,n,m,c=0;
    char s1[1005],s2[1005];
    while(gets(s1)){
        gets(s2);
        printf("%d\n",LCS(s1,strlen(s1),s2,strlen(s2)));
    }
    return 0;
}
