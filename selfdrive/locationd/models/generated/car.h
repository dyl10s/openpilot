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
void car_err_fun(double *nom_x, double *delta_x, double *out_2814030462933274886);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1640667606358073333);
void car_H_mod_fun(double *state, double *out_1064503278714903732);
void car_f_fun(double *state, double dt, double *out_4383566153016226252);
void car_F_fun(double *state, double dt, double *out_5929650816649805655);
void car_h_25(double *state, double *unused, double *out_257622994030229427);
void car_H_25(double *state, double *unused, double *out_1569837720915200444);
void car_h_24(double *state, double *unused, double *out_5563077321127263871);
void car_H_24(double *state, double *unused, double *out_1474479489089147748);
void car_h_30(double *state, double *unused, double *out_3604060482398272225);
void car_H_30(double *state, double *unused, double *out_1440498773771960374);
void car_h_26(double *state, double *unused, double *out_5860714419304438626);
void car_H_26(double *state, double *unused, double *out_2171665597958855780);
void car_h_27(double *state, double *unused, double *out_8762920418410247015);
void car_H_27(double *state, double *unused, double *out_734264538028464537);
void car_h_29(double *state, double *unused, double *out_8605733750059117870);
void car_H_29(double *state, double *unused, double *out_1950730118086352558);
void car_h_28(double *state, double *unused, double *out_1327776983981546202);
void car_H_28(double *state, double *unused, double *out_3914360389651678809);
void car_h_31(double *state, double *unused, double *out_7224938158711261921);
void car_H_31(double *state, double *unused, double *out_1600483682792160872);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}