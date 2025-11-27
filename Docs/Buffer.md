# FrameLog Buffer API

- The buffer's constructor and destructor accept nothing.


- The Add function and its overload accept char, std::string, std::string_view, const char*
and append the passed message to the buffer data
return a success/failure status


- GetData returns buffer data as std::string_view, which can be converted to a const char*, string.
and it doesn't accept anything.


- Clear function or Clean function to clear buffer data


- GetSize return size the Date

---

- list of all functions

bool Add(std::string_view Message);\
bool Add(const char);\
std::string_view GetData();\
bool Clear();\
bool Clean();\
size_t GetSize();
