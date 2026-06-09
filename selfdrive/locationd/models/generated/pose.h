#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6531280423659383110);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2847042605170284069);
void pose_H_mod_fun(double *state, double *out_1201664963462517165);
void pose_f_fun(double *state, double dt, double *out_4925442091395050631);
void pose_F_fun(double *state, double dt, double *out_3854196706556040023);
void pose_h_4(double *state, double *unused, double *out_6044371799568265897);
void pose_H_4(double *state, double *unused, double *out_8751938887176636728);
void pose_h_10(double *state, double *unused, double *out_9126782512040865980);
void pose_H_10(double *state, double *unused, double *out_2728048388349900962);
void pose_h_13(double *state, double *unused, double *out_6648711810487729870);
void pose_H_13(double *state, double *unused, double *out_1141307678859935799);
void pose_h_14(double *state, double *unused, double *out_6901319929397273887);
void pose_H_14(double *state, double *unused, double *out_4788698030837152199);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}