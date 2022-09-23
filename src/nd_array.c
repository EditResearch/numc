/**
** @file nd_array.c
** @brief Source code for Numc ND_Array data structure 
** @author Petr Horáček
*/

#include "include/nd_array.h"

#include <string.h>


struct ND_Array
{
    ND_Array_VTable v_tab;

    size_t itemsize;
    uint32_t ndim;
    uint32_t * shape;

    void * data;
};


static size_t
nd_array_count_size(
    uint32_t ndim
    , uint32_t * shape)
{
    size_t size = shape[0];

    for(size_t i = 1; i < ndim; i++)
        size *= shape[i];

    return size;
}


ND_Array *
nd_array_new(
    ND_Array_VTable * v_tab
    , size_t itemsize
    , uint32_t ndim
    , uint32_t shape[ndim])
{
    if(v_tab == NULL)
        return NULL;

    size_t data_size  = nd_array_count_size(ndim, shape) * itemsize;
    size_t shape_size = sizeof(uint32_t) * ndim; 

    ND_Array * self = v_tab->allocator(sizeof(ND_Array) + shape_size + data_size);

    if(self == NULL)
        return NULL;

    memcpy(&self->v_tab, v_tab, sizeof(ND_Array_VTable));
    self->itemsize = itemsize;
    self->ndim = ndim;
    
    self->shape = (uint32_t*) ((uint8_t*) self) + sizeof(ND_Array);
    memcpy(self->shape, shape, shape_size);

    self->data = ((uint8_t*) self) + sizeof(ND_Array) + shape_size;
    
    return self;
}


ND_Array *
nd_array_const_new(
    ND_Array_VTable * v_tab
    , size_t itemsize
    , uint32_t ndim
    , uint32_t shape[ndim]
    , void * data)
{
    
    if(v_tab == NULL)
        return NULL;

    size_t data_size  = nd_array_count_size(ndim, shape) * itemsize;
    size_t shape_size = sizeof(uint32_t) * ndim; 

    ND_Array * self = v_tab->allocator(sizeof(ND_Array) + shape_size + data_size);

    if(self == NULL)
        return NULL;

    memcpy(&self->v_tab, v_tab, sizeof(ND_Array_VTable));
    self->itemsize = itemsize;
    self->ndim = ndim;

    self->shape = (uint32_t*) ((uint8_t*) self) + sizeof(ND_Array);
    memcpy(self->shape, shape, shape_size);

    self->data = ((uint8_t*) self) + sizeof(ND_Array) + shape_size;
    memcpy(self->data, data, data_size);

    return self;
}


ND_Array *
nd_array_vector_new(
    ND_Array_VTable * v_tab
    , size_t itemsize
    , size_t length)
{
    return nd_array_new(
                v_tab
                , itemsize
                , 1
                , (uint32_t[]){length});
}


ND_Array *
nd_array_vector_const_new(
    ND_Array_VTable * v_tab
    , size_t itemsize
    , size_t length
    , void * data)
{
    return nd_array_const_new(
                v_tab
                , itemsize
                , 1
                , (uint32_t[]){length}
                , data);
}


ND_Array *
nd_array_copy_new(ND_Array * self)
{
    return self->v_tab.copy(self);
}


ND_Array *
nd_array_reshape_new(
    ND_Array * self
    , uint32_t ndim
    , uint32_t shape[ndim])
{
    return self->v_tab.reshape(self, ndim, shape);
}


ND_Array *
nd_array_concatenate(ND_Array * a, ND_Array * b)
{
    /*
    if(a->itemsize != b->itemsize)
        return NULL;

    uint32_t ndim = a->ndim + b->ndim;
    size_t size_a = nd_array_size(a);
    size_t size_b = nd_array_size(b); 
    size_t size = size_a + size_b;
    
    ND_Array * self = a.allocator(sizeof(ND_Array));

    self->ndim = ndim;
    self->itemsize = a->itemsize;

    memcpy(self->v_tab, a->v_tabe, sizeof(ND_Array_VTable));
    memcpy(self->shape, a->shape, size_a);
    memcpy(self->shape+size_a, b->shape, size_b);


    //TODO:concat data
    */

    return a->v_tab.concatenate(a, b);
}


ND_Array *
nd_array_slice(
    ND_Array * self
    , uint32_t ndim
    , uint32_t shape[ndim])
{
    //TODO: validate shape and dimension
    
    //ND_Array * slice = nd_array_new(self->v_tab, ndim, shape, self->itemsize);
    return self->v_tab.slice(self, ndim, shape);
}


size_t
nd_array_size(ND_Array * self)
{
    return nd_array_count_size(self->ndim, self->shape);
}


size_t 
nd_array_itemsize(ND_Array * self)
{
    return self->itemsize;
}


uint32_t 
nd_array_ndim(ND_Array * self)
{
    return self->ndim;
}


uint32_t *
nd_array_shape(ND_Array * self)
{
    return self->shape;
}


void *
nd_array_data(ND_Array * self)
{
    return self->data;
}


void
nd_array_delete(ND_Array * self)
{
    if(self != NULL)
        self->v_tab.dealocator(self);
}



