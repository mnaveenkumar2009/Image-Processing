#include <opencv2/opencv.hpp>
#include "../template.h"

using namespace cv;

int main(){
    Mat image = imread("../assets/ceu_arduino_logo.png");
    ofstream f;
    f.open("numbers");
    if (image.empty()){
        cout << "Could not open or find the image" << '\n';
        return -1;
    }

    Size size(64,64);//the dst image size,e.g.100x100
    resize(image,image,size);//resize image
    cvtColor(image, image, CV_BGR2GRAY);
    Mat fin(64,128,CV_8UC1,Scalar(0));
    int i,j;
    f(i,64){
        f(j,64){
            if(image.at<uchar>(i,j)!=image.at<uchar>(24,39)&&image.at<uchar>(i,j)!=image.at<uchar>(44,55))
                fin.at<uchar>(i,j) = image.at<uchar>(i,j);
        }
    }
    cout<<fin.at<uchar>(24,39)<<'\n';
    putText(fin, "ceu-arduino", Point(64,35), FONT_HERSHEY_DUPLEX, 0.3, Scalar(255), 0.2);

    int buffer[128*64/8]={0},SSD1306_LCDWIDTH=128;
    f<<"{ ";
    f(i,128){
        f(j,64){
            int x=i,y=j;
            
            Scalar intensity = fin.at<uchar>(j,i);
            if(intensity[0])
                buffer[x+ (y/8)*SSD1306_LCDWIDTH] |=  (1 << (y&7));
            else
                buffer[x+ (y/8)*SSD1306_LCDWIDTH] &= ~(1 << (y&7));
        }
    }
    f(i,128*8){
        f<<buffer[i]<<",";
        if(i%16==0)f<<'\n';
    }
    f<<'}';
    // Vec3b intensity = img.at<Vec3b>(y, x);
    // uchar blue = intensity.val[0];
    // uchar green = intensity.val[1];
    // uchar red = intensity.val[2];
    // for (int i = 0; i < image.rows; i++)
    // {
    //     for (int j = 0; j < image.cols; j++)
    //     {
    //         image.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);
    //     }
    // }

    // imshow("negative image", image);
    if (!imwrite("../assets/MyImage.jpg", fin)){
        cout << "Failed to save the image" << endl;
        return -1;
    }

    String windowName = "The Saved Image"; //Name of the window
    namedWindow(windowName); // Create a window
    imshow(windowName, fin); // Show our image inside the created window.
    waitKey(0); // Wait for any keystroke in the window
    destroyWindow(windowName); //destroy the created window
    return 0;
}