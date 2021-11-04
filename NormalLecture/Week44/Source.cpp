#include <fstream>
#include <iostream>
#include <string>

int countWords(std::string keyword);
void toLower(std::string& OUTString);

//bool compareStrings()
int main()
{
	std::string word{ "lorem" };
	std::cout << word << " was found " << countWords(word) << " times\n";

	return 0;
}

int countWords(std::string keyword)
{
	std::ifstream file("../lorem.txt");
	toLower(keyword);
	int count{};
	while (file)
	{
		
		std::string substring{};
		file >> substring;
		toLower(substring);
		// Fails for instances of keyword with a sign after. Like "keyword."
		if (substring == keyword)
			++count;
	}

	return count;
}

void toLower(std::string& OUTString)
{
	for (auto& it : OUTString)
	{
		it = tolower(it);
	}
}
