#include "esp_log.h"

// Include MicroPython API.
#include "py/runtime.h"
#include "py/mphal.h"

#include "mphalport.h"

#include "driver/mcpwm.h"
#include "soc/mcpwm_reg.h"
#include "soc/mcpwm_struct.h"

#define M1A_PIN     17
#define M1B_PIN     16
#define M2A_PIN     5
#define M2B_PIN     18

#define FORWARD     1
#define BACKWARD    2
#define TURN_LEFT   3
#define TURN_RIGHT  4

static mcpwm_config_t configs_mcpwm = {
    .frequency = 1E3, // 1 kHz
    .cmpr_a = 0.0f,
    .cmpr_b = 0.0f,
    .duty_mode = MCPWM_DUTY_MODE_0,
    .counter_mode = MCPWM_UP_COUNTER,
};

void _wheel(int speed_left, int speed_right) {
    int dir1 = speed_left > 0 ? 2 : speed_left < 0 ? 1 : 0;
    if (speed_left < 0) {
        speed_left = speed_left * -1;
    }
    if (dir1 == 0) {
        mcpwm_set_signal_high(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A);
        mcpwm_set_signal_high(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B);
    } else if (dir1 == 1) {
        mcpwm_set_signal_high(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A);
        mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, 100 - speed_left);
        mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, MCPWM_DUTY_MODE_0);
    } else if (dir1 == 2) {
        mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, 100 - speed_left);
        mcpwm_set_signal_high(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B);
        mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
    }

    int dir2 = speed_right > 0 ? 1 : speed_right < 0 ? 2 : 0;
    if (speed_right < 0) {
        speed_right = speed_right * -1;
    }
    if (dir2 == 0) {
        mcpwm_set_signal_high(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_A);
        mcpwm_set_signal_high(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_B);
    } else if (dir2 == 1) {
        mcpwm_set_signal_high(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_A);
        mcpwm_set_duty(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_B, 100 - speed_right);
        mcpwm_set_duty_type(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_B, MCPWM_DUTY_MODE_0);
    } else if (dir2 == 2) {
        mcpwm_set_duty(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_A, 100 - speed_right);
        mcpwm_set_signal_high(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_B);
        mcpwm_set_duty_type(MCPWM_UNIT_1, MCPWM_TIMER_1, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
    }
}

void _sleep(mp_float_t time) {
    mp_hal_delay_ms(time * 1000.0f);
}

STATIC mp_obj_t motor_init() {
    static bool init = false;
    if (!init) {
        mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, M1A_PIN);
        mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0B, M1B_PIN);
        mcpwm_gpio_init(MCPWM_UNIT_1, MCPWM1A, M2A_PIN);
        mcpwm_gpio_init(MCPWM_UNIT_1, MCPWM1B, M2B_PIN);

        /*
        mcpwm_group_set_resolution(MCPWM_CH, ...);
        mcpwm_timer_set_resolution(MCPWM_CH, MCPWM_TIMER, ...);
        */

        mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &configs_mcpwm);
        mcpwm_init(MCPWM_UNIT_1, MCPWM_TIMER_1, &configs_mcpwm);
    }

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(motor_init_obj, motor_init);

STATIC mp_obj_t motor_wheel(mp_obj_t speed_left_obj, mp_obj_t speed_right_obj) {
    mp_int_t speed_left = mp_obj_get_int(speed_left_obj);
    mp_int_t speed_right = mp_obj_get_int(speed_right_obj);

    _wheel(speed_left, speed_right);

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(motor_wheel_obj, motor_wheel);

STATIC mp_obj_t motor_forward(mp_obj_t speed_obj, mp_obj_t time_obj) {
    mp_int_t speed = mp_obj_get_int(speed_obj);
    mp_float_t time = mp_obj_get_float(time_obj);

    _wheel(speed, speed);
    _sleep(time);
    _wheel(0, 0);

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(motor_forward_obj, motor_forward);

STATIC mp_obj_t motor_backward(mp_obj_t speed_obj, mp_obj_t time_obj) {
    mp_int_t speed = mp_obj_get_int(speed_obj);
    mp_float_t time = mp_obj_get_float(time_obj);

    _wheel(speed * -1, speed * -1);
    _sleep(time);
    _wheel(0, 0);

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(motor_backward_obj, motor_backward);

STATIC mp_obj_t motor_turn_left(mp_obj_t speed_obj, mp_obj_t time_obj) {
    mp_int_t speed = mp_obj_get_int(speed_obj);
    mp_float_t time = mp_obj_get_float(time_obj);

    _wheel(0, speed);
    _sleep(time);
    _wheel(0, 0);

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(motor_turn_left_obj, motor_turn_left);

STATIC mp_obj_t motor_turn_right(mp_obj_t speed_obj, mp_obj_t time_obj) {
    mp_int_t speed = mp_obj_get_int(speed_obj);
    mp_float_t time = mp_obj_get_float(time_obj);

    _wheel(speed, 0);
    _sleep(time);
    _wheel(0, 0);

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(motor_turn_right_obj, motor_turn_right);

STATIC mp_obj_t motor_spin_left(mp_obj_t speed_obj, mp_obj_t time_obj) {
    mp_int_t speed = mp_obj_get_int(speed_obj);
    mp_float_t time = mp_obj_get_float(time_obj);

    _wheel(-speed, speed);
    _sleep(time);
    _wheel(0, 0);

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(motor_spin_left_obj, motor_spin_left);

STATIC mp_obj_t motor_spin_right(mp_obj_t speed_obj, mp_obj_t time_obj) {
    mp_int_t speed = mp_obj_get_int(speed_obj);
    mp_float_t time = mp_obj_get_float(time_obj);

    _wheel(speed, -speed);
    _sleep(time);
    _wheel(0, 0);

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(motor_spin_right_obj, motor_spin_right);

STATIC mp_obj_t motor_move(mp_obj_t dir_obj, mp_obj_t speed_obj) {
    mp_int_t dir = mp_obj_get_int(dir_obj);
    mp_int_t speed = mp_obj_get_int(speed_obj);

    if (dir == FORWARD) {
        _wheel(speed, speed);
    } else if (dir == BACKWARD) {
        _wheel(speed * -1, speed * -1);
    } else if (dir == TURN_LEFT) {
        _wheel(0, speed);
    } else if (dir == TURN_RIGHT) {
        _wheel(speed, 0);
    }

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(motor_move_obj, motor_move);

STATIC mp_obj_t motor_stop() {
    _wheel(0, 0);

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(motor_stop_obj, motor_stop);

STATIC const mp_rom_map_elem_t motor_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__),   MP_ROM_QSTR(MP_QSTR_motor) },
    { MP_ROM_QSTR(MP_QSTR_init),       MP_ROM_PTR(&motor_init_obj) },
    { MP_ROM_QSTR(MP_QSTR_wheel),      MP_ROM_PTR(&motor_wheel_obj) },
    { MP_ROM_QSTR(MP_QSTR_forward),    MP_ROM_PTR(&motor_forward_obj) },
    { MP_ROM_QSTR(MP_QSTR_backward),   MP_ROM_PTR(&motor_backward_obj) },
    { MP_ROM_QSTR(MP_QSTR_turn_left),  MP_ROM_PTR(&motor_turn_left_obj) },
    { MP_ROM_QSTR(MP_QSTR_turn_right), MP_ROM_PTR(&motor_turn_right_obj) },
    { MP_ROM_QSTR(MP_QSTR_spin_left),  MP_ROM_PTR(&motor_spin_left_obj) },
    { MP_ROM_QSTR(MP_QSTR_spin_right), MP_ROM_PTR(&motor_spin_right_obj) },
    { MP_ROM_QSTR(MP_QSTR_move),       MP_ROM_PTR(&motor_move_obj) },
    { MP_ROM_QSTR(MP_QSTR_stop),       MP_ROM_PTR(&motor_stop_obj) },

    { MP_ROM_QSTR(MP_QSTR_FORWARD),    MP_ROM_INT(FORWARD) },
    { MP_ROM_QSTR(MP_QSTR_BACKWARD),   MP_ROM_INT(BACKWARD) },
    { MP_ROM_QSTR(MP_QSTR_TURN_LEFT),  MP_ROM_INT(TURN_LEFT) },
    { MP_ROM_QSTR(MP_QSTR_TURN_RIGHT), MP_ROM_INT(TURN_RIGHT) },
};
STATIC MP_DEFINE_CONST_DICT(motor_module_globals, motor_module_globals_table);

const mp_obj_module_t motor_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&motor_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_motor, motor_user_cmodule, 1);
