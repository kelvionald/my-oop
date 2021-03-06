﻿#include "pch.h"

using namespace std;

int main()
{
	vector<double> inputArray;
	try
	{
		FillArray(cin, inputArray);
		if (inputArray.empty())
		{
			cout << "Array is empty";
		}
		else
		{
			MultiplyOnMinimal(inputArray);
			SortArray(inputArray);
			DisplayArray(cout, inputArray);
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}
	cout << endl;
}
