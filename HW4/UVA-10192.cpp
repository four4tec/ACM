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
    char s1[105],s2[105];
    while(1){
        gets(s1);
        if(s1[0]=='#'&&s1[1]=='\0'){break;}
        gets(s2);
        int l1=strlen(s1),l2=strlen(s2);
        int array[105][105]={0};
        for (int i = 1; i <= l1; i++){
            for (int j = 1; j <= l2; j++){
                if(s1[i-1] == s2[j-1])array[i][j] = array[i-1][j-1] + 1;
                else{array[i][j] = array[i-1][j] > array[i][j-1] ? array[i-1][j] : array[i][j-1];}
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",++c,array[l1][l2]);
    }
    return 0;
}
