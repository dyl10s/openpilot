#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3892827861815398533);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_341451131886162609);
void pose_H_mod_fun(double *state, double *out_328613363132085737);
void pose_f_fun(double *state, double dt, double *out_2411932017416861366);
void pose_F_fun(double *state, double dt, double *out_8127227481367081246);
void pose_h_4(double *state, double *unused, double *out_3493540261963132576);
void pose_H_4(double *state, double *unused, double *out_425547638922626870);
void pose_h_10(double *state, double *unused, double *out_6421583794262292879);
void pose_H_10(double *state, double *unused, double *out_2093218466854338741);
void pose_h_13(double *state, double *unused, double *out_3950551688454018720);
void pose_H_13(double *state, double *unused, double *out_3637821464254959671);
void pose_h_14(double *state, double *unused, double *out_4675773390607303658);
void pose_H_14(double *state, double *unused, double *out_2657240793372745426);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}