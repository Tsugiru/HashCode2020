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
    int id;
    bool shipped = false;
};

struct Input
{
	int numberOfBooks;
	int numberOfLibraries;
	int scanDays;

	std::vector<Book> books;
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
    vector<int> used;
    for(; i < input.libraries.size() && sum <= input.scanDays; i++) {
        vector<int> bookIdsUsed;

        for(int j = 0; j < input.libraries[i].numberOfBooks; j++) {
            int currentBookId = input.libraries[i].bookIds[j];
            if(!input.books[currentBookId].shipped) {
                bookIdsUsed.push_back(currentBookId);
                input.books[currentBookId].shipped = true;
            }
        }
        result.librariesOutputs.push_back({input.libraries[i].id, bookIdsUsed.size(), bookIdsUsed});
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

	input.books.reserve(input.numberOfBooks);
	for (int i = 0; i < input.numberOfBooks; ++i)
	{
		Book book;
        book.id = i;
		cin >> book.score;
		input.books.push_back(book);
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
	solve(0);
}