#ifndef TENSOR_LIBRARY_H
#define TENSOR_LIBRARY_H

#include <stdint.h>

typedef enum {
    TYPE_FLOAT32,
    TYPE_FLOAT16,
    TYPE_INT8
} TensorType;

typedef union {
    float *f32;
    uint16_t *f16;
    int8_t *i8;
} TensorData;

typedef struct {
    int rows;
    int cols;
    float scale;
    int zero_point;
    TensorType type;
    TensorData data;
} Tensor;

Tensor createTensor(int rows, int cols, TensorType type);
void freeTensor(Tensor *t);

int8_t quantize(float value, float scale, int zero_point);
float dequantize(int8_t value, float scale, int zero_point);


#endif // TENSOR_LIBRARY_H