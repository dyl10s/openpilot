#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_937271495952840532);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_712402659692030222);
void pose_H_mod_fun(double *state, double *out_4304163029800659692);
void pose_f_fun(double *state, double dt, double *out_7809694961382882469);
void pose_F_fun(double *state, double dt, double *out_4402047608279739822);
void pose_h_4(double *state, double *unused, double *out_1761018668225147827);
void pose_H_4(double *state, double *unused, double *out_6123861755706956553);
void pose_h_10(double *state, double *unused, double *out_5906261859060682989);
void pose_H_10(double *state, double *unused, double *out_8717187080084033317);
void pose_h_13(double *state, double *unused, double *out_5437403947989237748);
void pose_H_13(double *state, double *unused, double *out_8489126854700071039);
void pose_h_14(double *state, double *unused, double *out_2973157686650314108);
void pose_H_14(double *state, double *unused, double *out_9206650188002328849);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}