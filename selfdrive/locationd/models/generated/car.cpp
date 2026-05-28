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
void err_fun(double *nom_x, double *delta_x, double *out_1263767819732456823) {
   out_1263767819732456823[0] = delta_x[0] + nom_x[0];
   out_1263767819732456823[1] = delta_x[1] + nom_x[1];
   out_1263767819732456823[2] = delta_x[2] + nom_x[2];
   out_1263767819732456823[3] = delta_x[3] + nom_x[3];
   out_1263767819732456823[4] = delta_x[4] + nom_x[4];
   out_1263767819732456823[5] = delta_x[5] + nom_x[5];
   out_1263767819732456823[6] = delta_x[6] + nom_x[6];
   out_1263767819732456823[7] = delta_x[7] + nom_x[7];
   out_1263767819732456823[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3529295667634364975) {
   out_3529295667634364975[0] = -nom_x[0] + true_x[0];
   out_3529295667634364975[1] = -nom_x[1] + true_x[1];
   out_3529295667634364975[2] = -nom_x[2] + true_x[2];
   out_3529295667634364975[3] = -nom_x[3] + true_x[3];
   out_3529295667634364975[4] = -nom_x[4] + true_x[4];
   out_3529295667634364975[5] = -nom_x[5] + true_x[5];
   out_3529295667634364975[6] = -nom_x[6] + true_x[6];
   out_3529295667634364975[7] = -nom_x[7] + true_x[7];
   out_3529295667634364975[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5031874340838454569) {
   out_5031874340838454569[0] = 1.0;
   out_5031874340838454569[1] = 0.0;
   out_5031874340838454569[2] = 0.0;
   out_5031874340838454569[3] = 0.0;
   out_5031874340838454569[4] = 0.0;
   out_5031874340838454569[5] = 0.0;
   out_5031874340838454569[6] = 0.0;
   out_5031874340838454569[7] = 0.0;
   out_5031874340838454569[8] = 0.0;
   out_5031874340838454569[9] = 0.0;
   out_5031874340838454569[10] = 1.0;
   out_5031874340838454569[11] = 0.0;
   out_5031874340838454569[12] = 0.0;
   out_5031874340838454569[13] = 0.0;
   out_5031874340838454569[14] = 0.0;
   out_5031874340838454569[15] = 0.0;
   out_5031874340838454569[16] = 0.0;
   out_5031874340838454569[17] = 0.0;
   out_5031874340838454569[18] = 0.0;
   out_5031874340838454569[19] = 0.0;
   out_5031874340838454569[20] = 1.0;
   out_5031874340838454569[21] = 0.0;
   out_5031874340838454569[22] = 0.0;
   out_5031874340838454569[23] = 0.0;
   out_5031874340838454569[24] = 0.0;
   out_5031874340838454569[25] = 0.0;
   out_5031874340838454569[26] = 0.0;
   out_5031874340838454569[27] = 0.0;
   out_5031874340838454569[28] = 0.0;
   out_5031874340838454569[29] = 0.0;
   out_5031874340838454569[30] = 1.0;
   out_5031874340838454569[31] = 0.0;
   out_5031874340838454569[32] = 0.0;
   out_5031874340838454569[33] = 0.0;
   out_5031874340838454569[34] = 0.0;
   out_5031874340838454569[35] = 0.0;
   out_5031874340838454569[36] = 0.0;
   out_5031874340838454569[37] = 0.0;
   out_5031874340838454569[38] = 0.0;
   out_5031874340838454569[39] = 0.0;
   out_5031874340838454569[40] = 1.0;
   out_5031874340838454569[41] = 0.0;
   out_5031874340838454569[42] = 0.0;
   out_5031874340838454569[43] = 0.0;
   out_5031874340838454569[44] = 0.0;
   out_5031874340838454569[45] = 0.0;
   out_5031874340838454569[46] = 0.0;
   out_5031874340838454569[47] = 0.0;
   out_5031874340838454569[48] = 0.0;
   out_5031874340838454569[49] = 0.0;
   out_5031874340838454569[50] = 1.0;
   out_5031874340838454569[51] = 0.0;
   out_5031874340838454569[52] = 0.0;
   out_5031874340838454569[53] = 0.0;
   out_5031874340838454569[54] = 0.0;
   out_5031874340838454569[55] = 0.0;
   out_5031874340838454569[56] = 0.0;
   out_5031874340838454569[57] = 0.0;
   out_5031874340838454569[58] = 0.0;
   out_5031874340838454569[59] = 0.0;
   out_5031874340838454569[60] = 1.0;
   out_5031874340838454569[61] = 0.0;
   out_5031874340838454569[62] = 0.0;
   out_5031874340838454569[63] = 0.0;
   out_5031874340838454569[64] = 0.0;
   out_5031874340838454569[65] = 0.0;
   out_5031874340838454569[66] = 0.0;
   out_5031874340838454569[67] = 0.0;
   out_5031874340838454569[68] = 0.0;
   out_5031874340838454569[69] = 0.0;
   out_5031874340838454569[70] = 1.0;
   out_5031874340838454569[71] = 0.0;
   out_5031874340838454569[72] = 0.0;
   out_5031874340838454569[73] = 0.0;
   out_5031874340838454569[74] = 0.0;
   out_5031874340838454569[75] = 0.0;
   out_5031874340838454569[76] = 0.0;
   out_5031874340838454569[77] = 0.0;
   out_5031874340838454569[78] = 0.0;
   out_5031874340838454569[79] = 0.0;
   out_5031874340838454569[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1529561136835295758) {
   out_1529561136835295758[0] = state[0];
   out_1529561136835295758[1] = state[1];
   out_1529561136835295758[2] = state[2];
   out_1529561136835295758[3] = state[3];
   out_1529561136835295758[4] = state[4];
   out_1529561136835295758[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1529561136835295758[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1529561136835295758[7] = state[7];
   out_1529561136835295758[8] = state[8];
}
void F_fun(double *state, double dt, double *out_665605705060988729) {
   out_665605705060988729[0] = 1;
   out_665605705060988729[1] = 0;
   out_665605705060988729[2] = 0;
   out_665605705060988729[3] = 0;
   out_665605705060988729[4] = 0;
   out_665605705060988729[5] = 0;
   out_665605705060988729[6] = 0;
   out_665605705060988729[7] = 0;
   out_665605705060988729[8] = 0;
   out_665605705060988729[9] = 0;
   out_665605705060988729[10] = 1;
   out_665605705060988729[11] = 0;
   out_665605705060988729[12] = 0;
   out_665605705060988729[13] = 0;
   out_665605705060988729[14] = 0;
   out_665605705060988729[15] = 0;
   out_665605705060988729[16] = 0;
   out_665605705060988729[17] = 0;
   out_665605705060988729[18] = 0;
   out_665605705060988729[19] = 0;
   out_665605705060988729[20] = 1;
   out_665605705060988729[21] = 0;
   out_665605705060988729[22] = 0;
   out_665605705060988729[23] = 0;
   out_665605705060988729[24] = 0;
   out_665605705060988729[25] = 0;
   out_665605705060988729[26] = 0;
   out_665605705060988729[27] = 0;
   out_665605705060988729[28] = 0;
   out_665605705060988729[29] = 0;
   out_665605705060988729[30] = 1;
   out_665605705060988729[31] = 0;
   out_665605705060988729[32] = 0;
   out_665605705060988729[33] = 0;
   out_665605705060988729[34] = 0;
   out_665605705060988729[35] = 0;
   out_665605705060988729[36] = 0;
   out_665605705060988729[37] = 0;
   out_665605705060988729[38] = 0;
   out_665605705060988729[39] = 0;
   out_665605705060988729[40] = 1;
   out_665605705060988729[41] = 0;
   out_665605705060988729[42] = 0;
   out_665605705060988729[43] = 0;
   out_665605705060988729[44] = 0;
   out_665605705060988729[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_665605705060988729[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_665605705060988729[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_665605705060988729[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_665605705060988729[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_665605705060988729[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_665605705060988729[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_665605705060988729[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_665605705060988729[53] = -9.8100000000000005*dt;
   out_665605705060988729[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_665605705060988729[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_665605705060988729[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_665605705060988729[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_665605705060988729[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_665605705060988729[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_665605705060988729[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_665605705060988729[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_665605705060988729[62] = 0;
   out_665605705060988729[63] = 0;
   out_665605705060988729[64] = 0;
   out_665605705060988729[65] = 0;
   out_665605705060988729[66] = 0;
   out_665605705060988729[67] = 0;
   out_665605705060988729[68] = 0;
   out_665605705060988729[69] = 0;
   out_665605705060988729[70] = 1;
   out_665605705060988729[71] = 0;
   out_665605705060988729[72] = 0;
   out_665605705060988729[73] = 0;
   out_665605705060988729[74] = 0;
   out_665605705060988729[75] = 0;
   out_665605705060988729[76] = 0;
   out_665605705060988729[77] = 0;
   out_665605705060988729[78] = 0;
   out_665605705060988729[79] = 0;
   out_665605705060988729[80] = 1;
}
void h_25(double *state, double *unused, double *out_2720961962516974745) {
   out_2720961962516974745[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5863506002035943510) {
   out_5863506002035943510[0] = 0;
   out_5863506002035943510[1] = 0;
   out_5863506002035943510[2] = 0;
   out_5863506002035943510[3] = 0;
   out_5863506002035943510[4] = 0;
   out_5863506002035943510[5] = 0;
   out_5863506002035943510[6] = 1;
   out_5863506002035943510[7] = 0;
   out_5863506002035943510[8] = 0;
}
void h_24(double *state, double *unused, double *out_1485787421513289501) {
   out_1485787421513289501[0] = state[4];
   out_1485787421513289501[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1554885631640983383) {
   out_1554885631640983383[0] = 0;
   out_1554885631640983383[1] = 0;
   out_1554885631640983383[2] = 0;
   out_1554885631640983383[3] = 0;
   out_1554885631640983383[4] = 1;
   out_1554885631640983383[5] = 0;
   out_1554885631640983383[6] = 0;
   out_1554885631640983383[7] = 0;
   out_1554885631640983383[8] = 0;
   out_1554885631640983383[9] = 0;
   out_1554885631640983383[10] = 0;
   out_1554885631640983383[11] = 0;
   out_1554885631640983383[12] = 0;
   out_1554885631640983383[13] = 0;
   out_1554885631640983383[14] = 1;
   out_1554885631640983383[15] = 0;
   out_1554885631640983383[16] = 0;
   out_1554885631640983383[17] = 0;
}
void h_30(double *state, double *unused, double *out_2878148630868103890) {
   out_2878148630868103890[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5992844949179183580) {
   out_5992844949179183580[0] = 0;
   out_5992844949179183580[1] = 0;
   out_5992844949179183580[2] = 0;
   out_5992844949179183580[3] = 0;
   out_5992844949179183580[4] = 1;
   out_5992844949179183580[5] = 0;
   out_5992844949179183580[6] = 0;
   out_5992844949179183580[7] = 0;
   out_5992844949179183580[8] = 0;
}
void h_26(double *state, double *unused, double *out_158637420576228795) {
   out_158637420576228795[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8841734752799551882) {
   out_8841734752799551882[0] = 0;
   out_8841734752799551882[1] = 0;
   out_8841734752799551882[2] = 0;
   out_8841734752799551882[3] = 0;
   out_8841734752799551882[4] = 0;
   out_8841734752799551882[5] = 0;
   out_8841734752799551882[6] = 0;
   out_8841734752799551882[7] = 1;
   out_8841734752799551882[8] = 0;
}
void h_27(double *state, double *unused, double *out_2280711305143870900) {
   out_2280711305143870900[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8167608260979608491) {
   out_8167608260979608491[0] = 0;
   out_8167608260979608491[1] = 0;
   out_8167608260979608491[2] = 0;
   out_8167608260979608491[3] = 1;
   out_8167608260979608491[4] = 0;
   out_8167608260979608491[5] = 0;
   out_8167608260979608491[6] = 0;
   out_8167608260979608491[7] = 0;
   out_8167608260979608491[8] = 0;
}
void h_29(double *state, double *unused, double *out_6142394781572372552) {
   out_6142394781572372552[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5482613604864791396) {
   out_5482613604864791396[0] = 0;
   out_5482613604864791396[1] = 1;
   out_5482613604864791396[2] = 0;
   out_5482613604864791396[3] = 0;
   out_5482613604864791396[4] = 0;
   out_5482613604864791396[5] = 0;
   out_5482613604864791396[6] = 0;
   out_5482613604864791396[7] = 0;
   out_5482613604864791396[8] = 0;
}
void h_28(double *state, double *unused, double *out_6701257866862969865) {
   out_6701257866862969865[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7881731451775229646) {
   out_7881731451775229646[0] = 1;
   out_7881731451775229646[1] = 0;
   out_7881731451775229646[2] = 0;
   out_7881731451775229646[3] = 0;
   out_7881731451775229646[4] = 0;
   out_7881731451775229646[5] = 0;
   out_7881731451775229646[6] = 0;
   out_7881731451775229646[7] = 0;
   out_7881731451775229646[8] = 0;
}
void h_31(double *state, double *unused, double *out_4049873263833376191) {
   out_4049873263833376191[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5832860040158983082) {
   out_5832860040158983082[0] = 0;
   out_5832860040158983082[1] = 0;
   out_5832860040158983082[2] = 0;
   out_5832860040158983082[3] = 0;
   out_5832860040158983082[4] = 0;
   out_5832860040158983082[5] = 0;
   out_5832860040158983082[6] = 0;
   out_5832860040158983082[7] = 0;
   out_5832860040158983082[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_1263767819732456823) {
  err_fun(nom_x, delta_x, out_1263767819732456823);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3529295667634364975) {
  inv_err_fun(nom_x, true_x, out_3529295667634364975);
}
void car_H_mod_fun(double *state, double *out_5031874340838454569) {
  H_mod_fun(state, out_5031874340838454569);
}
void car_f_fun(double *state, double dt, double *out_1529561136835295758) {
  f_fun(state,  dt, out_1529561136835295758);
}
void car_F_fun(double *state, double dt, double *out_665605705060988729) {
  F_fun(state,  dt, out_665605705060988729);
}
void car_h_25(double *state, double *unused, double *out_2720961962516974745) {
  h_25(state, unused, out_2720961962516974745);
}
void car_H_25(double *state, double *unused, double *out_5863506002035943510) {
  H_25(state, unused, out_5863506002035943510);
}
void car_h_24(double *state, double *unused, double *out_1485787421513289501) {
  h_24(state, unused, out_1485787421513289501);
}
void car_H_24(double *state, double *unused, double *out_1554885631640983383) {
  H_24(state, unused, out_1554885631640983383);
}
void car_h_30(double *state, double *unused, double *out_2878148630868103890) {
  h_30(state, unused, out_2878148630868103890);
}
void car_H_30(double *state, double *unused, double *out_5992844949179183580) {
  H_30(state, unused, out_5992844949179183580);
}
void car_h_26(double *state, double *unused, double *out_158637420576228795) {
  h_26(state, unused, out_158637420576228795);
}
void car_H_26(double *state, double *unused, double *out_8841734752799551882) {
  H_26(state, unused, out_8841734752799551882);
}
void car_h_27(double *state, double *unused, double *out_2280711305143870900) {
  h_27(state, unused, out_2280711305143870900);
}
void car_H_27(double *state, double *unused, double *out_8167608260979608491) {
  H_27(state, unused, out_8167608260979608491);
}
void car_h_29(double *state, double *unused, double *out_6142394781572372552) {
  h_29(state, unused, out_6142394781572372552);
}
void car_H_29(double *state, double *unused, double *out_5482613604864791396) {
  H_29(state, unused, out_5482613604864791396);
}
void car_h_28(double *state, double *unused, double *out_6701257866862969865) {
  h_28(state, unused, out_6701257866862969865);
}
void car_H_28(double *state, double *unused, double *out_7881731451775229646) {
  H_28(state, unused, out_7881731451775229646);
}
void car_h_31(double *state, double *unused, double *out_4049873263833376191) {
  h_31(state, unused, out_4049873263833376191);
}
void car_H_31(double *state, double *unused, double *out_5832860040158983082) {
  H_31(state, unused, out_5832860040158983082);
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
