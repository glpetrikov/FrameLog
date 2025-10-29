#include <FrameLog.h>
#include <stdio.h>

int main(){
    FLPrintln("Hello, World!");

    for(int i = 0; i < 10; i++){
        FLTraceln("output in loop!");
    }
    int value = FLReadInt("");
    printf("%i%s", value, "\n");
    FLFlushBuffer();
}