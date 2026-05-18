#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_652600290238585961) {
   out_652600290238585961[0] = delta_x[0] + nom_x[0];
   out_652600290238585961[1] = delta_x[1] + nom_x[1];
   out_652600290238585961[2] = delta_x[2] + nom_x[2];
   out_652600290238585961[3] = delta_x[3] + nom_x[3];
   out_652600290238585961[4] = delta_x[4] + nom_x[4];
   out_652600290238585961[5] = delta_x[5] + nom_x[5];
   out_652600290238585961[6] = delta_x[6] + nom_x[6];
   out_652600290238585961[7] = delta_x[7] + nom_x[7];
   out_652600290238585961[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_428056314371954903) {
   out_428056314371954903[0] = -nom_x[0] + true_x[0];
   out_428056314371954903[1] = -nom_x[1] + true_x[1];
   out_428056314371954903[2] = -nom_x[2] + true_x[2];
   out_428056314371954903[3] = -nom_x[3] + true_x[3];
   out_428056314371954903[4] = -nom_x[4] + true_x[4];
   out_428056314371954903[5] = -nom_x[5] + true_x[5];
   out_428056314371954903[6] = -nom_x[6] + true_x[6];
   out_428056314371954903[7] = -nom_x[7] + true_x[7];
   out_428056314371954903[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_636098599351187827) {
   out_636098599351187827[0] = 1.0;
   out_636098599351187827[1] = 0.0;
   out_636098599351187827[2] = 0.0;
   out_636098599351187827[3] = 0.0;
   out_636098599351187827[4] = 0.0;
   out_636098599351187827[5] = 0.0;
   out_636098599351187827[6] = 0.0;
   out_636098599351187827[7] = 0.0;
   out_636098599351187827[8] = 0.0;
   out_636098599351187827[9] = 0.0;
   out_636098599351187827[10] = 1.0;
   out_636098599351187827[11] = 0.0;
   out_636098599351187827[12] = 0.0;
   out_636098599351187827[13] = 0.0;
   out_636098599351187827[14] = 0.0;
   out_636098599351187827[15] = 0.0;
   out_636098599351187827[16] = 0.0;
   out_636098599351187827[17] = 0.0;
   out_636098599351187827[18] = 0.0;
   out_636098599351187827[19] = 0.0;
   out_636098599351187827[20] = 1.0;
   out_636098599351187827[21] = 0.0;
   out_636098599351187827[22] = 0.0;
   out_636098599351187827[23] = 0.0;
   out_636098599351187827[24] = 0.0;
   out_636098599351187827[25] = 0.0;
   out_636098599351187827[26] = 0.0;
   out_636098599351187827[27] = 0.0;
   out_636098599351187827[28] = 0.0;
   out_636098599351187827[29] = 0.0;
   out_636098599351187827[30] = 1.0;
   out_636098599351187827[31] = 0.0;
   out_636098599351187827[32] = 0.0;
   out_636098599351187827[33] = 0.0;
   out_636098599351187827[34] = 0.0;
   out_636098599351187827[35] = 0.0;
   out_636098599351187827[36] = 0.0;
   out_636098599351187827[37] = 0.0;
   out_636098599351187827[38] = 0.0;
   out_636098599351187827[39] = 0.0;
   out_636098599351187827[40] = 1.0;
   out_636098599351187827[41] = 0.0;
   out_636098599351187827[42] = 0.0;
   out_636098599351187827[43] = 0.0;
   out_636098599351187827[44] = 0.0;
   out_636098599351187827[45] = 0.0;
   out_636098599351187827[46] = 0.0;
   out_636098599351187827[47] = 0.0;
   out_636098599351187827[48] = 0.0;
   out_636098599351187827[49] = 0.0;
   out_636098599351187827[50] = 1.0;
   out_636098599351187827[51] = 0.0;
   out_636098599351187827[52] = 0.0;
   out_636098599351187827[53] = 0.0;
   out_636098599351187827[54] = 0.0;
   out_636098599351187827[55] = 0.0;
   out_636098599351187827[56] = 0.0;
   out_636098599351187827[57] = 0.0;
   out_636098599351187827[58] = 0.0;
   out_636098599351187827[59] = 0.0;
   out_636098599351187827[60] = 1.0;
   out_636098599351187827[61] = 0.0;
   out_636098599351187827[62] = 0.0;
   out_636098599351187827[63] = 0.0;
   out_636098599351187827[64] = 0.0;
   out_636098599351187827[65] = 0.0;
   out_636098599351187827[66] = 0.0;
   out_636098599351187827[67] = 0.0;
   out_636098599351187827[68] = 0.0;
   out_636098599351187827[69] = 0.0;
   out_636098599351187827[70] = 1.0;
   out_636098599351187827[71] = 0.0;
   out_636098599351187827[72] = 0.0;
   out_636098599351187827[73] = 0.0;
   out_636098599351187827[74] = 0.0;
   out_636098599351187827[75] = 0.0;
   out_636098599351187827[76] = 0.0;
   out_636098599351187827[77] = 0.0;
   out_636098599351187827[78] = 0.0;
   out_636098599351187827[79] = 0.0;
   out_636098599351187827[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_190909160143243867) {
   out_190909160143243867[0] = state[0];
   out_190909160143243867[1] = state[1];
   out_190909160143243867[2] = state[2];
   out_190909160143243867[3] = state[3];
   out_190909160143243867[4] = state[4];
   out_190909160143243867[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_190909160143243867[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_190909160143243867[7] = state[7];
   out_190909160143243867[8] = state[8];
}
void F_fun(double *state, double dt, double *out_1195327144916471551) {
   out_1195327144916471551[0] = 1;
   out_1195327144916471551[1] = 0;
   out_1195327144916471551[2] = 0;
   out_1195327144916471551[3] = 0;
   out_1195327144916471551[4] = 0;
   out_1195327144916471551[5] = 0;
   out_1195327144916471551[6] = 0;
   out_1195327144916471551[7] = 0;
   out_1195327144916471551[8] = 0;
   out_1195327144916471551[9] = 0;
   out_1195327144916471551[10] = 1;
   out_1195327144916471551[11] = 0;
   out_1195327144916471551[12] = 0;
   out_1195327144916471551[13] = 0;
   out_1195327144916471551[14] = 0;
   out_1195327144916471551[15] = 0;
   out_1195327144916471551[16] = 0;
   out_1195327144916471551[17] = 0;
   out_1195327144916471551[18] = 0;
   out_1195327144916471551[19] = 0;
   out_1195327144916471551[20] = 1;
   out_1195327144916471551[21] = 0;
   out_1195327144916471551[22] = 0;
   out_1195327144916471551[23] = 0;
   out_1195327144916471551[24] = 0;
   out_1195327144916471551[25] = 0;
   out_1195327144916471551[26] = 0;
   out_1195327144916471551[27] = 0;
   out_1195327144916471551[28] = 0;
   out_1195327144916471551[29] = 0;
   out_1195327144916471551[30] = 1;
   out_1195327144916471551[31] = 0;
   out_1195327144916471551[32] = 0;
   out_1195327144916471551[33] = 0;
   out_1195327144916471551[34] = 0;
   out_1195327144916471551[35] = 0;
   out_1195327144916471551[36] = 0;
   out_1195327144916471551[37] = 0;
   out_1195327144916471551[38] = 0;
   out_1195327144916471551[39] = 0;
   out_1195327144916471551[40] = 1;
   out_1195327144916471551[41] = 0;
   out_1195327144916471551[42] = 0;
   out_1195327144916471551[43] = 0;
   out_1195327144916471551[44] = 0;
   out_1195327144916471551[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_1195327144916471551[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_1195327144916471551[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1195327144916471551[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1195327144916471551[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_1195327144916471551[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_1195327144916471551[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_1195327144916471551[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_1195327144916471551[53] = -9.8100000000000005*dt;
   out_1195327144916471551[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_1195327144916471551[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_1195327144916471551[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1195327144916471551[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1195327144916471551[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_1195327144916471551[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_1195327144916471551[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_1195327144916471551[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1195327144916471551[62] = 0;
   out_1195327144916471551[63] = 0;
   out_1195327144916471551[64] = 0;
   out_1195327144916471551[65] = 0;
   out_1195327144916471551[66] = 0;
   out_1195327144916471551[67] = 0;
   out_1195327144916471551[68] = 0;
   out_1195327144916471551[69] = 0;
   out_1195327144916471551[70] = 1;
   out_1195327144916471551[71] = 0;
   out_1195327144916471551[72] = 0;
   out_1195327144916471551[73] = 0;
   out_1195327144916471551[74] = 0;
   out_1195327144916471551[75] = 0;
   out_1195327144916471551[76] = 0;
   out_1195327144916471551[77] = 0;
   out_1195327144916471551[78] = 0;
   out_1195327144916471551[79] = 0;
   out_1195327144916471551[80] = 1;
}
void h_25(double *state, double *unused, double *out_8972033615374819768) {
   out_8972033615374819768[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4267593225833477013) {
   out_4267593225833477013[0] = 0;
   out_4267593225833477013[1] = 0;
   out_4267593225833477013[2] = 0;
   out_4267593225833477013[3] = 0;
   out_4267593225833477013[4] = 0;
   out_4267593225833477013[5] = 0;
   out_4267593225833477013[6] = 1;
   out_4267593225833477013[7] = 0;
   out_4267593225833477013[8] = 0;
}
void h_24(double *state, double *unused, double *out_1619093620334214225) {
   out_1619093620334214225[0] = state[4];
   out_1619093620334214225[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2538730106656162944) {
   out_2538730106656162944[0] = 0;
   out_2538730106656162944[1] = 0;
   out_2538730106656162944[2] = 0;
   out_2538730106656162944[3] = 0;
   out_2538730106656162944[4] = 1;
   out_2538730106656162944[5] = 0;
   out_2538730106656162944[6] = 0;
   out_2538730106656162944[7] = 0;
   out_2538730106656162944[8] = 0;
   out_2538730106656162944[9] = 0;
   out_2538730106656162944[10] = 0;
   out_2538730106656162944[11] = 0;
   out_2538730106656162944[12] = 0;
   out_2538730106656162944[13] = 0;
   out_2538730106656162944[14] = 1;
   out_2538730106656162944[15] = 0;
   out_2538730106656162944[16] = 0;
   out_2538730106656162944[17] = 0;
}
void h_30(double *state, double *unused, double *out_2004718450693787274) {
   out_2004718450693787274[0] = state[4];
}
void H_30(double *state, double *unused, double *out_6785926184340725640) {
   out_6785926184340725640[0] = 0;
   out_6785926184340725640[1] = 0;
   out_6785926184340725640[2] = 0;
   out_6785926184340725640[3] = 0;
   out_6785926184340725640[4] = 1;
   out_6785926184340725640[5] = 0;
   out_6785926184340725640[6] = 0;
   out_6785926184340725640[7] = 0;
   out_6785926184340725640[8] = 0;
}
void h_26(double *state, double *unused, double *out_7006391718354632919) {
   out_7006391718354632919[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7572119195594277614) {
   out_7572119195594277614[0] = 0;
   out_7572119195594277614[1] = 0;
   out_7572119195594277614[2] = 0;
   out_7572119195594277614[3] = 0;
   out_7572119195594277614[4] = 0;
   out_7572119195594277614[5] = 0;
   out_7572119195594277614[6] = 0;
   out_7572119195594277614[7] = 1;
   out_7572119195594277614[8] = 0;
}
void h_27(double *state, double *unused, double *out_4512330460653438616) {
   out_4512330460653438616[0] = state[3];
}
void H_27(double *state, double *unused, double *out_9009520255524668857) {
   out_9009520255524668857[0] = 0;
   out_9009520255524668857[1] = 0;
   out_9009520255524668857[2] = 0;
   out_9009520255524668857[3] = 1;
   out_9009520255524668857[4] = 0;
   out_9009520255524668857[5] = 0;
   out_9009520255524668857[6] = 0;
   out_9009520255524668857[7] = 0;
   out_9009520255524668857[8] = 0;
}
void h_29(double *state, double *unused, double *out_2948228303595449709) {
   out_2948228303595449709[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7296157528655117824) {
   out_7296157528655117824[0] = 0;
   out_7296157528655117824[1] = 1;
   out_7296157528655117824[2] = 0;
   out_7296157528655117824[3] = 0;
   out_7296157528655117824[4] = 0;
   out_7296157528655117824[5] = 0;
   out_7296157528655117824[6] = 0;
   out_7296157528655117824[7] = 0;
   out_7296157528655117824[8] = 0;
}
void h_28(double *state, double *unused, double *out_1907925139844740965) {
   out_1907925139844740965[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2213758511585587250) {
   out_2213758511585587250[0] = 1;
   out_2213758511585587250[1] = 0;
   out_2213758511585587250[2] = 0;
   out_2213758511585587250[3] = 0;
   out_2213758511585587250[4] = 0;
   out_2213758511585587250[5] = 0;
   out_2213758511585587250[6] = 0;
   out_2213758511585587250[7] = 0;
   out_2213758511585587250[8] = 0;
}
void h_31(double *state, double *unused, double *out_332156138656277884) {
   out_332156138656277884[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4298239187710437441) {
   out_4298239187710437441[0] = 0;
   out_4298239187710437441[1] = 0;
   out_4298239187710437441[2] = 0;
   out_4298239187710437441[3] = 0;
   out_4298239187710437441[4] = 0;
   out_4298239187710437441[5] = 0;
   out_4298239187710437441[6] = 0;
   out_4298239187710437441[7] = 0;
   out_4298239187710437441[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_652600290238585961) {
  err_fun(nom_x, delta_x, out_652600290238585961);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_428056314371954903) {
  inv_err_fun(nom_x, true_x, out_428056314371954903);
}
void car_H_mod_fun(double *state, double *out_636098599351187827) {
  H_mod_fun(state, out_636098599351187827);
}
void car_f_fun(double *state, double dt, double *out_190909160143243867) {
  f_fun(state,  dt, out_190909160143243867);
}
void car_F_fun(double *state, double dt, double *out_1195327144916471551) {
  F_fun(state,  dt, out_1195327144916471551);
}
void car_h_25(double *state, double *unused, double *out_8972033615374819768) {
  h_25(state, unused, out_8972033615374819768);
}
void car_H_25(double *state, double *unused, double *out_4267593225833477013) {
  H_25(state, unused, out_4267593225833477013);
}
void car_h_24(double *state, double *unused, double *out_1619093620334214225) {
  h_24(state, unused, out_1619093620334214225);
}
void car_H_24(double *state, double *unused, double *out_2538730106656162944) {
  H_24(state, unused, out_2538730106656162944);
}
void car_h_30(double *state, double *unused, double *out_2004718450693787274) {
  h_30(state, unused, out_2004718450693787274);
}
void car_H_30(double *state, double *unused, double *out_6785926184340725640) {
  H_30(state, unused, out_6785926184340725640);
}
void car_h_26(double *state, double *unused, double *out_7006391718354632919) {
  h_26(state, unused, out_7006391718354632919);
}
void car_H_26(double *state, double *unused, double *out_7572119195594277614) {
  H_26(state, unused, out_7572119195594277614);
}
void car_h_27(double *state, double *unused, double *out_4512330460653438616) {
  h_27(state, unused, out_4512330460653438616);
}
void car_H_27(double *state, double *unused, double *out_9009520255524668857) {
  H_27(state, unused, out_9009520255524668857);
}
void car_h_29(double *state, double *unused, double *out_2948228303595449709) {
  h_29(state, unused, out_2948228303595449709);
}
void car_H_29(double *state, double *unused, double *out_7296157528655117824) {
  H_29(state, unused, out_7296157528655117824);
}
void car_h_28(double *state, double *unused, double *out_1907925139844740965) {
  h_28(state, unused, out_1907925139844740965);
}
void car_H_28(double *state, double *unused, double *out_2213758511585587250) {
  H_28(state, unused, out_2213758511585587250);
}
void car_h_31(double *state, double *unused, double *out_332156138656277884) {
  h_31(state, unused, out_332156138656277884);
}
void car_H_31(double *state, double *unused, double *out_4298239187710437441) {
  H_31(state, unused, out_4298239187710437441);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
