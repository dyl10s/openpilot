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
void err_fun(double *nom_x, double *delta_x, double *out_3831254278589076381) {
   out_3831254278589076381[0] = delta_x[0] + nom_x[0];
   out_3831254278589076381[1] = delta_x[1] + nom_x[1];
   out_3831254278589076381[2] = delta_x[2] + nom_x[2];
   out_3831254278589076381[3] = delta_x[3] + nom_x[3];
   out_3831254278589076381[4] = delta_x[4] + nom_x[4];
   out_3831254278589076381[5] = delta_x[5] + nom_x[5];
   out_3831254278589076381[6] = delta_x[6] + nom_x[6];
   out_3831254278589076381[7] = delta_x[7] + nom_x[7];
   out_3831254278589076381[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2600409940070229376) {
   out_2600409940070229376[0] = -nom_x[0] + true_x[0];
   out_2600409940070229376[1] = -nom_x[1] + true_x[1];
   out_2600409940070229376[2] = -nom_x[2] + true_x[2];
   out_2600409940070229376[3] = -nom_x[3] + true_x[3];
   out_2600409940070229376[4] = -nom_x[4] + true_x[4];
   out_2600409940070229376[5] = -nom_x[5] + true_x[5];
   out_2600409940070229376[6] = -nom_x[6] + true_x[6];
   out_2600409940070229376[7] = -nom_x[7] + true_x[7];
   out_2600409940070229376[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1960169395562662079) {
   out_1960169395562662079[0] = 1.0;
   out_1960169395562662079[1] = 0.0;
   out_1960169395562662079[2] = 0.0;
   out_1960169395562662079[3] = 0.0;
   out_1960169395562662079[4] = 0.0;
   out_1960169395562662079[5] = 0.0;
   out_1960169395562662079[6] = 0.0;
   out_1960169395562662079[7] = 0.0;
   out_1960169395562662079[8] = 0.0;
   out_1960169395562662079[9] = 0.0;
   out_1960169395562662079[10] = 1.0;
   out_1960169395562662079[11] = 0.0;
   out_1960169395562662079[12] = 0.0;
   out_1960169395562662079[13] = 0.0;
   out_1960169395562662079[14] = 0.0;
   out_1960169395562662079[15] = 0.0;
   out_1960169395562662079[16] = 0.0;
   out_1960169395562662079[17] = 0.0;
   out_1960169395562662079[18] = 0.0;
   out_1960169395562662079[19] = 0.0;
   out_1960169395562662079[20] = 1.0;
   out_1960169395562662079[21] = 0.0;
   out_1960169395562662079[22] = 0.0;
   out_1960169395562662079[23] = 0.0;
   out_1960169395562662079[24] = 0.0;
   out_1960169395562662079[25] = 0.0;
   out_1960169395562662079[26] = 0.0;
   out_1960169395562662079[27] = 0.0;
   out_1960169395562662079[28] = 0.0;
   out_1960169395562662079[29] = 0.0;
   out_1960169395562662079[30] = 1.0;
   out_1960169395562662079[31] = 0.0;
   out_1960169395562662079[32] = 0.0;
   out_1960169395562662079[33] = 0.0;
   out_1960169395562662079[34] = 0.0;
   out_1960169395562662079[35] = 0.0;
   out_1960169395562662079[36] = 0.0;
   out_1960169395562662079[37] = 0.0;
   out_1960169395562662079[38] = 0.0;
   out_1960169395562662079[39] = 0.0;
   out_1960169395562662079[40] = 1.0;
   out_1960169395562662079[41] = 0.0;
   out_1960169395562662079[42] = 0.0;
   out_1960169395562662079[43] = 0.0;
   out_1960169395562662079[44] = 0.0;
   out_1960169395562662079[45] = 0.0;
   out_1960169395562662079[46] = 0.0;
   out_1960169395562662079[47] = 0.0;
   out_1960169395562662079[48] = 0.0;
   out_1960169395562662079[49] = 0.0;
   out_1960169395562662079[50] = 1.0;
   out_1960169395562662079[51] = 0.0;
   out_1960169395562662079[52] = 0.0;
   out_1960169395562662079[53] = 0.0;
   out_1960169395562662079[54] = 0.0;
   out_1960169395562662079[55] = 0.0;
   out_1960169395562662079[56] = 0.0;
   out_1960169395562662079[57] = 0.0;
   out_1960169395562662079[58] = 0.0;
   out_1960169395562662079[59] = 0.0;
   out_1960169395562662079[60] = 1.0;
   out_1960169395562662079[61] = 0.0;
   out_1960169395562662079[62] = 0.0;
   out_1960169395562662079[63] = 0.0;
   out_1960169395562662079[64] = 0.0;
   out_1960169395562662079[65] = 0.0;
   out_1960169395562662079[66] = 0.0;
   out_1960169395562662079[67] = 0.0;
   out_1960169395562662079[68] = 0.0;
   out_1960169395562662079[69] = 0.0;
   out_1960169395562662079[70] = 1.0;
   out_1960169395562662079[71] = 0.0;
   out_1960169395562662079[72] = 0.0;
   out_1960169395562662079[73] = 0.0;
   out_1960169395562662079[74] = 0.0;
   out_1960169395562662079[75] = 0.0;
   out_1960169395562662079[76] = 0.0;
   out_1960169395562662079[77] = 0.0;
   out_1960169395562662079[78] = 0.0;
   out_1960169395562662079[79] = 0.0;
   out_1960169395562662079[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5814026824526248658) {
   out_5814026824526248658[0] = state[0];
   out_5814026824526248658[1] = state[1];
   out_5814026824526248658[2] = state[2];
   out_5814026824526248658[3] = state[3];
   out_5814026824526248658[4] = state[4];
   out_5814026824526248658[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5814026824526248658[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5814026824526248658[7] = state[7];
   out_5814026824526248658[8] = state[8];
}
void F_fun(double *state, double dt, double *out_596946632886970600) {
   out_596946632886970600[0] = 1;
   out_596946632886970600[1] = 0;
   out_596946632886970600[2] = 0;
   out_596946632886970600[3] = 0;
   out_596946632886970600[4] = 0;
   out_596946632886970600[5] = 0;
   out_596946632886970600[6] = 0;
   out_596946632886970600[7] = 0;
   out_596946632886970600[8] = 0;
   out_596946632886970600[9] = 0;
   out_596946632886970600[10] = 1;
   out_596946632886970600[11] = 0;
   out_596946632886970600[12] = 0;
   out_596946632886970600[13] = 0;
   out_596946632886970600[14] = 0;
   out_596946632886970600[15] = 0;
   out_596946632886970600[16] = 0;
   out_596946632886970600[17] = 0;
   out_596946632886970600[18] = 0;
   out_596946632886970600[19] = 0;
   out_596946632886970600[20] = 1;
   out_596946632886970600[21] = 0;
   out_596946632886970600[22] = 0;
   out_596946632886970600[23] = 0;
   out_596946632886970600[24] = 0;
   out_596946632886970600[25] = 0;
   out_596946632886970600[26] = 0;
   out_596946632886970600[27] = 0;
   out_596946632886970600[28] = 0;
   out_596946632886970600[29] = 0;
   out_596946632886970600[30] = 1;
   out_596946632886970600[31] = 0;
   out_596946632886970600[32] = 0;
   out_596946632886970600[33] = 0;
   out_596946632886970600[34] = 0;
   out_596946632886970600[35] = 0;
   out_596946632886970600[36] = 0;
   out_596946632886970600[37] = 0;
   out_596946632886970600[38] = 0;
   out_596946632886970600[39] = 0;
   out_596946632886970600[40] = 1;
   out_596946632886970600[41] = 0;
   out_596946632886970600[42] = 0;
   out_596946632886970600[43] = 0;
   out_596946632886970600[44] = 0;
   out_596946632886970600[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_596946632886970600[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_596946632886970600[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_596946632886970600[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_596946632886970600[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_596946632886970600[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_596946632886970600[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_596946632886970600[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_596946632886970600[53] = -9.8100000000000005*dt;
   out_596946632886970600[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_596946632886970600[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_596946632886970600[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_596946632886970600[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_596946632886970600[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_596946632886970600[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_596946632886970600[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_596946632886970600[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_596946632886970600[62] = 0;
   out_596946632886970600[63] = 0;
   out_596946632886970600[64] = 0;
   out_596946632886970600[65] = 0;
   out_596946632886970600[66] = 0;
   out_596946632886970600[67] = 0;
   out_596946632886970600[68] = 0;
   out_596946632886970600[69] = 0;
   out_596946632886970600[70] = 1;
   out_596946632886970600[71] = 0;
   out_596946632886970600[72] = 0;
   out_596946632886970600[73] = 0;
   out_596946632886970600[74] = 0;
   out_596946632886970600[75] = 0;
   out_596946632886970600[76] = 0;
   out_596946632886970600[77] = 0;
   out_596946632886970600[78] = 0;
   out_596946632886970600[79] = 0;
   out_596946632886970600[80] = 1;
}
void h_25(double *state, double *unused, double *out_6549462771998662423) {
   out_6549462771998662423[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4945326686098262856) {
   out_4945326686098262856[0] = 0;
   out_4945326686098262856[1] = 0;
   out_4945326686098262856[2] = 0;
   out_4945326686098262856[3] = 0;
   out_4945326686098262856[4] = 0;
   out_4945326686098262856[5] = 0;
   out_4945326686098262856[6] = 1;
   out_4945326686098262856[7] = 0;
   out_4945326686098262856[8] = 0;
}
void h_24(double *state, double *unused, double *out_3025287820893037920) {
   out_3025287820893037920[0] = state[4];
   out_3025287820893037920[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8927649837496030754) {
   out_8927649837496030754[0] = 0;
   out_8927649837496030754[1] = 0;
   out_8927649837496030754[2] = 0;
   out_8927649837496030754[3] = 0;
   out_8927649837496030754[4] = 1;
   out_8927649837496030754[5] = 0;
   out_8927649837496030754[6] = 0;
   out_8927649837496030754[7] = 0;
   out_8927649837496030754[8] = 0;
   out_8927649837496030754[9] = 0;
   out_8927649837496030754[10] = 0;
   out_8927649837496030754[11] = 0;
   out_8927649837496030754[12] = 0;
   out_8927649837496030754[13] = 0;
   out_8927649837496030754[14] = 1;
   out_8927649837496030754[15] = 0;
   out_8927649837496030754[16] = 0;
   out_8927649837496030754[17] = 0;
}
void h_30(double *state, double *unused, double *out_8259831773456866843) {
   out_8259831773456866843[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2426993727591014229) {
   out_2426993727591014229[0] = 0;
   out_2426993727591014229[1] = 0;
   out_2426993727591014229[2] = 0;
   out_2426993727591014229[3] = 0;
   out_2426993727591014229[4] = 1;
   out_2426993727591014229[5] = 0;
   out_2426993727591014229[6] = 0;
   out_2426993727591014229[7] = 0;
   out_2426993727591014229[8] = 0;
}
void h_26(double *state, double *unused, double *out_2693730589396356978) {
   out_2693730589396356978[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8686830004972319080) {
   out_8686830004972319080[0] = 0;
   out_8686830004972319080[1] = 0;
   out_8686830004972319080[2] = 0;
   out_8686830004972319080[3] = 0;
   out_8686830004972319080[4] = 0;
   out_8686830004972319080[5] = 0;
   out_8686830004972319080[6] = 0;
   out_8686830004972319080[7] = 1;
   out_8686830004972319080[8] = 0;
}
void h_27(double *state, double *unused, double *out_1218913001142171261) {
   out_1218913001142171261[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4601757039391439140) {
   out_4601757039391439140[0] = 0;
   out_4601757039391439140[1] = 0;
   out_4601757039391439140[2] = 0;
   out_4601757039391439140[3] = 1;
   out_4601757039391439140[4] = 0;
   out_4601757039391439140[5] = 0;
   out_4601757039391439140[6] = 0;
   out_4601757039391439140[7] = 0;
   out_4601757039391439140[8] = 0;
}
void h_29(double *state, double *unused, double *out_3033924557621541896) {
   out_3033924557621541896[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1916762383276622045) {
   out_1916762383276622045[0] = 0;
   out_1916762383276622045[1] = 1;
   out_1916762383276622045[2] = 0;
   out_1916762383276622045[3] = 0;
   out_1916762383276622045[4] = 0;
   out_1916762383276622045[5] = 0;
   out_1916762383276622045[6] = 0;
   out_1916762383276622045[7] = 0;
   out_1916762383276622045[8] = 0;
}
void h_28(double *state, double *unused, double *out_1822228885818648778) {
   out_1822228885818648778[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6999161400346152619) {
   out_6999161400346152619[0] = 1;
   out_6999161400346152619[1] = 0;
   out_6999161400346152619[2] = 0;
   out_6999161400346152619[3] = 0;
   out_6999161400346152619[4] = 0;
   out_6999161400346152619[5] = 0;
   out_6999161400346152619[6] = 0;
   out_6999161400346152619[7] = 0;
   out_6999161400346152619[8] = 0;
}
void h_31(double *state, double *unused, double *out_3980504990301998057) {
   out_3980504990301998057[0] = state[8];
}
void H_31(double *state, double *unused, double *out_9133705966503881060) {
   out_9133705966503881060[0] = 0;
   out_9133705966503881060[1] = 0;
   out_9133705966503881060[2] = 0;
   out_9133705966503881060[3] = 0;
   out_9133705966503881060[4] = 0;
   out_9133705966503881060[5] = 0;
   out_9133705966503881060[6] = 0;
   out_9133705966503881060[7] = 0;
   out_9133705966503881060[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_3831254278589076381) {
  err_fun(nom_x, delta_x, out_3831254278589076381);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2600409940070229376) {
  inv_err_fun(nom_x, true_x, out_2600409940070229376);
}
void car_H_mod_fun(double *state, double *out_1960169395562662079) {
  H_mod_fun(state, out_1960169395562662079);
}
void car_f_fun(double *state, double dt, double *out_5814026824526248658) {
  f_fun(state,  dt, out_5814026824526248658);
}
void car_F_fun(double *state, double dt, double *out_596946632886970600) {
  F_fun(state,  dt, out_596946632886970600);
}
void car_h_25(double *state, double *unused, double *out_6549462771998662423) {
  h_25(state, unused, out_6549462771998662423);
}
void car_H_25(double *state, double *unused, double *out_4945326686098262856) {
  H_25(state, unused, out_4945326686098262856);
}
void car_h_24(double *state, double *unused, double *out_3025287820893037920) {
  h_24(state, unused, out_3025287820893037920);
}
void car_H_24(double *state, double *unused, double *out_8927649837496030754) {
  H_24(state, unused, out_8927649837496030754);
}
void car_h_30(double *state, double *unused, double *out_8259831773456866843) {
  h_30(state, unused, out_8259831773456866843);
}
void car_H_30(double *state, double *unused, double *out_2426993727591014229) {
  H_30(state, unused, out_2426993727591014229);
}
void car_h_26(double *state, double *unused, double *out_2693730589396356978) {
  h_26(state, unused, out_2693730589396356978);
}
void car_H_26(double *state, double *unused, double *out_8686830004972319080) {
  H_26(state, unused, out_8686830004972319080);
}
void car_h_27(double *state, double *unused, double *out_1218913001142171261) {
  h_27(state, unused, out_1218913001142171261);
}
void car_H_27(double *state, double *unused, double *out_4601757039391439140) {
  H_27(state, unused, out_4601757039391439140);
}
void car_h_29(double *state, double *unused, double *out_3033924557621541896) {
  h_29(state, unused, out_3033924557621541896);
}
void car_H_29(double *state, double *unused, double *out_1916762383276622045) {
  H_29(state, unused, out_1916762383276622045);
}
void car_h_28(double *state, double *unused, double *out_1822228885818648778) {
  h_28(state, unused, out_1822228885818648778);
}
void car_H_28(double *state, double *unused, double *out_6999161400346152619) {
  H_28(state, unused, out_6999161400346152619);
}
void car_h_31(double *state, double *unused, double *out_3980504990301998057) {
  h_31(state, unused, out_3980504990301998057);
}
void car_H_31(double *state, double *unused, double *out_9133705966503881060) {
  H_31(state, unused, out_9133705966503881060);
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
