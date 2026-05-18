#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6520327552806096841);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3933583929675800728);
void pose_H_mod_fun(double *state, double *out_6974741239016485936);
void pose_f_fun(double *state, double dt, double *out_7579043913228931093);
void pose_F_fun(double *state, double dt, double *out_7552939469662313928);
void pose_h_4(double *state, double *unused, double *out_3550900755285532144);
void pose_H_4(double *state, double *unused, double *out_3202934029172578364);
void pose_h_10(double *state, double *unused, double *out_7067714338468602861);
void pose_H_10(double *state, double *unused, double *out_4832878358593471680);
void pose_h_13(double *state, double *unused, double *out_6451839863147612103);
void pose_H_13(double *state, double *unused, double *out_9339796159754437);
void pose_h_14(double *state, double *unused, double *out_3486571009539339858);
void pose_H_14(double *state, double *unused, double *out_6285722461467950660);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}