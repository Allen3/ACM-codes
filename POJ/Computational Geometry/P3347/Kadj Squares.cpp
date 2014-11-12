#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

struct point
{
	int left , right , len;
};	//point

point arr[55];
int n;

int main()
{
	while (scanf("%d" , &n) && n)
	{
		for (int i = 0;i < n;i ++)
		{
			scanf("%d" , &arr[i].len);
			arr[i].left = 0;
			for (int j = 0;j < i;j ++)
				arr[i].left = max(arr[i].left , arr[j].right - abs(arr[i].len - arr[j].len));
			arr[i].right = arr[i].left + (arr[i].len << 1);
		}	//for i _ n

		for (int i = 1;i < n;i ++)
		{
			for (int j = 0;j < i;j ++)
			{
				if (arr[j].left < arr[j].right)
				{
					if ((arr[i].left < arr[j].right) && (arr[i].len < arr[j].len))
						arr[i].left = arr[j].right;
					if ((arr[i].left < arr[j].right) && (arr[i].len > arr[j].len))
						arr[j].right = arr[i].left;

				}	//if 
			}	//for j _ n
		}	//for i _ n

		for (int i = 0;i < n;i ++)
			if (arr[i].left < arr[i].right)
				printf("%d " , i + 1);
		printf("\n");
	}	//while

	return 0;
}	//main

