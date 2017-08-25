#pragma once
#include <vector>
#include <string>
#include "HitObject.h"
#include "TimingPoint.h"
#include <stdlib.h>
#include <math.h>
#include "../OsuFileParser.h"


using namespace std;

class Slider: public HitObject {
public:
    Slider();
    Slider(string s);
    virtual ~Slider();
    char sliderType;
    vector<string> curvePoints;
    int repeat;
    int pixelLength;
    string edgeHitsounds;
    string edgeAdditions;
    
    // is computed
    int duration;
};