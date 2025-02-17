import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())

hidden_layer_perceptron = [list(map(int, input().split())) for _ in range(m)]
output_layer_perceptron = list(map(int, input().split()))

weight = [0] * n
bias = output_layer_perceptron[-1]

for i in range(m):
    data_size = hidden_layer_perceptron[i][0]
    hidden_layer_data = hidden_layer_perceptron[i][1:1 + data_size]
    hidden_layer_weight = hidden_layer_perceptron[i][1 + data_size:-1]
    hidden_layer_bias = hidden_layer_perceptron[i][-1]
    output_layer_weight = output_layer_perceptron[i]

    for j in range(data_size):
        weight[hidden_layer_data[j] - 1] += hidden_layer_weight[j] * output_layer_weight

    bias += hidden_layer_bias * output_layer_weight

for _ in range(k):
    input_layer = list(map(int, input().split()))
    output = sum(input_layer[i] * weight[i] for i in range(n)) + bias
    print(output)