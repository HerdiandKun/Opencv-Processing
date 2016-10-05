IplImage *greyscale(IplImage *img){
    IplImage *red = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    IplImage *green = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    IplImage *blue = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    CvSize ukuran = cvGetSize(img);

    cvSplit(img,blue,green,red,NULL);
    cvShowImage("Grey",blue);
    return blue;
}

IplImage *treshold(IplImage *img,int tres){
    IplImage *grey = greyscale(img);
    IplImage *bin = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
    CvSize ukuran = cvGetSize(grey);

    for(int i=0;i<ukuran.height;i++){
        for(int j=0;j<ukuran.width;j++){
            int newpix = 0;
            int pixel = cvGetReal2D(grey,i,j);
                if(pixel < tres){
                    newpix = 0;
                }
                else {
                    newpix = 255;
                }
            cvSetReal2D(bin,i,j,newpix);
        }
    }
    return bin;
}

