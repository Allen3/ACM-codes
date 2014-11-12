#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define input   "input.txt"
#define output  "test.txt"

struct node
{
    int x , y;
};  //node

const int dx[4] = {0 , 0 , 1 , -1};
const int dy[4] = {1 , -1 , 0 , 0};

int N , I , W , H;
int Map[110][110];
bool vis[110][110];
node que[101000];

void solve(int xx , int yy)
{
    if (!Map[yy][xx]) return ;

    memset(vis , 0 , sizeof(vis));

    int head = 0 , tail = 1;
    que[tail].x = xx;   que[tail].y = yy;

    while (head < tail){
        head ++;
        int x = que[head].x;
        int y = que[head].y;
        Map[y][x] ++;

        if (Map[y][x] > 4){
            if (vis[y][x]) continue;

            vis[y][x] = true;
            for (int k = 0;k < 4;k ++){
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx >= 0 && xx < W && yy >= 0 && yy < H && Map[yy][xx]){
                    tail ++;
                    que[tail].x = xx;
                    que[tail].y = yy;
                }   //  Range check
            }   //for k _ 4
        }   //  Able to erupt

    }   //while
}   //solve

int main()
{
//    freopen(input , "r" , stdin);
//    freopen(output , "w" , stdout);

    char ch;

    scanf("%d" , &N);
    while (N --){
        scanf("%d%d%c" , &W , &H , &ch);
        for (int i = 0;i < H;i ++){
            for (int j = 0;j < W;j ++){
                scanf("%c" , &ch);
                if (ch == 'X')          Map[i][j] = 0;
                else if (ch == 'A')     Map[i][j] = 1;
                else if (ch == 'B')     Map[i][j] = 2;
                else if (ch == 'C')     Map[i][j] = 3;
                else                    Map[i][j] = 4;
            }   //for j
            scanf("%c" , &ch);
        }   //for i
        scanf("%d" , &I);
        for (int i = 0;i < I;i ++){
            int x , y;
            scanf("%d%d" , &x , &y);
            solve(x , y);
        }   //for i _ I
        for (int i = 0;i < H;i ++){
            for (int j = 0;j < W;j ++){
                if (!Map[i][j])             printf("X");
                else if (Map[i][j] == 1)    printf("A");
                else if (Map[i][j] == 2)    printf("B");
                else if (Map[i][j] == 3)    printf("C");
                else                        printf("D");
            }   //for j
            printf("\n");
        }   //for i
    }   //while N--

    return 0;
}   //main
