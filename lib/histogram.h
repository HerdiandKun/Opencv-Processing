#include "drawhist.h"

using namespace cv;
using namespace std;

Mat histogram(Mat img){
unsigned char *input = (unsigned char*)(img.data);
     int cn =img.channels();
    int b;
    int arr[256] = {0};
    for(int i = 0; i < img.rows; i++) {
        for(int j = 0; j < img.cols; j++) {
            b = input[i*img.cols*cn + j*cn +0]; //akses channel B
            arr[b] += 1;
        }
    }

    vector<double> histB(arr, arr + 256);
    Mat3b plotHist;

    drawHist(histB, plotHist, 3, 300,10);

    return plotHist;
}

Mat histogramkum(Mat img){
unsigned char *input = (unsigned char*)(img.data);
     int cn =img.channels();
    int b;
    int arr[256] = {0};
    for(int i = 0; i < img.rows; i++) {
        for(int j = 0; j < img.cols; j++) {
            b = input[i*img.cols*cn + j*cn +0]; //akses channel B
            arr[b] += 1;
        }
    }

    vector<double> histB(arr, arr + 256);
    vector<double> kum = histB;
    Mat3b  plotKum;

    for (int i = 1; i < histB.size(); ++i) {
        kum[i] = histB[i] + kum[i-1];
    }
    drawHist(kum, plotKum, 3, 300,10);

    return plotKum;
}

Mat histogramnormal(Mat img){
unsigned char *input = (unsigned char*)(img.data);
     int cn =img.channels();
    int b;
    int arr[256] = {0};
    for(int i = 0; i < img.rows; i++) {
        for(int j = 0; j < img.cols; j++) {
            b = input[i*img.cols*cn + j*cn +0]; //akses channel B
            arr[b] += 1;
        }
    }
    vector<double> histB(arr, arr + 256);
    vector<double> kum = histB;
    Mat3b  plotKum;
     for (int i = 0; i < histB.size(); ++i) {
        kum[i] = histB[i] / (img.rows * img.cols) *300;
    }
    drawHist(kum, plotKum, 3, 300,10);

    return plotKum;
}

void bawaan(Mat src)
    {
   Mat dst;

  /// Separate the image in 3 places ( B, G and R )
  vector<Mat> bgr_planes;
  split( src, bgr_planes );

  /// Establish the number of bins
  int histSize = 256;

  /// Set the ranges ( for B,G,R) )
  float range[] = { 0, 256 } ;
  const float* histRange = { range };

  bool uniform = true; bool accumulate = false;

  Mat b_hist, g_hist, r_hist;

  /// Compute the histograms:
  calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );

  // Draw the histograms for B, G and R
  int hist_w = 256 * 3; int hist_h = 300;
  int bin_w = cvRound( (double) hist_w/histSize );

  Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

  /// Normalize the result to [ 0, histImage.rows ]
  normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

  /// Draw for each channel
  for( int i = 1; i < histSize; i++ )
  {
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                       Scalar( 255, 0, 0), 2, 8, 0  );
  }

  /// Display
  namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
  imshow("calcHist Demo", histImage );
}

Mat banding(Mat src){
    Mat3b plotHis = histogram(src);
    bawaan(src);

    return plotHis;
}
