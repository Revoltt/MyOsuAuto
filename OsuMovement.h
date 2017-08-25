#pragma once
#include "Windows.h"
#include <vector>
#include <iostream>
#include "GeneralMovement.h"
#include "parser/HitObject.h"
#include "parser/Circle.h"
#include "parser/Slider.h"
#include "parser/Spinner.h"
#include "parser/TimingPoint.h"
#include "OsuFileParser.h"
#include <math.h>


using namespace std;

class OsuMovement
{
public:
    OsuMovement();
    ~OsuMovement();
    static int ClickTheCircle(LONG mapx, LONG mapy, LONG time);
    static int ClickFirstCircle(LONG mapx, LONG mapy, LONG time);
    
    static int ClickTheSpinner(LONG startTime, LONG endTime);
    static int ClickFirstSpinner(LONG startTime, LONG endTime);
    
    static int ClickFirstSlider(Slider* src);
    static int ClickTheSlider(Slider* src);
    
    static LONG XCoordTransform(LONG x);
    static LONG YCoordTransform(LONG y);
    static LONG curTimer;
    static LONG offset;
};