#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char 		u8;
typedef unsigned short int  u16;
typedef unsigned long int	u32;

typedef signed char 		s8;
typedef signed short int    s16;
typedef signed long int	    s32;

typedef float				f32;
typedef double 				f64;

#define NULL                ((void*)0)

#define     ISR(vect)       void vect(void) __attribute__ ((signal));\
                            void vect(void)

#endif