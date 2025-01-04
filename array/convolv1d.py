import numpy as np


def conv1d(signal, kernel, mode="full"):
    rst = []
    kernel.reverse()

    if mode == "full":
        zero_pad = [0] * (len(kernel) - 1)
        signal = zero_pad + signal + zero_pad

    for i in range(len(signal) - len(kernel) + 1):
        cur_val = 0
        for j in range(len(kernel)):
            cur_val += kernel[j] * signal[i + j]
        rst.append(cur_val)
    
    return rst


# Example usage:
signal1 = [1, 2, 3, 4, 5, 10, 15]
kernel1 = [0.5, 0.5]  # Example kernel
# result = conv1d(signal1, kernel1, mode="full")
# print("Result of 1D convolution:\n", result)
# print(np.convolve(signal1, kernel1, mode="full"))

result = conv1d(signal1, kernel1, mode="valid")
print("Result of 1D convolution:\n", result)
print(np.convolve(signal1, kernel1, mode="valid"))


