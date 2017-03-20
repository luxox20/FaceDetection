#ifndef DESCRIPTORES_H
#define DESCRIPTORES_H

//include Opencv libraries
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgproc.hpp"

#include <vector>
#include <fstream>
#include <chrono>
#include <iostream>
using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;

class Descriptores
{

public:
	Descriptores();
	vector<KeyPoint> getKeypoints() const; 
    void setKeypoints(const vector<KeyPoint> &value);
	void ComputeImage (const Mat &img);
	Mat getDescriptors() const;
	void setDescriptors(const Mat &value);

private:
	Mat descriptors;
    vector<KeyPoint> keypoints;
	Ptr<SURF> detector;
    Ptr<SURF> extractor;

};

#endif