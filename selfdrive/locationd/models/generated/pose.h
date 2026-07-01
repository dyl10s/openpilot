#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5567810526154209734);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7908491346196944566);
void pose_H_mod_fun(double *state, double *out_1058329813454059053);
void pose_f_fun(double *state, double dt, double *out_6164632031260569200);
void pose_F_fun(double *state, double dt, double *out_2115210801735647822);
void pose_h_4(double *state, double *unused, double *out_5340316977089833419);
void pose_H_4(double *state, double *unused, double *out_4789751993297899668);
void pose_h_10(double *state, double *unused, double *out_4503836725223465124);
void pose_H_10(double *state, double *unused, double *out_8320315452592553094);
void pose_h_13(double *state, double *unused, double *out_743896610209905980);
void pose_H_13(double *state, double *unused, double *out_1577478167965566867);
void pose_h_14(double *state, double *unused, double *out_2801914335576561864);
void pose_H_14(double *state, double *unused, double *out_826511136958415139);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}