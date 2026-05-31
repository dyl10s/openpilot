#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_6119760954545072171);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3032957791392119605);
void car_H_mod_fun(double *state, double *out_6225772227410316778);
void car_f_fun(double *state, double dt, double *out_1791723405675881227);
void car_F_fun(double *state, double dt, double *out_4540850954218753986);
void car_h_25(double *state, double *unused, double *out_6713287060643499630);
void car_H_25(double *state, double *unused, double *out_2967415998501920459);
void car_h_24(double *state, double *unused, double *out_7006841003408788110);
void car_H_24(double *state, double *unused, double *out_5140065597507420025);
void car_h_30(double *state, double *unused, double *out_57548165706851306);
void car_H_30(double *state, double *unused, double *out_449083039994671832);
void car_h_26(double *state, double *unused, double *out_5284319070179179257);
void car_H_26(double *state, double *unused, double *out_6708919317375976683);
void car_h_27(double *state, double *unused, double *out_2937147548800054846);
void car_H_27(double *state, double *unused, double *out_2623846351795096743);
void car_h_29(double *state, double *unused, double *out_3094334217151183991);
void car_H_29(double *state, double *unused, double *out_61148304319720352);
void car_h_28(double *state, double *unused, double *out_2064525718860790799);
void car_H_28(double *state, double *unused, double *out_5021250712749810222);
void car_h_31(double *state, double *unused, double *out_6870473728994628775);
void car_H_31(double *state, double *unused, double *out_7335127419609328159);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}