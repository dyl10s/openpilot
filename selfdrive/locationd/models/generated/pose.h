#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4711793940499862270);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8790106481935061031);
void pose_H_mod_fun(double *state, double *out_3710500625877642434);
void pose_f_fun(double *state, double dt, double *out_5725984385602899057);
void pose_F_fun(double *state, double dt, double *out_3503616768446574438);
void pose_h_4(double *state, double *unused, double *out_3803432647309987328);
void pose_H_4(double *state, double *unused, double *out_7950155699686530755);
void pose_h_10(double *state, double *unused, double *out_477421004614984104);
void pose_H_10(double *state, double *unused, double *out_8536057142137197060);
void pose_h_13(double *state, double *unused, double *out_1243321013145270066);
void pose_H_13(double *state, double *unused, double *out_8514757619368374859);
void pose_h_14(double *state, double *unused, double *out_7694485530011040401);
void pose_H_14(double *state, double *unused, double *out_4867367267391158459);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}