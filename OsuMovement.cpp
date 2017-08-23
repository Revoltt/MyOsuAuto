#include "OsuMovement.h"
#include "GeneralMovement.h"

#define XMAX 512
#define YMAX 384

// for 1920x1080
#define XCOEFF 380
#define YCOEFF 124
#define GLOBALCOEFF 2.25
#define SPIN 10

#define OSUXSIZE 1432
#define OSUYSIZE 806
#define SCRXSIZE 1920
#define SCRYSIZE 1080


#define OFFSET 2

LONG OsuMovement::curTimer = 0;

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
    // TODO switch to relative movement
    Sleep(time - OsuMovement::curTimer - OFFSET);
    GeneralMovement::mouseMoveAbsolute(XCoordTransform(mapx), YCoordTransform(mapy));
    cout << XCoordTransform(mapx) << " " << YCoordTransform(mapy) << endl;
    GeneralMovement::mouseLeftSinglePress();
    OsuMovement::curTimer = time - OFFSET;
    return 0;
}

int OsuMovement::ClickFirstCircle(LONG mapx, LONG mapy, LONG time) {
    //Sleep(time - OsuMovement::curTimer - OFFSET);
    GeneralMovement::mouseMoveAbsolute(XCoordTransform(mapx), YCoordTransform(mapy));
    cout << XCoordTransform(mapx) << " " << YCoordTransform(mapy) << endl;
    GeneralMovement::mouseLeftSinglePress();
    OsuMovement::curTimer = time - OFFSET;
    return 0;
}

int OsuMovement::ClickTheSpinner(LONG startTime, LONG endTime) {
    GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2) - 100, YCoordTransform(YMAX / 2));
    Sleep(startTime - OsuMovement::curTimer - OFFSET);
    
    curTimer = startTime - OFFSET;
    GeneralMovement::keyExtendedPress(A);
    while (OsuMovement::curTimer < endTime - OFFSET) {
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
    GeneralMovement::keyRelease(A);
    return 0;
}

int OsuMovement::ClickFirstSpinner(LONG startTime, LONG endTime) {
    GeneralMovement::mouseMoveAbsolute(XCoordTransform(XMAX / 2) - 100, YCoordTransform(YMAX / 2));
    //Sleep(startTime - OsuMovement::curTimer - OFFSET);
    GeneralMovement::keyExtendedPress(A);
    curTimer = startTime - OFFSET;
    while (OsuMovement::curTimer < endTime - OFFSET) {
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
    GeneralMovement::keyRelease(A);
    return 0;
}