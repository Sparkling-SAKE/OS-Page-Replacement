#include "Replacement.h"
#include <fstream>
#include <iostream>

Replacement::Replacement()	:
	pageFault(0)
{
	ReadFile();
}

Replacement::~Replacement()
{
}

void Replacement::ReadFile()
{
	std::ifstream	fin("input.txt");

	int reference;
	while (!fin.eof())
	{
		fin >> reference;
		referenceString.push_back(reference);
	}

	fin.close();
}

void Replacement::AddFault()
{
	SetPageFault(pageFault + 1);
}
