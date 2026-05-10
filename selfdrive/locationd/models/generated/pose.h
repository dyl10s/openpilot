#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6009088715125097596);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5460684038605246490);
void pose_H_mod_fun(double *state, double *out_2180245129448668184);
void pose_f_fun(double *state, double dt, double *out_1359935913624561504);
void pose_F_fun(double *state, double dt, double *out_3401373591342797666);
void pose_h_4(double *state, double *unused, double *out_2493922315843674136);
void pose_H_4(double *state, double *unused, double *out_1093976949342281069);
void pose_h_10(double *state, double *unused, double *out_288808481596522343);
void pose_H_10(double *state, double *unused, double *out_4474711072663792050);
void pose_h_13(double *state, double *unused, double *out_5108938482451502751);
void pose_H_13(double *state, double *unused, double *out_2118296875990051732);
void pose_h_14(double *state, double *unused, double *out_5863792870354861000);
void pose_H_14(double *state, double *unused, double *out_2869263906997203460);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}