#pragma once

#include <OpenANN/io/DataSet.h>
#include <OpenANN/optimization/Optimizable.h>

namespace OpenANN {

/**
 * @class Learner
 * Common base class of all learning algorithms.
 */
class Learner : public Optimizable
{
public:
  /**
   * Set training set.
   * @param trainingInput input vectors, each instance should be in a row
   * @param trainingOutput output vectors, each instance should be in a row
   */
  virtual Learner& trainingSet(Eigen::MatrixXd& trainingInput,
                               Eigen::MatrixXd& trainingOutput) = 0;
  /**
   * Set training set.
   * @param trainingSet training set
   */
  virtual Learner& trainingSet(DataSet& trainingSet) = 0;
  /**
   * Make a prediction.
   * @param x Input vector.
   * @return Prediction.
   */
  virtual Eigen::VectorXd operator()(const Eigen::VectorXd& x) = 0;
  /**
   * Make predictions.
   * @param X Each row represents an input vector.
   * @return Each row represents a prediction.
   */
  virtual Eigen::MatrixXd operator()(const Eigen::MatrixXd& X) = 0;
};

}