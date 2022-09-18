#include <stdio.h>
#include <stdlib.h>

#include "../src/include/numc.h"


int
main(void)
{
    Tensor * tensor = 
        tensor_new(
            2
            , (uint32_t[]){2,2}
            , sizeof(char *));

    char ** array = tensor->vector;

    for(size_t i = 0; i < tensor_size(tensor); i++)
        printf("%s\n", array[i] == NULL ? "NULL" : array[i]);

    //Tensor * t = tensor_peek(tensor_peek(tensor, tensor_new_copy), tensor_squeeze);


    tensor_delete(tensor);

    return EXIT_SUCCESS;
}
