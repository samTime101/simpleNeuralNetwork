# simpleNeuralNetwork
<img src="https://machinelearningmastery.com/wp-content/uploads/2021/08/neural_networks_5.png" alt="Neural Networks" width="400">

```C
double perceptron(double input1, double input2, double weight1, double weight2, double bias) {
    double sum = input1 * weight1 + input2 * weight2 + bias;

    return activation_function(sum);
}
```
<img src="https://victorzhou.com/27cf280166d7159c0465a58c68f99b39/network3.svg" alt="Neural Networks" width="400">

```C
    double weight1 = 0.0;
    double weight2 = 0.0;
    double bias = 0.0;
    double training_inputs[4][2] = {
        {6.0, 3.0}, 
        {9.0, 3.0}, 
        {8.0, 2.0},
        {16.0, 4.0}  

    };
    double training_outputs[4] = {2.0, 3.0, 4.0,4.0}; 
    double learning_rate = 0.01;
```
<img src="https://miro.medium.com/v2/resize:fit:870/1*_JmCClCwvxJ-A0NX0tO4Mw.png" alt="Neural Networks" width="400">

# Single Layer Perceptrion

```C
for (int epoch = 0; epoch < 20000; epoch++) {
    double total_error = 0;
    for (int i = 0; i < 4; i++) {
        double output = perceptron(training_inputs[i][0], training_inputs[i][1], weight1, weight2, bias);
        double error = training_outputs[i] - output;
        weight1 += learning_rate * error * training_inputs[i][0];
        weight2 += learning_rate * error * training_inputs[i][1];
        bias += learning_rate * error;
        printf("predicted output:%lf\n", output);
    }
}
```
# ReLU (Rectified Linear Unit) function

<p>If the sum is > 0 return sum else return 0</p>

<img src="https://qph.cf2.quoracdn.net/main-qimg-c8de28ad84eb26a35addf678e8197c28" >

```C
double activation_function(double sum) {
    return sum > 0 ? sum : 0;
```

