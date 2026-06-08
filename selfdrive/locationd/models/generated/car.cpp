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
void err_fun(double *nom_x, double *delta_x, double *out_5319131797443970272) {
   out_5319131797443970272[0] = delta_x[0] + nom_x[0];
   out_5319131797443970272[1] = delta_x[1] + nom_x[1];
   out_5319131797443970272[2] = delta_x[2] + nom_x[2];
   out_5319131797443970272[3] = delta_x[3] + nom_x[3];
   out_5319131797443970272[4] = delta_x[4] + nom_x[4];
   out_5319131797443970272[5] = delta_x[5] + nom_x[5];
   out_5319131797443970272[6] = delta_x[6] + nom_x[6];
   out_5319131797443970272[7] = delta_x[7] + nom_x[7];
   out_5319131797443970272[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3644993322176215676) {
   out_3644993322176215676[0] = -nom_x[0] + true_x[0];
   out_3644993322176215676[1] = -nom_x[1] + true_x[1];
   out_3644993322176215676[2] = -nom_x[2] + true_x[2];
   out_3644993322176215676[3] = -nom_x[3] + true_x[3];
   out_3644993322176215676[4] = -nom_x[4] + true_x[4];
   out_3644993322176215676[5] = -nom_x[5] + true_x[5];
   out_3644993322176215676[6] = -nom_x[6] + true_x[6];
   out_3644993322176215676[7] = -nom_x[7] + true_x[7];
   out_3644993322176215676[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3163511227028018782) {
   out_3163511227028018782[0] = 1.0;
   out_3163511227028018782[1] = 0.0;
   out_3163511227028018782[2] = 0.0;
   out_3163511227028018782[3] = 0.0;
   out_3163511227028018782[4] = 0.0;
   out_3163511227028018782[5] = 0.0;
   out_3163511227028018782[6] = 0.0;
   out_3163511227028018782[7] = 0.0;
   out_3163511227028018782[8] = 0.0;
   out_3163511227028018782[9] = 0.0;
   out_3163511227028018782[10] = 1.0;
   out_3163511227028018782[11] = 0.0;
   out_3163511227028018782[12] = 0.0;
   out_3163511227028018782[13] = 0.0;
   out_3163511227028018782[14] = 0.0;
   out_3163511227028018782[15] = 0.0;
   out_3163511227028018782[16] = 0.0;
   out_3163511227028018782[17] = 0.0;
   out_3163511227028018782[18] = 0.0;
   out_3163511227028018782[19] = 0.0;
   out_3163511227028018782[20] = 1.0;
   out_3163511227028018782[21] = 0.0;
   out_3163511227028018782[22] = 0.0;
   out_3163511227028018782[23] = 0.0;
   out_3163511227028018782[24] = 0.0;
   out_3163511227028018782[25] = 0.0;
   out_3163511227028018782[26] = 0.0;
   out_3163511227028018782[27] = 0.0;
   out_3163511227028018782[28] = 0.0;
   out_3163511227028018782[29] = 0.0;
   out_3163511227028018782[30] = 1.0;
   out_3163511227028018782[31] = 0.0;
   out_3163511227028018782[32] = 0.0;
   out_3163511227028018782[33] = 0.0;
   out_3163511227028018782[34] = 0.0;
   out_3163511227028018782[35] = 0.0;
   out_3163511227028018782[36] = 0.0;
   out_3163511227028018782[37] = 0.0;
   out_3163511227028018782[38] = 0.0;
   out_3163511227028018782[39] = 0.0;
   out_3163511227028018782[40] = 1.0;
   out_3163511227028018782[41] = 0.0;
   out_3163511227028018782[42] = 0.0;
   out_3163511227028018782[43] = 0.0;
   out_3163511227028018782[44] = 0.0;
   out_3163511227028018782[45] = 0.0;
   out_3163511227028018782[46] = 0.0;
   out_3163511227028018782[47] = 0.0;
   out_3163511227028018782[48] = 0.0;
   out_3163511227028018782[49] = 0.0;
   out_3163511227028018782[50] = 1.0;
   out_3163511227028018782[51] = 0.0;
   out_3163511227028018782[52] = 0.0;
   out_3163511227028018782[53] = 0.0;
   out_3163511227028018782[54] = 0.0;
   out_3163511227028018782[55] = 0.0;
   out_3163511227028018782[56] = 0.0;
   out_3163511227028018782[57] = 0.0;
   out_3163511227028018782[58] = 0.0;
   out_3163511227028018782[59] = 0.0;
   out_3163511227028018782[60] = 1.0;
   out_3163511227028018782[61] = 0.0;
   out_3163511227028018782[62] = 0.0;
   out_3163511227028018782[63] = 0.0;
   out_3163511227028018782[64] = 0.0;
   out_3163511227028018782[65] = 0.0;
   out_3163511227028018782[66] = 0.0;
   out_3163511227028018782[67] = 0.0;
   out_3163511227028018782[68] = 0.0;
   out_3163511227028018782[69] = 0.0;
   out_3163511227028018782[70] = 1.0;
   out_3163511227028018782[71] = 0.0;
   out_3163511227028018782[72] = 0.0;
   out_3163511227028018782[73] = 0.0;
   out_3163511227028018782[74] = 0.0;
   out_3163511227028018782[75] = 0.0;
   out_3163511227028018782[76] = 0.0;
   out_3163511227028018782[77] = 0.0;
   out_3163511227028018782[78] = 0.0;
   out_3163511227028018782[79] = 0.0;
   out_3163511227028018782[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1546760495327089109) {
   out_1546760495327089109[0] = state[0];
   out_1546760495327089109[1] = state[1];
   out_1546760495327089109[2] = state[2];
   out_1546760495327089109[3] = state[3];
   out_1546760495327089109[4] = state[4];
   out_1546760495327089109[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1546760495327089109[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1546760495327089109[7] = state[7];
   out_1546760495327089109[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3348391828080031822) {
   out_3348391828080031822[0] = 1;
   out_3348391828080031822[1] = 0;
   out_3348391828080031822[2] = 0;
   out_3348391828080031822[3] = 0;
   out_3348391828080031822[4] = 0;
   out_3348391828080031822[5] = 0;
   out_3348391828080031822[6] = 0;
   out_3348391828080031822[7] = 0;
   out_3348391828080031822[8] = 0;
   out_3348391828080031822[9] = 0;
   out_3348391828080031822[10] = 1;
   out_3348391828080031822[11] = 0;
   out_3348391828080031822[12] = 0;
   out_3348391828080031822[13] = 0;
   out_3348391828080031822[14] = 0;
   out_3348391828080031822[15] = 0;
   out_3348391828080031822[16] = 0;
   out_3348391828080031822[17] = 0;
   out_3348391828080031822[18] = 0;
   out_3348391828080031822[19] = 0;
   out_3348391828080031822[20] = 1;
   out_3348391828080031822[21] = 0;
   out_3348391828080031822[22] = 0;
   out_3348391828080031822[23] = 0;
   out_3348391828080031822[24] = 0;
   out_3348391828080031822[25] = 0;
   out_3348391828080031822[26] = 0;
   out_3348391828080031822[27] = 0;
   out_3348391828080031822[28] = 0;
   out_3348391828080031822[29] = 0;
   out_3348391828080031822[30] = 1;
   out_3348391828080031822[31] = 0;
   out_3348391828080031822[32] = 0;
   out_3348391828080031822[33] = 0;
   out_3348391828080031822[34] = 0;
   out_3348391828080031822[35] = 0;
   out_3348391828080031822[36] = 0;
   out_3348391828080031822[37] = 0;
   out_3348391828080031822[38] = 0;
   out_3348391828080031822[39] = 0;
   out_3348391828080031822[40] = 1;
   out_3348391828080031822[41] = 0;
   out_3348391828080031822[42] = 0;
   out_3348391828080031822[43] = 0;
   out_3348391828080031822[44] = 0;
   out_3348391828080031822[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3348391828080031822[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3348391828080031822[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3348391828080031822[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3348391828080031822[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3348391828080031822[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3348391828080031822[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3348391828080031822[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3348391828080031822[53] = -9.8100000000000005*dt;
   out_3348391828080031822[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3348391828080031822[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3348391828080031822[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3348391828080031822[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3348391828080031822[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3348391828080031822[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3348391828080031822[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3348391828080031822[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3348391828080031822[62] = 0;
   out_3348391828080031822[63] = 0;
   out_3348391828080031822[64] = 0;
   out_3348391828080031822[65] = 0;
   out_3348391828080031822[66] = 0;
   out_3348391828080031822[67] = 0;
   out_3348391828080031822[68] = 0;
   out_3348391828080031822[69] = 0;
   out_3348391828080031822[70] = 1;
   out_3348391828080031822[71] = 0;
   out_3348391828080031822[72] = 0;
   out_3348391828080031822[73] = 0;
   out_3348391828080031822[74] = 0;
   out_3348391828080031822[75] = 0;
   out_3348391828080031822[76] = 0;
   out_3348391828080031822[77] = 0;
   out_3348391828080031822[78] = 0;
   out_3348391828080031822[79] = 0;
   out_3348391828080031822[80] = 1;
}
void h_25(double *state, double *unused, double *out_4471759016602712561) {
   out_4471759016602712561[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1740180598156646058) {
   out_1740180598156646058[0] = 0;
   out_1740180598156646058[1] = 0;
   out_1740180598156646058[2] = 0;
   out_1740180598156646058[3] = 0;
   out_1740180598156646058[4] = 0;
   out_1740180598156646058[5] = 0;
   out_1740180598156646058[6] = 1;
   out_1740180598156646058[7] = 0;
   out_1740180598156646058[8] = 0;
}
void h_24(double *state, double *unused, double *out_3126254991737006136) {
   out_3126254991737006136[0] = state[4];
   out_3126254991737006136[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1269723116113307334) {
   out_1269723116113307334[0] = 0;
   out_1269723116113307334[1] = 0;
   out_1269723116113307334[2] = 0;
   out_1269723116113307334[3] = 0;
   out_1269723116113307334[4] = 1;
   out_1269723116113307334[5] = 0;
   out_1269723116113307334[6] = 0;
   out_1269723116113307334[7] = 0;
   out_1269723116113307334[8] = 0;
   out_1269723116113307334[9] = 0;
   out_1269723116113307334[10] = 0;
   out_1269723116113307334[11] = 0;
   out_1269723116113307334[12] = 0;
   out_1269723116113307334[13] = 0;
   out_1269723116113307334[14] = 1;
   out_1269723116113307334[15] = 0;
   out_1269723116113307334[16] = 0;
   out_1269723116113307334[17] = 0;
}
void h_30(double *state, double *unused, double *out_4168118460115829323) {
   out_4168118460115829323[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1610841651013405988) {
   out_1610841651013405988[0] = 0;
   out_1610841651013405988[1] = 0;
   out_1610841651013405988[2] = 0;
   out_1610841651013405988[3] = 0;
   out_1610841651013405988[4] = 1;
   out_1610841651013405988[5] = 0;
   out_1610841651013405988[6] = 0;
   out_1610841651013405988[7] = 0;
   out_1610841651013405988[8] = 0;
}
void h_26(double *state, double *unused, double *out_2045289894744513329) {
   out_2045289894744513329[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2001322720717410166) {
   out_2001322720717410166[0] = 0;
   out_2001322720717410166[1] = 0;
   out_2001322720717410166[2] = 0;
   out_2001322720717410166[3] = 0;
   out_2001322720717410166[4] = 0;
   out_2001322720717410166[5] = 0;
   out_2001322720717410166[6] = 0;
   out_2001322720717410166[7] = 1;
   out_2001322720717410166[8] = 0;
}
void h_27(double *state, double *unused, double *out_1927282500811136585) {
   out_1927282500811136585[0] = state[3];
}
void H_27(double *state, double *unused, double *out_563921660787018923) {
   out_563921660787018923[0] = 0;
   out_563921660787018923[1] = 0;
   out_563921660787018923[2] = 0;
   out_563921660787018923[3] = 1;
   out_563921660787018923[4] = 0;
   out_563921660787018923[5] = 0;
   out_563921660787018923[6] = 0;
   out_563921660787018923[7] = 0;
   out_563921660787018923[8] = 0;
}
void h_29(double *state, double *unused, double *out_8022800891634675039) {
   out_8022800891634675039[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2277284387656569956) {
   out_2277284387656569956[0] = 0;
   out_2277284387656569956[1] = 1;
   out_2277284387656569956[2] = 0;
   out_2277284387656569956[3] = 0;
   out_2277284387656569956[4] = 0;
   out_2277284387656569956[5] = 0;
   out_2277284387656569956[6] = 0;
   out_2277284387656569956[7] = 0;
   out_2277284387656569956[8] = 0;
}
void h_28(double *state, double *unused, double *out_4964068552255469270) {
   out_4964068552255469270[0] = state[0];
}
void H_28(double *state, double *unused, double *out_313654116091243705) {
   out_313654116091243705[0] = 1;
   out_313654116091243705[1] = 0;
   out_313654116091243705[2] = 0;
   out_313654116091243705[3] = 0;
   out_313654116091243705[4] = 0;
   out_313654116091243705[5] = 0;
   out_313654116091243705[6] = 0;
   out_313654116091243705[7] = 0;
   out_313654116091243705[8] = 0;
}
void h_31(double *state, double *unused, double *out_834309488348690211) {
   out_834309488348690211[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1770826560033606486) {
   out_1770826560033606486[0] = 0;
   out_1770826560033606486[1] = 0;
   out_1770826560033606486[2] = 0;
   out_1770826560033606486[3] = 0;
   out_1770826560033606486[4] = 0;
   out_1770826560033606486[5] = 0;
   out_1770826560033606486[6] = 0;
   out_1770826560033606486[7] = 0;
   out_1770826560033606486[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5319131797443970272) {
  err_fun(nom_x, delta_x, out_5319131797443970272);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3644993322176215676) {
  inv_err_fun(nom_x, true_x, out_3644993322176215676);
}
void car_H_mod_fun(double *state, double *out_3163511227028018782) {
  H_mod_fun(state, out_3163511227028018782);
}
void car_f_fun(double *state, double dt, double *out_1546760495327089109) {
  f_fun(state,  dt, out_1546760495327089109);
}
void car_F_fun(double *state, double dt, double *out_3348391828080031822) {
  F_fun(state,  dt, out_3348391828080031822);
}
void car_h_25(double *state, double *unused, double *out_4471759016602712561) {
  h_25(state, unused, out_4471759016602712561);
}
void car_H_25(double *state, double *unused, double *out_1740180598156646058) {
  H_25(state, unused, out_1740180598156646058);
}
void car_h_24(double *state, double *unused, double *out_3126254991737006136) {
  h_24(state, unused, out_3126254991737006136);
}
void car_H_24(double *state, double *unused, double *out_1269723116113307334) {
  H_24(state, unused, out_1269723116113307334);
}
void car_h_30(double *state, double *unused, double *out_4168118460115829323) {
  h_30(state, unused, out_4168118460115829323);
}
void car_H_30(double *state, double *unused, double *out_1610841651013405988) {
  H_30(state, unused, out_1610841651013405988);
}
void car_h_26(double *state, double *unused, double *out_2045289894744513329) {
  h_26(state, unused, out_2045289894744513329);
}
void car_H_26(double *state, double *unused, double *out_2001322720717410166) {
  H_26(state, unused, out_2001322720717410166);
}
void car_h_27(double *state, double *unused, double *out_1927282500811136585) {
  h_27(state, unused, out_1927282500811136585);
}
void car_H_27(double *state, double *unused, double *out_563921660787018923) {
  H_27(state, unused, out_563921660787018923);
}
void car_h_29(double *state, double *unused, double *out_8022800891634675039) {
  h_29(state, unused, out_8022800891634675039);
}
void car_H_29(double *state, double *unused, double *out_2277284387656569956) {
  H_29(state, unused, out_2277284387656569956);
}
void car_h_28(double *state, double *unused, double *out_4964068552255469270) {
  h_28(state, unused, out_4964068552255469270);
}
void car_H_28(double *state, double *unused, double *out_313654116091243705) {
  H_28(state, unused, out_313654116091243705);
}
void car_h_31(double *state, double *unused, double *out_834309488348690211) {
  h_31(state, unused, out_834309488348690211);
}
void car_H_31(double *state, double *unused, double *out_1770826560033606486) {
  H_31(state, unused, out_1770826560033606486);
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
