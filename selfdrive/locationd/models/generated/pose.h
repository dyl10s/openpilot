#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7641933708620610052);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_9128860405088658984);
void pose_H_mod_fun(double *state, double *out_3103725176518788441);
void pose_f_fun(double *state, double dt, double *out_5259001848744899041);
void pose_F_fun(double *state, double dt, double *out_6765250644485775616);
void pose_h_4(double *state, double *unused, double *out_6349780411594345580);
void pose_H_4(double *state, double *unused, double *out_4301672658401686545);
void pose_h_10(double *state, double *unused, double *out_1522297241205058892);
void pose_H_10(double *state, double *unused, double *out_2231099772160491337);
void pose_h_13(double *state, double *unused, double *out_9186389196897638740);
void pose_H_13(double *state, double *unused, double *out_7513946483734019346);
void pose_h_14(double *state, double *unused, double *out_60031468009030950);
void pose_H_14(double *state, double *unused, double *out_1218884226106314249);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}