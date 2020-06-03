#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <ctime>

class MarkovChainTextGenerator
{
private:
	

public:
	int n = 3;
	std::unordered_map<std::string, std::vector<std::string>> phraseMap;

	void addPhrase(std::string key, std::string value);
	void generateCorpus(std::string path);
	
	void printCorpus();

	std::string nextWord(std::string key);
	std::string generateText();
};

