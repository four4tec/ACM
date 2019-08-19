#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,i,j,k;
	int all[10010]={0};
	for(i=0;i<10010;i++){all[i]=1<<30;}
	all[0]=0;
	for(j=0;j<101;j++){
		for(i=j*j;i<10010;i++){
			all[i]= all[i] < all[i-j*j]+1 ? all[i] : all[i-j*j]+1;
		}
	}
	scanf("%d",&n);
	while(n--){
        scanf("%d",&k);
		printf("%d\n",all[k]);
	}
    return 0;
}
