#include "Optimal.h"

#include <algorithm>

Optimal::Optimal()	:
	Replacement()
{
	frames.resize(GetFrameNumber());
	for (auto& elem : frames)
		elem = INT_MIN;
}

Optimal::~Optimal()
{
}

void Optimal::Run()
{
	for (unsigned int i = 0; i < referenceString.size(); ++i)
		if (std::find(frames.begin(), frames.end(), referenceString[i]) == frames.end())
			PageFault(referenceString[i], i);
}

void Optimal::PageFault(int ref, int idx)
{
	auto iter = std::find(frames.begin(), frames.end(), INT_MIN);
	if (iter != frames.end())
		*iter = ref;
	else
	{
		std::vector<int> dist;
		for (int i = 0; i < GetFrameNumber(); ++i)
			dist.push_back(std::find(referenceString.begin() + idx, referenceString.end(), frames[i])
				- referenceString.begin());

		int maxIndex = std::max_element(dist.begin(), dist.end()) - dist.begin();
		frames[maxIndex] = ref;
	}
	AddFault();
}
