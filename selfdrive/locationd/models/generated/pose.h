#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2495962770948129313);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_17617025005773203);
void pose_H_mod_fun(double *state, double *out_8533106360868564993);
void pose_f_fun(double *state, double dt, double *out_5731605766251141681);
void pose_F_fun(double *state, double dt, double *out_3989820231164300868);
void pose_h_4(double *state, double *unused, double *out_4946255089901338531);
void pose_H_4(double *state, double *unused, double *out_8715690230958088519);
void pose_h_10(double *state, double *unused, double *out_1122773854384552196);
void pose_H_10(double *state, double *unused, double *out_5712996006774124697);
void pose_h_13(double *state, double *unused, double *out_1411072044725156723);
void pose_H_13(double *state, double *unused, double *out_5503416405625755718);
void pose_h_14(double *state, double *unused, double *out_2642104827226322779);
void pose_H_14(double *state, double *unused, double *out_2249908027471722673);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}