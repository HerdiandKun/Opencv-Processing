using namespace cv;

Mat rataan(Mat img){
    Mat rat= img.clone();
    int filter[3][3]={1,1,1,1,1,1,1,1,1};
    int sumfilter = 9;
    int n = 3/2;
       for(int x=n;x<img.rows-n;x++){
            for(int y=n;y<img.cols-n;y++){
                for(int c=0;c<3;c++){
                    int temp = 0;
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            temp += filter[i][j] * img.at<Vec3b>(x-(i-n),y-(j-n)).val[c];
                        }
                    }
                    rat.at<Vec3b>(x,y).val[c] = saturate_cast<uchar>(temp/sumfilter);
                }
            }
        }

    return rat;
}
