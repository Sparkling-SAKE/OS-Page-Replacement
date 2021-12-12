#pragma once
#include "Replacement.h"

class Optimal :
    public Replacement
{
private:
    std::vector<int> frames;

public:
    Optimal();
    virtual ~Optimal();

public:
    void Run();
    void PageFault(int ref, int idx);


};
