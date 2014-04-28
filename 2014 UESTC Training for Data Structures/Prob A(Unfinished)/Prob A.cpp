#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node{
    int level;
    int adjGrid[4]; //0 for up , 1 for left , 2 for right , 3 for down
};  //Node

int Z , n , m , T;
Node nodes[1000010];
bool vis[1000010];
Info arr[100010];

int main(){
    scanf("%d" , &Z);
    while (Z --){
        memset(vis , 0 , sizeof(vis));
        memset(nodes , -1 , sizeof(nodes));
        memset(arr , 0 , sizeof(arr));

        scanf("%d%d" , &n , &m);
        for (int i = 0;i < n;i ++)
            for (int j = 0;j < m;j ++){
                int index = i * n + j;
                scanf("%d" , &nodes[index].level);
                if (i > 0)
                    nodes[index].adjGrid[0] = index - n;
                if (j > 0)
                    nodes[index].adjGrid[1] = index - 1;
                if (j < m - 1)
                    nodes[index].adjGrid[2] = index + 1;
                if (i < n - 1)
                    nodes[index].adjGrid[3] = index + n;
            }   //for i j _ n m

        scanf("%d" , &T);
        for (int i = 0;i < T;i ++){
            scanf("%d" , &arr[i].year);
        }   //for i _ T


    }   //while
    return 0;
}   //main
