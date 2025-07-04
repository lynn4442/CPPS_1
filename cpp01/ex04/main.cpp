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
    std::string outFilename = filename + ".replace";
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


// write a c++ program that replaces a word in a text file with another word entered by the user
//

// #include<fstream>
// #include<iostream>
// #include <cstring>
// using namespace std;
// //fatahit l file bel function yaane majbouraa hott l write bedde hotto by ref so majboura hott by reference
// void edit(ifstream &, ofstream &, char [25], char [25]);
// int main()
// {
// 	char source[25], destination[25], oldword[25], newword[25];
// 	ifstream e;
// 	ofstream s;
// 	cout << "name of source file:";
// 	cin >> source;
// 	e.open(source);//aamletlo reading mode
// 	if (!e) {
// 		cerr << "error in openeing the file";
// 		exit(1);
// 	}
// 	cout << "name of destination file:";
// 	cin >> destination;
// 	s.open(destination);
// 	if (!s) {
// 		cerr << "error in openeing the file";
// 		exit(1);
// 	}
// 	cout << "word to search";
// 	cin >> oldword;
// 	cout << "word to replace:";
// 	cin >> newword;
// 	edit(e, s, oldword, newword);
// 	e.close();
// 	s.close();
// 	remove(source);//waeta aamoul replace la kelme ma fine aamoul rename lal file 
// 	rename(destination, source);//bsamme l destination bi esem source
//     return 0;
// }

// void edit(ifstream &e, ofstream &s, char oldword[25], char newword[25]) {
// 	char next[25];//bhott definition la word jdide bedde ooeriya bel file laenno by word
// 	e >> next;
// 	while (!e.fail()) {//yaane ma wsolet aal ekhir
// 		if (strcmp(next,oldword)==0) {
// 			cout << newword << " ";//heyde eza talabit tabaa l code
// 			s << newword << " ";//heyde eza bel file
// 		}
// 		else {
// 			cout << next << " ";
// 			s << next << " ";
// 		}
// 		e >> next;//read the next word ta teetaa aa kell kelme
// 	}
	
// }