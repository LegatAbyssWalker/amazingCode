/* Coded by OdnetninI */
/* Compile it with gcc -o amazingSort amazingSort.c -std=c89 -fms-extensions */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define new(x, ...) ({x* tmp = (x*)malloc(sizeof(x)); x##__ctor(tmp , ##__VA_ARGS__); tmp;})
#define delete(x) {free(x);};

#define nullptr ((void*)0x00)
#define null (0x00)

typedef struct Integer_Data {
  uint8_t* data;
} _Integer_Data;

struct Integer_Vtbl;
typedef struct __integer {
  struct Integer_Vtbl const *vptr;
  void const * super;
  _Integer_Data;
} Integer;

typedef struct Integer_Vtbl {
  void (*setInteger)(Integer * const this, int64_t x);
  int64_t (*getInteger)(Integer * const this);
} _Integer_Vtbl;

void Integer__setInteger(Integer * const this, int64_t x) {
  int i = 0;
  for (i = 0; i < 8; ++i) {
    this->data[i] = x >> (i * 8);
  }
}

int64_t Integer__getInteger(Integer * const this) {
  return
    (this->data[7] << 7*8) |
    (this->data[6] << 6*8) |
    (this->data[5] << 5*8) |
    (this->data[4] << 4*8) |
    (this->data[3] << 3*8) |
    (this->data[2] << 2*8) |
    (this->data[1] << 1*8) |
    (this->data[0] << 0*8);
}

static const struct Integer_Vtbl Integer_Vtbl =
{
 .setInteger = Integer__setInteger,
 .getInteger = Integer__getInteger,
};

void Integer__ctor(Integer * const this, int64_t x) {
  this->vptr = &Integer_Vtbl;
  this->data = malloc(8 * sizeof(uint8_t));
  Integer__setInteger(this, x);
}

void Integer__dtor(Integer * const this) {
  free(this->data);
}

typedef struct IntegerArray_Data {
  Integer** data;
  uint64_t size;
} _IntegerArray_Data;

struct IntegerArray_Vtbl;
typedef struct __array {
  struct IntegerArray_Vtbl const *vptr;
  void const * super;
  _IntegerArray_Data;
} IntegerArray;

typedef struct IntegerArray_Vtbl {
  Integer* (*get)(IntegerArray * const this, uint64_t index);
  void (*set)(IntegerArray * const this, uint64_t index, Integer* integer);
  uint64_t (*size)(IntegerArray * const this);
} _IntegerArray_Vtbl;


Integer* IntegerArray__get(IntegerArray * const this, uint64_t index) {
  if (index >= this->size) return nullptr;
  return this->data[index];
}

void IntegerArray__set(IntegerArray * const this, uint64_t index, Integer* integer) {
  if (index >= this->size) return nullptr;
  this->data[index] = integer;
}

Integer* IntegerArray__size(IntegerArray * const this) {
  return this->size;
}

static const struct IntegerArray_Vtbl IntegerArray_Vtbl =
{
 .get = IntegerArray__get,
 .set = IntegerArray__set,
 .size = IntegerArray__size,
};

void IntegerArray__ctor(IntegerArray * const this, uint64_t size) {
  this->vptr = &IntegerArray_Vtbl;
  this->data = malloc(size * sizeof(Integer*));
  this->size = size;
}

void IntegerArray__dtor(IntegerArray * const this) {
  free(this->data);
}

typedef struct Swapper_Data {
  void** a;
  void** b;
} _Swapper_Data;

struct Swapper_Vtbl;
typedef struct __swapper {
  struct Swapper_Vtbl const *vptr;
  void const * super;
  _Swapper_Data;
} Swapper;

typedef struct Swapper_Vtbl {
  void (*swap)(Swapper * const this);
} _Swapper_Vtbl;

void Swapper__swap(Swapper * const this) {
  (*(this->a)) = (void*)(((uint64_t)(*(this->a))) ^ ((uint64_t)(*(this->b))));
  (*(this->b)) = (void*)(((uint64_t)(*(this->b))) ^ ((uint64_t)(*(this->a))));
  (*(this->a)) = (void*)(((uint64_t)(*(this->a))) ^ ((uint64_t)(*(this->b))));
}

static const struct Swapper_Vtbl Swapper_Vtbl =
{
 .swap = Swapper__swap,
};

void Swapper__ctor(Swapper * const this, void** a, void** b) {
  this->vptr = &Swapper_Vtbl;
  this->a = a;
  this->b = b;
}

void Swapper__dtor(Swapper * const this) {
  
}

typedef struct ArraySorter_Data {
  Integer** data;
  uint64_t size;
  uint8_t mode;
} _ArraySorter_Data;

struct ArraySorter_Vtbl;
typedef struct __arraysorter {
  struct ArraySorter_Vtbl const *vptr;
  void const * super;
  _ArraySorter_Data;
} ArraySorter;

typedef struct ArraySorter_Vtbl {
  void (*amazingSort)(ArraySorter * const this, IntegerArray * const array);
  uint8_t (*amazingCompare)(ArraySorter * const this, Integer* a, Integer* b);
} _ArraySorter_Vtbl;

void ArraySorter__amazingSort(ArraySorter * const this, IntegerArray * const array) {
  uint64_t i = 0;
  for (i = 0; i < array->vptr->size(array); ++i) {
    uint64_t j = 0;
    for (j = i+1; j < array->vptr->size(array); ++j) {
      Integer* a = array->vptr->get(array, i);
      Integer* b = array->vptr->get(array, j);
      Swapper* s = new(Swapper, &a, &b);
      if (this->vptr->amazingCompare(this, a, b)) {
	s->vptr->swap(s);
	array->vptr->set(array, i, a);
	array->vptr->set(array, j, b);
      }
      Swapper__dtor(s);
      delete(s);
    }
  }
}

uint8_t ArraySorter__amazingCompare(ArraySorter * const this, Integer* a, Integer* b) {
  goto logic;
 less:
  return 1;
 eign:
  return 0;
 logic:
  switch(this->mode) {
  case 0:
    {
      if (a->vptr->getInteger(a) <= b->vptr->getInteger(b)) goto less;
      goto eign;
      break;
    }
  case 1:
    {
      if (a->vptr->getInteger(a) <= b->vptr->getInteger(b)) goto eign;
      goto less;
      break;
    }
  }
}

static const struct ArraySorter_Vtbl ArraySorter_Vtbl =
{
 .amazingSort = ArraySorter__amazingSort,
 .amazingCompare = ArraySorter__amazingCompare,
};

void ArraySorter__ctor(ArraySorter * const this) {
  this->vptr = &ArraySorter_Vtbl;
  this->mode = 1; /* 0 = greater, 1 = less */
}

void ArraySorter__dtor(ArraySorter * const this) {
  free(this->data);
}

int main (int argc, char* argv[]) {

  IntegerArray* ia = new(IntegerArray, 4);
  
  Integer* i = new(Integer, 258);
  Integer* i2 = new(Integer, 258*2);
  Integer* i3 = new(Integer, 258*3);
  Integer* i4 = new(Integer, 258*4);

  ia->vptr->set(ia, 0, i);
  ia->vptr->set(ia, 1, i3);
  ia->vptr->set(ia, 2, i2);
  ia->vptr->set(ia, 3, i4);

  ArraySorter* as = new(ArraySorter);
  as->vptr->amazingSort(as, ia);

  printf("%lli\n", ia->vptr->get(ia, 0)->vptr->getInteger(ia->vptr->get(ia, 0)));
  printf("%lli\n", ia->vptr->get(ia, 1)->vptr->getInteger(ia->vptr->get(ia, 1)));
  printf("%lli\n", ia->vptr->get(ia, 2)->vptr->getInteger(ia->vptr->get(ia, 2)));
  printf("%lli\n", ia->vptr->get(ia, 3)->vptr->getInteger(ia->vptr->get(ia, 3)));

  Integer__dtor(i);
  Integer__dtor(i2);
  Integer__dtor(i3);
  Integer__dtor(i4);
  IntegerArray__dtor(ia);
  ArraySorter__dtor(as);
  delete(i);
  delete(i2);
  delete(i3);
  delete(i4);
  delete(ia);
  delete(as);
  
  return 0;
}

