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
    int n,q,an[50005],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%d",&an[i]);}
    sort(an,an+n);
    an[n]=1<<30;
    scanf("%d",&q);
    while(q--){
        int ch;
        scanf("%d",&ch);
        int t=lower_bound(an,an+n,ch)-an;
        while(ch<=an[t]){t--;}
        if(t<0){printf("X ");}
        else{printf("%d ",an[t]);}
        int g=upper_bound(an,an+n,ch)-an;
        while(ch>=an[g]){g++;}
        if(g>=n){printf("X\n");}
        else{printf("%d\n",an[g]);}
    }
	return 0;
}
