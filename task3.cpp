#include "task3.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <openssl/sha.h>

std::string calculate_sha256(const cv::Mat& image) {

    size_t data_size = image.total() * image.elemSize();
    unsigned char hash[SHA256_DIGEST_LENGTH];
    
    SHA256(image.data, data_size, hash);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void run_image_hash_task(const std::string& image_path, const std::string& output_txt_path) {
    cv::Mat img = cv::imread(image_path);
    if (img.empty()) {
        std::cerr << "Error: Could not open or find the image at " << image_path << std::endl;
        return;
    }

    std::string original_hash = calculate_sha256(img);

    if (img.at<cv::Vec3b>(0, 0)[0] == 0) {
        img.at<cv::Vec3b>(0, 0)[0] = 1;
    } else {
        img.at<cv::Vec3b>(0, 0)[0] = 0;
    }


    std::string modified_hash = calculate_sha256(img);

    std::string comparison_result = (original_hash == modified_hash) 
        ? "Hashes match" 
        : "Hashes do not match";

    std::cout << "Original SHA256: " << original_hash << std::endl;
    std::cout << "Modified SHA256: " << modified_hash << std::endl;
    std::cout << "Result: " << comparison_result << std::endl;

    std::ofstream out_file(output_txt_path);
    if (out_file.is_open()) {
        out_file << "Original SHA256: " << original_hash << "\n";
        out_file << "Modified SHA256: " << modified_hash << "\n";
        out_file << "Result: " << comparison_result << "\n";
        out_file.close();
        std::cout << "Results successfully saved to " << output_txt_path << std::endl;
    } else {
        std::cerr << "Error writing to file" << std::endl;
    }
}