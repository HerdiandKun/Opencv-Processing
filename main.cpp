#include<cv.h>
#include<highgui.h>
#include <math.h>
#include "lib/threshold.h"
#include "lib/negative.h"
#include "lib/contras.h"
#include "lib/cropping.h"

using namespace std;
using namespace cv;

int main(){
    int pilih;
    IplImage *out;
    IplImage *img;
    system("CLS");
    cout<<"1. Segmentasi menggunakan image thresholding"<<endl;
    cout<<"2. Mengubah citra menjadi image negative"<<endl;
    cout<<"3. Meningkatkan kontrast citra/contract stretching"<<endl;
    cout<<"4. Cropping citra menggunakan image subtraction"<<endl;
    cout<<"Silakan pilih menu anda : ";
    cin>>pilih;

    if(pilih == 1){
         system("CLS");
         int gbr,tres;
        cout<<"=========THRESHOLD IMAGE=========="<<endl;
        cout<<"Pilih Gambar Anda"<<endl;
        cout<<"1. whitefly_pest"<<endl;
        cout<<"2. acasia_disease"<<endl;
        cout<<"Silakan pilih gambar : ";
        cin >> gbr;
        cout<<"Masukkan nilai threshold (0-255): ";
        cin >> tres;

        if(gbr == 1){
            img = cvLoadImage("img/whitefly_pest.jpg",CV_LOAD_IMAGE_COLOR);
            out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        }else{
            img = cvLoadImage("img/acasia_disease.jpg",CV_LOAD_IMAGE_COLOR);
            out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        }
        cvShowImage("Gambar Asli",img);
        out = treshold(img,tres);
    }else if(pilih == 2){
        system("CLS");
         int gbr;
        cout<<"=========NEGATIVE IMAGE=========="<<endl;
        cout<<"Pilih Gambar Anda"<<endl;
        cout<<"1. whitefly_pest"<<endl;
        cout<<"2. acasia_disease"<<endl;
        cout<<"Silakan pilih gambar : ";
        cin >> gbr;
        if(gbr == 1){
            img = cvLoadImage("img/whitefly_pest.jpg",CV_LOAD_IMAGE_COLOR);
            out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        }else{
            img = cvLoadImage("img/acasia_disease.jpg",CV_LOAD_IMAGE_COLOR);
            out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        }
        cvShowImage("Gambar Asli",img);
        out = negative(img);
    }else if(pilih == 3){
        system("CLS");
         int gbr,tipe,beta=0;
         double kon,alpha=0.0;
         cout<<"============CONTRAS IMAGE/IMAGE STRETCHING=========="<<endl;
        cout<<"Pilih Tipe Kontras"<<endl;
        cout<<"1. Fungsi Fout = (Fin - a) * b"<<endl;
        cout<<"2. Dinamis Kontras (alpha - betha)"<<endl;

        cout<<"Silakan pilih tipe contras : ";
        cin >> tipe;
        if(tipe == 2){
            cout<<"Silakan masukan alpha (1.0-3.0) : ";
            cin >> alpha;
            cout<<"Silakan masukan betha (0-100) : ";
            cin >> beta;
        }
        cout<<"Pilih Gambar Anda"<<endl;
        cout<<"1. whitefly_pest"<<endl;
        cout<<"2. acasia_disease"<<endl;
        cout<<"Silakan pilih gambar : ";
        cin >> gbr;
        //cout<<"Masukkan Kontras (1.0-3.0) : ";
        //cin >>kon;
        if(gbr == 1){
            img = cvLoadImage("img/whitefly_pest.jpg",CV_LOAD_IMAGE_COLOR);
            out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        }else{
            img = cvLoadImage("img/acasia_disease.jpg",CV_LOAD_IMAGE_COLOR);
            out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        }
        cvShowImage("Gambar Asli",img);
        out = contras(img,tipe,alpha,beta);
    }else if(pilih == 4){
        system("CLS");
         cout<<"=========IMAGE SUBTRACTION=========="<<endl;
        IplImage *crop = cvLoadImage("img/chest_landmark.jpg",CV_LOAD_IMAGE_COLOR);
        img = cvLoadImage("img/chest_x-ray.jpg",CV_LOAD_IMAGE_COLOR);
        out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        //cvSub(img,crop,out);
        cvShowImage("Gambar Landmark",crop);
        cvShowImage("Gambar Asli",img);
        out = croping(img,crop);
    }
    cvShowImage("Hasil Pengolahan",out);
    cvWaitKey(0);
    return 0;
 }
