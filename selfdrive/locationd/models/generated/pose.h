#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5896214411466158685);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2659108696170388183);
void pose_H_mod_fun(double *state, double *out_7168960818524543120);
void pose_f_fun(double *state, double dt, double *out_5063918395653700509);
void pose_F_fun(double *state, double dt, double *out_4470005302657516726);
void pose_h_4(double *state, double *unused, double *out_6574127459206923931);
void pose_H_4(double *state, double *unused, double *out_8003561176394059243);
void pose_h_10(double *state, double *unused, double *out_5886867664906462198);
void pose_H_10(double *state, double *unused, double *out_6245929205097449476);
void pose_h_13(double *state, double *unused, double *out_3309926433150949848);
void pose_H_13(double *state, double *unused, double *out_2832551688998791444);
void pose_h_14(double *state, double *unused, double *out_8057772104425340564);
void pose_H_14(double *state, double *unused, double *out_6479942040976007844);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}