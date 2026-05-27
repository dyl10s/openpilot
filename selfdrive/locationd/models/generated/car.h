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
void car_err_fun(double *nom_x, double *delta_x, double *out_7026316075073471994);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4587773260780687079);
void car_H_mod_fun(double *state, double *out_255548955770617621);
void car_f_fun(double *state, double dt, double *out_5905678958362697737);
void car_F_fun(double *state, double dt, double *out_2348542156060617804);
void car_h_25(double *state, double *unused, double *out_5870924613014703511);
void car_H_25(double *state, double *unused, double *out_7665789077203242184);
void car_h_24(double *state, double *unused, double *out_7175962086981114995);
void car_H_24(double *state, double *unused, double *out_2919279750236733150);
void car_h_30(double *state, double *unused, double *out_619120766018658974);
void car_H_30(double *state, double *unused, double *out_8262622037999060805);
void car_h_26(double *state, double *unused, double *out_2561596907152652789);
void car_H_26(double *state, double *unused, double *out_3924285758329185960);
void car_h_27(double *state, double *unused, double *out_6474240497691181028);
void car_H_27(double *state, double *unused, double *out_6039027966815117588);
void car_h_29(double *state, double *unused, double *out_5627330291441514494);
void car_H_29(double *state, double *unused, double *out_7752390693684668621);
void car_h_28(double *state, double *unused, double *out_3437454446246848343);
void car_H_28(double *state, double *unused, double *out_5611954362955352421);
void car_h_31(double *state, double *unused, double *out_556316564325718304);
void car_H_31(double *state, double *unused, double *out_3298077656095834484);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}