
#ifndef camFusion_hpp
#define camFusion_hpp

#include <stdio.h>
#include <vector>
#include <opencv2/core.hpp>
#include "dataStructures.h"

void clusterLidarWithROI(std::vector<BoundingBox> &boundingBoxes, std::vector<LidarPoint> &lidarPoints, float shrinkFactor, cv::Mat &P_rect_xx, cv::Mat &R_rect_xx, cv::Mat &RT);
void clusterKptMatchesWithROI(BoundingBox &boundingBox, const std::vector<cv::KeyPoint> &kptsPrev, const std::vector<cv::KeyPoint> &kptsCurr, std::vector<cv::DMatch> &kptMatches);
void matchBoundingBoxes(const std::vector<cv::DMatch> &matches, std::map<int, int> &bbBestMatches, const DataFrame &prevFrame, const DataFrame &currFrame);

void show3DObjects(std::vector<BoundingBox> &boundingBoxes, cv::Size worldSize, cv::Size imageSize, bool bWait=true);

void computeTTCCamera(const std::vector<cv::KeyPoint> &kptsPrev, const std::vector<cv::KeyPoint> &kptsCurr,
                      const std::vector<cv::DMatch> &kptMatches, const double frameRate, double &TTC, cv::Mat *visImg=nullptr, size_t frame=1);
void computeTTCLidar(std::vector<LidarPoint> &lidarPointsPrev,
                     std::vector<LidarPoint> &lidarPointsCurr, const double frameRate, double &TTC);
#endif /* camFusion_hpp */
