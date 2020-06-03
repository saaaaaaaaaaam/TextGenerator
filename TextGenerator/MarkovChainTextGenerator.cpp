#include "MarkovChainTextGenerator.h"
#include <iterator>

void MarkovChainTextGenerator::addPhrase(std::string key, std::string value)
{
	phraseMap[key].push_back(value);
}

void MarkovChainTextGenerator::generateCorpus(std::string path)
{
	// Open text file
	std::ifstream file;
	file.open(path);

	// Store the last n words read
	std::vector<std::string> memory;
	std::string key = ""; 
	for (int m = 0; m < n; m++) { memory.push_back(""); }
	

	// Read file word by word
	std::string word;
	while (file >> word)
	{
		// Add entry to phrase map
		addPhrase(key, word);

		// Update key
		for (int i = 0; i < memory.size() - 1; i++) { memory[i] = memory[i + 1]; }
		memory[memory.size() - 1] = word;
		key = "";
		for (int i = 0; i < memory.size() - 1; i++) { key += memory[i] + " "; }
		key += memory[memory.size() - 1];
	}
}

void MarkovChainTextGenerator::printCorpus()
{
	for (auto i : phraseMap)
	{
		std::cout << "\"" + i.first + "\"" + " : ";

		for (auto j : i.second)
		{
			std::cout << "\"" + j + "\"" + " ";
		}

		std::cout << std::endl;
	}
}

std::string MarkovChainTextGenerator::nextWord(std::string key)
{
	// Check key exists within map
	if (phraseMap.find(key) != phraseMap.end())
	{ 
		int size = phraseMap[key].size();
		int position = rand() % size;
		return phraseMap[key][position];
	}
	return "";
}

std::string MarkovChainTextGenerator::generateText()
{
	// Seed random
	srand((unsigned)std::time(0));

	// Store the last n words
	std::vector<std::string> memory = { "but", "the", "two" };
	for (int m = 0; m < n; m++) {  }

	// Generate key
	std::string key = "";
	for (int i = 0; i < memory.size() - 1; i++) { key += memory[i] + " "; }
	key += memory[memory.size() - 1];

	std::string text = key + " ";
	std::string word;
	
	// Generate words until the word limit is reached
	for (int count = 0; count < 500; count++)
	{
		// Get next word
		word = nextWord(key);
		if (word == "") { break; }
		text += word + " ";

		// Update key
		for (int i = 0; i < memory.size() - 1; i++) { memory[i] = memory[i+1]; }
		memory[memory.size() - 1] = word;
		
		key = "";
		for (int i = 0; i < memory.size() - 1; i++) { key += memory[i] + " "; }
		key += memory[memory.size() - 1];
	}
	
	// Return the randomly generated text
	return text;
}



