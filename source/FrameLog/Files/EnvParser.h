//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include <unordered_map>
#include <Common.hpp>
#include "FileHandler.hpp"

namespace FrameLog {
    class EnvParser {
        FileHandler file;
        std::unordered_map<std::string, std::string> vars;

    public:
        inline EnvParser(const std::string& path) : file(path) {
            parse();
        }

        inline void parse() {
            std::string line;
            while (file.FindLine(line)) {
                if (line.empty() || line[0] == '#') continue;

                auto pos = line.find('=');
                if (pos != std::string::npos) {
                    auto key = line.substr(0, pos);
                    auto value = line.substr(pos + 1);
                    vars[key] = value;
                }
            }
        }

        inline std::string get(const std::string& key, const std::string& defaultValue = "") {
            auto it = vars.find(key);
            return (it != vars.end()) ? it->second : defaultValue;
        }
    };
}