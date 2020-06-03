#include "MarkovChainTextGenerator.h"
#include <iostream>

#include <thread>
#include <chrono>

int main()
{
	// The quick brown fox jumped over the lazy dog.
	MarkovChainTextGenerator mctg;

	// Brothers Grimm
	mctg.generateCorpus("text/fairyTales.txt");
	
	// Franz Kafka
	mctg.generateCorpus("text/metamorphosis.txt");
	mctg.generateCorpus("text/theTrial.txt");
	
	// Robbert Chambers
	mctg.generateCorpus("text/theKingInYellow.txt");
	mctg.generateCorpus("text/inSearchOfTheUnknown.txt");
	mctg.generateCorpus("text/theMoonlitWay.txt");
	mctg.generateCorpus("text/theSlayerOfSouls.txt");

	// Technology Texts
	mctg.generateCorpus("text/transactionsOfTheAmericanSocietyOfEngineers.txt");
//	mctg.generateCorpus("text/nitroExplosivesAPracticalTreatise.txt");
	mctg.generateCorpus("text/theEarliestElectromagneticInstruments.txt");
	mctg.generateCorpus("text/theArtOfPerfumery.txt");
	mctg.generateCorpus("text/theHistoryOfTheGrowthOfTheSteamEngine.txt");


	while (true)
	{
		std::cout << mctg.generateText() << std::endl;
		std::cout << std::endl << "***" << std::endl << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(20000));
	}
}