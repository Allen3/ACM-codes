#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int T , x , y , z;

int check_before_5(){
    if (x >= 1){
        if (x >=2 || y >= 1){
            if ((x >=3) || (x >=1 && y >= 1)){
                if ((x >= 4) || (x >= 2 && y >= 1) || (y >= 2))
                    return -1;
                else return 4;
            }   //  3
            else return 3;
        }   //  2
        else return 2;
    }   //  1
    else return 1;
}   //check_before_5

void solve(int index){
    int flag1 , ans;
    flag1 = check_before_5();
    if (flag1 == -1){
        ans = 1 + x + y * 2 + z * 5;
        printf("Case #%d: %d\n" , index , ans);
    }   //check_before_5
    else printf("Case #%d: %d\n" , index , flag1);
}   //solve

int main(){
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++){
        scanf("%d%d%d" , &x , &y , &z);
        solve(i + 1);
    }   //for i _ T

}   //main
