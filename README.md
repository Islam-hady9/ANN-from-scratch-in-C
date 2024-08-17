# ANN From Scratch in C

## Overview

This repository contains a simple implementation of an Artificial Neural Network (ANN) from scratch in the C programming language. The code demonstrates the fundamental concepts of feedforward neural networks and backpropagation, using the XOR problem as an example.

## Features

- **Sigmoid Activation Function**: The network uses the sigmoid function for neuron activation.
- **Backpropagation Algorithm**: Implements the backpropagation algorithm to adjust the network's weights and biases during training.
- **Training on XOR Problem**: The example provided trains the network to solve the XOR problem, a classic problem in neural network research.
- **Customizable Parameters**: The network's size, learning rate, and number of epochs can be adjusted to experiment with different configurations.

## Getting Started

### Prerequisites

- A C compiler such as GCC is required to compile and run the code.

### Compilation

To compile the code, use the following command:

```bash
gcc -o ann ANN_model_from_scratch.c -lm
```

### Running the Program

After compiling, you can run the program with:

```bash
./ann
```

The program will train the neural network on the XOR problem and then test the network, printing the outputs for the given inputs.

## How It Works

### 1. Sigmoid Activation Function
   - The function `sigmoid` is used to compute the activation of each neuron in the hidden and output layers.
   - The function `sigmoid_derivative` computes the derivative of the sigmoid function, which is used in the backpropagation process.

### 2. Initialization
   - The `initialize` function initializes the weights and biases of the network with random values.
   - **Parameters**:
     - `weights_input_hidden`: Weights between the input layer and the hidden layer.
     - `weights_hidden_output`: Weights between the hidden layer and the output layer.
     - `bias_hidden`: Biases for the hidden layer.
     - `bias_output`: Biases for the output layer.

### 3. Forward Propagation
   - The `forward_propagation` function calculates the output of the network for a given input by passing the input through the network layers.
   - **Parameters**:
     - `input`: The input data for the network.
     - `weights_input_hidden`, `weights_hidden_output`, `bias_hidden`, `bias_output`: Weights and biases of the network.
     - `hidden_layer`: Stores the output of the hidden layer neurons.
     - `output_layer`: Stores the output of the output layer neurons.

### 4. Backpropagation
   - The `backpropagation` function adjusts the weights and biases based on the error between the predicted output and the target output.
   - **Parameters**:
     - `input`: The input data for the network.
     - `weights_input_hidden`, `weights_hidden_output`, `bias_hidden`, `bias_output`: Weights and biases of the network.
     - `hidden_layer`, `output_layer`: Outputs of the hidden and output layers.
     - `target`: The expected output for the given input.

### 5. Training Loop
   - The training loop iterates through the input data, performing forward propagation and backpropagation for each input to train the network.
   - The network is trained for a specified number of epochs (`EPOCHS`), which can be adjusted.

### 6. Testing the Network
   - After training, the network is tested on the same XOR inputs to verify its learning. The outputs are printed to the console.

## Example Output

After running the program, the output might look like this:

```
Input: [0.000000, 0.000000, 1.000000] Output: 0.000122
Input: [1.000000, 0.000000, 1.000000] Output: 0.999384
Input: [0.000000, 1.000000, 1.000000] Output: 0.999597
Input: [1.000000, 1.000000, 1.000000] Output: 0.000698
```

The network successfully learns to approximate the XOR function.

## Customization

- **INPUT_SIZE, HIDDEN_SIZE, OUTPUT_SIZE**: These constants define the architecture of the network. You can modify these to experiment with different network sizes.
- **LEARNING_RATE**: Controls how much the weights are adjusted during backpropagation. You can tweak this value to see how it affects training.
- **EPOCHS**: The number of training iterations. Increasing this may improve accuracy but also increases the time required to train.

## Contributing

Contributions are welcome! Feel free to fork the repository and submit pull requests.

## License

This project is licensed under the MIT License.
