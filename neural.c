#include <stdio.h>

double activation_function(double sum) {
    return sum > 0 ? sum : 0;
}
double perceptron(double input1, double input2, double weight1, double weight2, double bias) {
    double sum = input1 * weight1 + input2 * weight2 + bias;

    return activation_function(sum);
}

int main() {
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

    for (int epoch = 0; epoch < 20000; epoch++) {
        double total_error = 0;
        for (int i = 0; i < 4; i++) {
            double output = perceptron(training_inputs[i][0], training_inputs[i][1], weight1, weight2, bias);
            double error = training_outputs[i] - output;
            weight1 += learning_rate * error * training_inputs[i][0];
            weight2 += learning_rate * error * training_inputs[i][1];
            bias += learning_rate * error;
            printf("predicted output:%lf\n",output);
        }
    }

    double input1, input2;
    printf("Enter first number: ");
    scanf("%lf", &input1); 
    printf("Enter second number: ");
    scanf("%lf", &input2); 

    double result = perceptron(input1, input2, weight1, weight2, bias);
    printf("Result of %f and %f = %f\n", input1, input2, result);

    return 0;
}
