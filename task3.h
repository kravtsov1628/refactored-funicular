#pragma once
#include <string>
#include <opencv2/opencv.hpp>

std::string calculate_sha256(const cv::Mat& image);
void run_image_hash_task(const std::string& image_path, const std::string& output_txt_path);