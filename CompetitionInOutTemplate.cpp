#include <iostream>
#include <string>
#include <algorithm>
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
    int id;
	int numberOfBooks;
	std::vector<int> bookIds;

	int processDays;
	int shippingDays;
};

struct Book
{
    int score;
    bool shipped = false;
};

struct Input
{
	int numberOfBooks;
	int numberOfLibraries;
	int scanDays;

	std::vector<Book> bookScores;
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
	int numberOfLibraries = 0;

	std::vector<LibraryOutput> librariesOutputs;

	std::string toString() const
	{
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

Result solveCase(Input & input)
{
	Result result;
	
    std::sort(begin(input.libraries), end(input.libraries), [](const Library &lhs, const Library &rhs) {
        return lhs.processDays < rhs.processDays;
    });

    int sum = 0, i = 0;

    for(; i < input.libraries.size() && sum <= input.scanDays; i++) {
        result.librariesOutputs.push_back({input.libraries[i].id, input.libraries[i].numberOfBooks, input.libraries[i].bookIds});
        sum += input.libraries[i].processDays;
    }

    result.numberOfLibraries = i;
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
		Book book;
		cin >> book.score;
		input.bookScores.push_back(book);
	}

	for (int i = 0; i < input.numberOfLibraries; ++i)
	{
		Library	library;
        library.id = i;
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
}