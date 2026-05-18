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
void car_err_fun(double *nom_x, double *delta_x, double *out_652600290238585961);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_428056314371954903);
void car_H_mod_fun(double *state, double *out_636098599351187827);
void car_f_fun(double *state, double dt, double *out_190909160143243867);
void car_F_fun(double *state, double dt, double *out_1195327144916471551);
void car_h_25(double *state, double *unused, double *out_8972033615374819768);
void car_H_25(double *state, double *unused, double *out_4267593225833477013);
void car_h_24(double *state, double *unused, double *out_1619093620334214225);
void car_H_24(double *state, double *unused, double *out_2538730106656162944);
void car_h_30(double *state, double *unused, double *out_2004718450693787274);
void car_H_30(double *state, double *unused, double *out_6785926184340725640);
void car_h_26(double *state, double *unused, double *out_7006391718354632919);
void car_H_26(double *state, double *unused, double *out_7572119195594277614);
void car_h_27(double *state, double *unused, double *out_4512330460653438616);
void car_H_27(double *state, double *unused, double *out_9009520255524668857);
void car_h_29(double *state, double *unused, double *out_2948228303595449709);
void car_H_29(double *state, double *unused, double *out_7296157528655117824);
void car_h_28(double *state, double *unused, double *out_1907925139844740965);
void car_H_28(double *state, double *unused, double *out_2213758511585587250);
void car_h_31(double *state, double *unused, double *out_332156138656277884);
void car_H_31(double *state, double *unused, double *out_4298239187710437441);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}