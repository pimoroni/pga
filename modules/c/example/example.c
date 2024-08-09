#include <example.h>

MP_DEFINE_CONST_FUN_OBJ_1(example__del__obj, example__del__);

MP_DEFINE_CONST_FUN_OBJ_3(example_method_obj, example_method);

// Class Methods
static const mp_rom_map_elem_t example_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___del__), MP_ROM_PTR(&example__del__obj) },
    { MP_ROM_QSTR(MP_QSTR_mul), MP_ROM_PTR(&example_method_obj) }
};

static MP_DEFINE_CONST_DICT(example_locals_dict, example_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(
    Example_type,
    MP_QSTR_Example,
    MP_TYPE_FLAG_NONE,
    make_new, example_make_new,
    locals_dict, (mp_obj_dict_t*)&example_locals_dict
);

// Module Methods
static const mp_map_elem_t example_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_example) },  // Module name
    { MP_OBJ_NEW_QSTR(MP_QSTR_Example), (mp_obj_t)&Example_type },            // Class name & type
};

static MP_DEFINE_CONST_DICT(mp_module_example_globals, example_globals_table);

const mp_obj_module_t example_user_c_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_example_globals,
};

// First argument should match the __name__ given in the globals table
MP_REGISTER_MODULE(MP_QSTR_example, example_user_c_module);