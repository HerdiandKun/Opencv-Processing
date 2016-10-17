void drawHist(const vector<float>& data, Mat3b& dst,
            int binSize = 3, int height = 0,float range=0, int rev_value = -1)
{
    int max_value = *max_element(data.begin(), data.end());
    int rows = 0;
    int cols = 0;
    float scale = 1;
    if(height == 0){
        rows = max_value + 10;
    } else {
        rows = height;
        scale = float(height) / (max_value + range);
    }
    cols = data.size() * binSize;
    dst = Mat3b(rows, cols, Vec3b(0,0,0));
    for(int i = 0; i < data.size(); ++i){
        float h = rows - (scale * data[i]);
        rectangle(dst, Point(i*binSize, h),
                        Point((i+1)*binSize - 1, rows), (i%2) ?
                        Scalar(0,100,255) : Scalar(0,0,255), CV_FILLED);
    }

    if(rev_value >= 0)
    {
        int h = rows - int(scale * rev_value);
        line(dst, Point(0,h), Point(cols, h), Scalar(255,0,0));
    }
}
