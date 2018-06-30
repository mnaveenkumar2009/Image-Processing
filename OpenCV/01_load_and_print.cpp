#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main(){
    Mat face = imread("../../IDcard.png");
    if(face.empty()){
        cout<<"not there\n";
        return 0;
    }
    namedWindow("my id card"); // Create a window
    imshow("my id card",face);
    waitKey(0);
    destroyWindow("my id card");
    return 0;
}