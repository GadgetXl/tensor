#include <stdio.h>
#include "tensor.h"

int main() {
    float data[6] = {0.2f, 0.5f, -1.5f, 3.2f, 0.75f, -2.5f};

    printf("Orjinal degerler: ");
    for (int i = 0; i < 6; i++) {
        printf("%.2f ",data[i]);
    }

    Tensor t = createTensor(3,3,TYPE_INT8);
    t.scale = 0.1f;
    t.zero_point = 0;

    for (int i = 0; i < 6; i++) {
        t.data.i8[i] = quantize(data[i], t.scale, t.zero_point);
    }

    printf("\nQuantize edilmis degerler: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ",t.data.i8[i]);
    }

    freeTensor(&t);
}