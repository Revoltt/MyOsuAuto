#pragma once
#include <string>

using namespace std;

class HitObject {
public:
    HitObject();
    virtual ~HitObject();
    int xstart, ystart;
    int time;
    int type;
    int hitsound;
    string addition;
};
