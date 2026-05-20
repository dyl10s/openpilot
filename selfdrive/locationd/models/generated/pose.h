#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_3667758909157266385);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3255008687637156165);
void pose_H_mod_fun(double *state, double *out_1678148223451849404);
void pose_f_fun(double *state, double dt, double *out_4390690219844123460);
void pose_F_fun(double *state, double dt, double *out_5251920544283288288);
void pose_h_4(double *state, double *unused, double *out_2086181486544094617);
void pose_H_4(double *state, double *unused, double *out_141550502454447457);
void pose_h_10(double *state, double *unused, double *out_2304974017593414723);
void pose_H_10(double *state, double *unused, double *out_521311265061217175);
void pose_h_13(double *state, double *unused, double *out_6563098082746675966);
void pose_H_13(double *state, double *unused, double *out_3070723322877885344);
void pose_h_14(double *state, double *unused, double *out_4832039927491863335);
void pose_H_14(double *state, double *unused, double *out_3821690353885037072);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}