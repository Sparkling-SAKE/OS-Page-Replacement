#include "LRU.h"

#include <algorithm>


LRU::LRU()	:
	Replacement()
{
	frames.clear();
}

LRU::~LRU()
{
}

void LRU::Run()
{
	for (unsigned int i = 0; i < referenceString.size(); ++i)
	{
		if (frames.find(referenceString[i]) == frames.end())
			PageFault(referenceString[i]);
		else
			Update(referenceString[i]);
	}
}

void LRU::PageFault(int ref)
{
	if (frames.size() < GetFrameNumber())
		frames[ref] = 1;
	else
	{
		auto maxIter = std::max_element(frames.begin(), frames.end(),
			[](const std::pair<int, int>& p1, const std::pair<int, int>& p2)
				{ return p1.second < p2.second; });
		frames.erase(maxIter->first);
		frames[ref] = 1;
	}
	AddFault();
}

void LRU::Update(int ref)
{
	frames[ref] = 0;
	for (auto iter = frames.begin(); iter != frames.end(); ++iter)
		iter->second++;
}
