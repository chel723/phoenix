//
// Created by chelseaw on 18/04/17.
//

#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/stitching.hpp"

using namespace std;
using namespace cv;

const String keys =
        "{help h usage ?  |      | print this message   }"
// "{@image          |<none>| image to show        }"
;

// store the position of trackbar
int factorAmount=10;
int num;

// call back function to execute every time the trackbar change
static void onChange(int pos, void* userInput);
void call_menu();

int main( int argc, const char** argv )
{
    CommandLineParser parser(argc, argv, keys);
    parser.about("ISEP C++ 2017");
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

// String img_filename = parser.get<String>(0);

    if (!parser.check()) {
        parser.printErrors();
        return 0;
    }

    do
    {
            call_menu();
            
            if (num ==0)
            {
                    return 0;
            }

    if (num == 6)
    {int number_files =0;

        cout << "How many files you want to read ? "<<endl;
        cin >> number_files;

        vector<string> files(number_files);

        bool try_use_gpu = false;
        Stitcher::Mode mode = Stitcher::PANORAMA;
        vector<Mat> imgs;
        string result_name = "result.jpg";

        for(int i =0; i < number_files;++i)
        {
            //read files
            cout << "\nPlease input the image file name (for example: joconde.jpg): "<<endl;
            cin >> files[i];

            Mat img = imread(files[i]);
            imgs.push_back(img);
        }

        //use stiching function
        Mat pano;
        Ptr<Stitcher> stitcher = Stitcher::create(mode, try_use_gpu);
        Stitcher::Status status = stitcher->stitch(imgs, pano);

        if (status != Stitcher::OK)
        {
            cout << "Can't stitch images, error code = " << int(status) << endl;
            return -1;
        }

        imwrite(result_name, pano);
        imshow(result_name, pano);

        waitKey(0);
        
        destroyWindow(result_name);
    }
    else
    {
        string imageName;
        cout<<"\n Please tell me which image you like (for example: joconde.jpg): " <<endl;
        cin >> imageName;

        Mat img = imread(imageName);
        namedWindow("Original", WINDOW_AUTOSIZE);
            
        Mat imgFactor;
        namedWindow("Modified", WINDOW_AUTOSIZE);//create window for blur image

        // create the Trackbar
        createTrackbar("Factor", "Modified", &factorAmount, 20, onChange, &img);

        imshow("Original", img);

        // Call back to onChange function
        onChange(factorAmount, &img);

        // wait app for a key to exit
        waitKey(0);

        // Destroy the windows
        destroyWindow("Original");
        destroyWindow("Modified");
            
    }
    }while(1);
        return 0;
}

// Trackbar call back function
static void onChange(int pos , void* userInput)
{
    if(pos <= 0)
        return;
    // result
    Mat imgFactor;
    namedWindow("Modified", WINDOW_AUTOSIZE);//create window for blur image

    // casting the input user img to
    Mat* img= (Mat*)userInput;
    Mat element = getStructuringElement( MORPH_RECT, Size(2*pos+1,2*pos+1), Point(pos,pos));

    // Apply a filter
    switch (num){
        case 1:
            blur(*img, imgFactor, Size(pos, pos));
            break;

        case 2:
            resize(*img, imgFactor, Size(63*pos,48*pos));
            break;

        case 3:
            erode(*img, imgFactor, element);
            break;

        case 4:
            dilate(*img, imgFactor, element);
            break;

        case 5:
            img->convertTo(imgFactor, -1, 0.1*pos, pos);
            break;
    }

    // Show the result
    imshow("Modified", imgFactor);

}

void call_menu()
{
    cout <<"Please tell me which option you choose: " << endl;
    cout <<" 1 -> blur " << endl;
    cout <<" 2 -> resize " << endl;
    cout <<" 3 -> erode " << endl;
    cout <<" 4 -> dilate " << endl;
    cout <<" 5 -> brighten / darken " << endl;
    cout <<" 6 -> panorama \n " << endl;
    cout <<" Press '0' to exit ... \n" << endl;
    cin  >> num;
}
