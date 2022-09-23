#include <stdio.h>
#include <stdlib.h>

#include "../src/include/numc.h"


int
main(void)
{
    ND_Array(uint8_t)* tensor = 
        nd_array_uint8_const_new(
            2
            , (uint32_t[]){2,2}
            , (uint8_t[2][2]) {{1, 3}, {2, 2}});


    if(tensor == NULL)
    {
        printf("Allocation error\n");
        return EXIT_FAILURE;
    }

    uint8_t * array = (uint8_t*) nd_array_data(tensor);

    for(size_t i = 0; i < nd_array_size(tensor); i++)
        printf("%d\n", array[i]);



    nd_array_delete(tensor);

    return EXIT_SUCCESS;
}
