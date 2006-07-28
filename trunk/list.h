
/**
 * Copyright 2006, Micah Villmow, All Rights Reserved
 * @file base_list.h
 * @author Micah Villmow(villmow at cs dot fsu dot edu)
 * @brief a reuseable list class that takes any object
 */
#ifndef BASE_LIST_H_
#    define BASE_LIST_H_
#    include "gen/data_types.h"
#    include "gen/gen_macros.h"
#    include "gen/function_macros.h"



/**
 * @struct List
 * @brief The list object that handles the list structure
 */
#ifndef LIST_DEFINED
#define LIST_DEFINED
typedef struct _ptr_struct List;
#endif

/**
 * @struct ListIter
 * @brief the iterator for the List object
 */
#ifndef LIST_ITER_DEFINED
#define LIST_ITER_DEFINED
typedef struct _ptr_iter ITER(List);
#endif
/**
 * @fn int8_t construct_List(List*list)
 * @param list the list to initialize
 * @return 0 on success, non-zero on failure
 *
 * @warning if you are using a local variable
 * clear out the memory before calling this 
 * function using memset or bzero
 */
int8_t construct_List(List * list,size_t objsize, int flag);

/**
 * @fn int8_t construct_func_List()
 * @param list the list to initialize
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
int8_t construct_func_List(List * list,size_t objsize, int flag,
                           void *(*alloc) (size_t),
                           void (*dealloc) (void *),
                           int (*cmp) (const void *, const void *),
                           int (*rcmp) (const void *, const void *),
                           void (*print) (const void *),
                           void *(*copy) (void *, const void *, size_t));

/**
 * @fn int8_t destruct_List(List*list)
 * @param list the list to destroy
 * @return 0 on success, non-zero on failure
 */
int8_t destruct_List(List * list);

/**
 * @fn int8_t clear_List(List*list)
 * @param list the list to clear nodes from
 * @return 0 on success, non-zero on failure
 *
 * @brief move all nodes to the free lis
 */
int8_t clear_List(List * list);

/**
 * @fn int8_t push_front_List(List*,void*,size_t,int);
 * @param list the list to push the object onto
 * @param obj the object to push to the front of the list
 * @param objsize the size of the object
 * @param flag dynamic or static flag
 * @return 0 on success, non-zero on failure
 */
int8_t push_front_List(List * list, void *obj, size_t objsize, int flag);

/**
 * @fn int8_t push_back_List(List*,void*,size_t,int)
 * @param list the list to push the object onto
 * @param obj the object to push to the back of the list
 * @param objsize the size of the object
 * @param flag dynamic or static flag
 * @return 0 on success, non-zero on failure
 */
int8_t push_back_List(List * list, void *obj, size_t objsize, int flag);
#define convert_List(A,B,C,D)	push_back_List((A),(B),(C),(D))

/**
 * @fn int8_t pop_front_List(List*)
 * @param list the list to pop the front object off of
 * @return 0 on success, non-zero on failure
 */
int8_t pop_front_List(List * list);

/**
 * @fn int32_t pop_back_List(List*)
 * @param list the list to pop the back object off of
 * @return 0 on success, non-zero on failure
 */
int8_t pop_back_List(List * list);

/**
 * @fn void *front_List(List*)
 * @param list the list to get the front object from
 * @return pointer to obj on success, NULL otherwise
 */
void *front_List(List * list);



/**
 * @fn void *back_List(List*)
 * @param list the list to get the back object from
 * @return pointer to obj on success, NULL otherwise
 */
void *back_List(List * list);


/**
 * @fn void insert_List(List*,void*,size_t,int)
 * @param list the list to insert the object into
 * @param obj a pointer to the object to insert
 * @param objsize the size of the object being inserted
 * @param flag dynamic or static flag
 * @return ptr to object, NULL on error
 */
void *insert_List(List * list, void *obj, size_t objsize, int flag);

/**
 * @fn int8_t delete_List(List*,void*,size_t)
 * @param list the list to delete the object from
 * @param obj a pointer to the object to be deleted
 * @param objsize the size of the object being deleted
 * @return 0 on sucess, non-zero on error
 */
int8_t delete_List(List * list, void *obj, size_t objsize);

/**
 * @fn int8_t sort_List(List*,size_t)
 * @param list the list to sort the objects in
 * @param objsize the size of the objects being sorted
 * @return 0 on success, non-zero on error
 */
int8_t sort_List(List * list, size_t objsize);

/**
 * @fn int8_t rsort_List(List*,size_t)
 * @param list the list to reverse sort the objects in
 * @param objsize the size of the objects being sorted
 * @return 0 on success, non-zero on error
 */
int8_t rsort_List(List * list, size_t objsize);

/**
 * @fn int8_t print_List(List*)
 * @param list the list to print objects for
 * @return 0 on success, non-zero on error
 */
int8_t print_List(List * list);

/**
 * @fn int8_t empty_List(List*)
 * @param list the list to check for emptyness
 * @return 0 on empty, non-zero otherwise
 */
int8_t empty_List(List*);

/**
 * @fn size_t size_List(List*)
 * @param list the list to get size of
 * @return size of list or 0 on error
 */
size_t size_List(List* list);


/**
 * @fn void *find_List(List*list,void *obj,size_t objsize)
 * @param list the list to search the object for
 * @param obj the object to find in the list
 * @param objsize the size of the object to find
 * @return pointer to object on success, NULL on error
 */
void *find_List(List * list, void *obj, size_t objsize);

/**
  @fn void* to_array_List(List*list, size_t objsize)
  @param list the list to turn into an array
  @param objsize the size of the objects in the list
  @return pointer to array or null on error
  */
void *to_array_List(List * list, size_t objsize);


/**
  @fn ListIter* extract_ListIter(List*list,ListIter* iter);
  @param list the list to extract the node from
  @param iter the iterator that points to the object to remove from the list
  @return Iter pointing to current object on failure, iter pointing to the
  next object on success

  @brief Removes the object that the iterator points to in the link
  list and points the iterator at the next list. if the iterator
  points to the tail of the list, it will point to the new tail.
  */
ITER(List) * extract_ListIter(ITER(List) * iter);

/**
 * @fn int32_t dump_List(List*)
 * @param list the list to dump objects for
 * @return 0 on sucess, non-zero on error
 */
int8_t dump_List(List * list);


prototype(size_of, List);
prototype(set_compare, List);
prototype(set_rcompare, List);
prototype(set_print, List);
prototype(set_alloc, List);
prototype(set_dealloc, List);
prototype(set_copy, List);

create_iter_prototypes(List)
#endif
