#include "include/tensor.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
** vždycky je třeba vytvořit obecnou strukturu, která obsahuje void* ukazatel,
** nebo jen základní parametry a poté je třeba na místě vytvořit konkrétní implementaci
*/


size_t
tensor_compute_size(
    uint32_t ndim
    , uint32_t * shape)
{
    size_t size = shape[0];

    for(uint32_t i = 1; i < ndim; i++)
        size *= shape[i];

    return size;
}


size_t
tensor_size(Tensor * self)
{
    return tensor_compute_size(
                self->shape_struct.ndim
                , self->shape_struct.shape);
}


Tensor *
tensor_new(
    uint32_t ndim
    , uint32_t * shape
    , size_t byte_size)
{
    size_t vector_size  = tensor_compute_size(ndim, shape) * byte_size;
    size_t shape_length = sizeof(uint32_t) * ndim;

    Tensor * self = malloc(sizeof(Tensor) + vector_size + shape_length);

    if(self != NULL)
    {
        self->shape_struct.byte_size = byte_size;
        self->shape_struct.ndim      = ndim;
        self->shape_struct.shape     = (uint32_t *) (self + sizeof(uint32_t));
        self->vector                 = self + sizeof(uint32_t) * (ndim + 1);
 
        memcpy(self->shape_struct.shape, shape, shape_length);
    }

    return self;
}


Tensor *
tensor_new_copy(Tensor * self)
{
    Tensor * copy = 
        tensor_new(
            self->shape_struct.ndim
            , self->shape_struct.shape
            , self->shape_struct.byte_size);

    memcpy(
        copy->vector
        , self->vector
        , tensor_size(self) * self->shape_struct.byte_size);

    return copy;
}


T_Shape
tensor_shape_struct(Tensor * self)
{
    return self->shape_struct;
}


uint32_t 
tensor_ndim(Tensor * self)
{
    return self->shape_struct.ndim;
}


uint32_t *
tensor_shape(Tensor * self)
{
    return self->shape_struct.shape;
}


void *
tensor_data(Tensor * self)
{
    return self->vector;
}


Tensor *
tensor_reshape(
    Tensor * self
    , uint32_t ndim
    , uint32_t * shape)
{
    size_t vector_size     = tensor_size(self);
    size_t new_vector_size = tensor_compute_size(ndim, shape);

    if(vector_size == new_vector_size)
    {
        Tensor * reshaped_tensor = 
            tensor_new(
                ndim
                , shape
                , self->shape_struct.byte_size);

        memcpy(
            reshaped_tensor->vector
            , self->vector
            , tensor_size(self) * self->shape_struct.byte_size);

        return reshaped_tensor;
    }

    return NULL;
}


Tensor *
tensor_squeeze(Tensor * self)
{
    (void) self;
    return NULL;    
}


Tensor * 
tensor_peek(
    Tensor * self
    , Tensor * f(Tensor*))
{
    Tensor * t = f(self);
    tensor_delete(self);

    return t;
}


void
tensor_delete(Tensor * self)
{
    if(self != NULL)
        free(self);
}



