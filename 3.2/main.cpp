#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int i;
	vector<int>two;
	vector<int>three;
	vector<int>two_and_three;
	string temp;
	for (i = 1; i < 50; i++)
	{
		temp = "";
		temp += to_string(i);
		if (temp.find("2") != string::npos)
		{
			two.push_back(i);
		}
		if (temp.find("3") != string::npos)
		{
			three.push_back(i);
		}
		if (temp.find("3") != string::npos || temp.find("2") != string::npos)
		{
			two_and_three.push_back(i);
		}
	}
	cout << "包含数字2:";
	cout << endl;
	for (const auto& x : two)
	{
		cout << x << " ";
	}
	printf("\n");
    printf("共有%d个",two.size());
    printf("\n");
	printf("\n");
	cout << "包含数字3:";
	printf("\n");
	for (const auto& x : three)
	{
		cout <<  x << " ";
	}
	printf("\n");
    printf("共有%d个",three.size());
    printf("\n");
	printf("\n");
    cout << "包含数字3和2:";
    printf("\n");
	for (const auto& x : two_and_three)
	{
		cout << x << " ";
	}
    printf("\n");
    printf("共有%d个",two_and_three.size());
	printf("\n");
}