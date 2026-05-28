#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8550489212526755506);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2197167056715094306);
void pose_H_mod_fun(double *state, double *out_1273572215837011735);
void pose_f_fun(double *state, double dt, double *out_58843541046312828);
void pose_F_fun(double *state, double dt, double *out_4952539587807327652);
void pose_h_4(double *state, double *unused, double *out_105029621528743882);
void pose_H_4(double *state, double *unused, double *out_7121654022588970456);
void pose_h_10(double *state, double *unused, double *out_7355867801776776353);
void pose_H_10(double *state, double *unused, double *out_6146846088544597929);
void pose_h_13(double *state, double *unused, double *out_2344100091734301077);
void pose_H_13(double *state, double *unused, double *out_3909380197256637655);
void pose_h_14(double *state, double *unused, double *out_589344124113930337);
void pose_H_14(double *state, double *unused, double *out_3158413166249485927);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}