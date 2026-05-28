#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_628539194751276084);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5785405288888399451);
void pose_H_mod_fun(double *state, double *out_1308901075637477725);
void pose_f_fun(double *state, double dt, double *out_8416334481406024670);
void pose_F_fun(double *state, double dt, double *out_5288884962144890875);
void pose_h_4(double *state, double *unused, double *out_90872324407998874);
void pose_H_4(double *state, double *unused, double *out_7635460590420343617);
void pose_h_10(double *state, double *unused, double *out_729559215867171711);
void pose_H_10(double *state, double *unused, double *out_4724811786445925588);
void pose_h_13(double *state, double *unused, double *out_6088791521295825946);
void pose_H_13(double *state, double *unused, double *out_4423186765088010816);
void pose_h_14(double *state, double *unused, double *out_1848639786756728796);
void pose_H_14(double *state, double *unused, double *out_7728495050993835703);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}