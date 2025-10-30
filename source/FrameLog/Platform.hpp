//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

// --- Detect platform ---
#if defined(_WIN32) || defined(_WIN64)
#define FL_WINDOWS
#elif defined(__APPLE__) && defined(__MACH__)
#include <TargetConditionals.h>
#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#define FL_IOS
#else
#define FL_MACOS
#endif
#elif defined(__linux__)
#define FL_LINUX
#elif defined(__ANDROID__)
#define FL_ANDROID
#elif defined(__unix__) || defined(__unix)
#define FL_UNIX
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
#elif defined(FL_MACOS) || defined(FL_LINUX) || defined(FL_UNIX) || defined(FL_ANDROID)
#if defined(FRAMELOG_BUILD)
#define FL_API __attribute__((visibility("default")))
#else
#define FL_API
#endif
#else
#error "Unsupported or unknown platform detected by FrameLog."
#endif

// --- Compiler detection ---
#if defined(__clang__)
#define FL_COMPILER_CLANG
#elif defined(__GNUC__)
#define FL_COMPILER_GCC
#elif defined(_MSC_VER)
#define FL_COMPILER_MSVC
#endif