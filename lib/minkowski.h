#include <iostream>

using namespace std;
using namespace cv;

void hitminkowsky(Mat src1, Mat src2){
unsigned char *input1 = (unsigned char*)(src1.data);
unsigned char *input2 = (unsigned char*)(src2.data);
     int cn1 =src1.channels();
     int cn2 =src2.channels();
    int a,b;
    int arr1[256] = {0};
    int arr2[256] = {0};
    for(int i = 0; i < src1.rows; i++) {
        for(int j = 0; j < src1.cols; j++) {
            a = input1[i*src1.cols*cn1 + j*cn1 +0]; //akses channel B
            arr1[a] += 1;
        }
    }
    for(int i = 0; i < src2.rows; i++) {
        for(int j = 0; j < src2.cols; j++) {
            b = input2[i*src2.cols*cn2 + j*cn2 +0]; //akses channel B
            arr2[b] += 1;
        }
    }
    double jum = 0;
    for (int i = 0; i < 255; ++i) {
        jum += abs(((double)arr1[i] / (src1.rows * src1.cols))- ((double)arr2[i] / (src2.rows * src2.cols)));
    }
    cout << "Nilai Minkowski Distance : " << jum << "\n";
    if(jum == 0 )
    cout << "Kedua Citra SAMA" << endl;
    else if(jum <= 1)
    cout << "Kedua Citra MIRIP" << endl;
    else
    cout << "Kedua Citra TIDAK SAMA" << endl;
}
