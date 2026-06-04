#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2822233615381903085);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_3556797172859207138);
void pose_H_mod_fun(double *state, double *out_4158952900173024917);
void pose_f_fun(double *state, double dt, double *out_4480310224533440205);
void pose_F_fun(double *state, double dt, double *out_2252133042369597057);
void pose_h_4(double *state, double *unused, double *out_1225931617160521679);
void pose_H_4(double *state, double *unused, double *out_3404791898118312310);
void pose_h_10(double *state, double *unused, double *out_8314558572170779017);
void pose_H_10(double *state, double *unused, double *out_3543553484029179274);
void pose_h_13(double *state, double *unused, double *out_7492025966781743409);
void pose_H_13(double *state, double *unused, double *out_4205839310198388619);
void pose_h_14(double *state, double *unused, double *out_8444019918627598165);
void pose_H_14(double *state, double *unused, double *out_6487580330413684606);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}