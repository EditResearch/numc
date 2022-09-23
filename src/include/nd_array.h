#ifndef _ND_ARRAY_H_
#define _ND_ARRAY_H_

#include <stdint.h>

/**
** @brief
*/
struct ND_Array;
typedef struct ND_Array ND_Array;


/**
** @brief
*/ 
#define ND_Array(T) ND_Array_##T


/**
** @brief
*/ 
#define DEFINE_ND_ARRAY(T) typedef ND_Array ND_Array(T)



/**
**
*/
typedef void* (*ND_ArrayAllocator)(size_t);


/**
**
*/
typedef void (*ND_ArrayDealocator)(void *);


/**
**
*/
typedef ND_Array *(*ND_ArrayCopy)(ND_Array*);


/**
**
*/
typedef ND_Array *(*ND_ArrayReshape)(ND_Array*, uint32_t, uint32_t *);


/**
**
*/
typedef ND_Array *(*ND_ArrayConcatenate)(ND_Array *, ND_Array *);


/**
**
*/
typedef ND_Array *(*ND_ArraySlice)(ND_Array * self, uint32_t, uint32_t *);


/**
** @brief
*/
typedef struct
{
    ND_ArrayAllocator allocator;
    ND_ArrayDealocator dealocator;
    ND_ArrayCopy copy;
    ND_ArrayReshape reshape;
    ND_ArrayConcatenate concatenate;
    ND_ArraySlice slice;
}ND_Array_VTable;



/**
** @brief
*/
ND_Array *
nd_array_new(
    ND_Array_VTable * v_tab
    , size_t itemsize
    , uint32_t ndim
    , uint32_t shape[ndim]);


/**
** @brief
*/
ND_Array *
nd_array_const_new(
    ND_Array_VTable * v_tab
    , size_t itemsize
    , uint32_t ndim
    , uint32_t shape[ndim]
    , void * data);


/**
** @brief
*/
ND_Array *
nd_array_vector_new(
    ND_Array_VTable * v_tab
    , size_t itemsize
    , size_t length);


/**
** @brief
*/
ND_Array *
nd_array_vector_const_new(
    ND_Array_VTable * v_tab
    , size_t itemsize
    , size_t length
    , void * data);


/**
** @brief
*/
ND_Array *
nd_array_copy_new(ND_Array * self);


/**
** @brief
*/
ND_Array *
nd_array_reshape_new(
    ND_Array * self
    , uint32_t ndim
    , uint32_t shape[ndim]);


/**
** @brief
*/
ND_Array *
nd_array_transpose(ND_Array * self);


/**
** @breif 
*/
ND_Array *
nd_array_concatenate(ND_Array * a, ND_Array * b);


/**
** @brief 
*/
ND_Array *
nd_array_slice(
    ND_Array * self
    , uint32_t ndim
    , uint32_t shape[ndim]);


/**
** @brief
*/
size_t
nd_array_size(ND_Array * self);


/**
** @brief
*/
size_t 
nd_array_itemsize(ND_Array * self);


/**
** @brief 
*/
uint32_t 
nd_array_ndim(ND_Array * self);


/**
** @breif
*/
uint32_t *
nd_array_shape(ND_Array * self);


/**
** @brief
*/
void *
nd_array_data(ND_Array * self);


/**
** @brief
*/ 
void
nd_array_delete(ND_Array * self);


#endif
