#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1942165964233553274);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2238116153961167505);
void pose_H_mod_fun(double *state, double *out_4990084456757481789);
void pose_f_fun(double *state, double dt, double *out_6296202895308932040);
void pose_F_fun(double *state, double dt, double *out_909355394007943716);
void pose_h_4(double *state, double *unused, double *out_6818977063477642683);
void pose_H_4(double *state, double *unused, double *out_3954277209300339553);
void pose_h_10(double *state, double *unused, double *out_3834013708689822319);
void pose_H_10(double *state, double *unused, double *out_3533519720904001040);
void pose_h_13(double *state, double *unused, double *out_3025354993842492520);
void pose_H_13(double *state, double *unused, double *out_3389675289618495449);
void pose_h_14(double *state, double *unused, double *out_278507277292912803);
void pose_H_14(double *state, double *unused, double *out_7037065641595711849);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}