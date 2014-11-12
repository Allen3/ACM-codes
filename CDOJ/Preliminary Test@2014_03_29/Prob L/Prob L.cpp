#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

double a1 , b1 , c1 , a2 , b2 , c2;

void solve(){
    double delta = (b1 - b2) * (b1 - b2) - 4 * (a1 - a2) * (c1 - c2);
    if (delta < 0){
        printf("0.000\n");
        return ;
    }
    else{
        double x1 = ((b2 - b1) - sqrt(delta)) / (2 * (a1 - a2));
        double x2 = ((b2 - b1) + sqrt(delta)) / (2 * (a1 - a2));
        double ans = 0;
        ans += (a2 - a1) / 3 * (x2 * x2 * x2 - x1 * x1 * x1);
        ans += (b2 - b1) / 2 * (x2 * x2 - x1 * x1);
        ans += (c2 - c1) * (x2 - x1);
        printf("%.3lf\n" , ans);
    }   //  delta >= 0
}   //solve

int main(){
    scanf("%lf%lf%lf" , &a1 , &b1 , &c1);
    scanf("%lf%lf%lf" , &a2 , &b2 , &c2);
    solve();

    return 0;
}   //main
