//
// Created by kawa on 10/6/18.
//
#ifndef CONVERTPCL_CONVERT_H
#define CONVERTPCL_CONVERT_H

#include <librealsense2/rs.hpp>
#include <librealsense2/rs_advanced_mode.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>

#include <iostream>

#include "loadParams.hpp"

class ConvertPCL{

private:

    //Buffer関係
    rs2::pipeline pipeline;
    rs2::pipeline_profile pipeline_profile;
    rs2::frameset frameset;
    rs2::frame color_frame;
    rs2::colorizer color_map;

    cv::Mat color_mat_;
    int color_width_ = 640;
    int color_height_ = 480;
    int width_ = 640;
    int height_ = 480;
    int fps_ = 30;
    float degree;
    int count;

    const int markers_x           = 3;      // x方向に配置するマーカー数
    const int markers_y           = 2;      // y方向に配置するマーカー数
    const float marker_length     = 0.2;    // マーカーのサイズ
    const float marker_separation = 0.07;   // マーカー間の間隔

    std::vector<int> ids;
    cv::Vec3d rvecs, tvecs;
    cv::Mat camera_matrix;
    cv::Mat dist_coeffs;

    std::ostringstream vector_to_marker;
    float actual_marker_length = 0.15;
    //cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
    cv::Ptr<cv::aruco::Dictionary> dictionary;
    std::vector<std::vector<cv::Point2f>> corners;
    cv::Ptr<cv::aruco::GridBoard> grid_board;
    cv::Ptr<cv::aruco::Board> board;
 

public:

    ConvertPCL();
    ~ConvertPCL();
    void run();

private:

    inline void startSenser();
    void setupParams();
    void setupArUco();
    void detectArUco();
    void updateFrame();
    void draw();
    void show();
    void writeImage();
    void writeRotation();

    loadParams *load;
};

#endif //CONVERTPCL_CONVERT_H