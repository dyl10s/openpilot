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
void car_err_fun(double *nom_x, double *delta_x, double *out_8250891246740759679);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6699306425357192023);
void car_H_mod_fun(double *state, double *out_2914898107951165883);
void car_f_fun(double *state, double dt, double *out_2675178968316523152);
void car_F_fun(double *state, double dt, double *out_5308189961048980992);
void car_h_25(double *state, double *unused, double *out_6353754508244043817);
void car_H_25(double *state, double *unused, double *out_6338657739846148496);
void car_h_24(double *state, double *unused, double *out_2065669686396091997);
void car_H_24(double *state, double *unused, double *out_1518336235190160233);
void car_h_30(double *state, double *unused, double *out_4759906320160358758);
void car_H_30(double *state, double *unused, double *out_6209318792702908426);
void car_h_26(double *state, double *unused, double *out_163294403103182073);
void car_H_26(double *state, double *unused, double *out_2597154420972092272);
void car_h_27(double *state, double *unused, double *out_45287009169805329);
void car_H_27(double *state, double *unused, double *out_4034555480902483515);
void car_h_29(double *state, double *unused, double *out_4143590307449177193);
void car_H_29(double *state, double *unused, double *out_6719550137017300610);
void car_h_28(double *state, double *unused, double *out_8542875672635036079);
void car_H_28(double *state, double *unused, double *out_1637151119947770036);
void car_h_31(double *state, double *unused, double *out_5322154339115156863);
void car_H_31(double *state, double *unused, double *out_6369303701723108924);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}