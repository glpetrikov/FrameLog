//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include "../Common.hpp"
#include "FileHandler.hpp"
#include <unordered_map>

namespace FrameLog {
    class EnvParser {
        FileHandler file;
        std::unordered_map<std::string, std::string> vars;

    public:
        inline EnvParser(const std::string &path) : file(path) {
            parse();
        }

        inline std::string trim(const std::string &str) {
            size_t start = str.find_first_not_of(" \t\r\n");
            size_t end = str.find_last_not_of(" \t\r\n");
            return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
        }

        inline void parse() {
            std::string line;
            while (file.ReadLine(line)) {
                if (line.empty() || line[0] == '#')
                    continue;

                auto pos = line.find('=');
                if (pos != std::string::npos) {
                    auto key = line.substr(0, pos);
                    auto value = line.substr(pos + 1);
                    vars[key] = value;
                }
            }
        }

        inline std::string get(const std::string &key, const std::string &defaultValue = "") {
            auto it = vars.find(key);
            return (it != vars.end()) ? it->second : defaultValue;
        }
    };
}