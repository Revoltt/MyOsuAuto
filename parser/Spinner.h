#pragma once
#include <string>
#include "HitObject.h"
#include <stdlib.h>

class Spinner: public HitObject {
public:
    Spinner();
    Spinner(string s);
    ~Spinner();
    int endTime;
};