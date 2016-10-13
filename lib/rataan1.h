
IplImage *rataan1(IplImage *img){
    IplImage *bin = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
    CvSize ukuran = cvGetSize(img);
    bin = img;

    int filter[3][3]={1,1,1,1,1,1,1,1,1};
    int sumfilter = 9;
    int n = 3/2;

    for(int i=n;i<ukuran.height-n;i++){
        for(int j=n;j<ukuran.width-n;j++){
                for(int c=0;c<3;c++){
                    int temp = 0;
                    for(int x=0;x<3;x++){
                        for(int y=0;y<3;y++){
                            CvScalar pixelVal = cvGet2D(img, i-(x-n), j-(y-n));
                            temp += filter[x][y] * pixelVal.val[c];
                        }
                    }
                  bin->imageData[i*bin->widthStep+3*j+c] = saturate_cast<uchar>(temp/sumfilter);
                }
        }
    }

    return bin;
}

