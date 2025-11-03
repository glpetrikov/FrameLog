//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include "Common.hpp"
#include "Platform.hpp"

namespace FrameLog {
    class Logger; // forward declaration

    namespace Colors {

        // True Color Support (24-bit)
        FL_API inline std::string RGB(int r, int g, int b) {
            char code[32];
            if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                std::cout << "Color Error: Not RGB format" << "\n";
                return "\033[0m";
            }
            snprintf(code, 32, "\033[38;2;%d;%d;%dm", r, g, b);
            return std::string(code);
        }

        FL_API inline std::string RGB_BG(int r, int g, int b) {
            char code[32];
            if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                std::cout << "Color Error: Not RGB format" << "\n";
                return "\033[0m";
            }
            snprintf(code, 32, "\033[48;2;%d;%d;%dm", r, g, b);
            return std::string(code);
        }

        enum class Color {
            Reset,
            Empty,
            Black,
            Graphite,
            White,

            Red,
            Green,
            Blue,
            BrightBlue,
            Yellow,
        };
        enum class BGColor {

            Reset,
            Empty,
            BlackB,
            GraphiteB,
            RedB,
            GreenB,
            YellowB,
            BlueB,
            WhiteB,
        };

        enum class Style {
            Reset,
            Empty,
            Bold,
            Dim,
            Italic,
            Underline,
            Blink,
            Reverse
        };

        FL_API constexpr std::string_view IsColor(Color C) noexcept {
            switch (C) {
                case Color::Reset:
                    return "\033[39m";
                    break;

                case Color::Empty:
                    return "";
                    break;
                // Gray-scale Colors
                case Color::Black:
                    return "\033[30m";
                    break;
                case Color::Graphite:
                    return "\033[90m";
                    break;
                case Color::White:
                    return "\033[37m";
                    break;

                // Standard Colors
                case Color::Red:
                    return "\033[31m";
                    break;
                case Color::Green:
                    return "\033[32m";
                    break;
                case Color::Blue:
                    return "\033[34m";
                    break;
                case Color::BrightBlue:
                    return "\033[94m";
                    break;
                case Color::Yellow:
                    return "\033[33m";
                    break;
                default:
                    return "\033[0m";
                    break;
            }
        }

        FL_API constexpr std::string_view IsColor(BGColor BC) noexcept {
            switch (BC) {
                case BGColor::Reset:
                    return "\033[49m";
                    break;

                case BGColor::Empty:
                    return "";
                    break;
                // Background Colors
                case BGColor::RedB:
                    return "\033[41m";
                    break;
                case BGColor::BlueB:
                    return "\033[44m";
                    break;
                case BGColor::YellowB:
                    return "\033[43m";
                    break;
                case BGColor::GreenB:
                    return "\033[42m";
                    break;
                case BGColor::WhiteB:
                    return "\033[47m";
                    break;
                case BGColor::GraphiteB:
                    return "\033[100m";
                    break;
                case BGColor::BlackB:
                    return "\033[40m";
                    break;
                default:
                    return "\033[0m";
                    break;
            }
        }

        FL_API constexpr std::string_view IsColor(Colors::Style S) noexcept {
            switch (S) {
                // Reset
                case Style::Reset:
                    return "\033[0m";
                    break;
                case Style::Empty:
                    return "";
                    break;

                case Style::Blink:
                    return "\033[5m";
                    break;
                case Style::Reverse:
                    return "\033[7m";
                    break;

                // Text Style
                case Style::Bold:
                    return "\033[1m";
                    break;
                case Style::Dim:
                    return "\033[2m";
                    break;
                case Style::Italic:
                    return "\033[3m";
                    break;
                case Style::Underline:
                    return "\033[4m";
                    break;
                default:
                    return "\033[0m";
                    break;
            }
        }
    }
}