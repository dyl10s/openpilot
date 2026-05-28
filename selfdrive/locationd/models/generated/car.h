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
void car_err_fun(double *nom_x, double *delta_x, double *out_4387195160971747702);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7707264064834051115);
void car_H_mod_fun(double *state, double *out_7178605602671138983);
void car_f_fun(double *state, double dt, double *out_2416599425795193412);
void car_F_fun(double *state, double dt, double *out_6761986232654706930);
void car_h_25(double *state, double *unused, double *out_319074315832850169);
void car_H_25(double *state, double *unused, double *out_3655624952681647306);
void car_h_24(double *state, double *unused, double *out_5734853090591072423);
void car_H_24(double *state, double *unused, double *out_1429917168702778744);
void car_h_30(double *state, double *unused, double *out_8212013810717373528);
void car_H_30(double *state, double *unused, double *out_3784963899824887376);
void car_h_26(double *state, double *unused, double *out_5233056995331332443);
void car_H_26(double *state, double *unused, double *out_2998770888571335402);
void car_h_27(double *state, double *unused, double *out_3355860367277182854);
void car_H_27(double *state, double *unused, double *out_5959727211625312287);
void car_h_29(double *state, double *unused, double *out_7630324942183480437);
void car_H_29(double *state, double *unused, double *out_3274732555510495192);
void car_h_28(double *state, double *unused, double *out_4299370220178845289);
void car_H_28(double *state, double *unused, double *out_1311102283945168941);
void car_h_31(double *state, double *unused, double *out_594268378117356058);
void car_H_31(double *state, double *unused, double *out_3624978990804686878);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}