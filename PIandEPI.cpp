#include <iostream>
#include <fstream>
#include "stdlib.h"
#include <iomanip>
using namespace std;
#include<vector>
#include <map>
#include<string>
map<int, int>::iterator it;
bool flag;
vector<int> store;
struct Reps
{
	int decimal;
	string binary;
	bool primecheck;
	bool dontcarescheck;
	vector<int> comb;
};
vector<Reps> essentials;
void  readfile()
{
	cout << "Please enter filename" << endl;
	string filename;
	cin >> filename;
	ifstream file1;
	int i;
	file1.open(filename);
	if (file1.fail())
		cout << "Error, Cannot Read File" << endl;
	if (file1.is_open())
	{
		while (!file1.eof())

		{
			file1 >> i;
			store.push_back(i);
		}

	}
	file1.close();
}
int noofones(string test)
{

	int count = 0;
	for (int j = 0; j < test.size(); j++)
	{
		if (test.at(j) == '1')//checking number of ones in each element
			count++;
	}
	return count;
}



vector<string> binaryrep()
{

	vector <int> temp = store;
	int i;
	i = temp.back();
	temp.pop_back();
	int x;
	string y = "";
	vector <string> binary;
	for (int j = 1; j<temp.size(); j++)

		x = temp.back();
	temp.pop_back();
	while (x != 0)

		if (x % 2 == 0)

			y += "0";

		else

			y += "1";

	x = x / 2;

	binary.push_back(y);
	y = "";

	return binary;
}

vector <Reps> repsfun()
{
	vector<Reps> repss;
	vector<int>t = store;   // the name of the function that will read the file
	vector <string> temp2 = binaryrep();
	// change during assembling
	int counter = t[0];
	for (int i = 1; i<t.size(); i++) // t is the name of the vector that will store the return of the function
	{
		Reps minterm;
		minterm.decimal = t[i];
		minterm.binary = temp2[i];
		if (i<counter)
			minterm.dontcarescheck = 0;
		else
			minterm.dontcarescheck = 1;
		repss.push_back(minterm);

	}

	return repss;    // change that name repss later to be more indicative
}

vector< vector<Reps>> organize(vector<Reps> temp)
{
	vector< vector<Reps>> group;
	for (int i = 0; i< temp.size(); i++)
	{
		int tempno = noofones(temp[i].binary);
		switch (tempno)

		{

		case 0:
			group[0].push_back(temp[i]);
			break;

		case 1:
			group[1].push_back(temp[i]);
			break;

		case 2:
			group[2].push_back(temp[i]);
			break;

		case 3:
			group[3].push_back(temp[i]);
			break;

		case 4:
			group[4].push_back(temp[i]);
			break;

		case 5:
			group[5].push_back(temp[i]);
			break;

		case 6:
			group[6].push_back(temp[i]);
			break;

		case 7:
			group[7].push_back(temp[i]);
			break;

		case 8:
			group[8].push_back(temp[i]);
			break;

		case 9:
			group[9].push_back(temp[i]);
			break;

		case 10:
			group[10].push_back(temp[i]);
			break;

		case 11:
			group[11].push_back(temp[i]);
			break;

		case 12:
			group[12].push_back(temp[i]);
			break;

		case 13:
			group[13].push_back(temp[i]);
			break;

		case 14:
			group[14].push_back(temp[i]);
			break;

		case 15:
			group[15].push_back(temp[i]);
			break;

		case 16:
			group[16].push_back(temp[i]);
			break;
			//.......... up until 16

		}
	}
	return  group;

}

//minterm.binary= binaryrep(t[i]);
string D_replace(string x, string y)
{
	string temp = "";
	for (int i = 0; i<x.size(); i++)
	{

		if (x.at(i) == y.at(i))
			temp = temp + x.at(i);
		else
			temp = temp + '-';   //write -instead of 0/1 in the new string

	}

	return temp;

}
bool Bitdiff(string x, string y)
{
	int count = 0;
	bool check;
	for (int i = 0; i< x.size(); i++)

		if (x.at(i) == y.at(i))
			check = true;
		else

			if (count>1)

			{
				check = false;
				break;
			}

			else

				check = true;
	count++;


	if (count>1)
		check = 0;

	return check;

}

vector<Reps> compare(vector< vector<Reps>> groups)
{
	bool flag = false;

	vector<Reps> group2;

	for (int c = 0; c<16; c++) // this 16 will be changed later after the code is completed
	{

		for (int i = 0; i< groups[c].size(); i++)
		{
			for (int j = 0; j<groups[c + 1].size(); j++)
			{
				if (Bitdiff(groups[i][j].binary, groups[i++][j].binary)) //assuming that we have a //function  called bitdiff
				{
					flag = true;

					groups[i][j].primecheck = 1;
					groups[i++][j].primecheck = 1;
					Reps temp;
					temp.binary = D_replace(groups[i][j].binary, groups[i++][j].binary);
					if (groups[i][j].comb.size() != 0)
					{
						temp.comb = groups[i][j].comb;   // just copying content of vector x[i] into temp
						temp.comb.insert(temp.comb.end(), groups[i++][j].comb.
							begin(), groups[i++][j].comb.end());

					}
					else
					{
						temp.comb.push_back(groups[i][j].decimal);
						temp.comb.push_back(groups[i++][j].decimal);

						group2.push_back(temp);
					}
					if (groups[i][j].primecheck != 1)
						essentials.push_back(groups[i][j]);
				}
			}
		}
	}
	return group2;
}




void printessentials()
{
	vector<int> stored = store;
	vector<Reps> E;
	map <int, int> Mapp;
	vector<int> A;
	vector <int> X;
	int x = stored[0];
	int t = 0;
	int c = (char)'a';
	bool flag = false;
	cout << "Essential Prime Implicants are:" << endl;
	cout << "_________________________" << endl;
	for (int i = 0; i < x; i++)

		A[i] = stored[i + 1];

	for (int i = 0; i < E.size(); i++)
		for (int j = 0; j< E[i].comb.size(); j++)
		{
			for (int m = 0; m < x; m++)

				if (A[m] == E[i].comb[j])

					if (Mapp.find(E[i].comb[j]) != Mapp.end())
						Mapp[E[i].comb[j]]++;
					else
						Mapp[E[i].comb[j]] = 1;
			break;
		}

	for (it = Mapp.begin(); it != Mapp.end(); ++it)
	{


		if (it->second == 1)
			X[t] = it->first;
		t = 0;
	}

	for (int k = 0; k <t; k++)
		for (int i = 0; i < E.size(); i++)
			for (int j = 0; j< E[i].comb.size(); j++)

			{

				while (!flag)
				{
					if (X[k] == E[i].comb[j])

						flag = true;
					j = 0;
				}

				while ((flag) && (j <= E[i].comb.size() - 1))
				{
					c += E[i].comb[j];
					cout << (char)c << setw(3);
					c = (char)'a';
				}


				flag = false;
				cout << endl;
			}
}
void  cont()
{
	vector< vector<Reps>> temp2;
	vector<Reps> temp = repsfun();
	while (flag)

		temp2 = organize(temp);
	compare(temp2);
	temp = compare(temp2);


}
void printprime()
{
	vector<Reps> essential = essentials;
	string x;
	int c = (char)'a';
	cout << "Prime Implicants are:" << endl;
	cout << "_________________" << endl;
	for (int i = 0; i < essential.size(); i++)
	{
		x = essential[i].binary;
		for (int j = 0; j < x.length(); j++)

			if (x[j] == '0')
				cout << setw(3) << char(c + j) << "'";
			else if (x[j] == '1')
				cout << setw(3) << char(c + j);
		c = (char)'a';

		cout << endl;
	}

	printessentials();
}


int main()
{
	readfile();
	repsfun();
	//cont();
	//printprime();
	system("pause");
	return 0;
}
