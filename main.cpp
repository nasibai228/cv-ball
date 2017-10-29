#include <iostream>
#include <string>

#include <opencv2/tracking.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[]) {
    if(argc <= 1) {
        std::cout << "Lack of parameters" << std::endl;
        return 0;
    }

    // Open video stream
    cv::VideoCapture videoCapture(argv[1]);
    
    if(!videoCapture.isOpened()) {
        std::cout << "Failed to open video file" << std::endl;
        return 1;
    }
    
    // Frames
    cv::Mat frame;
    cv::Mat blurredFrame;
    cv::Mat hsvFrame;
    cv::Mat maskFrame;

    // until the end of the video
    while(videoCapture.read(frame)) {
        cv::imshow("tracking2", frame);

        // delay
        int k = cv::waitKey(10);
        if(k == 27) {
            break;
        }
    }

    return 0;
}
