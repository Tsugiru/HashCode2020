#include <iostream>
#include <string>

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


int main()
{
	int numberOfTestCases = 0;
	std::cin >> numberOfTestCases;

	for (int i = 0; i < numberOfTestCases; ++i)
	{
		solve(i + 1);
	}

	return 0;
}