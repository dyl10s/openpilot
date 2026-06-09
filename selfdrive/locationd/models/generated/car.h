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
void car_err_fun(double *nom_x, double *delta_x, double *out_3281150270443704084);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3048073845424101937);
void car_H_mod_fun(double *state, double *out_5861733525303608227);
void car_f_fun(double *state, double dt, double *out_6520674902136446798);
void car_F_fun(double *state, double dt, double *out_2036702211381872187);
void car_h_25(double *state, double *unused, double *out_7733856010300149046);
void car_H_25(double *state, double *unused, double *out_6810854447332090436);
void car_h_24(double *state, double *unused, double *out_8048847696560640687);
void car_H_24(double *state, double *unused, double *out_2407824440308265955);
void car_h_30(double *state, double *unused, double *out_7458661948015643157);
void car_H_30(double *state, double *unused, double *out_2283158117204482238);
void car_h_26(double *state, double *unused, double *out_5109796638135193371);
void car_H_26(double *state, double *unused, double *out_3069351128458034212);
void car_h_27(double *state, double *unused, double *out_2732182742639303401);
void car_H_27(double *state, double *unused, double *out_108394805404057327);
void car_h_29(double *state, double *unused, double *out_1129500733789198251);
void car_H_29(double *state, double *unused, double *out_2793389461518874422);
void car_h_28(double *state, double *unused, double *out_4422630577374984361);
void car_H_28(double *state, double *unused, double *out_2289009555550656152);
void car_h_31(double *state, double *unused, double *out_7765162073053917609);
void car_H_31(double *state, double *unused, double *out_2443143026224682736);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}