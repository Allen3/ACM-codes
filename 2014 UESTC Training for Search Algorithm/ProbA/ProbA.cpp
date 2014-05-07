#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct Node{
    int x , y , status;
};   //Node

const int dx[4] = {0 , 1 , 0 , -1};
const int dy[4] = {1 , 0 , -1 , 0};

int T , N , M;
int L_x , L_y , Q_x , Q_y;
Node Map[55][55] , transfer[30];
int head , tail;
Node que[3000];
bool vis[55][55];

void solve(){
    que[1].x = L_x; que[1].y = L_y; que[1].status = 0;
    vis[L_x][L_y] = true;
    head = 0; tail = 1;

    while (head < tail){
        head ++;
        int xx = que[head].x , yy = que[head].y;
        for (int k = 0;k < 4;k ++){
            int x = xx + dx[k] , y = yy + dy[k];
            if (x >= 0 && x < N && y >= 0 && y < M && Map[x][y].status != '#'){
                if (Map[x][y].status != '.'){
                    int x_trans = Map[x][y].x;
                    int y_trans = Map[x][y].y;
                    x = x_trans;
                    y = y_trans;
                }   //  transfer
                if (!vis[x][y]){
                    tail ++;
                    que[tail].x = x;
                    que[tail].y = y;
                    que[tail].status = que[head].status + 1;
                    vis[x][y] = true;
                }   //  add
                if (x == Q_x && y == Q_y){
                    printf("%d\n" , que[tail].status);
                    return;
                }   //  End
            }   //  accessible
        }   //for k _ 4
    }   //while
    printf("-1\n");
}   //solve

int main(){
    char ch;

    scanf("%d" , &T);
    while (T --){
        memset(Map , 0 , sizeof(Map));
        memset(transfer , 0 , sizeof(transfer));
        memset(vis , 0 , sizeof(vis));

        scanf("%d%d%c" , &N , &M , &ch);
        for (int i = 0;i < N;i ++){
            for (int j = 0;j < M;j ++){
                scanf("%c" , &Map[i][j].status);
                if (Map[i][j].status == 'L'){
                    L_x = i;    L_y = j;
                    Map[i][j].status = '.';
                }   //  L
                else if (Map[i][j].status == 'Q'){
                    Q_x = i;    Q_y = j;
                    Map[i][j].status = '.';
                }   //  Q
                else if (Map[i][j].status != '.' && Map[i][j].status != '#'){
                    if (transfer[Map[i][j].status - 'a'].status){
                        Map[transfer[Map[i][j].status - 'a'].x][transfer[Map[i][j].status - 'a'].y].x = i;
                        Map[transfer[Map[i][j].status - 'a'].x][transfer[Map[i][j].status - 'a'].y].y = j;

                        Map[i][j].x = transfer[Map[i][j].status - 'a'].x;
                        Map[i][j].y = transfer[Map[i][j].status - 'a'].y;
                    }   //

                    transfer[Map[i][j].status - 'a'].x = i;
                    transfer[Map[i][j].status - 'a'].y = j;
                    transfer[Map[i][j].status - 'a'].status = 1;
                }   //  transfer 

            }   //for j _ N
            scanf("%c" , &ch);
        }   //for i _ N

        solve();

    }   //while T --

    return 0;
}   //main
