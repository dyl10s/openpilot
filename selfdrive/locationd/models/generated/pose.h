#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8315489890310503187);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6008596051390826841);
void pose_H_mod_fun(double *state, double *out_5634677350720166788);
void pose_f_fun(double *state, double dt, double *out_5401222257802876036);
void pose_F_fun(double *state, double dt, double *out_1313183186567530475);
void pose_h_4(double *state, double *unused, double *out_717943751669182438);
void pose_H_4(double *state, double *unused, double *out_7659548337950304093);
void pose_h_10(double *state, double *unused, double *out_5351201218378086589);
void pose_H_10(double *state, double *unused, double *out_5063285185285945841);
void pose_h_13(double *state, double *unused, double *out_8511287818621351769);
void pose_H_13(double *state, double *unused, double *out_4447274512617971292);
void pose_h_14(double *state, double *unused, double *out_7796170631529448638);
void pose_H_14(double *state, double *unused, double *out_3696307481610819564);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}