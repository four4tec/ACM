#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m,i,j;
    long long int all[205][205]={1};
    for(i=0;i<205;i++){all[i][0]=1;}
    for(i=1;i<205;i++){
        for(j=1;j<=i;j++){
            all[i][j]=(all[i-1][j-1]+all[i-1][j])%1000000;
        }
    }
	while(1){
        scanf("%d%d",&n,&m);
        if(!n || !m){break;}
		printf("%lld\n",all[n+m-1][m-1]);
	}
    return 0;
}
