#pragma once
#include "Replacement.h"

#include <unordered_map>

using REFERENCE = int;
using COUNT     = int;

class LRU :
    public Replacement
{
private:
    std::unordered_map<REFERENCE, COUNT> frames;

public:
    LRU();
    virtual ~LRU();

public:
    void Run();
    void PageFault(int ref);
    void Update(int ref);
};
