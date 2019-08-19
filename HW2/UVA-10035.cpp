#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0){break;}
        int ans=0,c=0;
        while(n!=0 || m!=0){
            c=(n%10+m%10+c)/10;
            if(c){ans++;}
            n/=10;m/=10;
        }
        if(ans==1){printf("1 carry operation.\n");}
        else if(ans>1){printf("%d carry operations.\n",ans);}
        else{printf("No carry operation.\n");}
    }
    return 0;
}
