#include <iostream>
#include <fstream>
#include <string>

std::string replaceInString(const std::string& line, const std::string& s1, const std::string& s2) {
    std::string result = line;
    size_t pos = 0;
    
    // Cannot use std::string::replace as forbidden by the subject
    while ((pos = result.find(s1, pos)) != std::string::npos) {
        // Erase the substring s1
        result.erase(pos, s1.length());
        // Insert the substring s2 at position pos
        result.insert(pos, s2);
        // Move position past the newly inserted substring
        pos += s2.length();
    }
    
    return result;
}

int main(int argc, char* argv[]) {
    // Check if we have the right number of arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    // Check if s1 is an empty string
    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be an empty string" << std::endl;
        return 1;
    }
    
    // Open the input file
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    
    // Create the output file name
    std::string outFilename = filename + ".replace";
    
    // Open the output file
    std::ofstream outputFile(outFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create file " << outFilename << std::endl;
        inputFile.close();
        return 1;
    }
    
    // Read the file line by line and replace occurrences of s1 with s2
    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceInString(line, s1, s2);
        
        // Add newline if this wasn't the end of the file
        if (!inputFile.eof()) {
            outputFile << std::endl;
        }
    }
    
    // Close the files
    inputFile.close();
    outputFile.close();
    
    std::cout << "Replacement completed. Output written to " << outFilename << std::endl;
    
    return 0;
} 