
/*
# This file is part of PyEMMA.
#
# Copyright (c) 2015, 2014 Computational Molecular Biology Group, Freie Universitaet Berlin (GER)
#
# PyEMMA is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <stdio.h>

/** Subtracts given row vector from each row of the matrix X

@param X : (M, N) array
@param row : (N) array
@param M : int
@param N : int

*/
void _subtract_row_double(double* X, double* row, int M, int N)
{
        int i, j, ro;
        for (i=0; i!=M; ++i)
        {
                ro = i*N;
                for (j=0; j!=N; ++j)
                {
                        X[ro + j] -= row[j];
                }
        }
}

/** see above */
void _subtract_row_float(float* X, float* row, int M, int N)
{
        int i, j, ro;
        for (i=0; i!=M; ++i)
        {
                ro = i*N;
                for (j=0; j!=N; ++j)
                {
                        X[ro + j] -= row[j];
                }
        }
}

void _subtract_row_double_copy(double* X0, double* X, double* row, int M, int N)
{
        int i, j, ro;
        for (i=0; i!=M; ++i)
        {
                ro = i*N;
                for (j=0; j!=N; ++j)
                {
                        X0[ro + j] = X[ro + j] - row[j];
                }
        }
}

void _subtract_row_float_copy(float* X0, float* X, float* row, int M, int N)
{
        int i, j, ro;
        for (i=0; i!=M; ++i)
        {
                ro = i*N;
                for (j=0; j!=N; ++j)
                {
                        X0[ro + j] = X[ro + j] - row[j];
                }
        }
}


/** Checks each column whether it is constant in the rows or not

@param cols : (N) result array that will be filled with 0 (column constant) or 1 (column variable)
@param X : (M, N) array
@param M : int
@param N : int

*/
int _variable_cols_char(int* cols, char* X, int M, int N, int min_constant)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;
        int nconstant = N;  // current number of constant columns

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        if (X[j] != X[ro+j])
                        {
                                if (cols[j] == 0)
                                {
                                        cols[j] = 1;
                                        nconstant--;
                                        // are constant columns below threshold? Then interrupt.
                                        if (nconstant < min_constant)
                                                return 0;
                                        // do we have 0 constant columns? Then we can stop regularly.
                                        if (nconstant == 0)
                                                return 1;
                                }
                        }
                }
        }

        return 1;
}

/** see above */
int _variable_cols_int(int* cols, int* X, int M, int N, int min_constant)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;
        int nconstant = N;  // current number of constant columns

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        if (X[j] != X[ro+j])
                        {
                                if (cols[j] == 0)
                                {
                                        cols[j] = 1;
                                        nconstant--;
                                        // are constant columns below threshold? Then interrupt.
                                        if (nconstant < min_constant)
                                                return 0;
                                        // do we have 0 constant columns? Then we can stop regularly.
                                        if (nconstant == 0)
                                                return 1;
                                }
                        }
                }
        }

        return 1;
}

/** see above */
int _variable_cols_long(int* cols, long* X, int M, int N, int min_constant)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;
        int nconstant = N;  // current number of constant columns

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        if (X[j] != X[ro+j])
                        {
                                if (cols[j] == 0)
                                {
                                        cols[j] = 1;
                                        nconstant--;
                                        // are constant columns below threshold? Then interrupt.
                                        if (nconstant < min_constant)
                                                return 0;
                                        // do we have 0 constant columns? Then we can stop regularly.
                                        if (nconstant == 0)
                                                return 1;
                                }
                        }
                }
        }

        return 1;
}

/** see above */
int _variable_cols_float(int* cols, float* X, int M, int N, int min_constant)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;
        int nconstant = N;  // current number of constant columns

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        if (X[j] != X[ro+j])
                        {
                                if (cols[j] == 0)
                                {
                                        cols[j] = 1;
                                        nconstant--;
                                        // are constant columns below threshold? Then interrupt.
                                        if (nconstant < min_constant)
                                                return 0;
                                        // do we have 0 constant columns? Then we can stop regularly.
                                        if (nconstant == 0)
                                                return 1;
                                }
                        }
                }
        }

        return 1;
}

/** see above */
int _variable_cols_double(int* cols, double* X, int M, int N, int min_constant)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;
        int nconstant = N;  // current number of constant columns

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        if (X[j] != X[ro+j])
                        {
                                if (cols[j] == 0)
                                {
                                        cols[j] = 1;
                                        nconstant--;
                                        // are constant columns below threshold? Then interrupt.
                                        if (nconstant < min_constant)
                                                return 0;
                                        // do we have 0 constant columns? Then we can stop regularly.
                                        if (nconstant == 0)
                                                return 1;
                                }
                        }
                }
        }

        return 1;
}

/** Checks each column whether it is approximately constant in the rows or not

@param cols : (N) result array that will be filled with 0 (column constant) or 1 (column variable)
@param X : (M, N) array
@param M : number of rows
@param N : number of columns
@param tol : maximum difference of any row to the first row to be still considered equal.

*/
int _variable_cols_float_approx(int* cols, float* X, int M, int N, float tol, int min_constant)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;
        float diff;
        int nconstant = N;  // current number of constant columns

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        diff = X[j] - X[ro+j];
                        if (diff > tol || -diff > tol)
                        {
                                if (cols[j] == 0)
                                {
                                        cols[j] = 1;
                                        nconstant--;
                                        // are constant columns below threshold? Then interrupt.
                                        if (nconstant < min_constant)
                                                return 0;
                                        // do we have 0 constant columns? Then we can stop regularly.
                                        if (nconstant == 0)
                                                return 1;
                                }
                        }
                }
        }

        return 1;
}

/** see above */
int _variable_cols_double_approx(int* cols, double* X, int M, int N, double tol, int min_constant)
{
        // compare first and last row to get constant candidates
        int i,j;
        int ro = (M-1)*N;
        double diff;
        int nconstant = N;  // current number of constant columns

        // by default all 0 (constant)
        for (j=0; j<N; j++)
                cols[j] = 0;

        // go through all rows in order to confirm constant candidates
        for (i=0; i<M; i++)
        {
                ro = i*N;
                for (j=0; j<N; j++)
                {
                        diff = X[j] - X[ro+j];
                        if (diff > tol || -diff > tol)
                        {
                                if (cols[j] == 0)
                                {
                                        cols[j] = 1;
                                        nconstant--;
                                        // are constant columns below threshold? Then interrupt.
                                        if (nconstant < min_constant)
                                                return 0;
                                        // do we have 0 constant columns? Then we can stop regularly.
                                        if (nconstant == 0)
                                                return 1;
                                }
                        }
                }
        }

        return 1;
}
