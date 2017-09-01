#include "OsuFileParser.h"


int OsuFileParser::fileFormatVer = 0;
string OsuFileParser::line = "";
double OsuFileParser::lastPosMsPerBeat = 0.0;
vector<TimingPoint*> OsuFileParser::timing;
vector<HitObject*> OsuFileParser::objects;
double OsuFileParser::sliderMultiplier = 0.0;

ifstream OsuFileParser::infile;

OsuFileParser::OsuFileParser() {
    //OsuFileParser::infile.open("maps/Kuba Oms - Don't Stop Fallin' (Revo1tt) [spinnertest].osu");
    //OsuFileParser::infile.open("maps/Kuba Oms - Don't Stop Fallin' (Revo1tt) [test].osu");
    OsuFileParser::infile.open("maps/xi - Akasha (Jemmmmy) [Extreme].osu");
    //OsuFileParser::infile.open("maps/Kurokotei - Galaxy Collapse (Doomsday is Bad) [Galactic].osu");
    //OsuFileParser::infile.open("maps/The Koxx - A FOOL MOON NIGHT (Astar) [Friendofox's Galaxy].osu");
}

OsuFileParser::~OsuFileParser() {
}

string OsuFileParser:: ReadLine() {
    if (getline(OsuFileParser::infile, OsuFileParser::line)) {
        //cout << OsuFileParser::line << endl;
        return OsuFileParser::line;
    } else {
        return "end";
    }
}

int OsuFileParser::ReadFileFormat() {
    ReadLine();
    if (OsuFileParser::line.find("osu file format v") != -1) {
        if (OsuFileParser::line.size() == 20)
            return (OsuFileParser::line[18] - '0') + 10 * (OsuFileParser::line[17] - '0');
        else
            return OsuFileParser::line[17] - '0';
    } else {
        return -1;
    }
}	

int OsuFileParser::ReadGeneralInfo() {
    //  General info stub
    //  Possibly StackLatency will be needed
    do {
        ReadLine();
    } while (OsuFileParser::line[0] != '[');
}

int OsuFileParser::ReadEditorInfo() {
    //  Editor info stub
    do {
        ReadLine();
    } while (OsuFileParser::line[0] != '[');
}

int OsuFileParser::ReadMetaData() {
    //  Metadata stub
    do {
        ReadLine();
    } while (OsuFileParser::line[0] != '[');
}

int OsuFileParser::ReadDiffData() {
    //  Difficulty data stub
    int i = 0;
    do {
        ReadLine();
        if (OsuFileParser::line.find("SliderMultiplier") != -1) {
            // slider multiplier
            string temp = OsuFileParser::line.substr(OsuFileParser::line.find(':') + 1);
            OsuFileParser::sliderMultiplier = atof(temp.c_str());
        }
        i++;
    } while (OsuFileParser::line[0] != '[');
}

int OsuFileParser::ReadEvents() {
    //  Events stub
    do {
        ReadLine();
    } while (OsuFileParser::line[0] != '[');
}

int OsuFileParser::ReadColours() {
    // Colours stub
    do {
        ReadLine();
    } while (OsuFileParser::line[0] != '[');
}

int OsuFileParser::ReadTimingPoints() {
    //  Timing points
    //OsuFileParser::timing.clear();
    int i = 0;
    int lastpostp = 0;
    do {
        ReadLine();
        // parse line
        if (line.size() == 0) {
            continue;
        }
        
        if (line[0] != '[') {
            TimingPoint *point = new TimingPoint(); // TODO new
            string temp;
            temp = line.substr(0, line.find(","));
            point->time = atoi(temp.c_str());
            line = line.substr(line.find(",") + 1);
            
            temp = line.substr(0, line.find(","));
            if (atof(temp.c_str()) > 0) {
                point->msperbeat = atof(temp.c_str());
                lastpostp = atof(temp.c_str());
            } else {
                point->msperbeat = lastpostp + atof(temp.c_str());
            }
            
            line = line.substr(line.find(",") + 1);
            
            temp = line.substr(0, line.find(","));
            point->meter = atoi(temp.c_str());
            line = line.substr(line.find(",") + 1);
            
            temp = line.substr(0, line.find(","));
            point->sampleType = atoi(temp.c_str());
            line = line.substr(line.find(",") + 1);
            
            temp = line.substr(0, line.find(","));
            point->sampleSet = atoi(temp.c_str());
            line = line.substr(line.find(",") + 1);
            
            temp = line.substr(0, line.find(","));
            point->volume = atoi(temp.c_str());
            line = line.substr(line.find(",") + 1);
            
            temp = line.substr(0, line.find(","));
            point->inherited = atoi(temp.c_str());
            line = line.substr(line.find(",") + 1);
            
            temp = line.substr(0, line.size() - 1);
            point->kiai = atoi(temp.c_str());
            
            OsuFileParser::timing.push_back(point);
        }
        i++;
    } while (OsuFileParser::line[0] != '[');
}

TimingPoint OsuFileParser::GetTimingPoint(LONG time) {
    for (int i = OsuFileParser::timing.size() - 1; i >= 0; i--) {
        if (OsuFileParser::timing.at(i)->time <= time) {
            return *OsuFileParser::timing.at(i);
        }
    }
}

int OsuFileParser::ReadHitObjects() {
    // Hit Objects
    //OsuFileParser::objects.clear();
    int i = 0;
    do {
        ReadLine();
        // parse line
        if (line.size() == 0) {
            break;
        }
        
        if (line[0] != '[') {
            string temp = line.substr(line.find(",") + 1); // TODO new
            temp = temp.substr(temp.find(",") + 1);
            temp = temp.substr(temp.find(",") + 1);
            temp = temp.substr(0, temp.find(","));
            
            int lineType = atoi(temp.c_str());
            
            //cout << (lineType & 1) << " " << ((lineType & 2) >> 1) << " " << ((lineType & 8) >> 3) << endl; 
            // first equals 1 -- circle, second equals 1 -- slider, third equals 1 -- spinner
            
            if (lineType & 1 == 1) {
                Circle *temp = new Circle(line);
                OsuFileParser::objects.push_back(temp);
            } else if ((lineType & 2) >> 1 == 1) {
                //TODO slider
                Slider *temp = new Slider(line);
                OsuFileParser::objects.push_back(temp);
            } else if ((lineType & 8) >> 3 == 1) {
                //TODO upgrade spinner
                Spinner *temp = new Spinner(line);
                OsuFileParser::objects.push_back(temp);
            }
        }
        i++;
    } while (OsuFileParser::line != "");    
}

int OsuFileParser::ParseAll() {
    if (OsuFileParser::line != "end") {
        OsuFileParser::fileFormatVer = ReadFileFormat();
        //cout << OsuFileParser::fileFormatVer << endl;
        ReadLine();
        ReadLine();
        if (OsuFileParser::line.find("[General]") == 0)
            OsuFileParser::ReadGeneralInfo();
        //cout << OsuFileParser::line << endl;
        if (OsuFileParser::line.find("[Editor]") == 0)
            OsuFileParser::ReadEditorInfo();
        //cout << OsuFileParser::line << endl;
        if (OsuFileParser::line.find("[Metadata]") == 0)
            OsuFileParser::ReadMetaData();
        //cout << OsuFileParser::line << endl;
        if (OsuFileParser::line.find("[Difficulty]") == 0)
            OsuFileParser::ReadDiffData();
        //cout << OsuFileParser::line << endl;
        if (OsuFileParser::line.find("[Events]") == 0)
            OsuFileParser::ReadEvents();
        //cout << OsuFileParser::line << endl;
        if (OsuFileParser::line.find("[TimingPoints]") == 0)
            OsuFileParser::ReadTimingPoints();
        //cout << OsuFileParser::line << endl;
        if (OsuFileParser::line.find("[Colours]") == 0)
            OsuFileParser::ReadColours();
        //cout << OsuFileParser::line << endl;
        if (OsuFileParser::line.find("[HitObjects]") == 0)
            OsuFileParser::ReadHitObjects();
    }
}