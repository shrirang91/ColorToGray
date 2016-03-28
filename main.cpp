//
//  main.cpp
//  color_to_gray
//
//  Created by Shrirang Adgaonkar on 9/8/15.
//  Copyright (c) 2015 Shrirang Adgaonkar. All rights reserved.
//

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    char* frame1 = argv[1];
    char* frame2 = argv[2];
   
	 Mat image1,image2;
    image1 = imread( frame1, 1 );
    image2 =imread (frame2,1);

    if( argc != 3 || !image1.data )
    {
        printf( " No image data \n " );
        return -1;
    }
    
    Mat gray_image1,gray_image2,diff;

    cvtColor( image1, gray_image1, CV_BGR2GRAY );
  cvtColor(image2,gray_image2,CV_BGR2GRAY );

    imwrite( "./Gray_Image1.jpg", gray_image1 );
	imwrite ("./Gray_Image2.jpg",gray_image2);
    
absdiff (gray_image1,gray_image2,diff);
	imwrite ("./diff.jpg",diff);
    namedWindow( frame1, CV_WINDOW_AUTOSIZE );
    namedWindow( "original1", CV_WINDOW_AUTOSIZE );
	namedWindow ("original2",CV_WINDOW_AUTOSIZE);
	namedWindow (frame2,CV_WINDOW_AUTOSIZE);
namedWindow("diff",CV_WINDOW_AUTOSIZE);
    
imshow( frame1, gray_image1 );
imshow ("original2", image2);
    imshow ("original",image1);
  imshow( frame2, gray_image2 );
imshow ("diff",diff); 
    waitKey(0);
    
    return 0;
}
