# Feature Request

## Summary
<!-- Briefly describe the feature or improvement you’d like to see -->
Example: Add support for file-based logging.

## Motivation
<!-- Explain why this feature would be useful or what problem it solves -->
Example: It would allow saving logs from FrameLog into files for later analysis.

## Proposed Solution
<!-- Describe your proposed implementation or approach -->
Example: Add a `FileLog` class that writes buffered output to a file path.

## Related Issues

## Platform

## Alternatives / Related
<!-- Mention any alternative solutions or related projects -->
Example: Libraries like spdlog and log.c support file sinks, but FrameLog could stay smaller and simpler.

## Additional Context
<!-- Include any additional details, mockups, or references -->
Example: Ideally, it should reuse the existing buffered system used by `Logger::Flush()`.

