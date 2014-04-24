/*0ms,856KB*/

#define     input       "test.txt"
#define     output      "result1.txt"

#include<cstdio>

int main()
{
    freopen(input  , "r" , stdin);
    freopen(output , "w" , stdout);

	int T, n, m, cas = 1, max;
	scanf("%d", &T);
	for (; cas <= T; ++cas)
	{
		printf("Case #%d: ", cas);
		scanf("%d%d", &m, &n);
		printf("%d %d " , m , n);
		if ((m % 10) == 0) puts("INF");
		else if ((m % 5) == 0)
		{
			if ((n % 5) == 0) puts("INF");
			else
			{
				switch (m)
				{
					case 5: printf("%I64d\n", 55555LL + n + m); break;
					case 15: printf("%I64d\n", 5555555LL + n + m); break;
					case 25: case 35: puts("INF"); break;
					case 45: printf("%I64d\n", 5555555555555LL + n + m);
				}
			}
		}
		else
		{
			max = 9999 + n;
			if (max % 5 == 0) max += m;
			if (10000 + m > max) max = 10000 + m;
			printf("%d\n", max);
		}
	}
	return 0;
}
