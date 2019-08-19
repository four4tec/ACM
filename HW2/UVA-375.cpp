#include<cstdio>
#include<iostream>
#include<cmath>
#define pi 3.1415926535897932384626433
using namespace std;
int main(){
    int c;
    scanf("%d",&c);
    while(c--){
        double n,m,ans=0;
        scanf("%lf%lf",&n,&m);
        while(1){
            double t=hypot(n/2,m);
            double r=(n*m)/(2*t+n);
            if(r<0.000001){break;}
            ans+=(r*pi*2);
            double temp=m-2*r;
            n*=(temp/m);
            m=temp;
        }
        printf("%13.6lf\n",ans);
        if(c){printf("\n");}
    }
    return 0;
}
