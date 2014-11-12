#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define     MAX_NUM     10000

struct Node{
    int val , step;
};  //Node

int T , N , M;
int P[MAX_NUM] , cnt;
bool Iscomp[MAX_NUM];
bool vis[MAX_NUM];
Node que[400000];
int head , tail;

void preprocess(){
    memset(Iscomp , 0 , sizeof(Iscomp));
    cnt = 0;
    for (int i = 2;i < MAX_NUM;i ++){
        if (!Iscomp[i]) P[cnt ++] = i;
        for (int j = 0;j < cnt && P[j] * i < MAX_NUM;j ++){
            Iscomp[P[j] * i] = true;
            if (i % P[j] == 0) break;
        }   //for j 
    }   //for i _ MAX_NUM
}   //preprocess

int transfer(int val , int k , int num){
    if (k == 0 && num == 0)
        return -1;

    char str[5];
    int div = 1000;
    for (int i = 0;i < 4;i ++){
        str[i] = (val / div) + '0';
        val %= div;
        div /= 10;
    }   //for i _ 4

    str[k] = num + '0';

    int ans = 0;
    for (int i = 0;i < 4;i ++)
        ans = ans * 10 + str[i] - '0';

    return ans;
}   //transfer

void solve(){
    que[1].val = N;
    que[1].step = 0;
    vis[N] = true;
    head = 0; tail = 1;
    if (N == M){
        printf("0\n");
        return ;
    }

    while (head < tail){
        head ++;
        for (int k = 0;k < 4;k ++)
            for (int num = 0;num < 10;num ++){
                int new_num = transfer(que[head].val , k , num);
                if (new_num != -1 && !Iscomp[new_num] && !vis[new_num]){
                    tail ++;
                    que[tail].val = new_num;
                    que[tail].step = que[head].step + 1;
                    vis[new_num] = true;
                }   //  add
                if (new_num == M){
                    printf("%d\n" , que[tail].step);
                    return ;
                }   //  End
            }   //for k & num
    }   //while
    printf("Impossible\n");
}   //solve

int main(){
    preprocess();
    scanf("%d" , &T);
    while (T --){
        memset(vis , 0 , sizeof(vis));

        scanf("%d%d" , &N , &M);
        solve();
    }   //while 

    return 0;
}   //main
