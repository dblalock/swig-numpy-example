
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

ArrayXXd createEigenArray() {
	int nrows = 4;
	int ncols = 3;
	ArrayXXd A(nrows, ncols);
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			A(i, j) = i * ncols + j; // 0-11 in row-major order
		}
	}
	return A;
}

ArrayXd createEigenArrayVect() {
	int nrows = 4;
	ArrayXd v(nrows);
	for (int i = 0; i < nrows; i++) {
		v(i) = i;
	}
	return v;
}

// ------------------------------------------------ floats

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

ArrayXXf createEigenArrayf() {
	int nrows = 4;
	int ncols = 3;
	ArrayXXf M(nrows, ncols);
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			M(i, j) = i * ncols + j; // 0-11 in row-major order
		}
	}
	return M;
}

ArrayXf createEigenArrayVectf() {
	int nrows = 4;
	ArrayXf v(nrows);
	for (int i = 0; i < nrows; i++) {
		v(i) = i;
	}
	return v;
}

// ------------------------------------------------ ints

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

ArrayXXi createEigenArrayi() {
	int nrows = 4;
	int ncols = 3;
	ArrayXXi M(nrows, ncols);
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			M(i, j) = i * ncols + j; // 0-11 in row-major order
		}
	}
	return M;
}

ArrayXi createEigenArrayVecti() {
	int nrows = 4;
	ArrayXi v(nrows);
	for (int i = 0; i < nrows; i++) {
		v(i) = i;
	}
	return v;
}
