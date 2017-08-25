#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "parser/TimingPoint.h"
#include "parser/HitObject.h"
#include <stdlib.h>
#include "parser/Circle.h"
#include "parser/Spinner.h"
#include "parser/Slider.h"
#include "Windows.h"


using namespace std;

class OsuFileParser {
public:
    OsuFileParser();
    ~OsuFileParser();
    
    static int ReadFileFormat();
    static int ReadGeneralInfo();
    static int ReadEditorInfo();
    static int ReadMetaData();
    static int ReadDiffData();
    static int ReadEvents();
    static int ReadTimingPoints();
    static int ReadColours();
    static int ReadHitObjects();
    
    static int ParseAll();
    static string ReadLine();
    static TimingPoint GetTimingPoint(LONG time);
    
    static int fileFormatVer;
    static double lastPosMsPerBeat;
    static vector<TimingPoint*> timing;
    static vector<HitObject*> objects;
    static string line;
    static ifstream infile;
};

