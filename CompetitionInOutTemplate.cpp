#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <functional>
#include <utility>

using namespace std;

struct Library
{
	int numberOfBooks;
	std::vector<int> bookIds;

	int processDays;
	int shippingDays;
};

struct Input
{
	int numberOfBooks;
	int numberOfLibraries;
	int scanDays;

	std::vector<int> bookScores;
	std::vector<Library> libraries;
};

struct LibraryOutput
{
	int id;
	int numberOfBooksForScanning = 0;
	std::vector<int> bookIds;
};

struct Result
{
	// Fill Output info needed

	int numberOfLibraries = 0;

	std::vector<LibraryOutput> librariesOutputs;

	std::string toString() const
	{
		// Fill Format of output needed ( it will be appended to Case #, in case not needed check the solve function)
		std::string result;

		result.append(to_string(numberOfLibraries));
		result.append("\n");

		for (int i = 0; i < librariesOutputs.size(); ++i)
		{
			LibraryOutput libraryOutput = librariesOutputs[i];
			result.append(to_string(libraryOutput.id) + " " + to_string(libraryOutput.bookIds.size()));
			result.append("\n");

			for (int j = 0; j < libraryOutput.bookIds.size(); ++j)
			{
				result.append(to_string(libraryOutput.bookIds[j]) + " ");
			}
			result.append("\n");
		}

		return result;
	}
};

Result solveCase(const Input & input)
{
	Result result;
	
	// The actual solution goes here.. while filling "result", and reading input from "input"

	return result;
}

Input getInputs()
{
	Input input;

	cin >> input.numberOfBooks;
	cin >> input.numberOfLibraries;
	cin >> input.scanDays;

	input.bookScores.reserve(input.numberOfBooks);
	for (int i = 0; i < input.numberOfBooks; ++i)
	{
		int bookScore;
		cin >> bookScore;
		input.bookScores.push_back(bookScore);
	}

	for (int i = 0; i < input.numberOfLibraries; ++i)
	{
		Library	library;
		cin >> library.numberOfBooks;
		cin >> library.processDays;
		cin >> library.shippingDays;

		for (int j = 0; j < library.numberOfBooks; ++j)
		{
			int bookId;
			cin >> bookId;
			library.bookIds.push_back(bookId);
		}
		
		input.libraries.push_back(library);
	}

	// Fill in the input with std::cin >>..

	// std::cin >> ....;

	return input;
}

void solve(int /*caseNumber*/)
{
	Input input = getInputs();
	Result result = solveCase(input);
	//std::cout << "Case #" << caseNumber << ": " << result.toString() << std::endl;
	
	std::cout << result.toString() << std::endl;
}

int main()
{
	/*int numberOfTestCases = 0;
	std::cin >> numberOfTestCases;

	for (int i = 0; i < numberOfTestCases; ++i)
	{
		solve(i + 1);
	}*/

	solve(0);

	return 0;
}