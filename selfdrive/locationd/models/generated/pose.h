#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6656391008125290288);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2808972743269739579);
void pose_H_mod_fun(double *state, double *out_1869854945663891945);
void pose_f_fun(double *state, double dt, double *out_1891205901656639709);
void pose_F_fun(double *state, double dt, double *out_6621216135717119405);
void pose_h_4(double *state, double *unused, double *out_6788230556268759212);
void pose_H_4(double *state, double *unused, double *out_7632527461987838329);
void pose_h_10(double *state, double *unused, double *out_8432036585650852946);
void pose_H_10(double *state, double *unused, double *out_8928260110437863487);
void pose_h_13(double *state, double *unused, double *out_2724236674667547577);
void pose_H_13(double *state, double *unused, double *out_8197129381669682433);
void pose_h_14(double *state, double *unused, double *out_7287061467575581493);
void pose_H_14(double *state, double *unused, double *out_4549739029692466033);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}