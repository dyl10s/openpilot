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
void car_err_fun(double *nom_x, double *delta_x, double *out_3831254278589076381);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2600409940070229376);
void car_H_mod_fun(double *state, double *out_1960169395562662079);
void car_f_fun(double *state, double dt, double *out_5814026824526248658);
void car_F_fun(double *state, double dt, double *out_596946632886970600);
void car_h_25(double *state, double *unused, double *out_6549462771998662423);
void car_H_25(double *state, double *unused, double *out_4945326686098262856);
void car_h_24(double *state, double *unused, double *out_3025287820893037920);
void car_H_24(double *state, double *unused, double *out_8927649837496030754);
void car_h_30(double *state, double *unused, double *out_8259831773456866843);
void car_H_30(double *state, double *unused, double *out_2426993727591014229);
void car_h_26(double *state, double *unused, double *out_2693730589396356978);
void car_H_26(double *state, double *unused, double *out_8686830004972319080);
void car_h_27(double *state, double *unused, double *out_1218913001142171261);
void car_H_27(double *state, double *unused, double *out_4601757039391439140);
void car_h_29(double *state, double *unused, double *out_3033924557621541896);
void car_H_29(double *state, double *unused, double *out_1916762383276622045);
void car_h_28(double *state, double *unused, double *out_1822228885818648778);
void car_H_28(double *state, double *unused, double *out_6999161400346152619);
void car_h_31(double *state, double *unused, double *out_3980504990301998057);
void car_H_31(double *state, double *unused, double *out_9133705966503881060);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}