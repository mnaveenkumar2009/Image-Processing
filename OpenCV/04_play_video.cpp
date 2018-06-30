#include <opencv2/opencv.hpp>
#include "../template.h"

using namespace cv;

int main(){
    VideoCapture cap("assets/whatisml.mp4");
    if(!cap.isOpened()){
        cout<<"no such thing"<<'\n';
        return 0;
    }
    
    //Uncomment to start the video in the middle
    //cap.set(CAP_PROP_POS_MSEC, 300); 

    
    ld fps = cap.get(CAP_PROP_FPS); //get the frames rate of the video
    cout << "Frames per seconds : " << fps << '\n';

    namedWindow("vid"); // Create a window
    while(1){
        Mat frame;
        if(cap.read(frame)){
            imshow("vid",frame);
            if(waitKey(10) == 27)
                break;            
        }
        else{
            cout<<"The End";
            return 0;
        }
    }
    
    return 0;
}