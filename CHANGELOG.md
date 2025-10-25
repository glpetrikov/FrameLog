# Changelog

All notable changes to FrameLog will be documented in this file.

## [0.1.1-alpha] - 2025-10-25

### Added
- Buffered output for performance
- Color support (8 basic colors + backgrounds)
- Text styles (bold, italic, underline, etc.)
- True color support (24-bit RGB)
- Log levels (Trace, Info, Warn, Error)
- NULL safety checks
- Cross-platform support (Windows, Linux, macOS)

### Fixed
- FL_ENABLE_LOGS logic (now 1=enable, 0=disable)
- Buffer expansion algorithm
- Memory leak in edge cases

## [Unreleased]
### Planned for Beta
- Additional log levels
- Format patterns
- File logging