/**
** @file numc.h
** @brief Numc ND_Array is data container which is used as hidden indexed area of memory 
** which is used as abstract data type for various purposes. Numc ND_Array works as black box,
** it means that every internal attributes are hidden by default and only way to access them is throw the
** public api.
** This data type represents only matrix/vector structure without concreete data type representation.
** Concrete data type is assigned inside specific functions which are using Numc ND_Array data structure.
** Numc ND_Array structure contains only abstract functions for matrix/vector transformation
** @author Petr Horáček
*/

#ifndef _NUMC_H_
#define _NUMC_H_

#include "nd_array.h"

#include <math.h>
#include <version.h>
#include <stdint.h>

/**
** @brief Current version of the Numc library
*/
#define __version_numc__ DEFINE_VERSION(0, 3, 0)


/**
**
*/
#define ND_Array(T) ND_Array_##T


/**
**
*/
#define DEFINE_ND_ARRAY(T) typedef ND_Array ND_Array(T)

typedef enum
{
    TensorDouble
    , TensorFloat
}TensorID;

typedef struct
{

}Tensor_VTable;


typedef struct
{
    ND_Array * array;
    TensorID id;
    Tensor_VTable v_tab;
}Tensor;



DEFINE_ND_ARRAY(double);
DEFINE_ND_ARRAY(float);
DEFINE_ND_ARRAY(uint8_t);
DEFINE_ND_ARRAY(uint16_t);
DEFINE_ND_ARRAY(uint32_t);
DEFINE_ND_ARRAY(uint64_t);
DEFINE_ND_ARRAY(int8_t);
DEFINE_ND_ARRAY(int16_t);
DEFINE_ND_ARRAY(int32_t);
DEFINE_ND_ARRAY(int64_t);


ND_Array(double) *
nd_array_double_new(
    uint32_t ndim
    , uint32_t shape[ndim]);


ND_Array(float) *
nd_array_float_new(
    uint32_t ndim
    , uint32_t shape[ndim]);


ND_Array(uint8_t) *
nd_array_uint8_new(
    uint32_t ndim
    , uint32_t shape[ndim]);

ND_Array(uint16_t) *
nd_array_uint16_new(
    uint32_t ndim
    , uint32_t shape[ndim]);


ND_Array(uint32_t) *
nd_array_uint32_new(
    uint32_t ndim
    , uint32_t shape[ndim]);


ND_Array(uint64_t) *
nd_array_uint64_new(
    uint32_t ndim
    , uint32_t shape[ndim]);


ND_Array(int8_t) *
nd_array_int8_new(
    uint32_t ndim
    , uint32_t shape[ndim]);


ND_Array(int16_t) *
nd_array_int16_new(
    uint32_t ndim
    , uint32_t shape[ndim]);


ND_Array(int32_t) *
nd_array_int32_new(
    uint32_t ndim
    , uint32_t shape[ndim]);


ND_Array(int64_t) *
nd_array_int64_new(
    uint32_t ndim
    , uint32_t shape[ndim]);


ND_Array(double) *
nd_array_double_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data);


ND_Array(float) *
nd_array_float_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data);


ND_Array(uint8_t) *
nd_array_uint8_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data);


ND_Array(uint16_t) *
nd_array_uint16_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data);


ND_Array(uint32_t) *
nd_array_uint32_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data);


ND_Array(uint64_t) *
nd_array_uint64_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data);


ND_Array(int8_t) *
nd_array_int8_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data);


ND_Array(int16_t) *
nd_array_int16_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data);


ND_Array(int32_t) *
nd_array_uint32_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data);


ND_Array(int64_t) *
nd_array_uint64_const_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , void * data);



ND_Array(double) *
nd_array_double_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , double (*f)());


ND_Array(float) *
nd_array_float_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , float (*f)());


ND_Array(uint8_t) *
nd_array_uint8_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , uint8_t (*f)());


ND_Array(uint16_t) *
nd_array_uint16_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , uint16_t (*f)());


ND_Array(uint32_t) *
nd_array_uint32_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , uint32_t (*f)());


ND_Array(uint64_t) *
nd_array_uint64_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , uint64_t (*f)());


ND_Array(int8_t) *
nd_array_int8_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , int8_t (*f)());


ND_Array(int16_t) *
nd_array_int16_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , int16_t (*f)());


ND_Array(int32_t) *
nd_array_int32_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , int32_t (*f)());


ND_Array(int64_t) *
nd_array_int64_init_new(
    uint32_t ndim
    , uint32_t shape[ndim]
    , int64_t (*f)());


#endif


