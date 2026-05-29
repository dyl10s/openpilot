#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5715232905817063541);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5652160587936785451);
void pose_H_mod_fun(double *state, double *out_4347742436966495208);
void pose_f_fun(double *state, double dt, double *out_4741478081702887425);
void pose_F_fun(double *state, double dt, double *out_2534421229889867694);
void pose_h_4(double *state, double *unused, double *out_9104738239612597067);
void pose_H_4(double *state, double *unused, double *out_804775948072585527);
void pose_h_10(double *state, double *unused, double *out_2185381895971378953);
void pose_H_10(double *state, double *unused, double *out_5839728363410394932);
void pose_h_13(double *state, double *unused, double *out_2250384613419215699);
void pose_H_13(double *state, double *unused, double *out_4017049773404918328);
void pose_h_14(double *state, double *unused, double *out_3608499155932113812);
void pose_H_14(double *state, double *unused, double *out_2278012484222786769);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}