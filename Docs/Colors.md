# FrameLog Colors API

### namespace
Colors are in the FrameLog::Colors namespace

### Functions

The IsColor function accepts the Colors::Color, Colors::BGColor, and Colors::Style structures and returns the ANSI code (string)
The RGB function accepts three parameters, R, G, and B, of type Integer(int), and returns the ANSI RGB code
The RGB_BG function accepts three parameters, R, G, and B, of type Integer(int), and returns the ANSI RGB code for the background

### structs
```cpp
enum class Color {
Reset, // Resets the color to the default
Empty, // Does nothing; needed for functions that require a color
Black, // black
Graphite, // gray
White, // white

Red, // red
Green, // green
Blue, // blue
BrightBlue, // light blue
Yellow, // yellow
};
enum class BGColor {
Reset, // resets the background to default
Empty, // Does nothing; needed for functions that require a color
BlackB, // black background
GraphiteB, // gray background
RedB, // red background
GreenB, // green background
YellowB, // yellow background
BlueB, // blue background
WhiteB, // white background
};
enum class Style {
Reset, // resets everything to default
Empty, // Does nothing; needed for functions that require a color
Bold, //
Dim, //
Italic, //
Underline, //
Blink, //
Reverse //
};
```

You can get the ANSI code from them using the IsColor function.

### example
```cpp
using namespace FrameLog::Colors;

int main(){
std::cout << IsColor(Red) << "Red text" << IsColor(Style::Reset) << std::endl;
std::cout << RGB(255,128,0) << "Orange RGB text" << IsColor(Style::Reset) << std::endl;
std::cout << RGB_BG(0,128,255) << "Blue RGB background" << IsColor(Style::Reset) << std::endl;
return 0;
}
```