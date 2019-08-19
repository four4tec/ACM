#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;
typedef struct ns{
    double x,y;
    struct ns operator-(struct ns in){
        struct ns out;
        out.x=this->x-in.x;
        out.y=this->y-in.y;
        return out;
    }
    struct ns operator=(struct ns in){
        this->x=in.x;
        this->y=in.y;
        return in;
    }
}point;
double det(point in1,point in2){
    return in1.x*in2.y-in2.x*in1.y;
}
int cross(point s1,point e1,point s2,point e2){
    int re=0;
    if(((det(s1-s2,e2-s2)*det(e1-s2,e2-s2))<0) &&
       ((det(s2-s1,e1-s1)*det(e2-s1,e1-s1))<0)){
        re=1;
    }
    if(s2.x==e2.x){
        if(s1.x==s2.x&&
           ((s1.y<=s2.y&&s1.y>=e2.y)||(s1.y>=s2.y&&s1.y<=e2.y))){
           re=1;
        }
        if(s1.x==e1.x&&
           !((s2.y>=s1.y&&e2.y>=s1.y&&s2.y>=e1.y&&e2.y>=e1.y)||(s2.y<=s1.y&&e2.y<=s1.y&&s2.y<=e1.y&&e2.y<=e1.y))){
            re=1;
        }
    }
    else if(s2.y==e2.y){
        if(s1.y==s2.y&&((s1.x<=s2.x&&s1.x>=e2.x)||(s1.x>=s2.x&&s1.x<=e2.x))){re=1;}
        if(s1.y==e1.y&&!((s2.x>=s1.x&&e2.x>=s1.x&&s2.x>=e1.x&&e2.x>=e1.x)||(s2.x<=s1.x&&e2.x<=s1.x&&s2.x<=e1.x&&e2.x<=e1.x))){re=1;}
    }
    return re;
}
int main(){
    int n;
    vector<int>ans;
    vector<point>alls;
    vector<point>alle;
    while(scanf("%d",&n) && n){
        ans.clear();
        alls.clear();
        alle.clear();
        for(int i=0;i<n;++i){
            point tmps;
            point tmpe;
            scanf("%lf %lf %lf %lf",&tmps.x,&tmps.y,&tmpe.x,&tmpe.y);
            alls.push_back(tmps);
            alle.push_back(tmpe);
        }
        for(int i=0;i<n-1;++i){
            int flag=1;
            for(int j=i+1;j<n;++j){
                if(cross(alls[i],alle[i],alls[j],alle[j])){
                    flag=0;
                    break;
                }
            }
            if(flag){
                ans.push_back(i+1);
            }
        }
        printf("Top sticks: ");
		for(int i=0;i<ans.size();++i){
            printf("%d, ",ans[i]);
		}
		printf("%d.\n",n);
    }
    return 0;
}
