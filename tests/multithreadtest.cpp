#include <FrameLog/FrameLog.h>
#include <iostream>
#include <thread>
#include <vector>

void LogThread(int id, FrameLog::Logger& logger) {
    for (int i = 0; i < 10; i++) {
        logger.InfoLine("Thread " + std::to_string(id) + " logging message " + std::to_string(i));
    }
}

void FileThread(int id) {
    FrameLog::FileHandler file("thread_" + std::to_string(id) + ".txt",
                                FrameLog::FileHandler::WriteType::ReWrite,
                                FrameLog::FileHandler::ReadType::Read);
    for (int i = 0; i < 10; i++) {
        file.WriteLine("Thread " + std::to_string(id) + " writing line " + std::to_string(i));
    }
    file.Flush();
}

int main() {
    FrameLog::Logger logger("Main");

    std::vector<std::thread> logThreads;
    for (int i = 0; i < 5; i++) {
        logThreads.emplace_back(LogThread, i, std::ref(logger));
    }

    std::vector<std::thread> fileThreads;
    for (int i = 0; i < 5; i++) {
        fileThreads.emplace_back(FileThread, i);
    }

    for (auto& t : logThreads) t.join();
    for (auto& t : fileThreads) t.join();

    logger.Flush();
    logger.FlushFile();

    std::cout << "Multithreaded test finished." << std::endl;
    return 0;
}
