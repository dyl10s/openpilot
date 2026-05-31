#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4567767818172860295);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4613807108104960206);
void pose_H_mod_fun(double *state, double *out_6572770099193808423);
void pose_f_fun(double *state, double dt, double *out_972215043360367871);
void pose_F_fun(double *state, double dt, double *out_9096792433349462064);
void pose_h_4(double *state, double *unused, double *out_2265781100835663155);
void pose_H_4(double *state, double *unused, double *out_8392468825100105284);
void pose_h_10(double *state, double *unused, double *out_316139620022094761);
void pose_H_10(double *state, double *unused, double *out_3533745887327993443);
void pose_h_13(double *state, double *unused, double *out_5506810827115614970);
void pose_H_13(double *state, double *unused, double *out_781837616783404355);
void pose_h_14(double *state, double *unused, double *out_3429617090731340208);
void pose_H_14(double *state, double *unused, double *out_4429227968760620755);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}