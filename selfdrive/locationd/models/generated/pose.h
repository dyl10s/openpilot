#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8885367235752958450);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4135735359507688267);
void pose_H_mod_fun(double *state, double *out_2496917717950831316);
void pose_f_fun(double *state, double dt, double *out_6905768897951283532);
void pose_F_fun(double *state, double dt, double *out_5307423376078500036);
void pose_h_4(double *state, double *unused, double *out_1079193932347421775);
void pose_H_4(double *state, double *unused, double *out_1742756715896118709);
void pose_h_10(double *state, double *unused, double *out_6922910997507784152);
void pose_H_10(double *state, double *unused, double *out_283934102184360827);
void pose_h_13(double *state, double *unused, double *out_6392911292944498098);
void pose_H_13(double *state, double *unused, double *out_1469517109436214092);
void pose_h_14(double *state, double *unused, double *out_2710339252461203529);
void pose_H_14(double *state, double *unused, double *out_2220484140443365820);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}