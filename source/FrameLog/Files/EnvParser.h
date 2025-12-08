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
            std::string content = file.ReadAll();
            std::istringstream stream(content);
            std::string line;

            while (std::getline(stream, line)) {
                if (line.empty() || line[0] == '#') continue;

                auto pos = line.find('=');
                if (pos != std::string::npos) {
                    auto key = line.substr(0, pos);
                    auto value = line.substr(pos + 1);

                    // Trim whitespace
                    key.erase(0, key.find_first_not_of(" \t\r"));
                    key.erase(key.find_last_not_of(" \t\r") + 1);
                    value.erase(0, value.find_first_not_of(" \t\r"));
                    value.erase(value.find_last_not_of(" \t\r") + 1);

                    // Remove quotes if present
                    if (!value.empty() && value.front() == '"' && value.back() == '"') {
                        value = value.substr(1, value.size() - 2);
                    }

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