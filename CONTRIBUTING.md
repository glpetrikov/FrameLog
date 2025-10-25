# Contributing to FrameLog

Thanks for your interest!

## How to Contribute
1. Fork the repo
2. Create a branch (`git checkout -b feature/amazing`)
3. Commit changes (`git commit -m 'Add amazing feature'`)
4. Push (`git push origin feature/amazing`)
5. Open a Pull Request

## Code Style
- Use K&R brace style
- 4 spaces for indentation
- Prefix all functions with `FL`
- Add NULL checks for all pointer arguments

## Testing
Before submitting PR:
```bash
gcc -o test test.c -I./source -DFL_ENABLE_LOGS=1
./test
```