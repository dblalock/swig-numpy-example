
#ifndef PUBLIC_INTERFACE_EIGEN_HPP
#define PUBLIC_INTERFACE_EIGEN_HPP

#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;
// using Eigen::ArrayXd;

using Eigen::MatrixXf;
using Eigen::VectorXf;

using Eigen::MatrixXi;
using Eigen::VectorXi;

MatrixXd createEigenMat();
VectorXd createEigenVect();
// ArrayXd createEigenArray(); // TODO swig wrappers for this

MatrixXf createEigenMatf();
VectorXf createEigenVectf();

MatrixXi createEigenMati();
VectorXi createEigenVecti();

#endif
