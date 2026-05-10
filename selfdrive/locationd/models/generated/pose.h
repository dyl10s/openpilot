#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_7993353667610184364);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_533608207331381553);
void pose_H_mod_fun(double *state, double *out_5230913290931847385);
void pose_f_fun(double *state, double dt, double *out_60436790132025778);
void pose_F_fun(double *state, double dt, double *out_8562706762949720732);
void pose_h_4(double *state, double *unused, double *out_493571647291527942);
void pose_H_4(double *state, double *unused, double *out_6428860772814745489);
void pose_h_10(double *state, double *unused, double *out_7477536671061017990);
void pose_H_10(double *state, double *unused, double *out_3483601252945400253);
void pose_h_13(double *state, double *unused, double *out_2889929992082413223);
void pose_H_13(double *state, double *unused, double *out_8805609475562473326);
void pose_h_14(double *state, double *unused, double *out_207203314381018955);
void pose_H_14(double *state, double *unused, double *out_3346072340519373193);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}