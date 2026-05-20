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
void err_fun(double *nom_x, double *delta_x, double *out_3568804456057098654) {
   out_3568804456057098654[0] = delta_x[0] + nom_x[0];
   out_3568804456057098654[1] = delta_x[1] + nom_x[1];
   out_3568804456057098654[2] = delta_x[2] + nom_x[2];
   out_3568804456057098654[3] = delta_x[3] + nom_x[3];
   out_3568804456057098654[4] = delta_x[4] + nom_x[4];
   out_3568804456057098654[5] = delta_x[5] + nom_x[5];
   out_3568804456057098654[6] = delta_x[6] + nom_x[6];
   out_3568804456057098654[7] = delta_x[7] + nom_x[7];
   out_3568804456057098654[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1840397183166108031) {
   out_1840397183166108031[0] = -nom_x[0] + true_x[0];
   out_1840397183166108031[1] = -nom_x[1] + true_x[1];
   out_1840397183166108031[2] = -nom_x[2] + true_x[2];
   out_1840397183166108031[3] = -nom_x[3] + true_x[3];
   out_1840397183166108031[4] = -nom_x[4] + true_x[4];
   out_1840397183166108031[5] = -nom_x[5] + true_x[5];
   out_1840397183166108031[6] = -nom_x[6] + true_x[6];
   out_1840397183166108031[7] = -nom_x[7] + true_x[7];
   out_1840397183166108031[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8921258435077713963) {
   out_8921258435077713963[0] = 1.0;
   out_8921258435077713963[1] = 0.0;
   out_8921258435077713963[2] = 0.0;
   out_8921258435077713963[3] = 0.0;
   out_8921258435077713963[4] = 0.0;
   out_8921258435077713963[5] = 0.0;
   out_8921258435077713963[6] = 0.0;
   out_8921258435077713963[7] = 0.0;
   out_8921258435077713963[8] = 0.0;
   out_8921258435077713963[9] = 0.0;
   out_8921258435077713963[10] = 1.0;
   out_8921258435077713963[11] = 0.0;
   out_8921258435077713963[12] = 0.0;
   out_8921258435077713963[13] = 0.0;
   out_8921258435077713963[14] = 0.0;
   out_8921258435077713963[15] = 0.0;
   out_8921258435077713963[16] = 0.0;
   out_8921258435077713963[17] = 0.0;
   out_8921258435077713963[18] = 0.0;
   out_8921258435077713963[19] = 0.0;
   out_8921258435077713963[20] = 1.0;
   out_8921258435077713963[21] = 0.0;
   out_8921258435077713963[22] = 0.0;
   out_8921258435077713963[23] = 0.0;
   out_8921258435077713963[24] = 0.0;
   out_8921258435077713963[25] = 0.0;
   out_8921258435077713963[26] = 0.0;
   out_8921258435077713963[27] = 0.0;
   out_8921258435077713963[28] = 0.0;
   out_8921258435077713963[29] = 0.0;
   out_8921258435077713963[30] = 1.0;
   out_8921258435077713963[31] = 0.0;
   out_8921258435077713963[32] = 0.0;
   out_8921258435077713963[33] = 0.0;
   out_8921258435077713963[34] = 0.0;
   out_8921258435077713963[35] = 0.0;
   out_8921258435077713963[36] = 0.0;
   out_8921258435077713963[37] = 0.0;
   out_8921258435077713963[38] = 0.0;
   out_8921258435077713963[39] = 0.0;
   out_8921258435077713963[40] = 1.0;
   out_8921258435077713963[41] = 0.0;
   out_8921258435077713963[42] = 0.0;
   out_8921258435077713963[43] = 0.0;
   out_8921258435077713963[44] = 0.0;
   out_8921258435077713963[45] = 0.0;
   out_8921258435077713963[46] = 0.0;
   out_8921258435077713963[47] = 0.0;
   out_8921258435077713963[48] = 0.0;
   out_8921258435077713963[49] = 0.0;
   out_8921258435077713963[50] = 1.0;
   out_8921258435077713963[51] = 0.0;
   out_8921258435077713963[52] = 0.0;
   out_8921258435077713963[53] = 0.0;
   out_8921258435077713963[54] = 0.0;
   out_8921258435077713963[55] = 0.0;
   out_8921258435077713963[56] = 0.0;
   out_8921258435077713963[57] = 0.0;
   out_8921258435077713963[58] = 0.0;
   out_8921258435077713963[59] = 0.0;
   out_8921258435077713963[60] = 1.0;
   out_8921258435077713963[61] = 0.0;
   out_8921258435077713963[62] = 0.0;
   out_8921258435077713963[63] = 0.0;
   out_8921258435077713963[64] = 0.0;
   out_8921258435077713963[65] = 0.0;
   out_8921258435077713963[66] = 0.0;
   out_8921258435077713963[67] = 0.0;
   out_8921258435077713963[68] = 0.0;
   out_8921258435077713963[69] = 0.0;
   out_8921258435077713963[70] = 1.0;
   out_8921258435077713963[71] = 0.0;
   out_8921258435077713963[72] = 0.0;
   out_8921258435077713963[73] = 0.0;
   out_8921258435077713963[74] = 0.0;
   out_8921258435077713963[75] = 0.0;
   out_8921258435077713963[76] = 0.0;
   out_8921258435077713963[77] = 0.0;
   out_8921258435077713963[78] = 0.0;
   out_8921258435077713963[79] = 0.0;
   out_8921258435077713963[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3277027219914288776) {
   out_3277027219914288776[0] = state[0];
   out_3277027219914288776[1] = state[1];
   out_3277027219914288776[2] = state[2];
   out_3277027219914288776[3] = state[3];
   out_3277027219914288776[4] = state[4];
   out_3277027219914288776[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3277027219914288776[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3277027219914288776[7] = state[7];
   out_3277027219914288776[8] = state[8];
}
void F_fun(double *state, double dt, double *out_370955893725369602) {
   out_370955893725369602[0] = 1;
   out_370955893725369602[1] = 0;
   out_370955893725369602[2] = 0;
   out_370955893725369602[3] = 0;
   out_370955893725369602[4] = 0;
   out_370955893725369602[5] = 0;
   out_370955893725369602[6] = 0;
   out_370955893725369602[7] = 0;
   out_370955893725369602[8] = 0;
   out_370955893725369602[9] = 0;
   out_370955893725369602[10] = 1;
   out_370955893725369602[11] = 0;
   out_370955893725369602[12] = 0;
   out_370955893725369602[13] = 0;
   out_370955893725369602[14] = 0;
   out_370955893725369602[15] = 0;
   out_370955893725369602[16] = 0;
   out_370955893725369602[17] = 0;
   out_370955893725369602[18] = 0;
   out_370955893725369602[19] = 0;
   out_370955893725369602[20] = 1;
   out_370955893725369602[21] = 0;
   out_370955893725369602[22] = 0;
   out_370955893725369602[23] = 0;
   out_370955893725369602[24] = 0;
   out_370955893725369602[25] = 0;
   out_370955893725369602[26] = 0;
   out_370955893725369602[27] = 0;
   out_370955893725369602[28] = 0;
   out_370955893725369602[29] = 0;
   out_370955893725369602[30] = 1;
   out_370955893725369602[31] = 0;
   out_370955893725369602[32] = 0;
   out_370955893725369602[33] = 0;
   out_370955893725369602[34] = 0;
   out_370955893725369602[35] = 0;
   out_370955893725369602[36] = 0;
   out_370955893725369602[37] = 0;
   out_370955893725369602[38] = 0;
   out_370955893725369602[39] = 0;
   out_370955893725369602[40] = 1;
   out_370955893725369602[41] = 0;
   out_370955893725369602[42] = 0;
   out_370955893725369602[43] = 0;
   out_370955893725369602[44] = 0;
   out_370955893725369602[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_370955893725369602[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_370955893725369602[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_370955893725369602[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_370955893725369602[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_370955893725369602[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_370955893725369602[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_370955893725369602[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_370955893725369602[53] = -9.8100000000000005*dt;
   out_370955893725369602[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_370955893725369602[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_370955893725369602[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_370955893725369602[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_370955893725369602[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_370955893725369602[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_370955893725369602[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_370955893725369602[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_370955893725369602[62] = 0;
   out_370955893725369602[63] = 0;
   out_370955893725369602[64] = 0;
   out_370955893725369602[65] = 0;
   out_370955893725369602[66] = 0;
   out_370955893725369602[67] = 0;
   out_370955893725369602[68] = 0;
   out_370955893725369602[69] = 0;
   out_370955893725369602[70] = 1;
   out_370955893725369602[71] = 0;
   out_370955893725369602[72] = 0;
   out_370955893725369602[73] = 0;
   out_370955893725369602[74] = 0;
   out_370955893725369602[75] = 0;
   out_370955893725369602[76] = 0;
   out_370955893725369602[77] = 0;
   out_370955893725369602[78] = 0;
   out_370955893725369602[79] = 0;
   out_370955893725369602[80] = 1;
}
void h_25(double *state, double *unused, double *out_8154090013633331696) {
   out_8154090013633331696[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8415923992877417251) {
   out_8415923992877417251[0] = 0;
   out_8415923992877417251[1] = 0;
   out_8415923992877417251[2] = 0;
   out_8415923992877417251[3] = 0;
   out_8415923992877417251[4] = 0;
   out_8415923992877417251[5] = 0;
   out_8415923992877417251[6] = 1;
   out_8415923992877417251[7] = 0;
   out_8415923992877417251[8] = 0;
}
void h_24(double *state, double *unused, double *out_7351280482288278166) {
   out_7351280482288278166[0] = state[4];
   out_7351280482288278166[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8301956961654820296) {
   out_8301956961654820296[0] = 0;
   out_8301956961654820296[1] = 0;
   out_8301956961654820296[2] = 0;
   out_8301956961654820296[3] = 0;
   out_8301956961654820296[4] = 1;
   out_8301956961654820296[5] = 0;
   out_8301956961654820296[6] = 0;
   out_8301956961654820296[7] = 0;
   out_8301956961654820296[8] = 0;
   out_8301956961654820296[9] = 0;
   out_8301956961654820296[10] = 0;
   out_8301956961654820296[11] = 0;
   out_8301956961654820296[12] = 0;
   out_8301956961654820296[13] = 0;
   out_8301956961654820296[14] = 1;
   out_8301956961654820296[15] = 0;
   out_8301956961654820296[16] = 0;
   out_8301956961654820296[17] = 0;
}
void h_30(double *state, double *unused, double *out_4292406537204830044) {
   out_4292406537204830044[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1499233651385800496) {
   out_1499233651385800496[0] = 0;
   out_1499233651385800496[1] = 0;
   out_1499233651385800496[2] = 0;
   out_1499233651385800496[3] = 0;
   out_1499233651385800496[4] = 1;
   out_1499233651385800496[5] = 0;
   out_1499233651385800496[6] = 0;
   out_1499233651385800496[7] = 0;
   out_1499233651385800496[8] = 0;
}
void h_26(double *state, double *unused, double *out_7000316085453517212) {
   out_7000316085453517212[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6289316761958078141) {
   out_6289316761958078141[0] = 0;
   out_6289316761958078141[1] = 0;
   out_6289316761958078141[2] = 0;
   out_6289316761958078141[3] = 0;
   out_6289316761958078141[4] = 0;
   out_6289316761958078141[5] = 0;
   out_6289316761958078141[6] = 0;
   out_6289316761958078141[7] = 1;
   out_6289316761958078141[8] = 0;
}
void h_27(double *state, double *unused, double *out_3964284714812858416) {
   out_3964284714812858416[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3673996963186225407) {
   out_3673996963186225407[0] = 0;
   out_3673996963186225407[1] = 0;
   out_3673996963186225407[2] = 0;
   out_3673996963186225407[3] = 1;
   out_3673996963186225407[4] = 0;
   out_3673996963186225407[5] = 0;
   out_3673996963186225407[6] = 0;
   out_3673996963186225407[7] = 0;
   out_3673996963186225407[8] = 0;
}
void h_29(double *state, double *unused, double *out_3689090652528352527) {
   out_3689090652528352527[0] = state[1];
}
void H_29(double *state, double *unused, double *out_989002307071408312) {
   out_989002307071408312[0] = 0;
   out_989002307071408312[1] = 1;
   out_989002307071408312[2] = 0;
   out_989002307071408312[3] = 0;
   out_989002307071408312[4] = 0;
   out_989002307071408312[5] = 0;
   out_989002307071408312[6] = 0;
   out_989002307071408312[7] = 0;
   out_989002307071408312[8] = 0;
}
void h_28(double *state, double *unused, double *out_1914000772745856672) {
   out_1914000772745856672[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6071401324140938886) {
   out_6071401324140938886[0] = 1;
   out_6071401324140938886[1] = 0;
   out_6071401324140938886[2] = 0;
   out_6071401324140938886[3] = 0;
   out_6071401324140938886[4] = 0;
   out_6071401324140938886[5] = 0;
   out_6071401324140938886[6] = 0;
   out_6071401324140938886[7] = 0;
   out_6071401324140938886[8] = 0;
}
void h_31(double *state, double *unused, double *out_8205050127743358283) {
   out_8205050127743358283[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8385278031000456823) {
   out_8385278031000456823[0] = 0;
   out_8385278031000456823[1] = 0;
   out_8385278031000456823[2] = 0;
   out_8385278031000456823[3] = 0;
   out_8385278031000456823[4] = 0;
   out_8385278031000456823[5] = 0;
   out_8385278031000456823[6] = 0;
   out_8385278031000456823[7] = 0;
   out_8385278031000456823[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3568804456057098654) {
  err_fun(nom_x, delta_x, out_3568804456057098654);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1840397183166108031) {
  inv_err_fun(nom_x, true_x, out_1840397183166108031);
}
void car_H_mod_fun(double *state, double *out_8921258435077713963) {
  H_mod_fun(state, out_8921258435077713963);
}
void car_f_fun(double *state, double dt, double *out_3277027219914288776) {
  f_fun(state,  dt, out_3277027219914288776);
}
void car_F_fun(double *state, double dt, double *out_370955893725369602) {
  F_fun(state,  dt, out_370955893725369602);
}
void car_h_25(double *state, double *unused, double *out_8154090013633331696) {
  h_25(state, unused, out_8154090013633331696);
}
void car_H_25(double *state, double *unused, double *out_8415923992877417251) {
  H_25(state, unused, out_8415923992877417251);
}
void car_h_24(double *state, double *unused, double *out_7351280482288278166) {
  h_24(state, unused, out_7351280482288278166);
}
void car_H_24(double *state, double *unused, double *out_8301956961654820296) {
  H_24(state, unused, out_8301956961654820296);
}
void car_h_30(double *state, double *unused, double *out_4292406537204830044) {
  h_30(state, unused, out_4292406537204830044);
}
void car_H_30(double *state, double *unused, double *out_1499233651385800496) {
  H_30(state, unused, out_1499233651385800496);
}
void car_h_26(double *state, double *unused, double *out_7000316085453517212) {
  h_26(state, unused, out_7000316085453517212);
}
void car_H_26(double *state, double *unused, double *out_6289316761958078141) {
  H_26(state, unused, out_6289316761958078141);
}
void car_h_27(double *state, double *unused, double *out_3964284714812858416) {
  h_27(state, unused, out_3964284714812858416);
}
void car_H_27(double *state, double *unused, double *out_3673996963186225407) {
  H_27(state, unused, out_3673996963186225407);
}
void car_h_29(double *state, double *unused, double *out_3689090652528352527) {
  h_29(state, unused, out_3689090652528352527);
}
void car_H_29(double *state, double *unused, double *out_989002307071408312) {
  H_29(state, unused, out_989002307071408312);
}
void car_h_28(double *state, double *unused, double *out_1914000772745856672) {
  h_28(state, unused, out_1914000772745856672);
}
void car_H_28(double *state, double *unused, double *out_6071401324140938886) {
  H_28(state, unused, out_6071401324140938886);
}
void car_h_31(double *state, double *unused, double *out_8205050127743358283) {
  h_31(state, unused, out_8205050127743358283);
}
void car_H_31(double *state, double *unused, double *out_8385278031000456823) {
  H_31(state, unused, out_8385278031000456823);
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
