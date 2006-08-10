/**
 * Copyright 2006, All Rights Reserved, Micah Villmow
 * @file heap.h
 * @brief Generic heap implementation
 *
 * The generic heap implementation, when completed will
 * consist of the following heap types:
 * Binary Heap
 * Skew Heap
 * Trinary Heap
 * Leftist Heap
 */
#ifndef HEAP_H_
#define HEAP_H_
#include "gen/control_macros.h"
#include "gen/function_signatures.h"
COMMON_FUNCTION_PROTOTYPES

/**
 * @fn int8_t insert_Heap(Heap *obj,void *data, size_t datasize, int flag)
 * @param obj the heap object to insert data into
 * @param data the data to insert into the heap object
 * @param datasize the size of data to insert
 * @param flag flag whether data is dynamic or static
 * @return 0 on success, non-zero on error
 * @brief insert data into the heap in sorted order
 */
insert_Heap(Heap *obj, void *data, size_t datasize, int flag);

/**
 * @fn void* front_Heap(Heap *obj)
 * @param obj the heap object to get the max/min value from
 * @return Pointer to first value or NULL on error/empty
 * @brief returns the first value to be removed from the delete function
 * 
 * Front is used to get either the max or the min value based on the
 * comparision function. It returns the value stored at the first node
 * and is also the value to be removed from the heap on the proceeding
 * delete call
 */
void *front_Heap(Heap *obj);

/**
 * @fn int8_t pop_Heap(Heap *obj)
 * @param obj the heap object to remove the max/min value from
 * @return0 on success, non-zero on error
 * @brief Removes the top value of the heap
 *
 * Based on the comparison function, pop_Heap removes either the
 * max or the min value from the tree.
 */
int8_t pop_Heap(Heap* obj);

/**
 * @fn int8_t merge_Heap(Heap* obj, Heap* src)
 * @param obj the destination heap
 * @param src the source heap
 * @return 0 on success, non-zero on error
 */
int8_t merge_Heap(Heap* obj, Heap* src);

#endif
