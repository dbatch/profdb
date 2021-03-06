#ifndef _VM_REGION_H
#define _VM_REGION_H

#include <array.h>
#include <spinlock.h>

struct addrspace; /* opaque */

/**
 * using the built-in array data-structure instead of a linked list
 * to hold each vm_page that belongs to a vm_region
 */
DECLARRAY_BYTYPE( vm_page_array, struct vm_page );

struct vm_region {
	struct vm_page_array		*vmr_pages;
	vaddr_t				vmr_base;
};

DECLARRAY_BYTYPE( vm_region_array, struct vm_region );

struct vm_region		*vm_region_create( size_t );
void				vm_region_destroy( struct vm_region * );
int				vm_region_clone( struct vm_region *, struct vm_region ** );
int				vm_region_resize( struct vm_region *, unsigned );
struct vm_region		*vm_region_find_responsible( struct addrspace *, vaddr_t );
#endif
