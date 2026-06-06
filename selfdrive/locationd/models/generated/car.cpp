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
void err_fun(double *nom_x, double *delta_x, double *out_6669412735228971409) {
   out_6669412735228971409[0] = delta_x[0] + nom_x[0];
   out_6669412735228971409[1] = delta_x[1] + nom_x[1];
   out_6669412735228971409[2] = delta_x[2] + nom_x[2];
   out_6669412735228971409[3] = delta_x[3] + nom_x[3];
   out_6669412735228971409[4] = delta_x[4] + nom_x[4];
   out_6669412735228971409[5] = delta_x[5] + nom_x[5];
   out_6669412735228971409[6] = delta_x[6] + nom_x[6];
   out_6669412735228971409[7] = delta_x[7] + nom_x[7];
   out_6669412735228971409[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6779967762183071907) {
   out_6779967762183071907[0] = -nom_x[0] + true_x[0];
   out_6779967762183071907[1] = -nom_x[1] + true_x[1];
   out_6779967762183071907[2] = -nom_x[2] + true_x[2];
   out_6779967762183071907[3] = -nom_x[3] + true_x[3];
   out_6779967762183071907[4] = -nom_x[4] + true_x[4];
   out_6779967762183071907[5] = -nom_x[5] + true_x[5];
   out_6779967762183071907[6] = -nom_x[6] + true_x[6];
   out_6779967762183071907[7] = -nom_x[7] + true_x[7];
   out_6779967762183071907[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6491699675187271682) {
   out_6491699675187271682[0] = 1.0;
   out_6491699675187271682[1] = 0.0;
   out_6491699675187271682[2] = 0.0;
   out_6491699675187271682[3] = 0.0;
   out_6491699675187271682[4] = 0.0;
   out_6491699675187271682[5] = 0.0;
   out_6491699675187271682[6] = 0.0;
   out_6491699675187271682[7] = 0.0;
   out_6491699675187271682[8] = 0.0;
   out_6491699675187271682[9] = 0.0;
   out_6491699675187271682[10] = 1.0;
   out_6491699675187271682[11] = 0.0;
   out_6491699675187271682[12] = 0.0;
   out_6491699675187271682[13] = 0.0;
   out_6491699675187271682[14] = 0.0;
   out_6491699675187271682[15] = 0.0;
   out_6491699675187271682[16] = 0.0;
   out_6491699675187271682[17] = 0.0;
   out_6491699675187271682[18] = 0.0;
   out_6491699675187271682[19] = 0.0;
   out_6491699675187271682[20] = 1.0;
   out_6491699675187271682[21] = 0.0;
   out_6491699675187271682[22] = 0.0;
   out_6491699675187271682[23] = 0.0;
   out_6491699675187271682[24] = 0.0;
   out_6491699675187271682[25] = 0.0;
   out_6491699675187271682[26] = 0.0;
   out_6491699675187271682[27] = 0.0;
   out_6491699675187271682[28] = 0.0;
   out_6491699675187271682[29] = 0.0;
   out_6491699675187271682[30] = 1.0;
   out_6491699675187271682[31] = 0.0;
   out_6491699675187271682[32] = 0.0;
   out_6491699675187271682[33] = 0.0;
   out_6491699675187271682[34] = 0.0;
   out_6491699675187271682[35] = 0.0;
   out_6491699675187271682[36] = 0.0;
   out_6491699675187271682[37] = 0.0;
   out_6491699675187271682[38] = 0.0;
   out_6491699675187271682[39] = 0.0;
   out_6491699675187271682[40] = 1.0;
   out_6491699675187271682[41] = 0.0;
   out_6491699675187271682[42] = 0.0;
   out_6491699675187271682[43] = 0.0;
   out_6491699675187271682[44] = 0.0;
   out_6491699675187271682[45] = 0.0;
   out_6491699675187271682[46] = 0.0;
   out_6491699675187271682[47] = 0.0;
   out_6491699675187271682[48] = 0.0;
   out_6491699675187271682[49] = 0.0;
   out_6491699675187271682[50] = 1.0;
   out_6491699675187271682[51] = 0.0;
   out_6491699675187271682[52] = 0.0;
   out_6491699675187271682[53] = 0.0;
   out_6491699675187271682[54] = 0.0;
   out_6491699675187271682[55] = 0.0;
   out_6491699675187271682[56] = 0.0;
   out_6491699675187271682[57] = 0.0;
   out_6491699675187271682[58] = 0.0;
   out_6491699675187271682[59] = 0.0;
   out_6491699675187271682[60] = 1.0;
   out_6491699675187271682[61] = 0.0;
   out_6491699675187271682[62] = 0.0;
   out_6491699675187271682[63] = 0.0;
   out_6491699675187271682[64] = 0.0;
   out_6491699675187271682[65] = 0.0;
   out_6491699675187271682[66] = 0.0;
   out_6491699675187271682[67] = 0.0;
   out_6491699675187271682[68] = 0.0;
   out_6491699675187271682[69] = 0.0;
   out_6491699675187271682[70] = 1.0;
   out_6491699675187271682[71] = 0.0;
   out_6491699675187271682[72] = 0.0;
   out_6491699675187271682[73] = 0.0;
   out_6491699675187271682[74] = 0.0;
   out_6491699675187271682[75] = 0.0;
   out_6491699675187271682[76] = 0.0;
   out_6491699675187271682[77] = 0.0;
   out_6491699675187271682[78] = 0.0;
   out_6491699675187271682[79] = 0.0;
   out_6491699675187271682[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2858314681790673269) {
   out_2858314681790673269[0] = state[0];
   out_2858314681790673269[1] = state[1];
   out_2858314681790673269[2] = state[2];
   out_2858314681790673269[3] = state[3];
   out_2858314681790673269[4] = state[4];
   out_2858314681790673269[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2858314681790673269[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2858314681790673269[7] = state[7];
   out_2858314681790673269[8] = state[8];
}
void F_fun(double *state, double dt, double *out_1519249616957804461) {
   out_1519249616957804461[0] = 1;
   out_1519249616957804461[1] = 0;
   out_1519249616957804461[2] = 0;
   out_1519249616957804461[3] = 0;
   out_1519249616957804461[4] = 0;
   out_1519249616957804461[5] = 0;
   out_1519249616957804461[6] = 0;
   out_1519249616957804461[7] = 0;
   out_1519249616957804461[8] = 0;
   out_1519249616957804461[9] = 0;
   out_1519249616957804461[10] = 1;
   out_1519249616957804461[11] = 0;
   out_1519249616957804461[12] = 0;
   out_1519249616957804461[13] = 0;
   out_1519249616957804461[14] = 0;
   out_1519249616957804461[15] = 0;
   out_1519249616957804461[16] = 0;
   out_1519249616957804461[17] = 0;
   out_1519249616957804461[18] = 0;
   out_1519249616957804461[19] = 0;
   out_1519249616957804461[20] = 1;
   out_1519249616957804461[21] = 0;
   out_1519249616957804461[22] = 0;
   out_1519249616957804461[23] = 0;
   out_1519249616957804461[24] = 0;
   out_1519249616957804461[25] = 0;
   out_1519249616957804461[26] = 0;
   out_1519249616957804461[27] = 0;
   out_1519249616957804461[28] = 0;
   out_1519249616957804461[29] = 0;
   out_1519249616957804461[30] = 1;
   out_1519249616957804461[31] = 0;
   out_1519249616957804461[32] = 0;
   out_1519249616957804461[33] = 0;
   out_1519249616957804461[34] = 0;
   out_1519249616957804461[35] = 0;
   out_1519249616957804461[36] = 0;
   out_1519249616957804461[37] = 0;
   out_1519249616957804461[38] = 0;
   out_1519249616957804461[39] = 0;
   out_1519249616957804461[40] = 1;
   out_1519249616957804461[41] = 0;
   out_1519249616957804461[42] = 0;
   out_1519249616957804461[43] = 0;
   out_1519249616957804461[44] = 0;
   out_1519249616957804461[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_1519249616957804461[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_1519249616957804461[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1519249616957804461[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1519249616957804461[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_1519249616957804461[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_1519249616957804461[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_1519249616957804461[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_1519249616957804461[53] = -9.8100000000000005*dt;
   out_1519249616957804461[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_1519249616957804461[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_1519249616957804461[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1519249616957804461[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1519249616957804461[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_1519249616957804461[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_1519249616957804461[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_1519249616957804461[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1519249616957804461[62] = 0;
   out_1519249616957804461[63] = 0;
   out_1519249616957804461[64] = 0;
   out_1519249616957804461[65] = 0;
   out_1519249616957804461[66] = 0;
   out_1519249616957804461[67] = 0;
   out_1519249616957804461[68] = 0;
   out_1519249616957804461[69] = 0;
   out_1519249616957804461[70] = 1;
   out_1519249616957804461[71] = 0;
   out_1519249616957804461[72] = 0;
   out_1519249616957804461[73] = 0;
   out_1519249616957804461[74] = 0;
   out_1519249616957804461[75] = 0;
   out_1519249616957804461[76] = 0;
   out_1519249616957804461[77] = 0;
   out_1519249616957804461[78] = 0;
   out_1519249616957804461[79] = 0;
   out_1519249616957804461[80] = 1;
}
void h_25(double *state, double *unused, double *out_7032479070992890953) {
   out_7032479070992890953[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2968651036541906534) {
   out_2968651036541906534[0] = 0;
   out_2968651036541906534[1] = 0;
   out_2968651036541906534[2] = 0;
   out_2968651036541906534[3] = 0;
   out_2968651036541906534[4] = 0;
   out_2968651036541906534[5] = 0;
   out_2968651036541906534[6] = 1;
   out_2968651036541906534[7] = 0;
   out_2968651036541906534[8] = 0;
}
void h_24(double *state, double *unused, double *out_5672934374792452147) {
   out_5672934374792452147[0] = state[4];
   out_5672934374792452147[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5194358820520775096) {
   out_5194358820520775096[0] = 0;
   out_5194358820520775096[1] = 0;
   out_5194358820520775096[2] = 0;
   out_5194358820520775096[3] = 0;
   out_5194358820520775096[4] = 1;
   out_5194358820520775096[5] = 0;
   out_5194358820520775096[6] = 0;
   out_5194358820520775096[7] = 0;
   out_5194358820520775096[8] = 0;
   out_5194358820520775096[9] = 0;
   out_5194358820520775096[10] = 0;
   out_5194358820520775096[11] = 0;
   out_5194358820520775096[12] = 0;
   out_5194358820520775096[13] = 0;
   out_5194358820520775096[14] = 1;
   out_5194358820520775096[15] = 0;
   out_5194358820520775096[16] = 0;
   out_5194358820520775096[17] = 0;
}
void h_30(double *state, double *unused, double *out_6875292402641761808) {
   out_6875292402641761808[0] = state[4];
}
void H_30(double *state, double *unused, double *out_8561402695676028327) {
   out_8561402695676028327[0] = 0;
   out_8561402695676028327[1] = 0;
   out_8561402695676028327[2] = 0;
   out_8561402695676028327[3] = 0;
   out_8561402695676028327[4] = 1;
   out_8561402695676028327[5] = 0;
   out_8561402695676028327[6] = 0;
   out_8561402695676028327[7] = 0;
   out_8561402695676028327[8] = 0;
}
void h_26(double *state, double *unused, double *out_5172410153653940662) {
   out_5172410153653940662[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6273177006302707135) {
   out_6273177006302707135[0] = 0;
   out_6273177006302707135[1] = 0;
   out_6273177006302707135[2] = 0;
   out_6273177006302707135[3] = 0;
   out_6273177006302707135[4] = 0;
   out_6273177006302707135[5] = 0;
   out_6273177006302707135[6] = 0;
   out_6273177006302707135[7] = 1;
   out_6273177006302707135[8] = 0;
}
void h_27(double *state, double *unused, double *out_402664363435809860) {
   out_402664363435809860[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7710578066233098378) {
   out_7710578066233098378[0] = 0;
   out_7710578066233098378[1] = 0;
   out_7710578066233098378[2] = 0;
   out_7710578066233098378[3] = 1;
   out_7710578066233098378[4] = 0;
   out_7710578066233098378[5] = 0;
   out_7710578066233098378[6] = 0;
   out_7710578066233098378[7] = 0;
   out_7710578066233098378[8] = 0;
}
void h_29(double *state, double *unused, double *out_7173499589786160796) {
   out_7173499589786160796[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8051171351361636143) {
   out_8051171351361636143[0] = 0;
   out_8051171351361636143[1] = 1;
   out_8051171351361636143[2] = 0;
   out_8051171351361636143[3] = 0;
   out_8051171351361636143[4] = 0;
   out_8051171351361636143[5] = 0;
   out_8051171351361636143[6] = 0;
   out_8051171351361636143[7] = 0;
   out_8051171351361636143[8] = 0;
}
void h_28(double *state, double *unused, double *out_1346174216337472295) {
   out_1346174216337472295[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5313173705278384899) {
   out_5313173705278384899[0] = 1;
   out_5313173705278384899[1] = 0;
   out_5313173705278384899[2] = 0;
   out_5313173705278384899[3] = 0;
   out_5313173705278384899[4] = 0;
   out_5313173705278384899[5] = 0;
   out_5313173705278384899[6] = 0;
   out_5313173705278384899[7] = 0;
   out_5313173705278384899[8] = 0;
}
void h_31(double *state, double *unused, double *out_6757285008708385064) {
   out_6757285008708385064[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2999296998418866962) {
   out_2999296998418866962[0] = 0;
   out_2999296998418866962[1] = 0;
   out_2999296998418866962[2] = 0;
   out_2999296998418866962[3] = 0;
   out_2999296998418866962[4] = 0;
   out_2999296998418866962[5] = 0;
   out_2999296998418866962[6] = 0;
   out_2999296998418866962[7] = 0;
   out_2999296998418866962[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6669412735228971409) {
  err_fun(nom_x, delta_x, out_6669412735228971409);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6779967762183071907) {
  inv_err_fun(nom_x, true_x, out_6779967762183071907);
}
void car_H_mod_fun(double *state, double *out_6491699675187271682) {
  H_mod_fun(state, out_6491699675187271682);
}
void car_f_fun(double *state, double dt, double *out_2858314681790673269) {
  f_fun(state,  dt, out_2858314681790673269);
}
void car_F_fun(double *state, double dt, double *out_1519249616957804461) {
  F_fun(state,  dt, out_1519249616957804461);
}
void car_h_25(double *state, double *unused, double *out_7032479070992890953) {
  h_25(state, unused, out_7032479070992890953);
}
void car_H_25(double *state, double *unused, double *out_2968651036541906534) {
  H_25(state, unused, out_2968651036541906534);
}
void car_h_24(double *state, double *unused, double *out_5672934374792452147) {
  h_24(state, unused, out_5672934374792452147);
}
void car_H_24(double *state, double *unused, double *out_5194358820520775096) {
  H_24(state, unused, out_5194358820520775096);
}
void car_h_30(double *state, double *unused, double *out_6875292402641761808) {
  h_30(state, unused, out_6875292402641761808);
}
void car_H_30(double *state, double *unused, double *out_8561402695676028327) {
  H_30(state, unused, out_8561402695676028327);
}
void car_h_26(double *state, double *unused, double *out_5172410153653940662) {
  h_26(state, unused, out_5172410153653940662);
}
void car_H_26(double *state, double *unused, double *out_6273177006302707135) {
  H_26(state, unused, out_6273177006302707135);
}
void car_h_27(double *state, double *unused, double *out_402664363435809860) {
  h_27(state, unused, out_402664363435809860);
}
void car_H_27(double *state, double *unused, double *out_7710578066233098378) {
  H_27(state, unused, out_7710578066233098378);
}
void car_h_29(double *state, double *unused, double *out_7173499589786160796) {
  h_29(state, unused, out_7173499589786160796);
}
void car_H_29(double *state, double *unused, double *out_8051171351361636143) {
  H_29(state, unused, out_8051171351361636143);
}
void car_h_28(double *state, double *unused, double *out_1346174216337472295) {
  h_28(state, unused, out_1346174216337472295);
}
void car_H_28(double *state, double *unused, double *out_5313173705278384899) {
  H_28(state, unused, out_5313173705278384899);
}
void car_h_31(double *state, double *unused, double *out_6757285008708385064) {
  h_31(state, unused, out_6757285008708385064);
}
void car_H_31(double *state, double *unused, double *out_2999296998418866962) {
  H_31(state, unused, out_2999296998418866962);
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
