#include <FrameLog/FrameLog.h>
#include <chrono>
#include <filesystem>
#include <iomanip>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    FrameLog::FileHandler File("log.txt", FrameLog::FileHandler::WriteType::ReWrite);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 100000000; i++) {
        File.WriteLine("Test is Loop is 100000000 Messages");
    }

    File.Flush();
    auto mid = std::chrono::high_resolution_clock::now();

    File.CloseFile();
    auto end = std::chrono::high_resolution_clock::now();

    auto file_size_bytes = std::filesystem::file_size("log.txt");
    double gb = static_cast<double>(file_size_bytes) / (1024.0 * 1024.0 * 1024.0);

    auto ms_write = std::chrono::duration_cast<std::chrono::milliseconds>(mid - start).count();
    auto ms_fsync = std::chrono::duration_cast<std::chrono::milliseconds>(end - mid).count();
    auto ms_total = ms_write + ms_fsync;

    double sec_write = ms_write / 1000.0;
    double sec_total = ms_total / 1000.0;

    double mbps_write = (gb * 1024) / sec_write;
    double mbps_total = (gb * 1024) / sec_total;

    std::cout << std::fixed << std::setprecision(3)
              << "File size: " << gb << " GB (" << file_size_bytes << " bytes)\n"
              << "Write + flush: " << sec_write << " s → " << mbps_write << " MB/s\n"
              << "fsync (close): " << ms_fsync / 1000.0 << " s\n"
              << "Total:         " << sec_total << " s → " << mbps_total << " MB/s\n";
}