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
void err_fun(double *nom_x, double *delta_x, double *out_3281150270443704084) {
   out_3281150270443704084[0] = delta_x[0] + nom_x[0];
   out_3281150270443704084[1] = delta_x[1] + nom_x[1];
   out_3281150270443704084[2] = delta_x[2] + nom_x[2];
   out_3281150270443704084[3] = delta_x[3] + nom_x[3];
   out_3281150270443704084[4] = delta_x[4] + nom_x[4];
   out_3281150270443704084[5] = delta_x[5] + nom_x[5];
   out_3281150270443704084[6] = delta_x[6] + nom_x[6];
   out_3281150270443704084[7] = delta_x[7] + nom_x[7];
   out_3281150270443704084[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3048073845424101937) {
   out_3048073845424101937[0] = -nom_x[0] + true_x[0];
   out_3048073845424101937[1] = -nom_x[1] + true_x[1];
   out_3048073845424101937[2] = -nom_x[2] + true_x[2];
   out_3048073845424101937[3] = -nom_x[3] + true_x[3];
   out_3048073845424101937[4] = -nom_x[4] + true_x[4];
   out_3048073845424101937[5] = -nom_x[5] + true_x[5];
   out_3048073845424101937[6] = -nom_x[6] + true_x[6];
   out_3048073845424101937[7] = -nom_x[7] + true_x[7];
   out_3048073845424101937[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5861733525303608227) {
   out_5861733525303608227[0] = 1.0;
   out_5861733525303608227[1] = 0.0;
   out_5861733525303608227[2] = 0.0;
   out_5861733525303608227[3] = 0.0;
   out_5861733525303608227[4] = 0.0;
   out_5861733525303608227[5] = 0.0;
   out_5861733525303608227[6] = 0.0;
   out_5861733525303608227[7] = 0.0;
   out_5861733525303608227[8] = 0.0;
   out_5861733525303608227[9] = 0.0;
   out_5861733525303608227[10] = 1.0;
   out_5861733525303608227[11] = 0.0;
   out_5861733525303608227[12] = 0.0;
   out_5861733525303608227[13] = 0.0;
   out_5861733525303608227[14] = 0.0;
   out_5861733525303608227[15] = 0.0;
   out_5861733525303608227[16] = 0.0;
   out_5861733525303608227[17] = 0.0;
   out_5861733525303608227[18] = 0.0;
   out_5861733525303608227[19] = 0.0;
   out_5861733525303608227[20] = 1.0;
   out_5861733525303608227[21] = 0.0;
   out_5861733525303608227[22] = 0.0;
   out_5861733525303608227[23] = 0.0;
   out_5861733525303608227[24] = 0.0;
   out_5861733525303608227[25] = 0.0;
   out_5861733525303608227[26] = 0.0;
   out_5861733525303608227[27] = 0.0;
   out_5861733525303608227[28] = 0.0;
   out_5861733525303608227[29] = 0.0;
   out_5861733525303608227[30] = 1.0;
   out_5861733525303608227[31] = 0.0;
   out_5861733525303608227[32] = 0.0;
   out_5861733525303608227[33] = 0.0;
   out_5861733525303608227[34] = 0.0;
   out_5861733525303608227[35] = 0.0;
   out_5861733525303608227[36] = 0.0;
   out_5861733525303608227[37] = 0.0;
   out_5861733525303608227[38] = 0.0;
   out_5861733525303608227[39] = 0.0;
   out_5861733525303608227[40] = 1.0;
   out_5861733525303608227[41] = 0.0;
   out_5861733525303608227[42] = 0.0;
   out_5861733525303608227[43] = 0.0;
   out_5861733525303608227[44] = 0.0;
   out_5861733525303608227[45] = 0.0;
   out_5861733525303608227[46] = 0.0;
   out_5861733525303608227[47] = 0.0;
   out_5861733525303608227[48] = 0.0;
   out_5861733525303608227[49] = 0.0;
   out_5861733525303608227[50] = 1.0;
   out_5861733525303608227[51] = 0.0;
   out_5861733525303608227[52] = 0.0;
   out_5861733525303608227[53] = 0.0;
   out_5861733525303608227[54] = 0.0;
   out_5861733525303608227[55] = 0.0;
   out_5861733525303608227[56] = 0.0;
   out_5861733525303608227[57] = 0.0;
   out_5861733525303608227[58] = 0.0;
   out_5861733525303608227[59] = 0.0;
   out_5861733525303608227[60] = 1.0;
   out_5861733525303608227[61] = 0.0;
   out_5861733525303608227[62] = 0.0;
   out_5861733525303608227[63] = 0.0;
   out_5861733525303608227[64] = 0.0;
   out_5861733525303608227[65] = 0.0;
   out_5861733525303608227[66] = 0.0;
   out_5861733525303608227[67] = 0.0;
   out_5861733525303608227[68] = 0.0;
   out_5861733525303608227[69] = 0.0;
   out_5861733525303608227[70] = 1.0;
   out_5861733525303608227[71] = 0.0;
   out_5861733525303608227[72] = 0.0;
   out_5861733525303608227[73] = 0.0;
   out_5861733525303608227[74] = 0.0;
   out_5861733525303608227[75] = 0.0;
   out_5861733525303608227[76] = 0.0;
   out_5861733525303608227[77] = 0.0;
   out_5861733525303608227[78] = 0.0;
   out_5861733525303608227[79] = 0.0;
   out_5861733525303608227[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6520674902136446798) {
   out_6520674902136446798[0] = state[0];
   out_6520674902136446798[1] = state[1];
   out_6520674902136446798[2] = state[2];
   out_6520674902136446798[3] = state[3];
   out_6520674902136446798[4] = state[4];
   out_6520674902136446798[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6520674902136446798[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6520674902136446798[7] = state[7];
   out_6520674902136446798[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2036702211381872187) {
   out_2036702211381872187[0] = 1;
   out_2036702211381872187[1] = 0;
   out_2036702211381872187[2] = 0;
   out_2036702211381872187[3] = 0;
   out_2036702211381872187[4] = 0;
   out_2036702211381872187[5] = 0;
   out_2036702211381872187[6] = 0;
   out_2036702211381872187[7] = 0;
   out_2036702211381872187[8] = 0;
   out_2036702211381872187[9] = 0;
   out_2036702211381872187[10] = 1;
   out_2036702211381872187[11] = 0;
   out_2036702211381872187[12] = 0;
   out_2036702211381872187[13] = 0;
   out_2036702211381872187[14] = 0;
   out_2036702211381872187[15] = 0;
   out_2036702211381872187[16] = 0;
   out_2036702211381872187[17] = 0;
   out_2036702211381872187[18] = 0;
   out_2036702211381872187[19] = 0;
   out_2036702211381872187[20] = 1;
   out_2036702211381872187[21] = 0;
   out_2036702211381872187[22] = 0;
   out_2036702211381872187[23] = 0;
   out_2036702211381872187[24] = 0;
   out_2036702211381872187[25] = 0;
   out_2036702211381872187[26] = 0;
   out_2036702211381872187[27] = 0;
   out_2036702211381872187[28] = 0;
   out_2036702211381872187[29] = 0;
   out_2036702211381872187[30] = 1;
   out_2036702211381872187[31] = 0;
   out_2036702211381872187[32] = 0;
   out_2036702211381872187[33] = 0;
   out_2036702211381872187[34] = 0;
   out_2036702211381872187[35] = 0;
   out_2036702211381872187[36] = 0;
   out_2036702211381872187[37] = 0;
   out_2036702211381872187[38] = 0;
   out_2036702211381872187[39] = 0;
   out_2036702211381872187[40] = 1;
   out_2036702211381872187[41] = 0;
   out_2036702211381872187[42] = 0;
   out_2036702211381872187[43] = 0;
   out_2036702211381872187[44] = 0;
   out_2036702211381872187[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2036702211381872187[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2036702211381872187[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2036702211381872187[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2036702211381872187[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2036702211381872187[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2036702211381872187[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2036702211381872187[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2036702211381872187[53] = -9.8100000000000005*dt;
   out_2036702211381872187[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2036702211381872187[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2036702211381872187[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2036702211381872187[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2036702211381872187[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2036702211381872187[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2036702211381872187[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2036702211381872187[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2036702211381872187[62] = 0;
   out_2036702211381872187[63] = 0;
   out_2036702211381872187[64] = 0;
   out_2036702211381872187[65] = 0;
   out_2036702211381872187[66] = 0;
   out_2036702211381872187[67] = 0;
   out_2036702211381872187[68] = 0;
   out_2036702211381872187[69] = 0;
   out_2036702211381872187[70] = 1;
   out_2036702211381872187[71] = 0;
   out_2036702211381872187[72] = 0;
   out_2036702211381872187[73] = 0;
   out_2036702211381872187[74] = 0;
   out_2036702211381872187[75] = 0;
   out_2036702211381872187[76] = 0;
   out_2036702211381872187[77] = 0;
   out_2036702211381872187[78] = 0;
   out_2036702211381872187[79] = 0;
   out_2036702211381872187[80] = 1;
}
void h_25(double *state, double *unused, double *out_7733856010300149046) {
   out_7733856010300149046[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6810854447332090436) {
   out_6810854447332090436[0] = 0;
   out_6810854447332090436[1] = 0;
   out_6810854447332090436[2] = 0;
   out_6810854447332090436[3] = 0;
   out_6810854447332090436[4] = 0;
   out_6810854447332090436[5] = 0;
   out_6810854447332090436[6] = 1;
   out_6810854447332090436[7] = 0;
   out_6810854447332090436[8] = 0;
}
void h_24(double *state, double *unused, double *out_8048847696560640687) {
   out_8048847696560640687[0] = state[4];
   out_8048847696560640687[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2407824440308265955) {
   out_2407824440308265955[0] = 0;
   out_2407824440308265955[1] = 0;
   out_2407824440308265955[2] = 0;
   out_2407824440308265955[3] = 0;
   out_2407824440308265955[4] = 1;
   out_2407824440308265955[5] = 0;
   out_2407824440308265955[6] = 0;
   out_2407824440308265955[7] = 0;
   out_2407824440308265955[8] = 0;
   out_2407824440308265955[9] = 0;
   out_2407824440308265955[10] = 0;
   out_2407824440308265955[11] = 0;
   out_2407824440308265955[12] = 0;
   out_2407824440308265955[13] = 0;
   out_2407824440308265955[14] = 1;
   out_2407824440308265955[15] = 0;
   out_2407824440308265955[16] = 0;
   out_2407824440308265955[17] = 0;
}
void h_30(double *state, double *unused, double *out_7458661948015643157) {
   out_7458661948015643157[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2283158117204482238) {
   out_2283158117204482238[0] = 0;
   out_2283158117204482238[1] = 0;
   out_2283158117204482238[2] = 0;
   out_2283158117204482238[3] = 0;
   out_2283158117204482238[4] = 1;
   out_2283158117204482238[5] = 0;
   out_2283158117204482238[6] = 0;
   out_2283158117204482238[7] = 0;
   out_2283158117204482238[8] = 0;
}
void h_26(double *state, double *unused, double *out_5109796638135193371) {
   out_5109796638135193371[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3069351128458034212) {
   out_3069351128458034212[0] = 0;
   out_3069351128458034212[1] = 0;
   out_3069351128458034212[2] = 0;
   out_3069351128458034212[3] = 0;
   out_3069351128458034212[4] = 0;
   out_3069351128458034212[5] = 0;
   out_3069351128458034212[6] = 0;
   out_3069351128458034212[7] = 1;
   out_3069351128458034212[8] = 0;
}
void h_27(double *state, double *unused, double *out_2732182742639303401) {
   out_2732182742639303401[0] = state[3];
}
void H_27(double *state, double *unused, double *out_108394805404057327) {
   out_108394805404057327[0] = 0;
   out_108394805404057327[1] = 0;
   out_108394805404057327[2] = 0;
   out_108394805404057327[3] = 1;
   out_108394805404057327[4] = 0;
   out_108394805404057327[5] = 0;
   out_108394805404057327[6] = 0;
   out_108394805404057327[7] = 0;
   out_108394805404057327[8] = 0;
}
void h_29(double *state, double *unused, double *out_1129500733789198251) {
   out_1129500733789198251[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2793389461518874422) {
   out_2793389461518874422[0] = 0;
   out_2793389461518874422[1] = 1;
   out_2793389461518874422[2] = 0;
   out_2793389461518874422[3] = 0;
   out_2793389461518874422[4] = 0;
   out_2793389461518874422[5] = 0;
   out_2793389461518874422[6] = 0;
   out_2793389461518874422[7] = 0;
   out_2793389461518874422[8] = 0;
}
void h_28(double *state, double *unused, double *out_4422630577374984361) {
   out_4422630577374984361[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2289009555550656152) {
   out_2289009555550656152[0] = 1;
   out_2289009555550656152[1] = 0;
   out_2289009555550656152[2] = 0;
   out_2289009555550656152[3] = 0;
   out_2289009555550656152[4] = 0;
   out_2289009555550656152[5] = 0;
   out_2289009555550656152[6] = 0;
   out_2289009555550656152[7] = 0;
   out_2289009555550656152[8] = 0;
}
void h_31(double *state, double *unused, double *out_7765162073053917609) {
   out_7765162073053917609[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2443143026224682736) {
   out_2443143026224682736[0] = 0;
   out_2443143026224682736[1] = 0;
   out_2443143026224682736[2] = 0;
   out_2443143026224682736[3] = 0;
   out_2443143026224682736[4] = 0;
   out_2443143026224682736[5] = 0;
   out_2443143026224682736[6] = 0;
   out_2443143026224682736[7] = 0;
   out_2443143026224682736[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3281150270443704084) {
  err_fun(nom_x, delta_x, out_3281150270443704084);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3048073845424101937) {
  inv_err_fun(nom_x, true_x, out_3048073845424101937);
}
void car_H_mod_fun(double *state, double *out_5861733525303608227) {
  H_mod_fun(state, out_5861733525303608227);
}
void car_f_fun(double *state, double dt, double *out_6520674902136446798) {
  f_fun(state,  dt, out_6520674902136446798);
}
void car_F_fun(double *state, double dt, double *out_2036702211381872187) {
  F_fun(state,  dt, out_2036702211381872187);
}
void car_h_25(double *state, double *unused, double *out_7733856010300149046) {
  h_25(state, unused, out_7733856010300149046);
}
void car_H_25(double *state, double *unused, double *out_6810854447332090436) {
  H_25(state, unused, out_6810854447332090436);
}
void car_h_24(double *state, double *unused, double *out_8048847696560640687) {
  h_24(state, unused, out_8048847696560640687);
}
void car_H_24(double *state, double *unused, double *out_2407824440308265955) {
  H_24(state, unused, out_2407824440308265955);
}
void car_h_30(double *state, double *unused, double *out_7458661948015643157) {
  h_30(state, unused, out_7458661948015643157);
}
void car_H_30(double *state, double *unused, double *out_2283158117204482238) {
  H_30(state, unused, out_2283158117204482238);
}
void car_h_26(double *state, double *unused, double *out_5109796638135193371) {
  h_26(state, unused, out_5109796638135193371);
}
void car_H_26(double *state, double *unused, double *out_3069351128458034212) {
  H_26(state, unused, out_3069351128458034212);
}
void car_h_27(double *state, double *unused, double *out_2732182742639303401) {
  h_27(state, unused, out_2732182742639303401);
}
void car_H_27(double *state, double *unused, double *out_108394805404057327) {
  H_27(state, unused, out_108394805404057327);
}
void car_h_29(double *state, double *unused, double *out_1129500733789198251) {
  h_29(state, unused, out_1129500733789198251);
}
void car_H_29(double *state, double *unused, double *out_2793389461518874422) {
  H_29(state, unused, out_2793389461518874422);
}
void car_h_28(double *state, double *unused, double *out_4422630577374984361) {
  h_28(state, unused, out_4422630577374984361);
}
void car_H_28(double *state, double *unused, double *out_2289009555550656152) {
  H_28(state, unused, out_2289009555550656152);
}
void car_h_31(double *state, double *unused, double *out_7765162073053917609) {
  h_31(state, unused, out_7765162073053917609);
}
void car_H_31(double *state, double *unused, double *out_2443143026224682736) {
  H_31(state, unused, out_2443143026224682736);
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
