#pragma once
#include "HitObject.h"
#include <string>
#include <stdlib.h>

using namespace std;

class Circle: public HitObject {
public:
    Circle();
    Circle(string s);
    ~Circle();
};