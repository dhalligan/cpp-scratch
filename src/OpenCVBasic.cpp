#include "OpenCVBasic.h"

using namespace cv;
using std::cout;
using std::endl;
using std::string;

int display_image(string filename)
{
  namedWindow("Before" , CV_WINDOW_AUTOSIZE);

  // Load the source image
  Mat src = imread( "/home/deaglan/dev/git/cpp-scratch/input/cat_ferret.jpg", 1);

  // Create a destination Mat object
  Mat dst;

  // display the source image
  imshow("Before", src);

  for (int i=1; i<51; i=i+2)
    { 
      //smooth the image in the "src" and save it to "dst"
      //      blur(src, dst, Size(i,i));

      GaussianBlur( src, dst, Size( i, i ), 0, 0 );      

      //show the blurred image with the text
      imshow( "Smoothing by avaraging", dst );

      //wait for 3 seconds
      waitKey(3000);
    }
}
