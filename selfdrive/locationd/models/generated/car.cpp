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
void err_fun(double *nom_x, double *delta_x, double *out_7149517118868685515) {
   out_7149517118868685515[0] = delta_x[0] + nom_x[0];
   out_7149517118868685515[1] = delta_x[1] + nom_x[1];
   out_7149517118868685515[2] = delta_x[2] + nom_x[2];
   out_7149517118868685515[3] = delta_x[3] + nom_x[3];
   out_7149517118868685515[4] = delta_x[4] + nom_x[4];
   out_7149517118868685515[5] = delta_x[5] + nom_x[5];
   out_7149517118868685515[6] = delta_x[6] + nom_x[6];
   out_7149517118868685515[7] = delta_x[7] + nom_x[7];
   out_7149517118868685515[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1206282320038144058) {
   out_1206282320038144058[0] = -nom_x[0] + true_x[0];
   out_1206282320038144058[1] = -nom_x[1] + true_x[1];
   out_1206282320038144058[2] = -nom_x[2] + true_x[2];
   out_1206282320038144058[3] = -nom_x[3] + true_x[3];
   out_1206282320038144058[4] = -nom_x[4] + true_x[4];
   out_1206282320038144058[5] = -nom_x[5] + true_x[5];
   out_1206282320038144058[6] = -nom_x[6] + true_x[6];
   out_1206282320038144058[7] = -nom_x[7] + true_x[7];
   out_1206282320038144058[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2536050837023062909) {
   out_2536050837023062909[0] = 1.0;
   out_2536050837023062909[1] = 0.0;
   out_2536050837023062909[2] = 0.0;
   out_2536050837023062909[3] = 0.0;
   out_2536050837023062909[4] = 0.0;
   out_2536050837023062909[5] = 0.0;
   out_2536050837023062909[6] = 0.0;
   out_2536050837023062909[7] = 0.0;
   out_2536050837023062909[8] = 0.0;
   out_2536050837023062909[9] = 0.0;
   out_2536050837023062909[10] = 1.0;
   out_2536050837023062909[11] = 0.0;
   out_2536050837023062909[12] = 0.0;
   out_2536050837023062909[13] = 0.0;
   out_2536050837023062909[14] = 0.0;
   out_2536050837023062909[15] = 0.0;
   out_2536050837023062909[16] = 0.0;
   out_2536050837023062909[17] = 0.0;
   out_2536050837023062909[18] = 0.0;
   out_2536050837023062909[19] = 0.0;
   out_2536050837023062909[20] = 1.0;
   out_2536050837023062909[21] = 0.0;
   out_2536050837023062909[22] = 0.0;
   out_2536050837023062909[23] = 0.0;
   out_2536050837023062909[24] = 0.0;
   out_2536050837023062909[25] = 0.0;
   out_2536050837023062909[26] = 0.0;
   out_2536050837023062909[27] = 0.0;
   out_2536050837023062909[28] = 0.0;
   out_2536050837023062909[29] = 0.0;
   out_2536050837023062909[30] = 1.0;
   out_2536050837023062909[31] = 0.0;
   out_2536050837023062909[32] = 0.0;
   out_2536050837023062909[33] = 0.0;
   out_2536050837023062909[34] = 0.0;
   out_2536050837023062909[35] = 0.0;
   out_2536050837023062909[36] = 0.0;
   out_2536050837023062909[37] = 0.0;
   out_2536050837023062909[38] = 0.0;
   out_2536050837023062909[39] = 0.0;
   out_2536050837023062909[40] = 1.0;
   out_2536050837023062909[41] = 0.0;
   out_2536050837023062909[42] = 0.0;
   out_2536050837023062909[43] = 0.0;
   out_2536050837023062909[44] = 0.0;
   out_2536050837023062909[45] = 0.0;
   out_2536050837023062909[46] = 0.0;
   out_2536050837023062909[47] = 0.0;
   out_2536050837023062909[48] = 0.0;
   out_2536050837023062909[49] = 0.0;
   out_2536050837023062909[50] = 1.0;
   out_2536050837023062909[51] = 0.0;
   out_2536050837023062909[52] = 0.0;
   out_2536050837023062909[53] = 0.0;
   out_2536050837023062909[54] = 0.0;
   out_2536050837023062909[55] = 0.0;
   out_2536050837023062909[56] = 0.0;
   out_2536050837023062909[57] = 0.0;
   out_2536050837023062909[58] = 0.0;
   out_2536050837023062909[59] = 0.0;
   out_2536050837023062909[60] = 1.0;
   out_2536050837023062909[61] = 0.0;
   out_2536050837023062909[62] = 0.0;
   out_2536050837023062909[63] = 0.0;
   out_2536050837023062909[64] = 0.0;
   out_2536050837023062909[65] = 0.0;
   out_2536050837023062909[66] = 0.0;
   out_2536050837023062909[67] = 0.0;
   out_2536050837023062909[68] = 0.0;
   out_2536050837023062909[69] = 0.0;
   out_2536050837023062909[70] = 1.0;
   out_2536050837023062909[71] = 0.0;
   out_2536050837023062909[72] = 0.0;
   out_2536050837023062909[73] = 0.0;
   out_2536050837023062909[74] = 0.0;
   out_2536050837023062909[75] = 0.0;
   out_2536050837023062909[76] = 0.0;
   out_2536050837023062909[77] = 0.0;
   out_2536050837023062909[78] = 0.0;
   out_2536050837023062909[79] = 0.0;
   out_2536050837023062909[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4666135608333935516) {
   out_4666135608333935516[0] = state[0];
   out_4666135608333935516[1] = state[1];
   out_4666135608333935516[2] = state[2];
   out_4666135608333935516[3] = state[3];
   out_4666135608333935516[4] = state[4];
   out_4666135608333935516[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4666135608333935516[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4666135608333935516[7] = state[7];
   out_4666135608333935516[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2752692491938964849) {
   out_2752692491938964849[0] = 1;
   out_2752692491938964849[1] = 0;
   out_2752692491938964849[2] = 0;
   out_2752692491938964849[3] = 0;
   out_2752692491938964849[4] = 0;
   out_2752692491938964849[5] = 0;
   out_2752692491938964849[6] = 0;
   out_2752692491938964849[7] = 0;
   out_2752692491938964849[8] = 0;
   out_2752692491938964849[9] = 0;
   out_2752692491938964849[10] = 1;
   out_2752692491938964849[11] = 0;
   out_2752692491938964849[12] = 0;
   out_2752692491938964849[13] = 0;
   out_2752692491938964849[14] = 0;
   out_2752692491938964849[15] = 0;
   out_2752692491938964849[16] = 0;
   out_2752692491938964849[17] = 0;
   out_2752692491938964849[18] = 0;
   out_2752692491938964849[19] = 0;
   out_2752692491938964849[20] = 1;
   out_2752692491938964849[21] = 0;
   out_2752692491938964849[22] = 0;
   out_2752692491938964849[23] = 0;
   out_2752692491938964849[24] = 0;
   out_2752692491938964849[25] = 0;
   out_2752692491938964849[26] = 0;
   out_2752692491938964849[27] = 0;
   out_2752692491938964849[28] = 0;
   out_2752692491938964849[29] = 0;
   out_2752692491938964849[30] = 1;
   out_2752692491938964849[31] = 0;
   out_2752692491938964849[32] = 0;
   out_2752692491938964849[33] = 0;
   out_2752692491938964849[34] = 0;
   out_2752692491938964849[35] = 0;
   out_2752692491938964849[36] = 0;
   out_2752692491938964849[37] = 0;
   out_2752692491938964849[38] = 0;
   out_2752692491938964849[39] = 0;
   out_2752692491938964849[40] = 1;
   out_2752692491938964849[41] = 0;
   out_2752692491938964849[42] = 0;
   out_2752692491938964849[43] = 0;
   out_2752692491938964849[44] = 0;
   out_2752692491938964849[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2752692491938964849[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2752692491938964849[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2752692491938964849[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2752692491938964849[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2752692491938964849[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2752692491938964849[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2752692491938964849[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2752692491938964849[53] = -9.8100000000000005*dt;
   out_2752692491938964849[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2752692491938964849[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2752692491938964849[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2752692491938964849[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2752692491938964849[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2752692491938964849[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2752692491938964849[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2752692491938964849[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2752692491938964849[62] = 0;
   out_2752692491938964849[63] = 0;
   out_2752692491938964849[64] = 0;
   out_2752692491938964849[65] = 0;
   out_2752692491938964849[66] = 0;
   out_2752692491938964849[67] = 0;
   out_2752692491938964849[68] = 0;
   out_2752692491938964849[69] = 0;
   out_2752692491938964849[70] = 1;
   out_2752692491938964849[71] = 0;
   out_2752692491938964849[72] = 0;
   out_2752692491938964849[73] = 0;
   out_2752692491938964849[74] = 0;
   out_2752692491938964849[75] = 0;
   out_2752692491938964849[76] = 0;
   out_2752692491938964849[77] = 0;
   out_2752692491938964849[78] = 0;
   out_2752692491938964849[79] = 0;
   out_2752692491938964849[80] = 1;
}
void h_25(double *state, double *unused, double *out_3787568519496882893) {
   out_3787568519496882893[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3699858802985056505) {
   out_3699858802985056505[0] = 0;
   out_3699858802985056505[1] = 0;
   out_3699858802985056505[2] = 0;
   out_3699858802985056505[3] = 0;
   out_3699858802985056505[4] = 0;
   out_3699858802985056505[5] = 0;
   out_3699858802985056505[6] = 1;
   out_3699858802985056505[7] = 0;
   out_3699858802985056505[8] = 0;
}
void h_24(double *state, double *unused, double *out_1528856480665249325) {
   out_1528856480665249325[0] = state[4];
   out_1528856480665249325[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1970995683807742436) {
   out_1970995683807742436[0] = 0;
   out_1970995683807742436[1] = 0;
   out_1970995683807742436[2] = 0;
   out_1970995683807742436[3] = 0;
   out_1970995683807742436[4] = 1;
   out_1970995683807742436[5] = 0;
   out_1970995683807742436[6] = 0;
   out_1970995683807742436[7] = 0;
   out_1970995683807742436[8] = 0;
   out_1970995683807742436[9] = 0;
   out_1970995683807742436[10] = 0;
   out_1970995683807742436[11] = 0;
   out_1970995683807742436[12] = 0;
   out_1970995683807742436[13] = 0;
   out_1970995683807742436[14] = 1;
   out_1970995683807742436[15] = 0;
   out_1970995683807742436[16] = 0;
   out_1970995683807742436[17] = 0;
}
void h_30(double *state, double *unused, double *out_4709092161766857099) {
   out_4709092161766857099[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7830194929232878356) {
   out_7830194929232878356[0] = 0;
   out_7830194929232878356[1] = 0;
   out_7830194929232878356[2] = 0;
   out_7830194929232878356[3] = 0;
   out_7830194929232878356[4] = 1;
   out_7830194929232878356[5] = 0;
   out_7830194929232878356[6] = 0;
   out_7830194929232878356[7] = 0;
   out_7830194929232878356[8] = 0;
}
void h_26(double *state, double *unused, double *out_1815522905777326306) {
   out_1815522905777326306[0] = state[7];
}
void H_26(double *state, double *unused, double *out_41644515888999719) {
   out_41644515888999719[0] = 0;
   out_41644515888999719[1] = 0;
   out_41644515888999719[2] = 0;
   out_41644515888999719[3] = 0;
   out_41644515888999719[4] = 0;
   out_41644515888999719[5] = 0;
   out_41644515888999719[6] = 0;
   out_41644515888999719[7] = 1;
   out_41644515888999719[8] = 0;
}
void h_27(double *state, double *unused, double *out_8789241787157728538) {
   out_8789241787157728538[0] = state[3];
}
void H_27(double *state, double *unused, double *out_8441785832676248349) {
   out_8441785832676248349[0] = 0;
   out_8441785832676248349[1] = 0;
   out_8441785832676248349[2] = 0;
   out_8441785832676248349[3] = 1;
   out_8441785832676248349[4] = 0;
   out_8441785832676248349[5] = 0;
   out_8441785832676248349[6] = 0;
   out_8441785832676248349[7] = 0;
   out_8441785832676248349[8] = 0;
}
void h_29(double *state, double *unused, double *out_8252567880601862062) {
   out_8252567880601862062[0] = state[1];
}
void H_29(double *state, double *unused, double *out_7319963584918486172) {
   out_7319963584918486172[0] = 0;
   out_7319963584918486172[1] = 1;
   out_7319963584918486172[2] = 0;
   out_7319963584918486172[3] = 0;
   out_7319963584918486172[4] = 0;
   out_7319963584918486172[5] = 0;
   out_7319963584918486172[6] = 0;
   out_7319963584918486172[7] = 0;
   out_7319963584918486172[8] = 0;
}
void h_28(double *state, double *unused, double *out_5372968497508658522) {
   out_5372968497508658522[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6044381471721534870) {
   out_6044381471721534870[0] = 1;
   out_6044381471721534870[1] = 0;
   out_6044381471721534870[2] = 0;
   out_6044381471721534870[3] = 0;
   out_6044381471721534870[4] = 0;
   out_6044381471721534870[5] = 0;
   out_6044381471721534870[6] = 0;
   out_6044381471721534870[7] = 0;
   out_6044381471721534870[8] = 0;
}
void h_31(double *state, double *unused, double *out_6895910297391996282) {
   out_6895910297391996282[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3730504764862016933) {
   out_3730504764862016933[0] = 0;
   out_3730504764862016933[1] = 0;
   out_3730504764862016933[2] = 0;
   out_3730504764862016933[3] = 0;
   out_3730504764862016933[4] = 0;
   out_3730504764862016933[5] = 0;
   out_3730504764862016933[6] = 0;
   out_3730504764862016933[7] = 0;
   out_3730504764862016933[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_7149517118868685515) {
  err_fun(nom_x, delta_x, out_7149517118868685515);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1206282320038144058) {
  inv_err_fun(nom_x, true_x, out_1206282320038144058);
}
void car_H_mod_fun(double *state, double *out_2536050837023062909) {
  H_mod_fun(state, out_2536050837023062909);
}
void car_f_fun(double *state, double dt, double *out_4666135608333935516) {
  f_fun(state,  dt, out_4666135608333935516);
}
void car_F_fun(double *state, double dt, double *out_2752692491938964849) {
  F_fun(state,  dt, out_2752692491938964849);
}
void car_h_25(double *state, double *unused, double *out_3787568519496882893) {
  h_25(state, unused, out_3787568519496882893);
}
void car_H_25(double *state, double *unused, double *out_3699858802985056505) {
  H_25(state, unused, out_3699858802985056505);
}
void car_h_24(double *state, double *unused, double *out_1528856480665249325) {
  h_24(state, unused, out_1528856480665249325);
}
void car_H_24(double *state, double *unused, double *out_1970995683807742436) {
  H_24(state, unused, out_1970995683807742436);
}
void car_h_30(double *state, double *unused, double *out_4709092161766857099) {
  h_30(state, unused, out_4709092161766857099);
}
void car_H_30(double *state, double *unused, double *out_7830194929232878356) {
  H_30(state, unused, out_7830194929232878356);
}
void car_h_26(double *state, double *unused, double *out_1815522905777326306) {
  h_26(state, unused, out_1815522905777326306);
}
void car_H_26(double *state, double *unused, double *out_41644515888999719) {
  H_26(state, unused, out_41644515888999719);
}
void car_h_27(double *state, double *unused, double *out_8789241787157728538) {
  h_27(state, unused, out_8789241787157728538);
}
void car_H_27(double *state, double *unused, double *out_8441785832676248349) {
  H_27(state, unused, out_8441785832676248349);
}
void car_h_29(double *state, double *unused, double *out_8252567880601862062) {
  h_29(state, unused, out_8252567880601862062);
}
void car_H_29(double *state, double *unused, double *out_7319963584918486172) {
  H_29(state, unused, out_7319963584918486172);
}
void car_h_28(double *state, double *unused, double *out_5372968497508658522) {
  h_28(state, unused, out_5372968497508658522);
}
void car_H_28(double *state, double *unused, double *out_6044381471721534870) {
  H_28(state, unused, out_6044381471721534870);
}
void car_h_31(double *state, double *unused, double *out_6895910297391996282) {
  h_31(state, unused, out_6895910297391996282);
}
void car_H_31(double *state, double *unused, double *out_3730504764862016933) {
  H_31(state, unused, out_3730504764862016933);
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
