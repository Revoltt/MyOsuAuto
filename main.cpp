#include "GeneralMovement.h"
#include "OsuFileParser.h"
#include "OsuMovement.h"
#include <utility>
#include <iostream>
#include "parser/Spinner.h"

//scancodes for movement buttons
#define W 0x11
#define A 0x1E
#define D 0x20
#define S 0x1F

using namespace std;

int main()
{
//    Sleep(1000);
//    GeneralMovement::mouseLeftExtendedPress();
//    //GeneralMovement::mouseMoveAbsolute(716, 403);
//    Sleep(10000);
//    GeneralMovement::mouseLeftRelease();

    OsuFileParser x;
    x.ParseAll();
    bool first = true;
    Sleep(1000);
    cout << "start" << endl;
    for (int i = 0; i < OsuFileParser::objects.size(); i++) {
        if ((OsuFileParser::objects.at(i)->type & 1 == 1) && first) {
            // detect key press
            Circle* temp = static_cast<Circle*>(OsuFileParser::objects.at(i));
            while (true) {
                if(GetKeyState('D') & 0x8000/*check if high-order bit is set (1 << 15)*/)
                {
                    OsuMovement::ClickFirstCircle(temp->xstart, temp->ystart, temp->time);
                    first = false;
                    break;
                }
                Sleep(1);
            }
        } else if ((OsuFileParser::objects.at(i)->type & 1 == 1) && !first){
            //hitcircle
            Circle* temp = static_cast<Circle*>(OsuFileParser::objects.at(i));
            OsuMovement::ClickTheCircle(temp->xstart, temp->ystart, temp->time);
            // exit if anything goes wrong
            if(GetKeyState('X') & 0x8000)
            {
                break;
            }
        } else if (((OsuFileParser::objects.at(i)->type & 2) >> 1 == 1) && first) {
            // detect key press
            Slider* temp = static_cast<Slider*>(OsuFileParser::objects.at(i));
            while (true) {
                if(GetKeyState('D') & 0x8000/*check if high-order bit is set (1 << 15)*/)
                {
                    OsuMovement::ClickFirstSlider(temp);
                    first = false;
                    break;
                }
                Sleep(1);
            }
        } else if (((OsuFileParser::objects.at(i)->type & 2) >> 1 == 1) && !first){
            //hitSlider
            Slider* temp = static_cast<Slider*>(OsuFileParser::objects.at(i));
            OsuMovement::ClickTheSlider(temp);
            // exit if anything goes wrong
            if(GetKeyState('X') & 0x8000)
            {
                break;
            }
        } else if (((OsuFileParser::objects.at(i)->type & 8) >> 3 == 1) && first) {
            // detect key press
            Spinner* temp = static_cast<Spinner*>(OsuFileParser::objects.at(i)); // TODO incorrect endtime
            while (true) {
                if(GetKeyState('D') & 0x8000) /*check if high-order bit is set (1 << 15)*/
                {
                    OsuMovement::ClickFirstSpinner(temp->time, temp->endTime);
                    first = false;
                    break;
                }
                Sleep(1);
            }
        } else if (((OsuFileParser::objects.at(i)->type & 8) >> 3 == 1) && !first){
            //hitSpinner
            Spinner* temp = static_cast<Spinner*>(OsuFileParser::objects.at(i)); // TODO incorrect endtime
            OsuMovement::ClickTheSpinner(temp->time, temp->endTime);
            // exit if anything goes wrong
            if(GetKeyState('X') & 0x8000)
            {
                break;
            }
        }
    }
}