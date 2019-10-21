#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void Find_distinctLetters(vector<vector<char>> matrix)
{
	int rowNum = matrix.size();
	int colNum = matrix[0].size();

	cout << "Here are the distinct letters for each sub-matrix" << endl << endl;

	for (int j = 0; j < rowNum; j++)	// iterates through rows
	{
		for (int k = 0; k < colNum; k++)	// iterates through columns
		{
			for (int x = 0; x < rowNum-j; x++)	// iterates through sub-matrix rows
			{
				for (int y = 0; y < colNum-k; y++)	// iterates through sub-matrix columns
				{
					vector<char> distinctLetters;
					for (int m = 0; m <= x; m++)
					{
						for (int n = 0; n <= y; n++)
						{
							bool distinct = true;
							char distCandidate = tolower(matrix[j + m][k + n]);

							/* iterate through vector elements */
							for (int idx = 0; idx < distinctLetters.size(); idx++)
							{
								if (distinctLetters[idx] == distCandidate)
								{
									distinct = false;
									break;
								}
							}

							if (distinct)
								distinctLetters.push_back(distCandidate);
						}
					}

					cout << "((" << j+1 << "," << k+1 << ")," << x+1 << "," << y+1 << "):" << distinctLetters.size() << ":";
					/* print vector elements */
					for (int idx = 0; idx < distinctLetters.size(); idx++)
						cout << distinctLetters[idx];
					cout << endl;					 
				}
			}
		}
	}
}

string removeSpace(string s)
{
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	return s;
}

void ReadFileIntoMatrix()
{
	// Open File
	ifstream input;
	cout << "Enter the name of the file" << endl;

	string filename;
	cin >> filename;
	input.open(filename.c_str());

	while (input.fail())
	{
		cout << "Could not open " << filename  << "!" << endl << "Enter the name of the file" << endl;
		cin.clear();
		cin >> filename;
		input.open(filename.c_str());
	}

//	int rowNum = 0, colNum = 0;
	vector<vector<char>> matrix;
	vector<char> rowVector;

	char ch;
	string line;
	bool error = false;

	/* read line by line */
	while (getline(input, line))								
	{
		line = removeSpace(line);
		for (int i = 0; i < line.length(); i++)
		{
			rowVector.push_back(line[i]);

			/* alphabetic char check*/
			if (!isalpha(line[i]) && !error)
			{
				cout << "Error: Matrix contains invalid letter: " << line[i] << endl;
				error = true;
			}
		}

		if(rowVector.size() > 0)
			matrix.push_back(rowVector);
		rowVector.clear();
	}

	/* empty file check */
	if (matrix.size() < 1)
	{
		cout << "Error: File is empty" << endl;
		error = true;
	}

	/* column check */
	else if (matrix.size() > 1)
	{
		for (int i = 1; i < matrix.size(); i++)
			if (matrix[0].size() != matrix[i].size())
			{
				cout << "Error: number of element in each rows are not same" << endl;
				error = true;
				break;
			}
	}

	if (!error)
	{
		Find_distinctLetters(matrix);
	}
	else
		cout << "Program Exiting..." << endl;
	input.close();
}

int main()
{
	ReadFileIntoMatrix();
	return 0;
}