#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <iterator>
#include <vector>

#include "readFromFile.hpp"

std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}

std::vector<std::string> file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::string> out;
	std::string str;

	/*
	if (text.is_open()) {
		std::istream_iterator<std::string> iter(text);
		while (!text.eof()) {
			out.push_back(*iter);
			++iter;
		}
	}
	*/

	while (std::getline(text, str)) {
		if (str.size() > 0) out.push_back(str);
	}

	return out;
}

std::vector<int> split(std::string str, char delimiter)
{
    std::vector<int> line;
    std::stringstream ss(str);

    for (int i; ss >> i;) {
        line.push_back(i);    
        if (ss.peek() == delimiter)
            ss.ignore();
    }

	return line;
}

std::vector<std::string> splitTeams(std::string str, char delimiter) {
    std::vector<std::string> line;
    std::stringstream ss(str);
	//std::cout << str << std::endl;
	//std::cout << "~~~~~~~" << std::endl;

    for (std::string i; ss >> i;) {
        line.push_back(i);    
        if (ss.peek() == delimiter)
            ss.ignore();
    }
	return line;
}
