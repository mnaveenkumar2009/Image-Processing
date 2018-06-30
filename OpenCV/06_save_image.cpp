#include <opencv2/opencv.hpp>
#include "../template.h"

using namespace cv;

int main(){
     Mat image = imread("assets/amal_rank1.png");
    
    if (image.empty()){
        cout << "Could not open or find the image" << '\n';
        return -1;
    }
    
    if (!imwrite("assets/MyImage.jpg", image)){
        cout << "Failed to save the image" << endl;
        return -1;
    }

    String windowName = "The Saved Image"; //Name of the window
    namedWindow(windowName); // Create a window
    imshow(windowName, image); // Show our image inside the created window.
    waitKey(0); // Wait for any keystroke in the window
    destroyWindow(windowName); //destroy the created window
    return 0;
}