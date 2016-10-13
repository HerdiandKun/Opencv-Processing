#include <iostream>
IplImage *gaussian(IplImage *img){
    IplImage *bin = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
    CvSize ukuran = cvGetSize(img);
    bin = img;
    int N = 3;
    double filter[3][3]={1,2,1,2,4,2,1,2,1};
    int sumfilter = 16;
    int n = N/2;

    for(int i=n;i<ukuran.height-n;i++){
        for(int j=n;j<ukuran.width-n;j++){
                for(int c=0;c<3;c++){
                    double temp = 0;
                    for(int x=0;x<N;x++){
                        for(int y=0;y<N;y++){
                            CvScalar pixelVal = cvGet2D(img, i-(x-n), j-(y-n));
                            temp += filter[x][y] * pixelVal.val[c];
                        }
                    }
                  bin->imageData[i*bin->widthStep+3*j+c] = saturate_cast<uchar>(temp/sumfilter);
                  //std::cout << temp << " ";
                }
        }
    }

    return bin;
}

IplImage *gaussian2(IplImage *img){
    IplImage *bin = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
    CvSize ukuran = cvGetSize(img);
    bin = img;
    int N = 7;
    //double filter[N][N]={1,2,1,2,4,2,1,2,1};
    //double filter[3][3]={0,-1,0,-1,4,-1,0,-1,0};
    double filter[7][7]={{0,0,0,5,0,0,0},
    {0,5,18,32,18,5,0},
    {0,18,64,100,64,18,0},
    {5,32,100,100,100,32,5},
    {0,18,64,100,64,18,0},
    {0,5,18,32,18,5,0},
    {0,0,0,5,0,0,0}
    };
    int sumfilter = 0;
    for (int a=0;a<N;a++){
        for (int b=0;b<N;b++){
            sumfilter += filter[a][b];
        }
    }
    int n = N/2;

    for(int i=n;i<ukuran.height-n;i++){
        for(int j=n;j<ukuran.width-n;j++){
                for(int c=0;c<3;c++){
                    double temp = 0;
                    for(int x=0;x<N;x++){
                        for(int y=0;y<N;y++){
                            CvScalar pixelVal = cvGet2D(img, i-(x-n), j-(y-n));
                            temp += filter[x][y] * pixelVal.val[c];
                        }
                    }
                  bin->imageData[i*bin->widthStep+3*j+c] = saturate_cast<uchar>(temp/sumfilter);
                  //std::cout << temp << " ";
                }

        }
    }

    return bin;
}

