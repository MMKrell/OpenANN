#pragma once

#include <OpenANN/layers/Layer.h>
#include <OpenANN/ActivationFunctions.h>

namespace OpenANN {

/**
 * @class Compressed
 *
 * Fully connected layer with compressed weights.
 *
 * The number of optimizable parameters is reduced due to compressed indirect
 * weight representation. The weight matrix is generated by
 * \f$ W = \alpha \Phi \f$, where \f$ \alpha \f$ is an optimizable parameter
 * matrix with less components than \f$ W \f$ and \f$ \Phi \f$ is a fixed
 * matrix that could e. g. be generated randomly. Note that the compressed
 * representation of weights is equivalent to compressing the input of the
 * layer with \f$ \Phi x \f$ and regarding \f$ \alpha \f$ as the weight
 * matrix.
 *
 * [1] A. Fabisch, Y. Kassahun, H. Wöhrle and F. Kirchner:
 * Learning in compressed space,
 * Neural Networks 42, pp. 83-93, ISSN 0893-6080, 2013.
 */
class Compressed : public Layer
{
  int I, J, M;
  bool bias;
  ActivationFunction act;
  double stdDev;
  Eigen::MatrixXd W;
  Eigen::MatrixXd Wd;
  Eigen::MatrixXd phi;
  Eigen::MatrixXd alpha;
  Eigen::MatrixXd alphad;
  Eigen::MatrixXd* x;
  Eigen::MatrixXd a;
  Eigen::MatrixXd y;
  Eigen::MatrixXd yd;
  Eigen::MatrixXd deltas;
  Eigen::MatrixXd e;

public:
  Compressed(OutputInfo info, int J, int M, bool bias, ActivationFunction act,
             const std::string& compression, double stdDev);
  virtual OutputInfo initialize(std::vector<double*>& parameterPointers,
                                std::vector<double*>& parameterDerivativePointers);
  virtual void initializeParameters();
  virtual void updatedParameters();
  virtual void forwardPropagate(Eigen::MatrixXd* x, Eigen::MatrixXd*& y, bool dropout);
  virtual void backpropagate(Eigen::MatrixXd* ein, Eigen::MatrixXd*& eout);
  virtual Eigen::MatrixXd& getOutput();
};

}
