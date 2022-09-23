#include "include/numc.h"

#include <stdlib.h>


ND_Array(double) *
nd_array_double_new(
    uint32_t ndim
    , uint32_t shape[ndim])
{
    return nd_array_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(double)
            , ndim
            , shape);
}


ND_Array(float) *
nd_array_float_new(
    uint32_t ndim
    , uint32_t shape[ndim])
{
    return nd_array_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(float)
            , ndim
            , shape);
}


ND_Array(uint8_t) *
nd_array_uint8_new(
    uint32_t ndim
    , uint32_t shape[ndim])
{
    return nd_array_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint8_t)
            , ndim
            , shape);
}

ND_Array(uint16_t) *
nd_array_uint16_new(
    uint32_t ndim
    , uint32_t shape[ndim])
{
    return nd_array_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint16_t)
            , ndim
            , shape);
}


ND_Array(uint32_t) *
nd_array_uint32_new(
    uint32_t ndim
    , uint32_t shape[ndim])
{
    return nd_array_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint32_t)
            , ndim
            , shape);
}


ND_Array(uint64_t) *
nd_array_uint64_new(
    uint32_t ndim
    , uint32_t shape[ndim])
{
    return nd_array_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint64_t)
            , ndim
            , shape);
}


ND_Array(int8_t) *
nd_array_int8_new(
    uint32_t ndim
    , uint32_t shape[ndim])
{
    return nd_array_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int8_t)
            , ndim
            , shape);
}


ND_Array(int16_t) *
nd_array_int16_new(
    uint32_t ndim
    , uint32_t shape[ndim])
{
    return nd_array_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int16_t)
            , ndim
            , shape);
}


ND_Array(int32_t) *
nd_array_int32_new(
    uint32_t ndim
    , uint32_t shape[ndim])
{
    return nd_array_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int32_t)
            , ndim
            , shape);
}


ND_Array(int64_t) *
nd_array_int64_new(
    uint32_t ndim
    , uint32_t shape[ndim])
{
    return nd_array_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int64_t)
            , ndim
            , shape);
}


ND_Array(double) *
nd_array_double_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data)
{
    return nd_array_const_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(double)
            , ndim
            , shape
            , data);
}


ND_Array(float) *
nd_array_float_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data)
{
    return nd_array_const_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(float)
            , ndim
            , shape
            , data);
}


ND_Array(uint8_t) *
nd_array_uint8_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data)
{
    return nd_array_const_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint8_t)
            , ndim
            , shape
            , data);
}


ND_Array(uint16_t) *
nd_array_uint16_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data)
{
    return nd_array_const_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint16_t)
            , ndim
            , shape
            , data);
}


ND_Array(uint32_t) *
nd_array_uint32_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data)
{
    return nd_array_const_new(
            &(ND_Array_VTable) {malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint32_t)
            , ndim
            , shape
            , data);
}


ND_Array(uint64_t) *
nd_array_uint64_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data)
{
    return nd_array_const_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint64_t)
            , ndim
            , shape
            , data);
}


ND_Array(int8_t) *
nd_array_int8_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data)
{
    return nd_array_const_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int8_t)
            , ndim
            , shape
            , data);
}


ND_Array(int16_t) *
nd_array_int16_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data)
{
    return nd_array_const_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int16_t)
            , ndim
            , shape
            , data);
}


ND_Array(int32_t) *
nd_array_int32_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data)
{
    return nd_array_const_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int32_t)
            , ndim
            , shape
            , data);
}


ND_Array(int64_t) *
nd_array_int64_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data)
{
    return nd_array_const_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int64_t)
            , ndim
            , shape
            , data);
}



ND_Array(double) *
nd_array_double_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , double (*f)())
{
    ND_Array(double) * self =
        nd_array_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(double)
            , ndim
            , shape);

    double * vector = nd_array_data(self);
    size_t size = nd_array_size(self);

    for(size_t i = 0; i < size; i ++)
        vector[i] = f();

    return self;    
}


ND_Array(float) *
nd_array_float_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , float (*f)())
{
    ND_Array(float) * self =
        nd_array_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(float)
            , ndim
            , shape);

    float * vector = nd_array_data(self);
    size_t size = nd_array_size(self);

    for(size_t i = 0; i < size; i ++)
        vector[i] = f();

    return self;    
}


ND_Array(uint8_t) *
nd_array_uint8_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , uint8_t (*f)())
{
    ND_Array(uint8_t) * self =
        nd_array_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint8_t)
            , ndim
            , shape);

    uint8_t * vector = nd_array_data(self);
    size_t size = nd_array_size(self);

    for(size_t i = 0; i < size; i ++)
        vector[i] = f();

    return self;    
}


ND_Array(uint16_t) *
nd_array_uint16_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , uint16_t (*f)())
{
    ND_Array(uint16_t) * self =
        nd_array_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint16_t)
            , ndim
            , shape);

    uint16_t * vector = nd_array_data(self);
    size_t size = nd_array_size(self);

    for(size_t i = 0; i < size; i ++)
        vector[i] = f();

    return self;    
}


ND_Array(uint32_t) *
nd_array_uint32_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , uint32_t (*f)())
{
    ND_Array(uint32_t) * self =
        nd_array_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint32_t)
            , ndim
            , shape);

    uint32_t * vector = nd_array_data(self);
    size_t size = nd_array_size(self);

    for(size_t i = 0; i < size; i ++)
        vector[i] = f();

    return self;    
}


ND_Array(uint64_t) *
nd_array_uint64_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , uint64_t (*f)())
{
    ND_Array(uint64_t) * self =
        nd_array_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(uint64_t)
            , ndim
            , shape);

    uint64_t * vector = nd_array_data(self);
    size_t size = nd_array_size(self);

    for(size_t i = 0; i < size; i ++)
        vector[i] = f();

    return self;    
}


ND_Array(int8_t) *
nd_array_int8_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , int8_t (*f)())
{
    ND_Array(int8_t) * self =
        nd_array_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int8_t)
            , ndim
            , shape);

    int8_t * vector = nd_array_data(self);
    size_t size = nd_array_size(self);

    for(size_t i = 0; i < size; i ++)
        vector[i] = f();

    return self;    
}


ND_Array(int16_t) *
nd_array_int16_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , int16_t (*f)())
{
    ND_Array(int16_t) * self =
        nd_array_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int16_t)
            , ndim
            , shape);

    int16_t * vector = nd_array_data(self);
    size_t size = nd_array_size(self);

    for(size_t i = 0; i < size; i ++)
        vector[i] = f();

    return self;    
}


ND_Array(int32_t) *
nd_array_int32_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , int32_t (*f)())
{
    ND_Array(int32_t) * self =
        nd_array_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int32_t)
            , ndim
            , shape);

    int32_t * vector = nd_array_data(self);
    size_t size = nd_array_size(self);

    for(size_t i = 0; i < size; i ++)
        vector[i] = f();

    return self;    
}


ND_Array(int64_t) *
nd_array_int64_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , int64_t (*f)())
{
    ND_Array(int64_t) * self =
        nd_array_new(
            &(ND_Array_VTable){malloc, free, NULL, NULL, NULL, NULL}
            , sizeof(int64_t)
            , ndim
            , shape);

    uint64_t * vector = nd_array_data(self);
    size_t size = nd_array_size(self);

    for(size_t i = 0; i < size; i ++)
        vector[i] = f();

    return self;    
}



