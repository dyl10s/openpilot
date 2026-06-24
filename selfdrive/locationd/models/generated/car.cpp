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
void err_fun(double *nom_x, double *delta_x, double *out_8227521165613923208) {
   out_8227521165613923208[0] = delta_x[0] + nom_x[0];
   out_8227521165613923208[1] = delta_x[1] + nom_x[1];
   out_8227521165613923208[2] = delta_x[2] + nom_x[2];
   out_8227521165613923208[3] = delta_x[3] + nom_x[3];
   out_8227521165613923208[4] = delta_x[4] + nom_x[4];
   out_8227521165613923208[5] = delta_x[5] + nom_x[5];
   out_8227521165613923208[6] = delta_x[6] + nom_x[6];
   out_8227521165613923208[7] = delta_x[7] + nom_x[7];
   out_8227521165613923208[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5130787649833322574) {
   out_5130787649833322574[0] = -nom_x[0] + true_x[0];
   out_5130787649833322574[1] = -nom_x[1] + true_x[1];
   out_5130787649833322574[2] = -nom_x[2] + true_x[2];
   out_5130787649833322574[3] = -nom_x[3] + true_x[3];
   out_5130787649833322574[4] = -nom_x[4] + true_x[4];
   out_5130787649833322574[5] = -nom_x[5] + true_x[5];
   out_5130787649833322574[6] = -nom_x[6] + true_x[6];
   out_5130787649833322574[7] = -nom_x[7] + true_x[7];
   out_5130787649833322574[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7022051272719162928) {
   out_7022051272719162928[0] = 1.0;
   out_7022051272719162928[1] = 0.0;
   out_7022051272719162928[2] = 0.0;
   out_7022051272719162928[3] = 0.0;
   out_7022051272719162928[4] = 0.0;
   out_7022051272719162928[5] = 0.0;
   out_7022051272719162928[6] = 0.0;
   out_7022051272719162928[7] = 0.0;
   out_7022051272719162928[8] = 0.0;
   out_7022051272719162928[9] = 0.0;
   out_7022051272719162928[10] = 1.0;
   out_7022051272719162928[11] = 0.0;
   out_7022051272719162928[12] = 0.0;
   out_7022051272719162928[13] = 0.0;
   out_7022051272719162928[14] = 0.0;
   out_7022051272719162928[15] = 0.0;
   out_7022051272719162928[16] = 0.0;
   out_7022051272719162928[17] = 0.0;
   out_7022051272719162928[18] = 0.0;
   out_7022051272719162928[19] = 0.0;
   out_7022051272719162928[20] = 1.0;
   out_7022051272719162928[21] = 0.0;
   out_7022051272719162928[22] = 0.0;
   out_7022051272719162928[23] = 0.0;
   out_7022051272719162928[24] = 0.0;
   out_7022051272719162928[25] = 0.0;
   out_7022051272719162928[26] = 0.0;
   out_7022051272719162928[27] = 0.0;
   out_7022051272719162928[28] = 0.0;
   out_7022051272719162928[29] = 0.0;
   out_7022051272719162928[30] = 1.0;
   out_7022051272719162928[31] = 0.0;
   out_7022051272719162928[32] = 0.0;
   out_7022051272719162928[33] = 0.0;
   out_7022051272719162928[34] = 0.0;
   out_7022051272719162928[35] = 0.0;
   out_7022051272719162928[36] = 0.0;
   out_7022051272719162928[37] = 0.0;
   out_7022051272719162928[38] = 0.0;
   out_7022051272719162928[39] = 0.0;
   out_7022051272719162928[40] = 1.0;
   out_7022051272719162928[41] = 0.0;
   out_7022051272719162928[42] = 0.0;
   out_7022051272719162928[43] = 0.0;
   out_7022051272719162928[44] = 0.0;
   out_7022051272719162928[45] = 0.0;
   out_7022051272719162928[46] = 0.0;
   out_7022051272719162928[47] = 0.0;
   out_7022051272719162928[48] = 0.0;
   out_7022051272719162928[49] = 0.0;
   out_7022051272719162928[50] = 1.0;
   out_7022051272719162928[51] = 0.0;
   out_7022051272719162928[52] = 0.0;
   out_7022051272719162928[53] = 0.0;
   out_7022051272719162928[54] = 0.0;
   out_7022051272719162928[55] = 0.0;
   out_7022051272719162928[56] = 0.0;
   out_7022051272719162928[57] = 0.0;
   out_7022051272719162928[58] = 0.0;
   out_7022051272719162928[59] = 0.0;
   out_7022051272719162928[60] = 1.0;
   out_7022051272719162928[61] = 0.0;
   out_7022051272719162928[62] = 0.0;
   out_7022051272719162928[63] = 0.0;
   out_7022051272719162928[64] = 0.0;
   out_7022051272719162928[65] = 0.0;
   out_7022051272719162928[66] = 0.0;
   out_7022051272719162928[67] = 0.0;
   out_7022051272719162928[68] = 0.0;
   out_7022051272719162928[69] = 0.0;
   out_7022051272719162928[70] = 1.0;
   out_7022051272719162928[71] = 0.0;
   out_7022051272719162928[72] = 0.0;
   out_7022051272719162928[73] = 0.0;
   out_7022051272719162928[74] = 0.0;
   out_7022051272719162928[75] = 0.0;
   out_7022051272719162928[76] = 0.0;
   out_7022051272719162928[77] = 0.0;
   out_7022051272719162928[78] = 0.0;
   out_7022051272719162928[79] = 0.0;
   out_7022051272719162928[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2984704176532588452) {
   out_2984704176532588452[0] = state[0];
   out_2984704176532588452[1] = state[1];
   out_2984704176532588452[2] = state[2];
   out_2984704176532588452[3] = state[3];
   out_2984704176532588452[4] = state[4];
   out_2984704176532588452[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2984704176532588452[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2984704176532588452[7] = state[7];
   out_2984704176532588452[8] = state[8];
}
void F_fun(double *state, double dt, double *out_314948888837440074) {
   out_314948888837440074[0] = 1;
   out_314948888837440074[1] = 0;
   out_314948888837440074[2] = 0;
   out_314948888837440074[3] = 0;
   out_314948888837440074[4] = 0;
   out_314948888837440074[5] = 0;
   out_314948888837440074[6] = 0;
   out_314948888837440074[7] = 0;
   out_314948888837440074[8] = 0;
   out_314948888837440074[9] = 0;
   out_314948888837440074[10] = 1;
   out_314948888837440074[11] = 0;
   out_314948888837440074[12] = 0;
   out_314948888837440074[13] = 0;
   out_314948888837440074[14] = 0;
   out_314948888837440074[15] = 0;
   out_314948888837440074[16] = 0;
   out_314948888837440074[17] = 0;
   out_314948888837440074[18] = 0;
   out_314948888837440074[19] = 0;
   out_314948888837440074[20] = 1;
   out_314948888837440074[21] = 0;
   out_314948888837440074[22] = 0;
   out_314948888837440074[23] = 0;
   out_314948888837440074[24] = 0;
   out_314948888837440074[25] = 0;
   out_314948888837440074[26] = 0;
   out_314948888837440074[27] = 0;
   out_314948888837440074[28] = 0;
   out_314948888837440074[29] = 0;
   out_314948888837440074[30] = 1;
   out_314948888837440074[31] = 0;
   out_314948888837440074[32] = 0;
   out_314948888837440074[33] = 0;
   out_314948888837440074[34] = 0;
   out_314948888837440074[35] = 0;
   out_314948888837440074[36] = 0;
   out_314948888837440074[37] = 0;
   out_314948888837440074[38] = 0;
   out_314948888837440074[39] = 0;
   out_314948888837440074[40] = 1;
   out_314948888837440074[41] = 0;
   out_314948888837440074[42] = 0;
   out_314948888837440074[43] = 0;
   out_314948888837440074[44] = 0;
   out_314948888837440074[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_314948888837440074[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_314948888837440074[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_314948888837440074[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_314948888837440074[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_314948888837440074[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_314948888837440074[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_314948888837440074[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_314948888837440074[53] = -9.8100000000000005*dt;
   out_314948888837440074[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_314948888837440074[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_314948888837440074[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_314948888837440074[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_314948888837440074[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_314948888837440074[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_314948888837440074[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_314948888837440074[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_314948888837440074[62] = 0;
   out_314948888837440074[63] = 0;
   out_314948888837440074[64] = 0;
   out_314948888837440074[65] = 0;
   out_314948888837440074[66] = 0;
   out_314948888837440074[67] = 0;
   out_314948888837440074[68] = 0;
   out_314948888837440074[69] = 0;
   out_314948888837440074[70] = 1;
   out_314948888837440074[71] = 0;
   out_314948888837440074[72] = 0;
   out_314948888837440074[73] = 0;
   out_314948888837440074[74] = 0;
   out_314948888837440074[75] = 0;
   out_314948888837440074[76] = 0;
   out_314948888837440074[77] = 0;
   out_314948888837440074[78] = 0;
   out_314948888837440074[79] = 0;
   out_314948888837440074[80] = 1;
}
void h_25(double *state, double *unused, double *out_26482314378299030) {
   out_26482314378299030[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3499070622729671251) {
   out_3499070622729671251[0] = 0;
   out_3499070622729671251[1] = 0;
   out_3499070622729671251[2] = 0;
   out_3499070622729671251[3] = 0;
   out_3499070622729671251[4] = 0;
   out_3499070622729671251[5] = 0;
   out_3499070622729671251[6] = 1;
   out_3499070622729671251[7] = 0;
   out_3499070622729671251[8] = 0;
}
void h_24(double *state, double *unused, double *out_7613998408709405751) {
   out_7613998408709405751[0] = state[4];
   out_7613998408709405751[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1273362838750802689) {
   out_1273362838750802689[0] = 0;
   out_1273362838750802689[1] = 0;
   out_1273362838750802689[2] = 0;
   out_1273362838750802689[3] = 0;
   out_1273362838750802689[4] = 1;
   out_1273362838750802689[5] = 0;
   out_1273362838750802689[6] = 0;
   out_1273362838750802689[7] = 0;
   out_1273362838750802689[8] = 0;
   out_1273362838750802689[9] = 0;
   out_1273362838750802689[10] = 0;
   out_1273362838750802689[11] = 0;
   out_1273362838750802689[12] = 0;
   out_1273362838750802689[13] = 0;
   out_1273362838750802689[14] = 1;
   out_1273362838750802689[15] = 0;
   out_1273362838750802689[16] = 0;
   out_1273362838750802689[17] = 0;
}
void h_30(double *state, double *unused, double *out_7907754965132348215) {
   out_7907754965132348215[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3417619718761945504) {
   out_3417619718761945504[0] = 0;
   out_3417619718761945504[1] = 0;
   out_3417619718761945504[2] = 0;
   out_3417619718761945504[3] = 0;
   out_3417619718761945504[4] = 1;
   out_3417619718761945504[5] = 0;
   out_3417619718761945504[6] = 0;
   out_3417619718761945504[7] = 0;
   out_3417619718761945504[8] = 0;
}
void h_26(double *state, double *unused, double *out_7304439080455870698) {
   out_7304439080455870698[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2842216558619359347) {
   out_2842216558619359347[0] = 0;
   out_2842216558619359347[1] = 0;
   out_2842216558619359347[2] = 0;
   out_2842216558619359347[3] = 0;
   out_2842216558619359347[4] = 0;
   out_2842216558619359347[5] = 0;
   out_2842216558619359347[6] = 0;
   out_2842216558619359347[7] = 1;
   out_2842216558619359347[8] = 0;
}
void h_27(double *state, double *unused, double *out_8106273622613022122) {
   out_8106273622613022122[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1242856406961520593) {
   out_1242856406961520593[0] = 0;
   out_1242856406961520593[1] = 0;
   out_1242856406961520593[2] = 0;
   out_1242856406961520593[3] = 1;
   out_1242856406961520593[4] = 0;
   out_1242856406961520593[5] = 0;
   out_1242856406961520593[6] = 0;
   out_1242856406961520593[7] = 0;
   out_1242856406961520593[8] = 0;
}
void h_29(double *state, double *unused, double *out_1742679644311206261) {
   out_1742679644311206261[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3927851063076337688) {
   out_3927851063076337688[0] = 0;
   out_3927851063076337688[1] = 1;
   out_3927851063076337688[2] = 0;
   out_3927851063076337688[3] = 0;
   out_3927851063076337688[4] = 0;
   out_3927851063076337688[5] = 0;
   out_3927851063076337688[6] = 0;
   out_3927851063076337688[7] = 0;
   out_3927851063076337688[8] = 0;
}
void h_28(double *state, double *unused, double *out_6626345518038675162) {
   out_6626345518038675162[0] = state[0];
}
void H_28(double *state, double *unused, double *out_1154547953993192886) {
   out_1154547953993192886[0] = 1;
   out_1154547953993192886[1] = 0;
   out_1154547953993192886[2] = 0;
   out_1154547953993192886[3] = 0;
   out_1154547953993192886[4] = 0;
   out_1154547953993192886[5] = 0;
   out_1154547953993192886[6] = 0;
   out_1154547953993192886[7] = 0;
   out_1154547953993192886[8] = 0;
}
void h_31(double *state, double *unused, double *out_1477113707007182197) {
   out_1477113707007182197[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3468424660852710823) {
   out_3468424660852710823[0] = 0;
   out_3468424660852710823[1] = 0;
   out_3468424660852710823[2] = 0;
   out_3468424660852710823[3] = 0;
   out_3468424660852710823[4] = 0;
   out_3468424660852710823[5] = 0;
   out_3468424660852710823[6] = 0;
   out_3468424660852710823[7] = 0;
   out_3468424660852710823[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8227521165613923208) {
  err_fun(nom_x, delta_x, out_8227521165613923208);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5130787649833322574) {
  inv_err_fun(nom_x, true_x, out_5130787649833322574);
}
void car_H_mod_fun(double *state, double *out_7022051272719162928) {
  H_mod_fun(state, out_7022051272719162928);
}
void car_f_fun(double *state, double dt, double *out_2984704176532588452) {
  f_fun(state,  dt, out_2984704176532588452);
}
void car_F_fun(double *state, double dt, double *out_314948888837440074) {
  F_fun(state,  dt, out_314948888837440074);
}
void car_h_25(double *state, double *unused, double *out_26482314378299030) {
  h_25(state, unused, out_26482314378299030);
}
void car_H_25(double *state, double *unused, double *out_3499070622729671251) {
  H_25(state, unused, out_3499070622729671251);
}
void car_h_24(double *state, double *unused, double *out_7613998408709405751) {
  h_24(state, unused, out_7613998408709405751);
}
void car_H_24(double *state, double *unused, double *out_1273362838750802689) {
  H_24(state, unused, out_1273362838750802689);
}
void car_h_30(double *state, double *unused, double *out_7907754965132348215) {
  h_30(state, unused, out_7907754965132348215);
}
void car_H_30(double *state, double *unused, double *out_3417619718761945504) {
  H_30(state, unused, out_3417619718761945504);
}
void car_h_26(double *state, double *unused, double *out_7304439080455870698) {
  h_26(state, unused, out_7304439080455870698);
}
void car_H_26(double *state, double *unused, double *out_2842216558619359347) {
  H_26(state, unused, out_2842216558619359347);
}
void car_h_27(double *state, double *unused, double *out_8106273622613022122) {
  h_27(state, unused, out_8106273622613022122);
}
void car_H_27(double *state, double *unused, double *out_1242856406961520593) {
  H_27(state, unused, out_1242856406961520593);
}
void car_h_29(double *state, double *unused, double *out_1742679644311206261) {
  h_29(state, unused, out_1742679644311206261);
}
void car_H_29(double *state, double *unused, double *out_3927851063076337688) {
  H_29(state, unused, out_3927851063076337688);
}
void car_h_28(double *state, double *unused, double *out_6626345518038675162) {
  h_28(state, unused, out_6626345518038675162);
}
void car_H_28(double *state, double *unused, double *out_1154547953993192886) {
  H_28(state, unused, out_1154547953993192886);
}
void car_h_31(double *state, double *unused, double *out_1477113707007182197) {
  h_31(state, unused, out_1477113707007182197);
}
void car_H_31(double *state, double *unused, double *out_3468424660852710823) {
  H_31(state, unused, out_3468424660852710823);
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
