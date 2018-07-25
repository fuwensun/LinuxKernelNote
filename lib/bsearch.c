/*
 * A generic implementation of binary search for the Linux kernel
 *
 * Copyright (C) 2008-2009 Ksplice, Inc.
 * Author: Tim Abbott <tabbott@ksplice.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2.
 */

#include <linux/export.h>
#include <linux/bsearch.h>

/*
 * bsearch - binary search an array of elements
 * @key: pointer to item being searched for
 * @base: pointer to first element to search
 * @num: number of elements
 * @size: size of each element
 * @cmp: pointer to comparison function
 *
 * This function does a binary search on the given array.  The
 * contents of the array should already be in ascending sorted order
 * under the provided comparison function.
 *
 * Note that the key need not have the same type as the elements in
 * the array, e.g. key could be a string and the comparison function
 * could compare the string with the struct's name field.  However, if
 * the key and elements in the array are of the same type, you can use
 * the same comparison function for both sort() and bsearch().
 */
//sfw**二分查找(binary search)
void *bsearch(const void *key, const void *base, size_t num, size_t size,
	      int (*cmp)(const void *key, const void *elt))
{
	const char *pivot;
	int result;

	while (num > 0) {
		pivot = base + (num >> 1) * size;
		result = cmp(key, pivot);

		if (result == 0)
			return (void *)pivot;

		if (result > 0) {
			base = pivot + size;
			num--;					//参考下面***行
		}
		num >>= 1;
	}

	return NULL;
}
/*sfw**
case1：偶数
--------------------------------
123456789abcde(14)
|      |
b      p

9abcde(6)	 *** ok:(14-1)/2 == 6		err: 14/2 == 7
|  |
b  p

case2：奇数
--------------------------------
123456789abcdef(15)
|      |
b      p

9abcdef(7)
|  |
b  p
*/
EXPORT_SYMBOL(bsearch);
