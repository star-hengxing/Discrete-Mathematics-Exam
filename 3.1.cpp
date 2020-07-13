#include<iostream>
#include<vector>
#include<string>
#include<time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	vector<vector<int> >sequence;
	vector<int>temp_vector;
	int i;
	bool flag = true;
	while (sequence.size() <= 720)
	{
		temp_vector.clear();
		for (i = 0; i < 6; ++i)
		{
			temp_vector.push_back(rand() % 5 + 1);
		}
		if (sequence.size() > 1)
		{
			for (const auto& x : sequence)
			{
				if (x == temp_vector)
				{
					flag = false;
					break;
				}
				else
				{
					flag = true;
				}
			}
		}
		if (flag)
		{
			sequence.push_back(temp_vector);
		}
	}

	for (i = 0; i < sequence.size(); i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (j == 5)
			{
				cout << sequence[i][j];
				break;
			}
			cout << sequence[i][j] << ",";
		}
		cout << endl;
	}
}