#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2367672105654731741);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5219205296235492699);
void pose_H_mod_fun(double *state, double *out_7701265832873588876);
void pose_f_fun(double *state, double dt, double *out_2925592785824916722);
void pose_F_fun(double *state, double dt, double *out_6409294416375959373);
void pose_h_4(double *state, double *unused, double *out_915233285986441516);
void pose_H_4(double *state, double *unused, double *out_8851967337240186650);
void pose_h_10(double *state, double *unused, double *out_1698568734316977875);
void pose_H_10(double *state, double *unused, double *out_2859565754749971930);
void pose_h_13(double *state, double *unused, double *out_4058736517215946312);
void pose_H_13(double *state, double *unused, double *out_6382502911137032165);
void pose_h_14(double *state, double *unused, double *out_6181664354414385783);
void pose_H_14(double *state, double *unused, double *out_8416850810595303051);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}