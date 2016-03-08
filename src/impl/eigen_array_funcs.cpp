
#include "public_interface_eigen.hpp"

// TODO just instantiate two template funcs to avoid dup code

MatrixXd createEigenMat() {
	int nrows = 4;
	int ncols = 3;
	MatrixXd M(nrows, ncols);
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			M(i, j) = i * ncols + j; // 0-11 in row-major order
		}
	}
	return M;
}

VectorXd createEigenVect() {
	int nrows = 4;
	VectorXd v(nrows);
	for (int i = 0; i < nrows; i++) {
		v(i) = i;
	}
	return v;
}

// ArrayXd createEigenArray() {
// 	int nrows = 4;
// 	int ncols = 3;
// 	ArrayXd A(nrows, ncols);
// 	for (int i = 0; i < nrows; i++) {
// 		for (int j = 0; j < ncols; j++) {
// 			A(i, j) = i * ncols + j; // 0-11 in row-major order
// 		}
// 	}
// 	return A;
// }

MatrixXf createEigenMatf() {
	int nrows = 4;
	int ncols = 3;
	MatrixXf M(nrows, ncols);
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			M(i, j) = i * ncols + j; // 0-11 in row-major order
		}
	}
	return M;
}
VectorXf createEigenVectf() {
	int nrows = 4;
	VectorXf v(nrows);
	for (int i = 0; i < nrows; i++) {
		v(i) = i;
	}
	return v;
}

MatrixXi createEigenMati() {
	int nrows = 4;
	int ncols = 3;
	MatrixXi M(nrows, ncols);
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			M(i, j) = i * ncols + j; // 0-11 in row-major order
		}
	}
	return M;
}
VectorXi createEigenVecti() {
	int nrows = 4;
	VectorXi v(nrows);
	for (int i = 0; i < nrows; i++) {
		v(i) = i;
	}
	return v;
}

