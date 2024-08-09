#include <new> // Required for allocating C classes into MicroPython heap with placement new

class Example {
    public:
        Example () {

        }

        int mul(int a, int b) {
            return a * b;
        }

        ~Example () {

        }
};

// Explicitly typed variant of MP_OBJ_TO_PTR to make C++ happy
#define MP_OBJ_TO_PTR_T(o, t) ((t *)(o))

// Macro for assigning *self in class methods
#define __self__ MP_OBJ_TO_PTR_T(self_in, Example_obj_t)


extern "C" {
#include "example.h"

typedef struct Example_obj_t  {
    mp_obj_base_t base;
    void *pins;
    Example *cls;
} Example_obj_t;

mp_obj_t example_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args) {
    Example_obj_t *self = mp_obj_malloc_with_finaliser(Example_obj_t, &Example_type);

    // Use C++ "placement new" to place an instance of our C++ class in
    // memory allocated by MicroPython's m_new.
    self->cls = new(m_new(Example, 1)) Example();
    
    return MP_OBJ_FROM_PTR(self);
}

mp_obj_t example__del__(mp_obj_t self_in) {
    // Explicitly call the destructor
    // self->class->~Example();

    // Or use delete
    delete(__self__->cls);

    // Explicitly inform the GC that the memory is free
    // Usually this object is deleted and the pointer goes out of scope
    // and gets GC'd anyway so we don't *need* to do this.
    m_del(Example, __self__->cls, 1);

    return mp_const_none;
}

mp_obj_t example_method(mp_obj_t self_in, mp_obj_t a_in, mp_obj_t b_in) {
    int a = mp_obj_get_int(a_in);
    int b = mp_obj_get_int(b_in);

    int c = __self__->cls->mul(a, b);

    return mp_obj_new_int(c);
}
};