#include <FrameLog.hpp>
#include <chrono>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

std::string GetTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                  now.time_since_epoch()) %
              1000;

    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    ss << '.' << std::setfill('0') << std::setw(3) << ms.count();
    return ss.str();
}

int main() {
    std::vector<std::string> messages = {
        "User login from IP address 192.168.1.100",
        "Database query executed in 45ms for table users",
        "Cache miss on key: user_session_abc123def456",
        "API request received from client v2.3.1 endpoint /api/data",
        "File upload completed: document.pdf (2.5MB) by user Alice"};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, messages.size() - 1);

    // ========================================
    // test 1:
    // ========================================
    {
        std::cout << "=== Test 1: Varied messages WITHOUT timestamp ===\n";
        FrameLog::FileHandler file("no_timestamp.txt", FrameLog::FileHandler::WriteType::ReWrite);

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < 5000000; i++) {
            file.WriteLine(messages[dist(gen)] + " #" + std::to_string(i));
        }

        file.Flush();
        file.CloseFile();

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        auto file_size = std::filesystem::file_size("no_timestamp.txt");

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Messages:   5,000,000\n";
        std::cout << "Duration:   " << duration << " ms\n";
        std::cout << "Throughput: " << (5000000.0 / duration * 1000) << " msg/s\n";
        std::cout << "File size:  " << (file_size / (1024.0 * 1024.0)) << " MB\n";
        std::cout << "Write speed: " << (file_size / (1024.0 * 1024.0)) / (duration / 1000.0) << " MB/s\n\n";
    }

    // ========================================
    // test 2:
    // ========================================
    {
        std::cout << "=== Test 2: Varied messages WITH timestamp ===\n";
        FrameLog::FileHandler file("with_timestamp.txt", FrameLog::FileHandler::WriteType::ReWrite);

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < 1000000; i++) {
            std::string msg = "[" + GetTimestamp() + "] [INFO] " +
                              messages[dist(gen)] + " #" + std::to_string(i);
            file.WriteLine(msg);
        }

        file.Flush();
        file.CloseFile();

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        auto file_size = std::filesystem::file_size("with_timestamp.txt");

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Messages:   1,000,000\n";
        std::cout << "Duration:   " << duration << " ms\n";
        std::cout << "Throughput: " << (1000000.0 / duration * 1000) << " msg/s\n";
        std::cout << "File size:  " << (file_size / (1024.0 * 1024.0)) << " MB\n";
        std::cout << "Write speed: " << (file_size / (1024.0 * 1024.0)) / (duration / 1000.0) << " MB/s\n\n";
    }

    // ========================================
    // test 3:
    // ========================================
    {
        std::cout << "=== Test 3: Identical strings (baseline) ===\n";
        FrameLog::FileHandler file("identical.txt", FrameLog::FileHandler::WriteType::ReWrite);

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < 10000000; i++) {
            file.WriteLine("Test message for baseline performance measurement");
        }

        file.Flush();
        file.CloseFile();

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        auto file_size = std::filesystem::file_size("identical.txt");

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Messages:   10,000,000\n";
        std::cout << "Duration:   " << duration << " ms\n";
        std::cout << "Throughput: " << (10000000.0 / duration * 1000) << " msg/s\n";
        std::cout << "File size:  " << (file_size / (1024.0 * 1024.0)) << " MB\n";
        std::cout << "Write speed: " << (file_size / (1024.0 * 1024.0)) / (duration / 1000.0) << " MB/s\n\n";
    }
}