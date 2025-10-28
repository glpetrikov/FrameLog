#include <FrameLog.h>

int main(){
    FLPrintln("Hello, World!");

    for(int i = 0; i < 10; i++){
        FLTraceln("output in loop!");
    }
    FLFlushBuffer();
}