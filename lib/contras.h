#include <iostream>

IplImage *contras(IplImage *img,int tipe,double alpha=1.0,int beta=0){
    IplImage *kon = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
    CvSize ukuran = cvGetSize(img);

     unsigned int chan[3];
     if(tipe == 1){
         unsigned int min[3]={255};
         unsigned int max[3]={0};

        for(int i=0;i<ukuran.height;i++){
            for(int j=0;j<ukuran.width;j++){
                CvScalar pixelVal = cvGet2D( img, i, j);
                for(int k=0;k<3;k++){
                    if(min[k] > pixelVal.val[k])
                        min[k] = pixelVal.val[k];
                    if(max[k] < pixelVal.val[k]);
                        max[k] = pixelVal.val[k];
                }
            }
        }
        for(int i=0;i<ukuran.height;i++){
            for(int j=0;j<ukuran.width;j++){
                CvScalar pixelVal = cvGet2D( img, i, j);
                for(int k=0;k<3;k++){
                chan[k] = (pixelVal.val[k]-min[k]) * (255/(max[k]-min[k]));
                kon->imageData[i*kon->widthStep+3*j+k]=cv::saturate_cast<uchar>(chan[k]);
                }
            }
        }
    }else{
        for(int i=0;i<ukuran.height;i++){
            for(int j=0;j<ukuran.width;j++){
                CvScalar pixelVal = cvGet2D( img, i, j);
                for(int k=0;k<3;k++){
                chan[k] = cv::saturate_cast<uchar>(alpha*pixelVal.val[k]+beta);
                kon->imageData[i*kon->widthStep+3*j+k]=chan[k];
                }
            }
        }
    }
    return kon;
}
