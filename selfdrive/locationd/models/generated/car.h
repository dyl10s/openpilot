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
void car_err_fun(double *nom_x, double *delta_x, double *out_6892109097522362188);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5432001000781993507);
void car_H_mod_fun(double *state, double *out_1134362066478752987);
void car_f_fun(double *state, double dt, double *out_9123630075498474389);
void car_F_fun(double *state, double dt, double *out_5012636381780854897);
void car_h_25(double *state, double *unused, double *out_5169748066208681951);
void car_H_25(double *state, double *unused, double *out_6786975966495106818);
void car_h_24(double *state, double *unused, double *out_6620362679693609370);
void car_H_24(double *state, double *unused, double *out_8101842508412121662);
void car_h_30(double *state, double *unused, double *out_5326934734559811096);
void car_H_30(double *state, double *unused, double *out_9141435148707196171);
void car_h_26(double *state, double *unused, double *out_5930250619236288613);
void car_H_26(double *state, double *unused, double *out_3045472647621050594);
void car_h_27(double *state, double *unused, double *out_7982300169478535334);
void car_H_27(double *state, double *unused, double *out_84516324567073709);
void car_h_29(double *state, double *unused, double *out_3693608677880665346);
void car_H_29(double *state, double *unused, double *out_2769510980681890804);
void car_h_28(double *state, double *unused, double *out_9150043970554677071);
void car_H_28(double *state, double *unused, double *out_4733141252247217055);
void car_h_31(double *state, double *unused, double *out_1601087160141668985);
void car_H_31(double *state, double *unused, double *out_2419264545387699118);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}