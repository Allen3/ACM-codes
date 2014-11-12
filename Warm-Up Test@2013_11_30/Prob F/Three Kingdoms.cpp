/*
 *  ID:     Allen_3
 *  Prob:   Three Kingdoms
 *  LANG:   C++
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define     output      "test.txt"

struct node
{
    int dmg , def;
};  //node

int T , n , m;
node equip[1002];

inline int min(int a , int b)
{
    if (a < b)
        return a;
    return b;
}   //min

int main()
{
    //freopen(output , "w" , stdout);
    scanf("%d" , &T);
    for (int i = 0;i < T;i ++)
    {
        printf("Case #%d:\n" , i + 1);
        memset(equip , 0 , sizeof(equip));
        char ch;
        scanf("%d%d" , &n , &m);
        scanf("%c" , &ch);      //\n
        for (int i = 0;i < m;i ++)
        {
            scanf("%c" , &ch);
            if (ch == 'K')
            {
                int u , v , dis;
                scanf("%d%d" , &u , &v);
                if (u < v)
                    dis = min(v - u , u + n - v);
                else
                    dis = min(u - v , v + n - u);
                if (dis - equip[u].dmg + equip[v].def <= 1)
                    printf("Yes!\n");
                else
                    printf("I'm sorry.\n");
            }
            else
            {
                int u = 0 , num;
                while (ch != ' ')
                {
                    u = u * 10 + (ch - '0');
                    scanf("%c" , &ch);
                }   //
                scanf("%c" , &ch);          // + or -
                scanf("%d" , &num);
                if (ch == '+')
                {
                    equip[u].def = num;
                }
                else
                {
                    equip[u].dmg = num;
                }
            }
            scanf("%c" , &ch);  //\n
        }   //
        printf("\n");
    }   //  for T

    return 0;
}   //main
