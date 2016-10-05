IplImage *negative(IplImage *img){
    IplImage *neg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
    CvSize ukuran = cvGetSize(img);
     unsigned char chan[3];

    for(int i=0;i<ukuran.height;i++){
        for(int j=0;j<ukuran.width;j++){
            CvScalar pixelVal = cvGet2D( img, i, j);
            for(int k=0;k<3;k++){
            chan[k] = 255-pixelVal.val[k];
            neg->imageData[i*neg->widthStep+3*j+k]=cv::saturate_cast<uchar>((uchar)chan[k]);
            }
        }
    }
    return neg;
}
