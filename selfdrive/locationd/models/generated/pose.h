#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2383575066684203465);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2531792213831641268);
void pose_H_mod_fun(double *state, double *out_5270168453751144292);
void pose_f_fun(double *state, double dt, double *out_5870118476100851027);
void pose_F_fun(double *state, double dt, double *out_6643036112755764466);
void pose_h_4(double *state, double *unused, double *out_3825151169355500496);
void pose_H_4(double *state, double *unused, double *out_4438379387875418186);
void pose_h_10(double *state, double *unused, double *out_6180343716098328505);
void pose_H_10(double *state, double *unused, double *out_6436902649839043686);
void pose_h_13(double *state, double *unused, double *out_5615804281251360017);
void pose_H_13(double *state, double *unused, double *out_8272134851177942210);
void pose_h_14(double *state, double *unused, double *out_1282457731118130678);
void pose_H_14(double *state, double *unused, double *out_7521167820170790482);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}