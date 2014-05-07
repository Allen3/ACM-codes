#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

struct Node{
    int x , y , z , step;
};  //Node

const int dx[6] = {0 , 0 , 0 , 0 , 1 , -1};
const int dy[6] = {0 , 0 , 1 , -1 , 0 , 0};
const int dz[6] = {1 , -1 , 0 , 0 , 0 , 0};

int L , R , C;
int S_x , S_y , S_z , E_x , E_y , E_z;
char Map[32][32][32];
bool vis[32][32][32];
int head , tail;
Node que[30000];

void solve(){
    que[1].x = S_x;
    que[1].y = S_y;
    que[1].z = S_z;
    que[1].step = 0;
    vis[S_x][S_y][S_z] = true;

    head = 0; tail = 1;
    while (head < tail){
        head ++;
        int xx = que[head].x , yy = que[head].y , zz = que[head].z;
        for (int k = 0;k < 6;k ++){
            int x = xx + dx[k];
            int y = yy + dy[k];
            int z = zz + dz[k];
            if (x >= 0 && x < L && y >= 0 && y < R && z >= 0 && z < C && Map[x][y][z] != '#' && !vis[x][y][z]){
                tail ++;
                que[tail].x = x;
                que[tail].y = y;
                que[tail].z = z;
                que[tail].step = que[head].step + 1;
                vis[x][y][z] = true;

                if (x == E_x && y == E_y && z == E_z){
                    printf("Escaped in %d minute(s).\n" , que[tail].step);
                    return;
                }
            }   //  accessible
        }   //for k _ 6
    }   //while
    printf("Trapped!\n");
}   //solve

int main(){
    char ch;

    while (scanf("%d%d%d%c" , &L , &R , &C , &ch) && (L | R | C)){
        memset(Map , 0 , sizeof(Map));
        memset(vis , 0 , sizeof(vis));

        for (int i = 0;i < L;i ++){
            for (int j = 0;j < R;j ++){
                for (int k = 0;k < C;k ++){
                    scanf("%c" , &Map[i][j][k]);
                    if (Map[i][j][k] == 'S'){
                        S_x = i;    S_y = j;    S_z = k;
                    }   //  S
                    else if (Map[i][j][k] == 'E'){
                        E_x = i;    E_y = j;    E_z = k;
                    }   //  E
                }   //for k _ C
                scanf("%c" , &ch);
            }   //for j _ R
            scanf("%c" , &ch);
        }   //for i _ L

        solve();

    }   //while

    return 0;
}   //main
