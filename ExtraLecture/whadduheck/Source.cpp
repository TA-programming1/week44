#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h> // for _getch

struct ExampleStruct
{
	int x{};
	int y{};
};

enum Test
{
	TEST_PLAYERNAME,
	TEST_SCORE,
	TEST_COLOR,
	TEST_NONE
};

std::vector<int> numbersInInt(std::string stringToParse);
void parseFile();
void vectorExample();
void menuExample();
void sizeOfCArrayExample();

void pointerExample();
void passByReferenceExample(ExampleStruct &OUTexampleStruct);
void passByPointerExample(ExampleStruct *OUTexampleStruct);
int main()
{
	//std::string stringToParse = "This is some strina1231566g with numbers like 0 or 1 or maybe345";

	//for (auto it : numbersInInt(stringToParse))
	//{
	//	std::cout << it << '\n';
	//}
	//parseFile();
	//vectorExample();
	//menuExample();
	//sizeOfCArrayExample();
	pointerExample();
	return 0;
}

std::vector<int> numbersInInt(std::string stringToParse)
{
	std::vector<int> numbers;

	for (const auto& it : stringToParse)
	{
		if (it <= '9' && it >= '0')
			numbers.push_back(it - '0');
	}

	return numbers;
}

void parseFile()
{
	std::ifstream file("../stats.txt");

	int state = TEST_NONE;
	std::string playerName;
	int playerScore;
	while (file)
	{
		if (state == TEST_NONE)
		{
			char buffer;
			file >> buffer;
			if (buffer == '#')
				state = TEST_PLAYERNAME;
			else if (buffer == '*')
				state = TEST_SCORE;
		}
		else if (state == TEST_PLAYERNAME)
		{
			file >> playerName;
			state = TEST_NONE;
		}
		else if (state == TEST_SCORE)
		{
			file >> playerScore;
			state = TEST_NONE;
		}
	}
}

void vectorExample()
{
	std::vector<int> exampleVector;
	exampleVector.push_back(1);
	exampleVector.push_back(2);
	exampleVector.push_back(3);
	exampleVector.push_back(4);
	exampleVector.push_back(5);
	std::cout << "Size of vector before erase: " << exampleVector.size() << '\n';

	for (auto it : exampleVector)
		std::cout << it << " ";

	std::cout << '\n';
	exampleVector.erase(exampleVector.begin() + 3);

	for (auto it : exampleVector)
		std::cout << it << " ";
	std::cout << "Size of vector after erase: " << exampleVector.size() << '\n';

	std::vector<std::vector<int>> vector2DExample;
	vector2DExample.push_back(std::vector<int>(3, 4));
	vector2DExample.push_back(std::vector<int>(1, 2));
	vector2DExample[0][2] = 1;
	vector2DExample[0][1] = 2;

	int arr[3][3];
}

void menuExample()
{
	std::vector<std::string> menuElements;
	menuElements.push_back("Start");
	menuElements.push_back("Multiplayer");
	menuElements.push_back("Options");
	menuElements.push_back("Options");
	menuElements.push_back("Options");
	menuElements.push_back("Options");
	menuElements.push_back("Quit");
	int positionY{};
	for (int i{}; i < menuElements.size(); ++i)
	{
		if (i == positionY)
			std::cout << "  ";

		std::cout << "    " << menuElements[i] << '\n';
	}

	while (true)
	{
		switch (_getch())
		{
		case 'W': case 'w':
			positionY--;
			break;
		case 'S': case 's':
			positionY++;
			break;
		case ' ':
			if (positionY == menuElements.size() - 1)
				exit(0);
			break;
		default:
			break;
		}

		if (positionY < 0)
			positionY = menuElements.size() -1;
		else if (positionY > menuElements.size()-1)
			positionY = 0;


		system("CLS");
		for (int i{}; i < menuElements.size(); ++i)
		{
			if(i == positionY)
				std::cout << "  ";

			std::cout <<"    "<< menuElements[i]<<'\n';
		}
	}
}

void sizeOfCArrayExample()
{
	int exampleArray[4];
	short sizeOfArray{};

	sizeOfArray = sizeof(exampleArray) / sizeof(exampleArray[0]);
	
	for (int i{}; i < 5; i++)
	{
		exampleArray[i] = i;
		std::cout << exampleArray[i] << '\n';
	}

	std::cout << "Size of array: " << sizeOfArray << '\n';
}

void pointerExample()
{
	int temp{20};
	int* pointerToTemp{};
	//int** doublePointerToTemp{};

	pointerToTemp = &temp;
	//doublePointerToTemp = &pointerToTemp;
	int arraySize{ 300 };
	int* someValue = new int[arraySize];

	ExampleStruct* someStruct = new ExampleStruct();
	ExampleStruct& referenceStruct = (*new ExampleStruct);
	someStruct->x = 50;

	//delete someStruct;
	//someStruct = nullptr;
	
	if (someStruct != nullptr)
	{
		//std::cout << temp;

		//passByReferenceExample(*someStruct);
		//std::cout << someStruct;
		//std::cout << *pointerToTemp; 
		//std::cout << someStruct->x<<'\n'; 
	}
}

void passByReferenceExample(ExampleStruct& OUTexampleStruct)
{
	OUTexampleStruct.x = 30;
}

void passByPointerExample(ExampleStruct* OUTexampleStruct)
{
	OUTexampleStruct->x = 20;
}
