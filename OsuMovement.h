#pragma once
#include "Windows.h"
#include <vector>
#include <iostream>

using namespace std;

class OsuMovement
{
public:
    OsuMovement();
    ~OsuMovement();
    static int ClickTheCircle(LONG x, LONG y, LONG time);
    static int ClickFirstCircle(LONG x, LONG y, LONG time);
    static int ClickTheSpinner(LONG startTime, LONG endTime);
    static int ClickFirstSpinner(LONG startTime, LONG endTime);
    static int ClickTheSlider(vector<LONG> coordx, vector<LONG> coordy, LONG startTime);
    static LONG XCoordTransform(LONG x);
    static LONG YCoordTransform(LONG y);
    static LONG curTimer;
};