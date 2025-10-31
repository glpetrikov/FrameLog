#include <FrameLog.hpp>
#include <iostream>

using namespace FrameLog;

int main()
{
    FileWriter Writer1("Test.txt");
    Writer1.Write("Test");
    Writer1.WriteLine("???");
    Writer1.CloseFile();

    FileWriter Writer2("Test2.txt", TypeWrite::Write);
    Writer2.Write("Test");
    Writer2.WriteLine("???");
    Writer2.CloseFile();

    FileWriter Writer3("Test2.txt", TypeWrite::ReWrite);
    Writer3.Write("Rewrited!");
    Writer3.CloseFile();
}