#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "MatrixUtils.h"
#include "Simplex.h"
#include "Data.h"

int main(int argc, char **argv)
{
    Data *data;
    ReadData1(&data, argv[1]);
    PrintData(data);

    Simplex *s = malloc(sizeof(Simplex));
    InitializeSimplex(s, data);

    //
    {
        int bcols[] = {0, 2, 6};
        int nbcols[] = {1, 3, 4, 5};
        t_double B[3][3] = {{0.5, -0.5, 0}, {-0.5, 1.5, 0}, {-0.5, -2.5, 1}};

        for (int i = 0; i < data->n; i++)
        {
            s->x[i] = 0;
        }

        for (int i = 0; i < data->m; i++)
        {
            for (int j = 0; j < data->m; j++)
            {
                // s->B_inv[i][j] = data->A[i][j + data->n - data->m];
                s->B_inv[i][j] = B[i][j];
                s->x[bcols[i]] += s->B_inv[i][j] * data->b[j];
            }
            // s->basic_cols[i] = i + data->n - data->m;
            s->basic_cols[i] = bcols[i];
        }

        for (int i = 0; i < data->n - data->m; i++)
        {
            s->non_basic_cols[i] = nbcols[i];
        }

        for (int i = 0; i < data->n; i++)
        {
            printf("%g ", s->x[i]);
        }

        printf("\n");
    }

    SolvePricing(s);
    ComputeDirection(s);
    ComputeNewBasis(s);

    DeleteSimplex(s);

    DeleteData(data);

    exit(0);
}