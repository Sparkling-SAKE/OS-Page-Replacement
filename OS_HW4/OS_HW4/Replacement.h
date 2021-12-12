#pragma once

#include <vector>

class Replacement
{
protected:
	const int			frameNumber = 4;
	int					pageFault;
	std::vector<int>	referenceString;

public:
	Replacement();
	virtual ~Replacement();

public:
	int GetPageFault()		const { return pageFault; }
	int GetFrameNumber()	const { return frameNumber; }

public:
	void SetPageFault(int fault) { pageFault = fault; }

protected:
	void ReadFile();
	void AddFault();
};

