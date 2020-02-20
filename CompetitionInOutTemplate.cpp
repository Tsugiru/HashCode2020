#include <iostream>
#include <string>
<<<<<<< HEAD
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <functional>
#include <utility>

using namespace std;
=======
>>>>>>> e56a647ce745a6eef9d28bff367faac7e67f7474

struct Input
{
	// Fill Input info needed
};

struct Result
{
	// Fill Output info needed

	std::string toString() const
	{
		// Fill Format of output needed ( it will be appended to Case #, in case not needed check the solve function)
		return "";
	}
};

<<<<<<< HEAD
=======

>>>>>>> e56a647ce745a6eef9d28bff367faac7e67f7474
Result solveCase(const Input & input)
{
	Result result;
	
	// The actual solution goes here.. while filling "result", and reading input from "input"

	return result;
}

Input getInputs()
{
	Input input;

	// Fill in the input with std::cin >>..

	// std::cin >> ....;

	return input;
}

void solve(int caseNumber)
{
	Input input = getInputs();
	Result result = solveCase(input);
	std::cout << "Case #" << caseNumber << ": " << result.toString() << std::endl;
}

<<<<<<< HEAD
int main()
{
    
=======

int main()
{
	int numberOfTestCases = 0;
	std::cin >> numberOfTestCases;

	for (int i = 0; i < numberOfTestCases; ++i)
	{
		solve(i + 1);
	}

>>>>>>> e56a647ce745a6eef9d28bff367faac7e67f7474
	return 0;
}