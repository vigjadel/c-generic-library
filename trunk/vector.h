
/**
 * Copyright 2006, Micah Villmow, All Rights Reserved
 * @file base_vector.h
 * @author Micah Villmow
 * @brief a reusable vector class that takes any object
 * The base class that other data structures are
 * created from
 */
#ifndef BASE_VECTOR_H_
#    define BASE_VECTOR_H_
#include "gen/gen_macros.h"
#include "gen/data_types.h"
#include "gen/function_macros.h"

#ifndef VECTOR_ITER_DEFINED
#define VECTOR_ITER_DEFINED
typedef struct _array_iter ITER(Vector);
#endif


#ifndef VECTOR_DEFINED
#define VECTOR_DEFINED
typedef struct _array_struct Vector;
#endif

#    define FUNC(X,Y)	((X)->API.Y(X));


/**
 * @fn int8_t construct_Vector(Vector *vec)
 * @param vec the vector to initialize
 * @return 0 on success, non-zero on failure
 *
 * @warning if you are using a local variable
 * clear out the memory before calling this function
 * using memset or bzero
 */
int8_t construct_Vector(Vector * vec,size_t objsize, int flag);

/**
 * @fn int8_t construct_func()
 * @param vec the vector to initialize
 * @param alloc the allocation functor
 * @param dealloc the deallocation functor
 * @param cmp the comparison functor
 * @param rcmp the reverse comparison functor
 * @param print the print functor
 * @param copy the copy functor
 * @return 0 on success, non-zero on failure
 *
 * @brief assigns all the
 * function pointers in one function call
 */
int8_t construct_func_Vector(Vector * vec,size_t objsize, int flag,
                             void *(*alloc) (size_t),
                             void (*dealloc) (void *),
                             int (*cmp) (const void *, const void *),
                             int (*rcmp) (const void *, const void *),
                             void (*print) (const void *),
                             void *(*copy) (void *, const void *, size_t));

/**
 * @fn int8_t destruct_Vector(Vector *vec)
 * @param vec the vector to destroy
 * @return 0 on succes, non-zero on failure
 */
int8_t destruct_Vector(Vector * vec);
/**
 * @fn int8_t clear_Vector(Vector* vec)
 * @param vec the vector to clear 
 * @return 0 on success, non-zero on failure
 */
int8_t clear_Vector(Vector* vec);

#define convert_Vector(A,B,C,D) push_back_Vector((A),(B),(C),(D))

/**
 * @fn int8_t insert_at_Vector(Vector *, void *,uint32_t)
 * @param vec the vector to insert the object into
 * @param obj the object to insert into the array
 * @param loc the location in the array to put the item
 * @return 0 on success, non-zero on error
 * @brief inserts into the array at a specific index the
 * object
 * This is the equivalent of the vec[index] = obj operation
 */
int8_t insert_at_Vector(Vector * vec, void *obj, uint32_t loc);

/**
 * @fn int8_t insert_Vector(Vector *, void *,size_t,int)
 * @param vec the vector to insert the object into
 * @param obj the object to insert into the array
 * @param objsize the size of the object being inserted into the vector
 * @param flag the flag specifying whether it is static or dynamic data
 * @return 0 on success, non-zero on error
 * @brief inserts the object into the array in sorted order
 */
int8_t insert_Vector(Vector * vec, void *obj,size_t objsize, int flag);
int8_t push_back_Vector(Vector *vec, void *obj, size_t objsize, int flag);
int8_t push_front_Vector(Vector *vec, void *obj, size_t objsize, int flag);
int8_t pop_back_Vector(Vector *vec);
int8_t pop_front_Vector(Vector *vec);
void *front_Vector(Vector *vec);
void *back_Vector(Vector *vec);

/**
 * @fn void *return_at_Vector(Vector *vec, uint32_t loc)
 * @param vec the vector to return the object into
 * @param loc the loc in the array to return the object from
 * @return pointer to the object on success, NULL on error
 * @brief returns the object from the vector at the given
 * point
 */
void *return_at_Vector(Vector * vec, uint32_t loc);

/**
 * @fn int8_t resize_Vector(Vector *vec, size_t size) {
 * @param vec the vector to resize
 * @param size the size to resize the vector to
 * @return 0 on success, non-zero otherwise
 * @brief resizes the array that is inside of the vector
 * and copies the first n objects over to the new array
 */
int8_t resize_Vector(Vector * vec, size_t size);

prototype(size_of, Vector);
prototype(set_compare, Vector);
prototype(set_rcompare, Vector);
prototype(set_print, Vector);
prototype(set_alloc, Vector);
prototype(set_dealloc, Vector);
prototype(set_copy, Vector);

create_iter_prototypes(Vector)
#endif
