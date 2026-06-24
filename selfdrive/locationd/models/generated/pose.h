#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2889016141520795461);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6586333085018065986);
void pose_H_mod_fun(double *state, double *out_6984305438091048706);
void pose_f_fun(double *state, double dt, double *out_4187862153732757636);
void pose_F_fun(double *state, double dt, double *out_7339590787986428927);
void pose_h_4(double *state, double *unused, double *out_8608741357917418213);
void pose_H_4(double *state, double *unused, double *out_8804004163997345567);
void pose_h_10(double *state, double *unused, double *out_4067868698993544544);
void pose_H_10(double *state, double *unused, double *out_6538171315605639203);
void pose_h_13(double *state, double *unused, double *out_1704356913043206317);
void pose_H_13(double *state, double *unused, double *out_5591730338665012766);
void pose_h_14(double *state, double *unused, double *out_5410919187051701678);
void pose_H_14(double *state, double *unused, double *out_4840763307657861038);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}