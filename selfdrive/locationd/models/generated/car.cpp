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
void err_fun(double *nom_x, double *delta_x, double *out_8796389704996072171) {
   out_8796389704996072171[0] = delta_x[0] + nom_x[0];
   out_8796389704996072171[1] = delta_x[1] + nom_x[1];
   out_8796389704996072171[2] = delta_x[2] + nom_x[2];
   out_8796389704996072171[3] = delta_x[3] + nom_x[3];
   out_8796389704996072171[4] = delta_x[4] + nom_x[4];
   out_8796389704996072171[5] = delta_x[5] + nom_x[5];
   out_8796389704996072171[6] = delta_x[6] + nom_x[6];
   out_8796389704996072171[7] = delta_x[7] + nom_x[7];
   out_8796389704996072171[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8849207833158339340) {
   out_8849207833158339340[0] = -nom_x[0] + true_x[0];
   out_8849207833158339340[1] = -nom_x[1] + true_x[1];
   out_8849207833158339340[2] = -nom_x[2] + true_x[2];
   out_8849207833158339340[3] = -nom_x[3] + true_x[3];
   out_8849207833158339340[4] = -nom_x[4] + true_x[4];
   out_8849207833158339340[5] = -nom_x[5] + true_x[5];
   out_8849207833158339340[6] = -nom_x[6] + true_x[6];
   out_8849207833158339340[7] = -nom_x[7] + true_x[7];
   out_8849207833158339340[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1622786580378488408) {
   out_1622786580378488408[0] = 1.0;
   out_1622786580378488408[1] = 0.0;
   out_1622786580378488408[2] = 0.0;
   out_1622786580378488408[3] = 0.0;
   out_1622786580378488408[4] = 0.0;
   out_1622786580378488408[5] = 0.0;
   out_1622786580378488408[6] = 0.0;
   out_1622786580378488408[7] = 0.0;
   out_1622786580378488408[8] = 0.0;
   out_1622786580378488408[9] = 0.0;
   out_1622786580378488408[10] = 1.0;
   out_1622786580378488408[11] = 0.0;
   out_1622786580378488408[12] = 0.0;
   out_1622786580378488408[13] = 0.0;
   out_1622786580378488408[14] = 0.0;
   out_1622786580378488408[15] = 0.0;
   out_1622786580378488408[16] = 0.0;
   out_1622786580378488408[17] = 0.0;
   out_1622786580378488408[18] = 0.0;
   out_1622786580378488408[19] = 0.0;
   out_1622786580378488408[20] = 1.0;
   out_1622786580378488408[21] = 0.0;
   out_1622786580378488408[22] = 0.0;
   out_1622786580378488408[23] = 0.0;
   out_1622786580378488408[24] = 0.0;
   out_1622786580378488408[25] = 0.0;
   out_1622786580378488408[26] = 0.0;
   out_1622786580378488408[27] = 0.0;
   out_1622786580378488408[28] = 0.0;
   out_1622786580378488408[29] = 0.0;
   out_1622786580378488408[30] = 1.0;
   out_1622786580378488408[31] = 0.0;
   out_1622786580378488408[32] = 0.0;
   out_1622786580378488408[33] = 0.0;
   out_1622786580378488408[34] = 0.0;
   out_1622786580378488408[35] = 0.0;
   out_1622786580378488408[36] = 0.0;
   out_1622786580378488408[37] = 0.0;
   out_1622786580378488408[38] = 0.0;
   out_1622786580378488408[39] = 0.0;
   out_1622786580378488408[40] = 1.0;
   out_1622786580378488408[41] = 0.0;
   out_1622786580378488408[42] = 0.0;
   out_1622786580378488408[43] = 0.0;
   out_1622786580378488408[44] = 0.0;
   out_1622786580378488408[45] = 0.0;
   out_1622786580378488408[46] = 0.0;
   out_1622786580378488408[47] = 0.0;
   out_1622786580378488408[48] = 0.0;
   out_1622786580378488408[49] = 0.0;
   out_1622786580378488408[50] = 1.0;
   out_1622786580378488408[51] = 0.0;
   out_1622786580378488408[52] = 0.0;
   out_1622786580378488408[53] = 0.0;
   out_1622786580378488408[54] = 0.0;
   out_1622786580378488408[55] = 0.0;
   out_1622786580378488408[56] = 0.0;
   out_1622786580378488408[57] = 0.0;
   out_1622786580378488408[58] = 0.0;
   out_1622786580378488408[59] = 0.0;
   out_1622786580378488408[60] = 1.0;
   out_1622786580378488408[61] = 0.0;
   out_1622786580378488408[62] = 0.0;
   out_1622786580378488408[63] = 0.0;
   out_1622786580378488408[64] = 0.0;
   out_1622786580378488408[65] = 0.0;
   out_1622786580378488408[66] = 0.0;
   out_1622786580378488408[67] = 0.0;
   out_1622786580378488408[68] = 0.0;
   out_1622786580378488408[69] = 0.0;
   out_1622786580378488408[70] = 1.0;
   out_1622786580378488408[71] = 0.0;
   out_1622786580378488408[72] = 0.0;
   out_1622786580378488408[73] = 0.0;
   out_1622786580378488408[74] = 0.0;
   out_1622786580378488408[75] = 0.0;
   out_1622786580378488408[76] = 0.0;
   out_1622786580378488408[77] = 0.0;
   out_1622786580378488408[78] = 0.0;
   out_1622786580378488408[79] = 0.0;
   out_1622786580378488408[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1981095305174081329) {
   out_1981095305174081329[0] = state[0];
   out_1981095305174081329[1] = state[1];
   out_1981095305174081329[2] = state[2];
   out_1981095305174081329[3] = state[3];
   out_1981095305174081329[4] = state[4];
   out_1981095305174081329[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1981095305174081329[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1981095305174081329[7] = state[7];
   out_1981095305174081329[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3561550856242897713) {
   out_3561550856242897713[0] = 1;
   out_3561550856242897713[1] = 0;
   out_3561550856242897713[2] = 0;
   out_3561550856242897713[3] = 0;
   out_3561550856242897713[4] = 0;
   out_3561550856242897713[5] = 0;
   out_3561550856242897713[6] = 0;
   out_3561550856242897713[7] = 0;
   out_3561550856242897713[8] = 0;
   out_3561550856242897713[9] = 0;
   out_3561550856242897713[10] = 1;
   out_3561550856242897713[11] = 0;
   out_3561550856242897713[12] = 0;
   out_3561550856242897713[13] = 0;
   out_3561550856242897713[14] = 0;
   out_3561550856242897713[15] = 0;
   out_3561550856242897713[16] = 0;
   out_3561550856242897713[17] = 0;
   out_3561550856242897713[18] = 0;
   out_3561550856242897713[19] = 0;
   out_3561550856242897713[20] = 1;
   out_3561550856242897713[21] = 0;
   out_3561550856242897713[22] = 0;
   out_3561550856242897713[23] = 0;
   out_3561550856242897713[24] = 0;
   out_3561550856242897713[25] = 0;
   out_3561550856242897713[26] = 0;
   out_3561550856242897713[27] = 0;
   out_3561550856242897713[28] = 0;
   out_3561550856242897713[29] = 0;
   out_3561550856242897713[30] = 1;
   out_3561550856242897713[31] = 0;
   out_3561550856242897713[32] = 0;
   out_3561550856242897713[33] = 0;
   out_3561550856242897713[34] = 0;
   out_3561550856242897713[35] = 0;
   out_3561550856242897713[36] = 0;
   out_3561550856242897713[37] = 0;
   out_3561550856242897713[38] = 0;
   out_3561550856242897713[39] = 0;
   out_3561550856242897713[40] = 1;
   out_3561550856242897713[41] = 0;
   out_3561550856242897713[42] = 0;
   out_3561550856242897713[43] = 0;
   out_3561550856242897713[44] = 0;
   out_3561550856242897713[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3561550856242897713[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3561550856242897713[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3561550856242897713[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3561550856242897713[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3561550856242897713[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3561550856242897713[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3561550856242897713[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3561550856242897713[53] = -9.8100000000000005*dt;
   out_3561550856242897713[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3561550856242897713[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3561550856242897713[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3561550856242897713[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3561550856242897713[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3561550856242897713[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3561550856242897713[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3561550856242897713[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3561550856242897713[62] = 0;
   out_3561550856242897713[63] = 0;
   out_3561550856242897713[64] = 0;
   out_3561550856242897713[65] = 0;
   out_3561550856242897713[66] = 0;
   out_3561550856242897713[67] = 0;
   out_3561550856242897713[68] = 0;
   out_3561550856242897713[69] = 0;
   out_3561550856242897713[70] = 1;
   out_3561550856242897713[71] = 0;
   out_3561550856242897713[72] = 0;
   out_3561550856242897713[73] = 0;
   out_3561550856242897713[74] = 0;
   out_3561550856242897713[75] = 0;
   out_3561550856242897713[76] = 0;
   out_3561550856242897713[77] = 0;
   out_3561550856242897713[78] = 0;
   out_3561550856242897713[79] = 0;
   out_3561550856242897713[80] = 1;
}
void h_25(double *state, double *unused, double *out_3280789364307995853) {
   out_3280789364307995853[0] = state[6];
}
void H_25(double *state, double *unused, double *out_445738705382224348) {
   out_445738705382224348[0] = 0;
   out_445738705382224348[1] = 0;
   out_445738705382224348[2] = 0;
   out_445738705382224348[3] = 0;
   out_445738705382224348[4] = 0;
   out_445738705382224348[5] = 0;
   out_445738705382224348[6] = 1;
   out_445738705382224348[7] = 0;
   out_445738705382224348[8] = 0;
}
void h_24(double *state, double *unused, double *out_5100775928185398157) {
   out_5100775928185398157[0] = state[4];
   out_5100775928185398157[1] = state[5];
}
void H_24(double *state, double *unused, double *out_399257903401471051) {
   out_399257903401471051[0] = 0;
   out_399257903401471051[1] = 0;
   out_399257903401471051[2] = 0;
   out_399257903401471051[3] = 0;
   out_399257903401471051[4] = 1;
   out_399257903401471051[5] = 0;
   out_399257903401471051[6] = 0;
   out_399257903401471051[7] = 0;
   out_399257903401471051[8] = 0;
   out_399257903401471051[9] = 0;
   out_399257903401471051[10] = 0;
   out_399257903401471051[11] = 0;
   out_399257903401471051[12] = 0;
   out_399257903401471051[13] = 0;
   out_399257903401471051[14] = 1;
   out_399257903401471051[15] = 0;
   out_399257903401471051[16] = 0;
   out_399257903401471051[17] = 0;
}
void h_30(double *state, double *unused, double *out_3331749478418022440) {
   out_3331749478418022440[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2072594253125024279) {
   out_2072594253125024279[0] = 0;
   out_2072594253125024279[1] = 0;
   out_2072594253125024279[2] = 0;
   out_2072594253125024279[3] = 0;
   out_2072594253125024279[4] = 1;
   out_2072594253125024279[5] = 0;
   out_2072594253125024279[6] = 0;
   out_2072594253125024279[7] = 0;
   out_2072594253125024279[8] = 0;
}
void h_26(double *state, double *unused, double *out_1066202602863606572) {
   out_1066202602863606572[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4187242024256280572) {
   out_4187242024256280572[0] = 0;
   out_4187242024256280572[1] = 0;
   out_4187242024256280572[2] = 0;
   out_4187242024256280572[3] = 0;
   out_4187242024256280572[4] = 0;
   out_4187242024256280572[5] = 0;
   out_4187242024256280572[6] = 0;
   out_4187242024256280572[7] = 1;
   out_4187242024256280572[8] = 0;
}
void h_27(double *state, double *unused, double *out_3118252153105853293) {
   out_3118252153105853293[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4296188324308967496) {
   out_4296188324308967496[0] = 0;
   out_4296188324308967496[1] = 0;
   out_4296188324308967496[2] = 0;
   out_4296188324308967496[3] = 1;
   out_4296188324308967496[4] = 0;
   out_4296188324308967496[5] = 0;
   out_4296188324308967496[6] = 0;
   out_4296188324308967496[7] = 0;
   out_4296188324308967496[8] = 0;
}
void h_29(double *state, double *unused, double *out_8557656694253347387) {
   out_8557656694253347387[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2582825597439416463) {
   out_2582825597439416463[0] = 0;
   out_2582825597439416463[1] = 1;
   out_2582825597439416463[2] = 0;
   out_2582825597439416463[3] = 0;
   out_2582825597439416463[4] = 0;
   out_2582825597439416463[5] = 0;
   out_2582825597439416463[6] = 0;
   out_2582825597439416463[7] = 0;
   out_2582825597439416463[8] = 0;
}
void h_28(double *state, double *unused, double *out_4285995954181995030) {
   out_4285995954181995030[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2499573419630114111) {
   out_2499573419630114111[0] = 1;
   out_2499573419630114111[1] = 0;
   out_2499573419630114111[2] = 0;
   out_2499573419630114111[3] = 0;
   out_2499573419630114111[4] = 0;
   out_2499573419630114111[5] = 0;
   out_2499573419630114111[6] = 0;
   out_2499573419630114111[7] = 0;
   out_2499573419630114111[8] = 0;
}
void h_31(double *state, double *unused, double *out_6669294028137815771) {
   out_6669294028137815771[0] = state[8];
}
void H_31(double *state, double *unused, double *out_415092743505263920) {
   out_415092743505263920[0] = 0;
   out_415092743505263920[1] = 0;
   out_415092743505263920[2] = 0;
   out_415092743505263920[3] = 0;
   out_415092743505263920[4] = 0;
   out_415092743505263920[5] = 0;
   out_415092743505263920[6] = 0;
   out_415092743505263920[7] = 0;
   out_415092743505263920[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8796389704996072171) {
  err_fun(nom_x, delta_x, out_8796389704996072171);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8849207833158339340) {
  inv_err_fun(nom_x, true_x, out_8849207833158339340);
}
void car_H_mod_fun(double *state, double *out_1622786580378488408) {
  H_mod_fun(state, out_1622786580378488408);
}
void car_f_fun(double *state, double dt, double *out_1981095305174081329) {
  f_fun(state,  dt, out_1981095305174081329);
}
void car_F_fun(double *state, double dt, double *out_3561550856242897713) {
  F_fun(state,  dt, out_3561550856242897713);
}
void car_h_25(double *state, double *unused, double *out_3280789364307995853) {
  h_25(state, unused, out_3280789364307995853);
}
void car_H_25(double *state, double *unused, double *out_445738705382224348) {
  H_25(state, unused, out_445738705382224348);
}
void car_h_24(double *state, double *unused, double *out_5100775928185398157) {
  h_24(state, unused, out_5100775928185398157);
}
void car_H_24(double *state, double *unused, double *out_399257903401471051) {
  H_24(state, unused, out_399257903401471051);
}
void car_h_30(double *state, double *unused, double *out_3331749478418022440) {
  h_30(state, unused, out_3331749478418022440);
}
void car_H_30(double *state, double *unused, double *out_2072594253125024279) {
  H_30(state, unused, out_2072594253125024279);
}
void car_h_26(double *state, double *unused, double *out_1066202602863606572) {
  h_26(state, unused, out_1066202602863606572);
}
void car_H_26(double *state, double *unused, double *out_4187242024256280572) {
  H_26(state, unused, out_4187242024256280572);
}
void car_h_27(double *state, double *unused, double *out_3118252153105853293) {
  h_27(state, unused, out_3118252153105853293);
}
void car_H_27(double *state, double *unused, double *out_4296188324308967496) {
  H_27(state, unused, out_4296188324308967496);
}
void car_h_29(double *state, double *unused, double *out_8557656694253347387) {
  h_29(state, unused, out_8557656694253347387);
}
void car_H_29(double *state, double *unused, double *out_2582825597439416463) {
  H_29(state, unused, out_2582825597439416463);
}
void car_h_28(double *state, double *unused, double *out_4285995954181995030) {
  h_28(state, unused, out_4285995954181995030);
}
void car_H_28(double *state, double *unused, double *out_2499573419630114111) {
  H_28(state, unused, out_2499573419630114111);
}
void car_h_31(double *state, double *unused, double *out_6669294028137815771) {
  h_31(state, unused, out_6669294028137815771);
}
void car_H_31(double *state, double *unused, double *out_415092743505263920) {
  H_31(state, unused, out_415092743505263920);
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
