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
    int i,j;
    char s1[1005],s2[1005];
    while(gets(s1)){
        gets(s2);
        int l1=strlen(s1),l2=strlen(s2),a1[26]={0},a2[26]={0};
        for(i=0;i<l1;i++){a1[s1[i]-'a']++;}
        for(i=0;i<l2;i++){a2[s2[i]-'a']++;}
        for(i=0;i<26;i++){
            for(j=0;j<min(a1[i],a2[i]);j++){printf("%c",i+'a');}
        }
        printf("\n");
    }
    return 0;
}
