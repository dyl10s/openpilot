#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8796389704996072171);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8849207833158339340);
void car_H_mod_fun(double *state, double *out_1622786580378488408);
void car_f_fun(double *state, double dt, double *out_1981095305174081329);
void car_F_fun(double *state, double dt, double *out_3561550856242897713);
void car_h_25(double *state, double *unused, double *out_3280789364307995853);
void car_H_25(double *state, double *unused, double *out_445738705382224348);
void car_h_24(double *state, double *unused, double *out_5100775928185398157);
void car_H_24(double *state, double *unused, double *out_399257903401471051);
void car_h_30(double *state, double *unused, double *out_3331749478418022440);
void car_H_30(double *state, double *unused, double *out_2072594253125024279);
void car_h_26(double *state, double *unused, double *out_1066202602863606572);
void car_H_26(double *state, double *unused, double *out_4187242024256280572);
void car_h_27(double *state, double *unused, double *out_3118252153105853293);
void car_H_27(double *state, double *unused, double *out_4296188324308967496);
void car_h_29(double *state, double *unused, double *out_8557656694253347387);
void car_H_29(double *state, double *unused, double *out_2582825597439416463);
void car_h_28(double *state, double *unused, double *out_4285995954181995030);
void car_H_28(double *state, double *unused, double *out_2499573419630114111);
void car_h_31(double *state, double *unused, double *out_6669294028137815771);
void car_H_31(double *state, double *unused, double *out_415092743505263920);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}