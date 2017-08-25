#include "OsuMovement.h"

#define XMAX 512
#define YMAX 384

// for 1920x1080
#define XCOEFF 360
#define YCOEFF 124
#define GLOBALCOEFF 2.25
#define SPIN 10

#define OSUXSIZE 1432
#define OSUYSIZE 806
#define SCRXSIZE 1920
#define SCRYSIZE 1080

LONG OsuMovement::curTimer = 0;
LONG OsuMovement::offset = 2;

OsuMovement::OsuMovement() {
}

OsuMovement::~OsuMovement() {
}

LONG OsuMovement::XCoordTransform(LONG x) {
    return (x * GLOBALCOEFF + XCOEFF) * OSUXSIZE / SCRXSIZE;
}

LONG OsuMovement::YCoordTransform(LONG y) {
    return (y * GLOBALCOEFF + YCOEFF) * OSUYSIZE / SCRYSIZE;
}

int OsuMovement::ClickTheCircle(LONG mapx, LONG mapy, LONG time) {
    //LONG mapx = src->xstart;
    //LONG mapy = src->ystart;
    //LONG time = src->time;
    
    // TODO switch to relative movement
    Sleep(time - OsuMovement::curTimer - offset);
    GeneralMovement::mouseMoveAbsolute(XCoordTransform(mapx), YCoordTransform(mapy));
    cout << XCoordTransform(mapx) << " " << YCoordTransform(mapy) << endl;
    GeneralMovement::mouseLeftSinglePress();
    //GeneralMovement::keySinglePress(A);
    OsuMovement::curTimer = time - offset;
    return 0;
}

int OsuMovement::ClickFirstCircle(LONG mapx, LONG mapy, LONG time) {
    //LONG mapx = src->xstart;
    //LONG mapy = src->ystart;
    //LONG time = src->time;
    
    //Sleep(time - OsuMovement::curTimer - offset);
    GeneralMovement::mouseMoveAbsolute(XCoordTransform(mapx), YCoordTransform(mapy));
    cout << XCoordTransform(mapx) << " " << YCoordTransform(mapy) << endl;
    GeneralMovement::mouseLeftSinglePress();
    //GeneralMovement::keySinglePress(A);
    OsuMovement::curTimer = time - offset;
    return 0;
}

int OsuMovement::ClickTheSlider(Slider* src) {
    LONG mapx = src->xstart;
    LONG mapy = src->ystart;
    LONG time = src->time;
    
    // TODO switch to relative movement
    Sleep(time - OsuMovement::curTimer - offset);
    GeneralMovement::mouseMoveAbsolute(XCoordTransform(mapx), YCoordTransform(mapy));
    cout << XCoordTransform(mapx) << " " << YCoordTransform(mapy) << endl;
    GeneralMovement::mouseLeftExtendedPress();
    //GeneralMovement::keyExtendedPress(A);
    Sleep(src->duration);
    GeneralMovement::mouseLeftRelease();
    //GeneralMovement::keyRelease(A);
    OsuMovement::curTimer = time + src->duration - offset;
    return 0;
}

int OsuMovement::ClickFirstSlider(Slider* src) {
    LONG mapx = src->xstart;
    LONG mapy = src->ystart;
    LONG time = src->time;
    
    //Sleep(time - OsuMovement::curTimer - offset);
    GeneralMovement::mouseMoveAbsolute(XCoordTransform(mapx), YCoordTransform(mapy));
    cout << XCoordTransform(mapx) << " " << YCoordTransform(mapy) << endl;
    GeneralMovement::mouseLeftExtendedPress();
    //GeneralMovement::keyExtendedPress(A);
    Sleep(src->duration);
    GeneralMovement::mouseLeftRelease();
    //GeneralMovement::keyRelease(A);
    OsuMovement::curTimer = time + src->duration - offset;
    return 0;
}

int OsuMovement::ClickTheSpinner(LONG startTime, LONG endTime) {
//    LONG startTime = src->time;
//    LONG endTime = src->endTime;
    
    GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2) - 100, YCoordTransform(YMAX / 2));
    Sleep(startTime - OsuMovement::curTimer - offset);
    curTimer = startTime - offset;
    GeneralMovement::mouseLeftExtendedPress();
    //GeneralMovement::keyExtendedPress(A);
    while (OsuMovement::curTimer < endTime - offset) {
        GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2), YCoordTransform(YMAX / 2) - 100);
        Sleep(SPIN);
        GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2) + 100, YCoordTransform(YMAX / 2));
        Sleep(SPIN);
        GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2), YCoordTransform(YMAX / 2) + 100);
        Sleep(SPIN);
        GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2) - 100, YCoordTransform(YMAX / 2));
        Sleep(SPIN);
        OsuMovement::curTimer = OsuMovement::curTimer + SPIN * 4;
    }
    //GeneralMovement::keyRelease(A);
    GeneralMovement::mouseLeftRelease();
    return 0;
}

int OsuMovement::ClickFirstSpinner(LONG startTime, LONG endTime) {
    //LONG startTime = src->time;
    //LONG endTime = src->endTime;
    
    GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2) - 100, YCoordTransform(YMAX / 2));
    //Sleep(startTime - OsuMovement::curTimer - offset);
    GeneralMovement::mouseLeftExtendedPress();
    //GeneralMovement::keyExtendedPress(A);
    curTimer = startTime - offset;
    while (OsuMovement::curTimer < endTime - offset) {
       GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2), YCoordTransform(YMAX / 2) - 100);
        Sleep(SPIN);
        GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2) + 100, YCoordTransform(YMAX / 2));
        Sleep(SPIN);
        GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2), YCoordTransform(YMAX / 2) + 100);
        Sleep(SPIN);
        GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2) - 100, YCoordTransform(YMAX / 2));
        Sleep(SPIN);
        OsuMovement::curTimer =  OsuMovement::curTimer + 4 * SPIN;
    }
    //GeneralMovement::keyRelease(A);
    GeneralMovement::mouseLeftRelease();
    return 0;
}