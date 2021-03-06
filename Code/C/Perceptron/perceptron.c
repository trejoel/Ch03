#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float randomFloat()
{
    float r = (float)rand() / (float)RAND_MAX;
    return r;
}

int calculateOutput(float weights[], float x, float y)
{
    float sum = x * weights[0] + y * weights[1];
    return (sum >= 0) ? 1 : -1;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    // X coordinates of the training set.

    float x[] = { -3.2, 1.1, 2.7, -1 };
     

    float y[] = { 1.5, 3.3, 5.12, 2.1 };
    

    // The training set outputs.
    int outputs[] = { 1, -1, -1, 1 };
    

    int i = 0; // iterator

    FILE *fp;

    system("PAUSE");

    int patternCount = sizeof(x) / sizeof(int);

    float weights[2];
    weights[0] = randomFloat();
    weights[1] = randomFloat();

    float learningRate = 0.1;

    int iteration = 0;
    float globalError;

    do {
        globalError = 0;
        int p = 0; // iterator
        for (p = 0; p < patternCount; p++)
        {
            // Calculate output.
            int output = calculateOutput(weights, x[p], y[p]);

            // Calculate error.
            float localError = outputs[p] - output;

            if (localError != 0)
            {
                // Update weights.
                for (i = 0; i < 2; i++)
                {
                    float add = learningRate * localError;
                    if (i == 0)
                    {
                        add *= x[p];
                    }
                    else if (i == 1)
                    {
                        add *= y[p];
                    }
                    weights[i] +=  add;
                }
            }

            // Convert error to absolute value.
            globalError += fabs(localError);

            printf("Iteration %d Error %.2f\n", iteration, globalError);          
        }

        iteration++;

    } while (globalError != 0);

    // Display network generalisation.
    printf("X       Y     Output\n");
    float j, k;
    for (j = -1; j <= 1; j += .5)
    {
        for (j = -1; j <= 1; j += .5)
        {
            // Calculate output.
            int output = calculateOutput(weights, j, k);
            printf("%.2f  %.2f  %s\n", j, k, (output == 1) ? "Blue" : "Red");
        }
    }

    // Display modified weights.
    printf("Modified weights: %.2f %.2f\n", weights[0], weights[1]);

    system("PAUSE");
    return 0;
}