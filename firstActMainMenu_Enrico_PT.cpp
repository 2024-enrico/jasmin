#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

void list_files() {
    int choice;
    std::cout << "1. List all files in the current directory.\n";
    std::cout << "2. List files based on a specific extension (e.g., .txt).\n";
    std::cout << "3. List files based on a pattern (e.g., moha*.*).\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();  

    std::string pattern;
    switch (choice) {
        case 1:
            for (const auto& entry : fs::directory_iterator(fs::current_path())) {
                std::cout << entry.path().filename().string() << std::endl;
            }
            break;
        case 2:
            std::cout << "Enter file extension (e.g., .txt): ";
            std::getline(std::cin, pattern);
            for (const auto& entry : fs::directory_iterator(fs::current_path())) {
                if (entry.path().extension() == pattern) {
                    std::cout << entry.path().filename().string() << std::endl;
                }
            }
            break;
        case 3:
            std::cout << "Enter file pattern (e.g., moha*.*): ";
            std::getline(std::cin, pattern);
            for (const auto& entry : fs::directory_iterator(fs::current_path())) {
                if (entry.path().filename().string().find(pattern) != std::string::npos) {
                    std::cout << entry.path().filename().string() << std::endl;
                }
            }
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}

void create_directory() {
    std::string dir_name;
    std::cout << "Enter the name of the directory to create: ";
    std::getline(std::cin, dir_name);

    if (!fs::create_directory(dir_name)) {
        std::cout << "Failed to create directory or directory already exists.\n";
    } else {
        std::cout << "Directory created successfully.\n";
    }
}

void change_directory() {
    int choice;
    std::cout << "1. Move one step back (to the parent directory).\n";
    std::cout << "2. Move to the root directory.\n";
    std::cout << "3. Move to a specific directory provided by the user.\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); 

    switch (choice) {
        case 1:
            fs::current_path(fs::current_path().parent_path());
            std::cout << "Moved to parent directory.\n";
            break;
        case 2:
            fs::current_path(fs::path("/"));
            std::cout << "Moved to root directory.\n";
            break;
        case 3:
            {
                std::string dir_name;
                std::cout << "Enter the name of the directory to move to: ";
                std::getline(std::cin, dir_name);
                if (fs::exists(dir_name) && fs::is_directory(dir_name)) {
                    fs::current_path(dir_name);
                    std::cout << "Moved to directory: " << dir_name << "\n";
                } else {
                    std::cout << "Directory does not exist.\n";
                }
            }
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}

int main() {
    while (true) {
        int main_choice;
        std::cout << "Main Menu:\n";
        std::cout << "1. List files in the current directory.\n";
        std::cout << "2. Create a new directory.\n";
        std::cout << "3. Change the working directory.\n";
        std::cout << "4. Exit the program.\n";
        std::cout << "Enter your choice: ";
        std::cin >> main_choice;
        std::cin.ignore();  

        switch (main_choice) {
            case 1:
                list_files();
                break;
            case 2:
                create_directory();
                break;
            case 3:
                change_directory();
                break;
            case 4:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}













