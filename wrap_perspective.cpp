#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;
float w = 250, h = 350;
Mat matrix, imgWarp;
int main()
{
    string path = "resources/cards.jpg";

    Mat img = imread(path);

    // Floating point
    Point2f src[4] = {{529, 142}, {771, 190}, {405, 395}, {674, 457}};

    Point2f dest[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    matrix = getPerspectiveTransform(src, dest);

    warpPerspective(img, imgWarp, matrix, Point(w, h));

    for (int i = 0; i < 4; i++)
    {
        circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
    }

    imshow("Image", img);
    imshow("Image Warp", imgWarp);

    waitKey(0);
    return 0;
}
