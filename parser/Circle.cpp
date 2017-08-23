#include "Circle.h"

Circle::Circle() {
}

Circle::Circle(string s) {
    // parse string
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
    
    this->addition = temp.substr(0, temp.size() - 1);
}

Circle::~Circle() {
}