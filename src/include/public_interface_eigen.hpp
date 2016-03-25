
#ifndef PUBLIC_INTERFACE_EIGEN_HPP
#define PUBLIC_INTERFACE_EIGEN_HPP

#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::ArrayXd;
using Eigen::ArrayXXd;

using Eigen::MatrixXf;
using Eigen::VectorXf;
using Eigen::ArrayXf;
using Eigen::ArrayXXf;

using Eigen::MatrixXi;
using Eigen::VectorXi;
using Eigen::ArrayXi;
using Eigen::ArrayXXi;

MatrixXd createEigenMat();
VectorXd createEigenVect();
ArrayXXd createEigenArray();
ArrayXd createEigenArrayVect();

MatrixXf createEigenMatf();
VectorXf createEigenVectf();
ArrayXXf createEigenArrayf();
ArrayXf createEigenArrayVectf();

MatrixXi createEigenMati();
VectorXi createEigenVecti();
ArrayXXi createEigenArrayi();
ArrayXi createEigenArrayVecti();

#endif
