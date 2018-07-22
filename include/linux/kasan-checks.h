/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_KASAN_CHECKS_H
#define _LINUX_KASAN_CHECKS_H

//sfw**KASAN是一个动态检测内存错误的工具。KASAN可以检测全局变量、栈、堆分配的内存发生越界访问等问题
#ifdef CONFIG_KASAN
void kasan_check_read(const volatile void *p, unsigned int size);
void kasan_check_write(const volatile void *p, unsigned int size);
#else
static inline void kasan_check_read(const volatile void *p, unsigned int size)
{ }
static inline void kasan_check_write(const volatile void *p, unsigned int size)
{ }
#endif

#endif
