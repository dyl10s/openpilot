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
void car_err_fun(double *nom_x, double *delta_x, double *out_787387508528698300);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4326351974821968285);
void car_H_mod_fun(double *state, double *out_253192225752308971);
void car_f_fun(double *state, double dt, double *out_7053536604478710960);
void car_F_fun(double *state, double dt, double *out_1214429005669720164);
void car_h_25(double *state, double *unused, double *out_3464829860448870764);
void car_H_25(double *state, double *unused, double *out_9000363622045005408);
void car_h_24(double *state, double *unused, double *out_4762731858686047091);
void car_H_24(double *state, double *unused, double *out_6827714023039505842);
void car_h_30(double *state, double *unused, double *out_3738386096537115206);
void car_H_30(double *state, double *unused, double *out_6928047493157297581);
void car_h_26(double *state, double *unused, double *out_3696757337891585607);
void car_H_26(double *state, double *unused, double *out_6141854481903745607);
void car_h_27(double *state, double *unused, double *out_8319345477692799991);
void car_H_27(double *state, double *unused, double *out_4704453421973354364);
void car_h_29(double *state, double *unused, double *out_6118557469171333555);
void car_H_29(double *state, double *unused, double *out_6417816148842905397);
void car_h_28(double *state, double *unused, double *out_5845834754773091117);
void car_H_28(double *state, double *unused, double *out_6946528907797115645);
void car_h_31(double *state, double *unused, double *out_3122998066027424399);
void car_H_31(double *state, double *unused, double *out_6768062584137097083);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}