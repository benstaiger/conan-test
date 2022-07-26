#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>


int main()
{
    cv::Mat img = cv::Mat::zeros(256, 256, CV_8UC3);
    if(img.empty())
    {
        std::cout << "Failed to create empty image" << std::endl;
        return 1;
    }
    for (size_t i = 0; i < 10; ++i) {
        cv::rectangle(img, cv::Rect(10, 10*i, 100, 100), {0, 0, 200});
        cv::imshow("Display window", img);
        int k = cv::waitKey(1000); // Wait for a keystroke in the window
        if(k == 's') {
            cv::imwrite("example.png", img);
            break;
        }
    }
    return 0;
}