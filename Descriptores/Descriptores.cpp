#include "Descriptores.hpp"

Descriptores::Descriptores()
{
	detector=SURF::create(500);
    extractor=SURF::create();
}

vector<KeyPoint> Descriptores::getKeypoints() const
{
    return keypoints;
}

void Descriptores::setKeypoints(const vector<KeyPoint> &value)
{
    keypoints=value;
}

void Descriptores::ComputeImage(const Mat &img)
{
    detector->detect(img,keypoints);
    extractor->compute(img,keypoints,descriptors);
}

Mat Descriptores::getDescriptors() const
{
    return descriptors;
}

void Descriptores::setDescriptors(const Mat &value)
{
    descriptors=value;
}