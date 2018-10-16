// AmazonReviewsExtractor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "amazon.h"
#include "menu.h"

//VERGA COMMIT
//Done in GITAR
//3er comentario
//4to comentario en visual
void cinIntInput(size_t & intRef) {
	std::string string;
	std::getline(std::cin, string);
	std::stringstream ss(string);

	if (!(ss >> intRef)) {
		std::cout <<"\"" <<string << "\" is NOT number "<< std::hex << std::stoi(string) << std::endl;
		std::cin.clear();
	}

}
int main()
{
	auto &amazon = Amazon::getInstance();
	//Amazon *b = &Amazon::getInstance();



	std::cout << "Welcome to Ammazon Reviews Extractor\n";
	size_t selectedHost( argm::showMenu(
		"From what country/region you want to extract reviews?",
		amazon.getHostList() ));

	try {
		while (selectedHost < (unsigned int)1 || selectedHost > amazon.getNumberOfHostCountries()) {
			std::cout << "input the country number a press Enter" << std::endl;
			cinIntInput(selectedHost);
		}
	}
	catch (const std::exception &e) { std::cerr << e.what(); }
	catch (const char *e) { std::cerr << e; }
	std::cout << "You chose " << amazon.getCountryNameByNumber(selectedHost) << std::endl;
		std::cout << "Inpute the ASIN to query";
		//std::string asin;
		//std::cin >> asin;
		//std::cout << asin;
		
}


