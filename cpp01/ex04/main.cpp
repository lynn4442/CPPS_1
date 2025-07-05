#include <iostream>
#include <fstream>
#include <string>

std::string replaceInString(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string result = line;
	size_t pos = 0;
	
	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		result.erase(pos, s1.length());
		result.insert(pos, s2);
		pos += s2.length();
	}
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be an empty string" << std::endl;
		return (1);
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return (1);
	}
	std::string outFilename = filename + ".rep";
	std::ofstream outputFile(outFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Could not create file " << outFilename << std::endl;
		inputFile.close();
		return 1;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		outputFile << replaceInString(line, s1, s2);
		if (!inputFile.eof())
			outputFile << std::endl;
	}
	inputFile.close();
	outputFile.close();
	std::cout << "Replacement completed. Output written to " << outFilename << std::endl;
	return 0;
} 
