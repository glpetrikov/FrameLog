# Changelog

All notable changes to FrameLog will be documented in this file.

## [0.2.0-beta] - 2025-10-25

### Added
- FLRead
```c
int value = FLReadInt("Message");
float value = FLReadFloat("Message");
double value = FLReadDouble("Message");
char symbol = FLReadChar("Message");
const char* string = FLReadString("Message");
```
- FLFatal
```c
FLFatal("Message");
FLFatalln("Message");
```

### Fixed

## [Unreleased]
### Planned for Beta
- Additional log levels
- Format patterns
- File logging