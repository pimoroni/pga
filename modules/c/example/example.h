#include "py/runtime.h"

extern const mp_obj_type_t Example_type;

extern mp_obj_t example_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args);
extern mp_obj_t example__del__(mp_obj_t self_in);

extern mp_obj_t example_method(mp_obj_t self_in, mp_obj_t a_in, mp_obj_t b_in);