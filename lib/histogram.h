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

    vector<float> histB(arr, arr + 256);
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

    vector<float> histB(arr, arr + 256);
    vector<float> kum = histB;
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

    vector<float> histB(arr, arr + 256);
    vector<float> kum = histB;
    Mat3b  plotKum;

    for (int i = 1; i < histB.size(); ++i) {
        kum[i] = histB[i] / (img.rows * img.cols);
    }
    drawHist(kum, plotKum, 3, 300,0.01);

    return plotKum;
}
