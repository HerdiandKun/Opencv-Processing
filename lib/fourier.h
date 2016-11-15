
void forwardDFT(const double *s, const int &N, double *&a, double *&b)
{
    for (int k = 0; k <= N / 2; ++k) {
        a[k] = b[k] = 0;
        for (int x = 0; x < N; ++x) {
            a[k] += s[x] * cos(2 * M_PI / N * k * x);
            b[k] += s[x] * sin(2 * M_PI / N * k * x);
        }
        // normalization
        a[k] *= (k == 0 || k == N / 2) ? 1. / N : 2. / N;
        b[k] *= 2. / N;
    }
}


void inverseDFT(const double *a, const double *b, const int &N, double *&s)
{
    for (int x = 0; x < N; ++x) {
        s[x] = a[0];
        for (int k = 1; k <= N / 2; ++k) {
            s[x] += a[k] * cos(2 * M_PI / N * k * x) + b[k] * sin(2 * M_PI / N * k * x);
        }
    }
}

void fourier(Mat img){
    int n = img.rows*img.cols;
    int w = img.rows;
    //cout << n << endl;
    double *sig_in = new double [n];
     int i = 0;
     for(int x=0;x<img.rows;x++){
        for(int y=0;y<img.cols;y++){
               sig_in[i] = img.at<uchar>(x,y)/225.0;
               //cout << i << '=' << sig_in[i] << '\n';
            i++;
        }
     }

    double *a = new double [w/2 + 1];
    double *b = new double [w/2 + 1];
    double *sig_out = new double [w];

    forwardDFT(sig_in, w, a, b); //DFT
    inverseDFT(a, b, w, sig_out); // inverse DFT
    i=0;
    for(int x=0;x<img.rows;x++){
        for(int y=0;y<img.cols;y++){
               cout << sig_in[i] << " = " << sig_out[i] << endl;
            i++;
        }
     }

}
