#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7636423458425794019);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4233815579108349573);
void pose_H_mod_fun(double *state, double *out_534131660440936662);
void pose_f_fun(double *state, double dt, double *out_2390572541081456385);
void pose_F_fun(double *state, double dt, double *out_1513223696750910511);
void pose_h_4(double *state, double *unused, double *out_7543652368314576620);
void pose_H_4(double *state, double *unused, double *out_4618386724598144073);
void pose_h_10(double *state, double *unused, double *out_1260309873169513594);
void pose_H_10(double *state, double *unused, double *out_3724360775848728158);
void pose_h_13(double *state, double *unused, double *out_7136718217250129115);
void pose_H_13(double *state, double *unused, double *out_7830660549930476874);
void pose_h_14(double *state, double *unused, double *out_5010661569828504853);
void pose_H_14(double *state, double *unused, double *out_8581627580937628602);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}