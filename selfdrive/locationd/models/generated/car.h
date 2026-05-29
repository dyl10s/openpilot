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
void car_err_fun(double *nom_x, double *delta_x, double *out_8206107047934752633);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3582621965851683853);
void car_H_mod_fun(double *state, double *out_3381247545329584694);
void car_f_fun(double *state, double dt, double *out_4828443839748202677);
void car_F_fun(double *state, double dt, double *out_3545622658498023447);
void car_h_25(double *state, double *unused, double *out_7855544973847125055);
void car_H_25(double *state, double *unused, double *out_5811940680582652543);
void car_h_24(double *state, double *unused, double *out_7215169173686495729);
void car_H_24(double *state, double *unused, double *out_7984590279588152109);
void car_h_30(double *state, double *unused, double *out_1700097778006464926);
void car_H_30(double *state, double *unused, double *out_1104749660908964212);
void car_h_26(double *state, double *unused, double *out_6125458693304696459);
void car_H_26(double *state, double *unused, double *out_8893300074252842849);
void car_h_27(double *state, double *unused, double *out_2212815102766168220);
void car_H_27(double *state, double *unused, double *out_1070013650891460699);
void car_h_29(double *state, double *unused, double *out_4304503098815162577);
void car_H_29(double *state, double *unused, double *out_2783376377761011732);
void car_h_28(double *state, double *unused, double *out_8381962881269050695);
void car_H_28(double *state, double *unused, double *out_7865775394830542306);
void car_h_31(double *state, double *unused, double *out_8130739036131630944);
void car_H_31(double *state, double *unused, double *out_5781294718705692115);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}