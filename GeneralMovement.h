#pragma once
#include "Windows.h"

//scancodes for movement buttons
#define W 0x11
#define A 0x1E
#define D 0x20
#define S 0x1F

class GeneralMovement
{
public:
	GeneralMovement();
	~GeneralMovement();
	static int keyExtendedPress(WORD hexcode);
	static int keyRelease(WORD hexcode);
	static int mouseLeftSinglePress();
	static int mouseLeftExtendedPress();
	static int mouseLeftRelease();
	static int mouseRightSinglePress();
	static int mouseRightExtendedPress();
        static int mouseRightRelease();
	static int mouseMoveRelative(LONG dx, LONG dy);
        static int mouseMoveAbsolute(LONG x, LONG y);
        static HWND getNeededWindow(char name[100]);
        static int keySinglePress(WORD hexcode);
private:
	static INPUT inputGenerateKeyboard(WORD hexcode, DWORD flags);
	static INPUT inputGenerateMouse(LONG dx, LONG dy, DWORD flags);
};
