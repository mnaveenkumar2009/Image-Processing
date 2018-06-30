#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main(){
    Mat temp(600,800,CV_8UC3 );
    
    namedWindow("nothing"); // Create a window
    imshow("nothing",temp);
    waitKey(0);
    destroyWindow("nothing");
    return 0;
}