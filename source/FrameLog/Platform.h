//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

// --- Detect platforms ---
#if defined(_WIN32) || defined(_WIN64)
    #define FL_WINDOWS
#elif defined(__APPLE__) && defined(__MACH__)
    #define FL_APPLE
#elif defined(__linux__)
    #define FL_LINUX
#elif defined(ARDUINO) || defined(__AVR__) || defined(__STM32F1__) || \
    defined(ESP32) || defined(ESP_PLATFORM) || defined(__XTENSA__)
    #define FL_EMBEDDED
#elif defined(__unix__) || defined(__unix)
    #define FL_UNIX
#elif defined(__ANDROID__)
    #define FL_ANDROID
#else
    #define FL_UNKNOWN
#endif

// --- Cross-platform API macro ---
#if defined(FL_WINDOWS)
    #if defined(FRAMELOG_BUILD)
        #define FL_API __declspec(dllexport)
    #else
        #define FL_API __declspec(dllimport)
    #endif
#elif defined(FL_APPLE) || defined(FL_LINUX)
    #if defined(FRAMELOG_BUILD)
        #define FL_API __attribute__((visibility("default")))
    #else
        #define FL_API
    #endif
#elif defined(FL_EMBEDDED)
    #define FL_API
#elif defined(FL_UNKNOWN)
    #error "UNKNOWN platform"
#endif
