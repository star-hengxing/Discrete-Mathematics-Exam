#include<iostream>

using namespace std;

int main()
{
	for (int i = 0;; i++)
	{
		if (pow(2, i) > 10000000000)
		{
			printf("%d月,大概%d年多", i,i/12);
			break;
		}
	}
	printf("\n");
	return 0;
}