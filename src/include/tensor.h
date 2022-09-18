/**
** @file tensor.h
** @brief Header file for tensor library
** @author Petr Horáček
*/

#ifndef _TENSOR_H_
#define _TENSOR_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>


/**
** @brief
*/
typedef struct
{
    size_t byte_size;

    uint32_t ndim;
    uint32_t * shape;
}T_Shape;


/**
** @brief
*/
typedef struct 
{
    T_Shape shape_struct;
    void * vector;
}Tensor;


/**
** @brief
*/
Tensor *
tensor_new(
    uint32_t ndim
    , uint32_t * shape
    , size_t byte_size);


/**
** @brief
*/
size_t
tensor_size(Tensor * self);


/**
** @brief
*/
size_t
tensor_compute_size(
    uint32_t ndim
    , uint32_t * shape);


/**
** @brief
*/
uint32_t 
tensor_ndim(Tensor * self);


/**
** @brief
*/
uint32_t *
tensor_shape(Tensor * self);


/**
** @brief
*/
void *
tensor_data(Tensor * self);


/**
** @brief
*/
T_Shape
tensor_shape_struct(Tensor * self);


/**
** @brief
*/
Tensor *
tensor_squeeze(Tensor * self);


/**
** @brief
*/
Tensor *
tensor_reshape(
    Tensor * self
    , uint32_t ndim
    , uint32_t * shape);


/**
** @brief
*/
Tensor *
tensor_transpose(Tensor * self);


/**
** @brief
*/
Tensor *
tensor_new_copy(Tensor * self);


/**
** @brief
*/
Tensor *
tensor_filter(
    Tensor * self
    , bool f(void *));



/**
** @brief
*/
Tensor * 
tensor_peek(
    Tensor * self
    , Tensor * f(Tensor*));


/**
** @brief
*/
void
tensor_delete(Tensor * self);


#endif
