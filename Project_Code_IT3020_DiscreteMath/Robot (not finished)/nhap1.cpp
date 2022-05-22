#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	std::ifstream fileInput("input.txt");

	if (fileInput.fail())
	{
		std::cout << "Failed to open this file!" << std::endl;
		return -1;
	}

		int n, m;
		fileInput >> n;
        fileInput >> m;
		std::cout << n << " " << m;

	std::cout << std::endl;

	fileInput.close();

	return 0;
}