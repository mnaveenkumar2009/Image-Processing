#include <opencv2/opencv.hpp>
#include "../template.h"

using namespace cv;

int main(){
    VideoCapture cap(0);
    if(!cap.isOpened()){
        cout<<"no web cam"<<'\n';
        return 0;
    }

    ld fps = cap.get(CAP_PROP_FPS); //get the frames rate of the video
    cout << "Frames per seconds : " << fps << '\n';


    ld dWidth = cap.get(CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
    ld dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

    namedWindow("vid"); // Create a window
    while(1){
        Mat frame;
        if(cap.read(frame)){
            imshow("vid",frame);
            if(waitKey(10) == 27)
                break;            
        }
        else{
            cout<<"Cam disconnected";
            return 0;
        }
    }
    
    return 0;
}