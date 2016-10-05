IplImage *croping(IplImage *img,IplImage *crop){
    IplImage *krop = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
    krop = img;
     CvSize ukuran = cvGetSize(crop);
      unsigned char chan[3];
    for(int i=0;i<ukuran.height;i++){
        for(int j=0;j<ukuran.width;j++){
            CvScalar pixelValimg = cvGet2D( img, i, j);
            CvScalar pixelValcrop = cvGet2D( crop, i, j);
            for(int k=0;k<3;k++){
            chan[k] = cv::saturate_cast<uchar>(pixelValimg.val[k]-pixelValcrop.val[k]);
            krop->imageData[i*krop->widthStep+3*j+k]=chan[k];
            }
        }
    }
    return krop;
}
