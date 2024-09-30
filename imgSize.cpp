#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
    string path = "resources/test.png";
    Mat img = imread(path);

    Mat imgResize;
    cout << img.size() << endl;
    // resize(img, imgResize, Size(1920, 1080));
    // Scaling
    resize(img, imgResize, Size(), 0.5, 0.5);

    Mat imgCrop;
    Rect roi(200, 100, 300, 300);

    imgCrop = img(roi);

    imshow("Image", img);
    imshow("Image Resize", imgResize);
    imshow("Image Crop", imgCrop);

    waitKey(0);
    return 0;
}