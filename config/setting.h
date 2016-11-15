#include<cv.h>
#include<highgui.h>
#include <math.h>
#include <iostream>

//namespace
using namespace std;
using namespace cv;

#include "../lib/threshold.h"
#include "../lib/negative.h"
#include "../lib/contras.h"
#include "../lib/cropping.h"
#include "../lib/rataan.h"
#include "../lib/rataan1.h"
#include "../lib/gaussian.h"
#include "../lib/laplace.h"
#include "../lib/histogram.h"
#include "../lib/minkowski.h"
#include "../lib/fourier.h"

//Variable
bool print = true;
int his,gbr, pilih;
bool cekMat=false;
IplImage *out;
IplImage *img;
Mat image;
Mat hasil;
