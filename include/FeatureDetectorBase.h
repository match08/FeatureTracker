/*************************************************************************
 *
 *              Author: b51
 *                Mail: b51live@gmail.com
 *            FileName: FeatureDetectorBase.h
 *
 *          Created On: Thu 27 Jun 2019 03:29:38 PM CST
 *     Licensed under The MIT License [see LICENSE for details]
 *
 ************************************************************************/

#ifndef FEATURE_TRACKER_FEATURE_DETECTOR_BASE_H_
#define FEATURE_TRACKER_FEATURE_DETECTOR_BASE_H_

#include <Eigen/Core>

#include "FeatureDescriptor.h"

class FeatureDetectorBase {
 public:
  FeatureDetectorBase(){};
  virtual ~FeatureDetectorBase(){};

  virtual void Init(int width, int height, int stride,
                    int max_number_of_features, bool rotation_invariant) = 0;

  virtual void FeatureDetect(
      const unsigned char* im, Eigen::Matrix2Xd* current_measurements,
      std::vector<float>* current_feature_orientations,
      std::vector<float>* current_feature_scales,
      FeatureDescriptor* current_feature_descriptors) = 0;

  virtual bool IsInitialized() const = 0;
  virtual int GetHeight() const = 0;
  virtual int GetWidth() const = 0;
  virtual int GetRowStride() const = 0;
  virtual int GetMaxNumberOfFeatures() const = 0;

 private:
  FeatureDetectorBase(const feature_tracker::FeatureDetectorBase& ft) = delete;
  FeatureDetectorBase& operator=(
      const feature_tracker::FeatureDetectorBase& ft) = delete;
};

#endif