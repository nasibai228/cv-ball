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

    // Container for object's countours points
    std::vector<std::vector<cv::Point> > contoursPoints;
    
    // until the end of the video
    while(videoCapture.read(frame)) {
        // Reduce noise
        cv::GaussianBlur(frame, blurredFrame, {5, 5}, 0);
        // Convert to HSV
        cv::cvtColor(blurredFrame, hsvFrame, cv::COLOR_BGR2HSV);
        
        // Find object between 2 color schemes (orange and yellow)
        cv::inRange(hsvFrame,
                    cv::Scalar(14, 160, 233),
                    cv::Scalar(35, 255, 255),
                    maskFrame);
        
        cv::findContours(maskFrame.clone(),
                         contoursPoints,
                         cv::RETR_LIST, // ierarchy type
                         cv::CHAIN_APPROX_NONE);
        
        cv::imshow("tracking2", frame);

        // delay
        int k = cv::waitKey(10);
        if(k == 27) {
            break;
        }
    }

    return 0;
}
