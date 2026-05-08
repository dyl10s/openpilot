#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1416756098750413745);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_288660278795817354);
void pose_H_mod_fun(double *state, double *out_8072626393727229290);
void pose_f_fun(double *state, double dt, double *out_3550739231859078198);
void pose_F_fun(double *state, double dt, double *out_4236350099338455825);
void pose_h_4(double *state, double *unused, double *out_2031088737794184983);
void pose_H_4(double *state, double *unused, double *out_6602310470138414754);
void pose_h_10(double *state, double *unused, double *out_2254252755933878198);
void pose_H_10(double *state, double *unused, double *out_4753607725561450752);
void pose_h_13(double *state, double *unused, double *out_561467872228044768);
void pose_H_13(double *state, double *unused, double *out_3390036644806081953);
void pose_h_14(double *state, double *unused, double *out_5074055792402957007);
void pose_H_14(double *state, double *unused, double *out_8761645171275764566);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}