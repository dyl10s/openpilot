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
void car_err_fun(double *nom_x, double *delta_x, double *out_4413943037710355540);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_896653973664715101);
void car_H_mod_fun(double *state, double *out_5267188789104253679);
void car_f_fun(double *state, double dt, double *out_1590758894307502735);
void car_F_fun(double *state, double dt, double *out_4932077017586128960);
void car_h_25(double *state, double *unused, double *out_2151142981028497358);
void car_H_25(double *state, double *unused, double *out_5796040611085329032);
void car_h_24(double *state, double *unused, double *out_7809478958388963293);
void car_H_24(double *state, double *unused, double *out_1813717459687561134);
void car_h_30(double *state, double *unused, double *out_8921978207378848294);
void car_H_30(double *state, double *unused, double *out_5734013121132605829);
void car_h_26(double *state, double *unused, double *out_3355877023318338429);
void car_H_26(double *state, double *unused, double *out_6452894675195640936);
void car_h_27(double *state, double *unused, double *out_6869400431411979084);
void car_H_27(double *state, double *unused, double *out_7908776432933030740);
void car_h_29(double *state, double *unused, double *out_3696070991543523347);
void car_H_29(double *state, double *unused, double *out_5223781776818213645);
void car_h_28(double *state, double *unused, double *out_6575670374636726887);
void car_H_28(double *state, double *unused, double *out_8140563279821807397);
void car_h_31(double *state, double *unused, double *out_5612122275792175083);
void car_H_31(double *state, double *unused, double *out_5826686572962289460);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}