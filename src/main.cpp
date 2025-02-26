#include <filesystem>
#include <fstream>
#include <iostream>

#include <nlohmann/json.hpp>
#include <optional>
#include <string>

int main() {
    auto file = std::ifstream("json.txt");

    if (file.is_open()) {
        const auto src = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
        const auto json = nlohmann::json::parse(src);

        auto output = std::optional<std::filesystem::path>();
        
        if (const auto &it = json.find("dataset_folder"); it != json.end()) {
            output = it.value().get<std::filesystem::path>();
        }

        if (output) {
            std::filesystem::create_directory(*output);

            if (const auto &it = json.find("include_folders"); it != json.end()) {
                for (const auto &object : it.value()) {
                    auto filenames = std::vector<std::string>();
                    auto include = std::optional<std::string>();

                    if (const auto &it = object.find("folder_name"); it != object.end()) {
                        include = it.value().get<std::string>();
                    }

                    if (include) {
                        const auto dirpath = *output / *include;

                        std::filesystem::create_directory(dirpath);

                        if (const auto &it = object.find("include_files"); it != object.end()) {
                            filenames = it.value().get<std::vector<std::string>>();
                        }

                        for (const auto &filename : filenames) {
                            auto file = std::ofstream(dirpath / filename);

                            if (file.is_open()) {
                                file << "Hello, world!";
                            }
                        }
                    }
                }
            }
        } else {
            std::cout << "Output folder is not found" << std::endl;
        }
    } else {
        std::cout << "File `json.txt` is not found" << std::endl;
    }

    return 0;
}