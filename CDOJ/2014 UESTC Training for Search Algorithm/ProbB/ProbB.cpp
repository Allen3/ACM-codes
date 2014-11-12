#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

const int pwr[12] = {1 , 10 , 100 , 1000 , 10000 , 100000 , 1000000 , 10000000 , 100000000 , 1000000000};

int n , T;

int count(int num){
    int ans = 0;
    while (num){
        ans ++;
        num /= 10;
    }   //while
    return ans;
}   //count

bool check(int x , int y){
    long long tmp = (long long)x * (long long)x;
    int num = count(y);
    if (tmp % pwr[num] == y)
        return true;
    return false;
}   //check

bool dfs(int num , int lvl , int cnt , int tail , int n){
//TEST INFO
    //printf("num=%d lvl=%d cnt=%d tail=%d n=%d\n" , num , lvl , cnt , tail , n);

    if (lvl == cnt - 1){
        int ans1 , ans2;
        if (tail == 1){
            ans1 = num * 10 + 1;
            ans2 = num * 10 + 9;
        }   //  1 | 9
        else if (tail == 4){
            ans1 = num * 10 + 2;
            ans2 = num * 10 + 8;
        }   //  2 | 8
        else if (tail == 9){
            ans1 = num * 10 + 3;
            ans2 = num * 10 + 7;
        }   //  3 | 7
        else if (tail == 6){
            ans1 = num * 10 + 4;
            ans2 = num * 10 + 6;
        }   //  4 | 6
        else{
            ans1 = num * 10 + 5;
            ans2 = ans1;
        }   //  5

        if (check(ans1 , n)){
            printf("%d\n" , ans1);
            return true;
        }   //  ans1 check
        if (check(ans2 , n)){
            printf("%d\n" , ans2);
            return true;
        }   //  ans2 check
    }   //  tail 
    else{
        if (lvl == 0){
            for (int i = 1;i < 10;i ++)
                if (dfs(num * 10 + i , lvl + 1 , cnt , tail , n))
                    return true;
        }   //  No leading 0
        else{
            for (int i = 0;i < 10;i ++)
                if (dfs(num * 10 + i , lvl + 1 , cnt , tail , n))
                    return true;
        }
    }   //else
    return false;
}   //dfs

void solve(int n){
    int cnt = count(n);
    int cnt_sqrt = count(sqrt(n));
    int tail = n % 10;

    if (tail == 2 || tail == 3 || tail == 7 || tail == 8){
        printf("None\n");
        return ;
    }   //  No answer

    for (int i = cnt_sqrt;i <= cnt;i ++){
        if (dfs(0 , 0 , i , tail , n)){
            return ;
        }   //  if dfs find answer
    }   //for i | counts
    printf("None\n");
}   //solve

int main(){
    scanf("%d" , &T);
    while (T --){
        scanf("%d" , &n);
        if (n == 1000000000)
            printf("100000\n");
        else
            solve(n);
    }   //while 

    return 0;
}   //main
