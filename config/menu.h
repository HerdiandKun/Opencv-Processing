void menuutama(){
    system("CLS");
    cout<<"1. Segmentasi menggunakan image thresholding"<<endl;
    cout<<"2. Mengubah citra menjadi image negative"<<endl;
    cout<<"3. Meningkatkan kontrast citra/contract stretching"<<endl;
    cout<<"4. Cropping citra menggunakan image subtraction"<<endl;
    cout<<"5. FILTER RATA RATA"<<endl;
    cout<<"6. FILTER GAUSSIAN 3x3"<<endl;
    cout<<"7. FILTER GAUSSIAN 7x7"<<endl;
    cout<<"8. FILTER LAPLACE"<<endl;
    cout<<"9. Histogram"<<endl;
    cout<<"10. Minkowski Distance"<<endl;
    cout<<"11. Fourier Transform (Little Image)"<<endl;
    cout<<"Silakan pilih menu anda : ";
    cin>>pilih;
}

void menuhis(){
    cout<<"Pilih Histogram"<<endl;
    cout<<"1. Histogram"<<endl;
    cout<<"2. Histogram Kumlatif"<<endl;
    cout<<"3. Histogram Normalization"<<endl;
    cout<<"4. Perbandingan Histogram"<<endl;
    cout<<"Silakan pilih gambar : ";

    cin >> his;
}

void menugbr1(){
    cout<<"Pilih Gambar Anda"<<endl;
    cout<<"1. whitefly_pest"<<endl;
    cout<<"2. acasia_disease"<<endl;
    cout<<"Silakan pilih gambar : ";
    cin >> gbr;
     if(gbr == 1){
            img = cvLoadImage("img/whitefly_pest.jpg",CV_LOAD_IMAGE_COLOR);
            out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        }else{
            img = cvLoadImage("img/acasia_disease.jpg",CV_LOAD_IMAGE_COLOR);
            out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        }
}

void menugbr2(){
    cout<<"Pilih Gambar Anda"<<endl;
    cout<<"1. Triawan Munaf"<<endl;
    cout<<"2. Dian Sastro"<<endl;
    cout<<"Silakan pilih gambar : ";
    cin >> gbr;
        if(gbr == 1){
            img = cvLoadImage("img/daun.jpg",CV_LOAD_IMAGE_COLOR);
            out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        }else{
            img = cvLoadImage("img/dian_sastro.jpg",CV_LOAD_IMAGE_COLOR);
            out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
        }
}

void menugbrhis(){
    cout<<"Pilih Gambar Anda"<<endl;
    cout<<"1. Triawan Munaf"<<endl;
    cout<<"2. Dian Sastro"<<endl;
    cout<<"Silakan pilih gambar : ";
    cin >> gbr;
            if(gbr == 1){
                image = imread("img/daun.jpg",CV_LOAD_IMAGE_GRAYSCALE);
                menuhis();
                imshow("Gambar Asli",image);
                if(his == 1)
                    hasil = histogram(image);
                else if(his ==  2)
                    hasil = histogramkum(image);
                else if(his ==  3)
                    hasil = histogramnormal(image);
                else
                    hasil = banding(image);
            }else{
                image = imread("img/dian_sastro.jpg",CV_LOAD_IMAGE_GRAYSCALE);
                menuhis();
                imshow("Gambar Asli",image);
                if(his == 1)
                    hasil = histogram(image);
                else if(his ==  2)
                    hasil = histogramkum(image);
                else if(his ==  3)
                    hasil = histogramnormal(image);
                else
                    hasil = banding(image);
            }
}

void menufourier(){
    cout<<"Pilih Gambar Anda"<<endl;
    cout<<"1. 3.jpg"<<endl;
    cout<<"2. 5.jpg"<<endl;
    cout<<"Silakan pilih gambar : ";
    cin >> gbr;
            if(gbr == 1)
                image = imread("img/3.jpg",CV_LOAD_IMAGE_GRAYSCALE);
            else
                image = imread("img/5.jpg",CV_LOAD_IMAGE_GRAYSCALE);

            fourier(image);
            imshow("Gambar Asli",image);
}
