#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4833077353004324467);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4980437301453189923);
void pose_H_mod_fun(double *state, double *out_4718726566615345673);
void pose_f_fun(double *state, double dt, double *out_2093259032196707743);
void pose_F_fun(double *state, double dt, double *out_7597852127146355968);
void pose_h_4(double *state, double *unused, double *out_89080864518885864);
void pose_H_4(double *state, double *unused, double *out_946919356771438101);
void pose_h_10(double *state, double *unused, double *out_2699740651616676276);
void pose_H_10(double *state, double *unused, double *out_8679455089612648559);
void pose_h_13(double *state, double *unused, double *out_622335723485041042);
void pose_H_13(double *state, double *unused, double *out_2265354468560894700);
void pose_h_14(double *state, double *unused, double *out_299516174209740344);
void pose_H_14(double *state, double *unused, double *out_3016321499568046428);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}