#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8207359146711228947);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8369219426901598353);
void pose_H_mod_fun(double *state, double *out_7202306802530511060);
void pose_f_fun(double *state, double dt, double *out_4961001892384611064);
void pose_F_fun(double *state, double dt, double *out_4383751150204030030);
void pose_h_4(double *state, double *unused, double *out_878843833946471253);
void pose_H_4(double *state, double *unused, double *out_7970215192388091303);
void pose_h_10(double *state, double *unused, double *out_1191517594273352576);
void pose_H_10(double *state, double *unused, double *out_7914634342859917414);
void pose_h_13(double *state, double *unused, double *out_5300060524255047032);
void pose_H_13(double *state, double *unused, double *out_7264255055989127512);
void pose_h_14(double *state, double *unused, double *out_3965460404426586337);
void pose_H_14(double *state, double *unused, double *out_6513288024981975784);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}