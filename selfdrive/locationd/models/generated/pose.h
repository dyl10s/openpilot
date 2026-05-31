#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8743902382867857614);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3636694381902544351);
void pose_H_mod_fun(double *state, double *out_2152190311268096506);
void pose_f_fun(double *state, double dt, double *out_5042547316032857663);
void pose_F_fun(double *state, double dt, double *out_6708996175305477877);
void pose_h_4(double *state, double *unused, double *out_3603221658780671100);
void pose_H_4(double *state, double *unused, double *out_7556357530358465972);
void pose_h_10(double *state, double *unused, double *out_8258563454346399047);
void pose_H_10(double *state, double *unused, double *out_2735534763065741146);
void pose_h_13(double *state, double *unused, double *out_7576910815427407655);
void pose_H_13(double *state, double *unused, double *out_4344083705026133171);
void pose_h_14(double *state, double *unused, double *out_984451843965455601);
void pose_H_14(double *state, double *unused, double *out_7807598111055713348);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}