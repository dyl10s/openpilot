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
void car_err_fun(double *nom_x, double *delta_x, double *out_2765937094321424100);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1382255689110899984);
void car_H_mod_fun(double *state, double *out_6175643942212596402);
void car_f_fun(double *state, double dt, double *out_2437881867604815540);
void car_F_fun(double *state, double dt, double *out_3645925778664752399);
void car_h_25(double *state, double *unused, double *out_1347552076965832871);
void car_H_25(double *state, double *unused, double *out_6035190491488835800);
void car_h_24(double *state, double *unused, double *out_7176999251413506765);
void car_H_24(double *state, double *unused, double *out_6210520902369554390);
void car_h_30(double *state, double *unused, double *out_2798183469594716038);
void car_H_30(double *state, double *unused, double *out_881499850002780955);
void car_h_26(double *state, double *unused, double *out_7428563492211452550);
void car_H_26(double *state, double *unused, double *out_8670050263346659592);
void car_h_27(double *state, double *unused, double *out_3654121190695012774);
void car_H_27(double *state, double *unused, double *out_8339292750432500781);
void car_h_29(double *state, double *unused, double *out_2203489798066129607);
void car_H_29(double *state, double *unused, double *out_5654298094317683686);
void car_h_28(double *state, double *unused, double *out_3781022243733688039);
void car_H_28(double *state, double *unused, double *out_3690667822752357435);
void car_h_31(double *state, double *unused, double *out_5423283149384518065);
void car_H_31(double *state, double *unused, double *out_6004544529611875372);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}