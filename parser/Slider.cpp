#include "Slider.h"

Slider::Slider() {
}

Slider::Slider(string s) {
    //parse string
    string temp = s;
    string curnum = temp.substr(0, temp.find(","));
    this->xstart = atoi(curnum.c_str());
    temp = temp.substr(temp.find(",") + 1);
    
    curnum = temp.substr(0, temp.find(","));
    this->ystart = atoi(curnum.c_str());
    temp = temp.substr(temp.find(",") + 1);
    
    curnum = temp.substr(0, temp.find(","));
    this->time = atoi(curnum.c_str());
    temp = temp.substr(temp.find(",") + 1);
    
    curnum = temp.substr(0, temp.find(","));
    this->type = atoi(curnum.c_str());
    temp = temp.substr(temp.find(",") + 1);
    
    curnum = temp.substr(0, temp.find(","));
    this->hitsound = atoi(curnum.c_str());
    temp = temp.substr(temp.find(",") + 1);
    
    curnum = temp.substr(0, temp.find("|"));
    this->sliderType = curnum[0];
    temp = temp.substr(temp.find("|") + 1);
    
    // not quite parsing curvepoints
    curnum = temp.substr(0, temp.find(","));
    while (curnum.find('|') != -1) {
        string curvep = curnum.substr(0, curnum.find("|"));
        curnum = curnum.substr(curnum.find("|") + 1);
        this->curvePoints.push_back(curvep);
    }
    this->curvePoints.push_back(curnum);
    temp = temp.substr(temp.find(",") + 1);
    
    curnum = temp.substr(0, temp.find(","));
    this->repeat = atoi(curnum.c_str());
    temp = temp.substr(temp.find(",") + 1);
    
    if (temp.find(",") != -1) {
        curnum = temp.substr(0, temp.find(","));
        this->pixelLength = atoi(curnum.c_str());
        temp = temp.substr(temp.find(",") + 1);
        
        curnum = temp.substr(0, temp.find(","));
        this->edgeHitsounds = curnum;
        temp = temp.substr(temp.find(",") + 1);
    
        curnum = temp.substr(0, temp.find(","));
        this->edgeAdditions = curnum;
        temp = temp.substr(temp.find(",") + 1);
    
        this->addition = temp.substr(0, temp.size() - 1);
    } else {
        curnum = temp.substr(0, temp.size());
        this->pixelLength = atoi(curnum.c_str());
        temp = "";
    }
    
    TimingPoint tp = OsuFileParser::GetTimingPoint(this->time);
    double pixelsPerBeat = this->repeat * 100 * 100 / tp.msperbeat;
    double beatsNum = this->repeat * this->pixelLength / pixelsPerBeat;
    
    this->duration = static_cast<int>(time + ceil(beatsNum * tp.msperbeat));
}

Slider::~Slider() {
}