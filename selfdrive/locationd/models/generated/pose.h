#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_9044617002367965712);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2986388781113821274);
void pose_H_mod_fun(double *state, double *out_5449976102936300367);
void pose_f_fun(double *state, double dt, double *out_2001314774583974236);
void pose_F_fun(double *state, double dt, double *out_173210708380746968);
void pose_h_4(double *state, double *unused, double *out_4290451809527946304);
void pose_H_4(double *state, double *unused, double *out_4695815100881587760);
void pose_h_10(double *state, double *unused, double *out_6723857678965398132);
void pose_H_10(double *state, double *unused, double *out_984080189925557249);
void pose_h_13(double *state, double *unused, double *out_1838091537859337419);
void pose_H_13(double *state, double *unused, double *out_1483541275549254959);
void pose_h_14(double *state, double *unused, double *out_849503921054780572);
void pose_H_14(double *state, double *unused, double *out_732574244542103231);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}