# Contributing to FrameLog

Thanks for your interest!

## How You Can Help

### 1. Use FrameLog
The best contribution is **using** FrameLog and sharing your experience!

### 2. Fork and Customize
Feel free to:
- Fork FrameLog for personal use
- Modify it for your needs
- Keep your fork private or make it public
- Share your fork with others

**You don't need permission to fork!** MIT License allows it.

### 3. Report Bugs
Found a bug? [Open an issue](https://github.com/glpetrikov/FrameLog/issues)

Please include:
- OS and compiler (e.g., Windows 11, GCC 11.2)
- Code to reproduce
- Expected vs actual behavior

### 4. Suggest Features
Have an idea? Open an issue with the `enhancement` label.

**Note:** I review all suggestions, but can't guarantee implementation.

### 5. Spread the Word
Like FrameLog? Share it:
- Star the repo
- Tell your friends
- Write a blog post
- Mention it in your projects

## What About Pull Requests?

**I'm not accepting PRs at this time.**

Why? I want to maintain full control over the codebase and design decisions.

**Instead:**
- Fork the project
- Make your changes in your fork
- Share your fork if you want
- I might incorporate your ideas in future versions

## Found a Bug?

If you find a bug, you have options:

1. **Report it** — open an issue, I'll fix it
2. **Fix it in your fork** — fork and fix for personal use
3. **Wait** — I'll fix critical bugs in updates

All options are valid!

## Code Style (for your forks)

If you fork FrameLog, here's the style used:

- K&R brace style
- 4 spaces for indentation
- Prefix functions with `FL`
- Add NULL checks for pointers
- Use PascalCase for names

(But it's your fork, so do whatever you want!)

## Testing Your Fork
```bash
mkdir build
premake5 gmake
cd build

# Debug build
mingw32-make config=debug # On Windows
make config=debug # On Linux/macOS
cd Debug
./FrameLog       # On Linux/macOS
./FrameLog.exe   # On Windows

cd ..

# Release build
mingw32-make config=release # On Windows
make config=release # On Linux/macOS
cd Release
./FrameLog       # On Linux/macOS
./FrameLog.exe   # On Windows
```

## Commit Messages (for your fork)

Good examples:
- ✅ "Fix buffer overflow in FLExpandBuffer"
- ✅ "Add RGB color support"
- ✅ "Update README with installation steps"

Avoid:
- ❌ "fix"
- ❌ "update"
- ❌ "changes"

## Questions?

Open an issue or discussion. I'm happy to help!

---

**Remember:** Forking is encouraged! Make FrameLog work for YOU.