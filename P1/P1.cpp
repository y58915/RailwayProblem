#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

int coaches;
vector <int> train;
vector <int> input;
ifstream fin;
ofstream fout;

void exam(const vector<int>&);

int main()
{
	fin.open("lab1in.txt");
	fout.open("lab1out.txt");
	while (fin)
	{
		int temp;
		fin >> temp;
		input.push_back(temp);
	}

	int index = 0;
	while (input[index] != 0)
	{
		coaches = input[index];
		train.resize(coaches);
		index++;
		do
		{
			if (input[index] != 0)
			{
				for (int i = 0; i < coaches; i++)
				{
					train[i] = input[index];
					index++;
				}
				exam(train);
			}
		} while (input[index] != 0);
		index++;
	}

	fin.close();
	fout.close();

	return 0;
}

void exam(const vector<int>& train)
{
	stack<int> station;
	vector<int> incoming;
	int index = 0;

	for (int i = 0; i < train.size(); i++)
	{
		station.push(i + 1);
		while (!station.empty() && station.top() == train[index])
		{
			station.pop();
			index++;
		}
	}

	if (station.empty())
	{
		fout << "Yes" << endl;
	}
	else
	{
		fout << "No" << endl;
	}
}