#include "tensor.h"
#include <stdlib.h>

Tensor createTensor(int rows, int cols, TensorType type)
{
    Tensor t;
    t.rows = rows;
    t.cols = cols;
    t.type = type;
    t.scale = 1.0f;
    t.zero_point = 0;

    int size = rows * cols;

    if(type == TYPE_FLOAT32)
    {
        t.data.f32 = (float*)malloc(size * sizeof(float));
    }
    else if(type == TYPE_FLOAT16)
    {
        t.data.f16 = (uint16_t*)malloc(size * sizeof(uint16_t));
    }
    else if(type == TYPE_INT8)
    {
        t.data.i8 = (int8_t*)malloc(size * sizeof(int8_t));
    }

    return t;
}

void freeTensor(Tensor *t)
{
    if(t->type == TYPE_FLOAT32)
    {
        free(t->data.f32);
    }
    else if(t->type == TYPE_FLOAT16)
    {
        free(t->data.f16);
    }
    else if(t->type == TYPE_INT8)
    {
        free(t->data.i8);
    }
}

int8_t quantize(float value, float scale, int zero_point)
{
    int q = (int)(value / scale + zero_point);

    if(q > 127) q = 127;
    if(q < -128) q = -128;

    return (int8_t)q;
}

float dequantize(int8_t value, float scale, int zero_point)
{
    return (value - zero_point) * scale;
}
