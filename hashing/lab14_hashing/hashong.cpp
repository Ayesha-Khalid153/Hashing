//#include "hash.h";
//#include "linearProb.h"
//#include "quadProb.h"
#include<vector>
#include<iostream>
#include<unordered_map>
#include <algorithm>
using namespace std;
int main()
{

	/*int arr[]= { 15, 11, 27, 8, 12 };
	int size= sizeof(arr) / sizeof(arr[0]);*/
	//hashing h(7);
	/*for (int i = 0;i < size;i++)
	{
		h.insertElement(arr[i]);
	}
	h.displayHashTable();
	cout << endl;
	h.deleteElement(15);
	h.displayHashTable();*/


	linearProbing lp;
	quadProbing qp;

	int arr[] = { 50, 700, 76, 85, 92, 73, 101 };
	int arr_size = 7;

	int table_size = 7;
	int hash_table[7];

	for (int i = 0; i < table_size; i++) {
		hash_table[i] = -1;
	}
	qp.quadProb(hash_table, table_size, arr, arr_size);
	cout << endl << endl;
	lp.linearProb(hash_table, table_size, arr, arr_size);
}
//linear probing


#pragma once
#pragma once
#include<iostream>
#include<list>

using namespace std;
class linearProbing {
public:

	void linearProb(int table[], int table_size, int arr[], int arr_size)
	{
		for (int i = 0; i < arr_size; i++)
		{
			int index = arr[i] % table_size;
			if (table[index] == -1)
			{
				table[index] = arr[i];
			}
			else {
				for (int j = 0; j < table_size; j++)
				{
					int newIndex = (index + j) % table_size;
					if (table[newIndex] == -1) {
						table[newIndex] = arr[i];
						break;
					}
				}
			}
		}
		printTable(table, table_size);
	}
	void printTable(int table[], int table_size)
	{
		for (int i = 0; i < table_size; i++)
		{
			cout << table[i] << " ";
		}
	}
};


//quadratic probing

#pragma once
#include<iostream>
#include<list>

using namespace std;
class quadProbing {
public:
	void quadProb(int table[], int table_size, int arr[], int arr_size)
	{
		for (int i = 0; i < arr_size; i++)
		{
			int index = arr[i] % table_size;
			if (table[index] == -1)
			{
				table[index] = arr[i];
			}
			else {
				for (int j = 0; j < table_size; j++)
				{
					int newIndex = (index + j * j) % table_size;
					if (table[newIndex] == -1) {
						table[newIndex] = arr[i];
						break;
					}

				}
			}
		}
		printTable(table, arr_size);
	}
	void printTable(int table[], int arr_size)
	{
		for (int i = 0; i < arr_size; i++)
		{
			cout << table[i] << " ";
		}
	}
};


//leetcode prob 1


class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> output;
		unordered_map<string, int> mp;
		for (int i = 0; i < s.length(); i++)
		{
			string wrd = s.substr(i, 10);
			mp[wrd]++;
		}
		for (auto x : mp)
		{
			if (x.second > 1)
			{
				output.push_back(x.first);
			}
		}
		return output;
	}
};

//leetcode prob 2

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>>mp;
		for (auto x : strs)
		{
			string wrd = x;
			sort(wrd.begin(), wrd.end());
			mp[wrd].push_back(x);
		}
		vector<vector<string>> output;
		for (auto x : mp)
		{
			output.push_back(x.second);
		}
		return output;
	}
};
