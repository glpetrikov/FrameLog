//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include "Common.hpp"
#include "Platform.hpp"

namespace FrameLog
{
    class Logger; // forward declaration
    namespace Colors
    {

        // True Color Support (24-bit)
        inline std::string RGB(int r, int g, int b)
        {
            char code[32];
            if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
            {
                std::cout << "Color Error: Not RGB format" << "\n";
                return "\033[0m";
            }
            snprintf(code, 32, "\033[38;2;%d;%d;%dm", r, g, b);
            return std::string(code);
        }
        inline std::string RGB_BG(int r, int g, int b)
        {
            char code[32];
            if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
            {
                std::cout << "Color Error: Not RGB format" << "\n";
                return "\033[0m";
            }
            snprintf(code, 32, "\033[48;2;%d;%d;%dm", r, g, b);
            return std::string(code);
        }

        enum class Style
        {
            Reset,
            Bold,
            Dim,
            Italic,
            Underline,
            Blink,
            Reverse
        };

        enum class Color
        {
            Reset,
            Black,
            Graphite,
            White,

            Red,
            Green,
            Blue,
            BrightBlue,
            Yellow,
        };
        enum class BGColor
        {

            Reset,
            BlackB,
            GraphiteB,
            RedB,
            GreenB,
            YellowB,
            BlueB,
            WhiteB,
        };
        constexpr std::string_view IsColor(Color C) noexcept
        {
            switch (C)
            {
            case Color::Reset:
                return "\033[0m";
            // Gray-scale Colors
            case Color::Black:
                return "\033[30m";
            case Color::Graphite:
                return "\033[90m";
            case Color::White:
                return "\033[37m";

            // Standard Colors
            case Color::Red:
                return "\033[31m";
            case Color::Green:
                return "\033[32m";
            case Color::Blue:
                return "\033[34m";
            case Color::BrightBlue:
                return "\033[94m";
            case Color::Yellow:
                return "\033[33m";
            default:
                return "\033[0m";
            }
        }
        constexpr std::string_view IsColor(Colors::Style S) noexcept
        {
            switch (S)
            {
            // Reset
            case Style::Reset:
                return "\033[0m";

            case Style::Blink:
                return "\033[5m";
            case Style::Reverse:
                return "\033[7m";

            // Text Style
            case Style::Bold:
                return "\033[1m";
            case Style::Dim:
                return "\033[2m";
            case Style::Italic:
                return "\033[3m";
            case Style::Underline:
                return "\033[4m";
            default:
                return "\033[0m";
            }
        }
        constexpr std::string_view IsColor(BGColor BC) noexcept
        {
            switch (BC)
            {
            case BGColor::Reset:
                return "\033[0m";
            // Background Colors
            case BGColor::RedB:
                return "\033[41m";
            case BGColor::BlueB:
                return "\033[44m";
            case BGColor::YellowB:
                return "\033[43m";
            case BGColor::GreenB:
                return "\033[42m";
            case BGColor::WhiteB:
                return "\033[47m";
            case BGColor::GraphiteB:
                return "\033[100m";
            case BGColor::BlackB:
                return "\033[40m";
            default:
                return "\033[0m";
            }
        }
    }
}