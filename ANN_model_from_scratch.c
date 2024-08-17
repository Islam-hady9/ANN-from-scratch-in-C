#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define INPUT_SIZE 3
#define HIDDEN_SIZE 3
#define OUTPUT_SIZE 1
#define LEARNING_RATE 0.5
#define EPOCHS 10000

// Sigmoid activation function
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Derivative of sigmoid function
double sigmoid_derivative(double x) {
    return x * (1 - x);
}

// Initialize weights and biases with random values
void initialize(double weights_input_hidden[INPUT_SIZE][HIDDEN_SIZE], double weights_hidden_output[HIDDEN_SIZE][OUTPUT_SIZE], double bias_hidden[HIDDEN_SIZE], double bias_output[OUTPUT_SIZE]) {
    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            weights_input_hidden[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            weights_hidden_output[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        bias_hidden[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        bias_output[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
}

// Forward propagation
void forward_propagation(double input[INPUT_SIZE], double weights_input_hidden[INPUT_SIZE][HIDDEN_SIZE], double weights_hidden_output[HIDDEN_SIZE][OUTPUT_SIZE], double bias_hidden[HIDDEN_SIZE], double bias_output[OUTPUT_SIZE], double hidden_layer[HIDDEN_SIZE], double output_layer[OUTPUT_SIZE]) {
    for (int i = 0; i < HIDDEN_SIZE; i++) {
        hidden_layer[i] = 0;
        for (int j = 0; j < INPUT_SIZE; j++) {
            hidden_layer[i] += input[j] * weights_input_hidden[j][i];
        }
        hidden_layer[i] += bias_hidden[i];
        hidden_layer[i] = sigmoid(hidden_layer[i]);
    }
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_layer[i] = 0;
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            output_layer[i] += hidden_layer[j] * weights_hidden_output[j][i];
        }
        output_layer[i] += bias_output[i];
        output_layer[i] = sigmoid(output_layer[i]);
    }
}

// Backpropagation
void backpropagation(double input[INPUT_SIZE], double weights_input_hidden[INPUT_SIZE][HIDDEN_SIZE], double weights_hidden_output[HIDDEN_SIZE][OUTPUT_SIZE], double bias_hidden[HIDDEN_SIZE], double bias_output[OUTPUT_SIZE], double hidden_layer[HIDDEN_SIZE], double output_layer[OUTPUT_SIZE], double target[OUTPUT_SIZE]) {
    double output_error[OUTPUT_SIZE];
    double hidden_error[HIDDEN_SIZE];

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output_error[i] = target[i] - output_layer[i];
    }

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        hidden_error[i] = 0;
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            hidden_error[i] += output_error[j] * weights_hidden_output[i][j];
        }
        hidden_error[i] *= sigmoid_derivative(hidden_layer[i]);
    }

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < OUTPUT_SIZE; j++) {
            weights_hidden_output[i][j] += LEARNING_RATE * output_error[j] * hidden_layer[i];
        }
    }

    for (int i = 0; i < OUTPUT_SIZE; i++) {
        bias_output[i] += LEARNING_RATE * output_error[i];
    }

    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            weights_input_hidden[i][j] += LEARNING_RATE * hidden_error[j] * input[i];
        }
    }

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        bias_hidden[i] += LEARNING_RATE * hidden_error[i];
    }
}

int main() {
    // Example input and output data for XOR problem
    double input[4][INPUT_SIZE] = { {0, 0, 1}, {1, 0, 1}, {0, 1, 1}, {1, 1, 1} };
    double target[4][OUTPUT_SIZE] = { {0}, {1}, {1}, {0} };

    // Initialize weights and biases
    double weights_input_hidden[INPUT_SIZE][HIDDEN_SIZE];
    double weights_hidden_output[HIDDEN_SIZE][OUTPUT_SIZE];
    double bias_hidden[HIDDEN_SIZE];
    double bias_output[OUTPUT_SIZE];

    initialize(weights_input_hidden, weights_hidden_output, bias_hidden, bias_output);

    double hidden_layer[HIDDEN_SIZE];
    double output_layer[OUTPUT_SIZE];

    // Training loop
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        for (int i = 0; i < 4; i++) {
            forward_propagation(input[i], weights_input_hidden, weights_hidden_output, bias_hidden, bias_output, hidden_layer, output_layer);
            backpropagation(input[i], weights_input_hidden, weights_hidden_output, bias_hidden, bias_output, hidden_layer, output_layer, target[i]);
        }
    }

    // Test the trained network
    for (int i = 0; i < 4; i++) {
        forward_propagation(input[i], weights_input_hidden, weights_hidden_output, bias_hidden, bias_output, hidden_layer, output_layer);
        printf("Input: [%f, %f, %f] Output: %f\\n", input[i][0], input[i][1], input[i][2], output_layer[0]);
    }

    return 0;
}