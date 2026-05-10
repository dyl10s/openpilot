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
void car_err_fun(double *nom_x, double *delta_x, double *out_7149517118868685515);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1206282320038144058);
void car_H_mod_fun(double *state, double *out_2536050837023062909);
void car_f_fun(double *state, double dt, double *out_4666135608333935516);
void car_F_fun(double *state, double dt, double *out_2752692491938964849);
void car_h_25(double *state, double *unused, double *out_3787568519496882893);
void car_H_25(double *state, double *unused, double *out_3699858802985056505);
void car_h_24(double *state, double *unused, double *out_1528856480665249325);
void car_H_24(double *state, double *unused, double *out_1970995683807742436);
void car_h_30(double *state, double *unused, double *out_4709092161766857099);
void car_H_30(double *state, double *unused, double *out_7830194929232878356);
void car_h_26(double *state, double *unused, double *out_1815522905777326306);
void car_H_26(double *state, double *unused, double *out_41644515888999719);
void car_h_27(double *state, double *unused, double *out_8789241787157728538);
void car_H_27(double *state, double *unused, double *out_8441785832676248349);
void car_h_29(double *state, double *unused, double *out_8252567880601862062);
void car_H_29(double *state, double *unused, double *out_7319963584918486172);
void car_h_28(double *state, double *unused, double *out_5372968497508658522);
void car_H_28(double *state, double *unused, double *out_6044381471721534870);
void car_h_31(double *state, double *unused, double *out_6895910297391996282);
void car_H_31(double *state, double *unused, double *out_3730504764862016933);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}